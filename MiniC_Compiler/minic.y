%{
#include "definition.h"
extern char *yytext;
extern int yylineno;
extern int lex_err;
int funcount, gcount, syntax_err, prg_err, total_err;
struct allFunc **ALL;
struct globalVar **gVar;
%}

/* 终结符的定义 */
%token IDENT VOID INT WHILE IF ELSE RETURN EQ NE LE GE
%token AND OR DECNUM CONTINUE BREAK HEXNUM LSHIFT RSHIFT

/* 定义运算符结合性 */
%left OR
%left AND
%left EQ NE LE GE '<' '>'
%left '+' '-'
%left '|'
%left '&' '^'
%left '*' '/' '%'
%right LSHIFT RSHIFT
%right '!'
%right '~'
%nonassoc UMINUS
%nonassoc ELSE

/* 定义program为开始符号，所有推导从它开始 */
%start program

/* 语义值类型定义为一个union，包括2种可能用到的类型 */
%union {
    char *text;         /* 终结符语义值类型 */
    struct AST *node;	/* 非终结符语义值类型 */
}

/* 终结符语义值类型说明 */
%type <text> IDENT VOID INT WHILE IF ELSE RETURN EQ NE LE GE
%type <text> AND OR DECNUM CONTINUE BREAK HEXNUM LSHIFT RSHIFT

/* 非终结符语义值类型说明 */
%type <node> program
%type <node> decl_list
%type <node> decl
%type <node> var_decl
%type <node> type_spec
%type <node> fun_decl
%type <node> params
%type <node> param_list
%type <node> param
%type <node> stmt_list
%type <node> stmt
%type <node> expr_stmt
%type <node> while_stmt
%type <node> block_stmt
%type <node> compound_stmt
%type <node> local_decls
%type <node> local_decl
%type <node> if_stmt
%type <node> return_stmt
%type <node> expr
%type <node> int_literal
%type <node> arg_list
%type <node> continue_stmt
%type <node> break_stmt

%%
program
    : decl_list                 {   $$ = makeNode(1); $$->child[0] = $1; $1->parent = $$;
                                    $$->ntno = 1; $$->procno = 1;
                                    $$->lineno = yylineno;
                                }
    ;

decl_list
    : decl_list decl            {   $$ = makeNode(2); $$->child[0] = $1; $1->parent = $$;
                                    $$->child[1] = $2; $2->parent = $$;
                                    $$->ntno = 2; $$->procno = 1;
                                    $$->multiplicity = $1->multiplicity + 1;
                                    $$->lineno = yylineno;
                                }
    | decl                      {   $$ = makeNode(1); $$->child[0] = $1; $1->parent = $$;
                                    $$->ntno = 2; $$->procno = 2;
                                    $$->multiplicity = 1;
                                    $$->lineno = yylineno;
                                }
    | error
    ;

decl
    : var_decl                  {   $$ = makeNode(1); $$->child[0] = $1; $1->parent = $$;
                                    $$->ntno = 3; $$->procno = 1;
                                    $$->lineno = yylineno;
                                }
    | fun_decl                  {   $$ = makeNode(1); $$->child[0] = $1; $1->parent = $$;
                                    $$->ntno = 3; $$->procno = 2;
                                    $$->lineno = yylineno;
                                }
    | error
    ;

var_decl
    : type_spec IDENT ';'       {   $$ = makeNode(1); $$->child[0] = $1; $1->parent = $$;
                                    $$->ntno = 4; $$->procno = 1;
                                    strcpy($$->txt, $2);
                                    $$->lineno = yylineno;
                                    gVar[gcount] = (struct globalVar *)malloc(sizeof(struct globalVar));
                                    strcpy(gVar[gcount]->name, $2); gVar[gcount]->space = 1;
                                    gVar[gcount]->t = $$; gcount++;
                                }
    | type_spec IDENT '[' DECNUM ']' ';'
                                {   $$ = makeNode(1); $$->child[0] = $1; $1->parent = $$;
                                    $$->ntno = 4; $$->procno = 2;
                                    strcpy($$->txt, $2); strcpy($$->numtxt, $4);
                                    $$->lineno = yylineno;
                                    gVar[gcount] = (struct globalVar *)malloc(sizeof(struct globalVar));
                                    strcpy(gVar[gcount]->name, $2); gVar[gcount]->space = atoi($4);
                                    gVar[gcount]->t = $$; gcount++;
                                }
    | error
    ;

type_spec
    : VOID                      {   $$ = makeNode(0); $$->ntno = 5; $$->procno = 1;
                                    $$->lineno = yylineno;
                                }
    | INT                       {   $$ = makeNode(0); $$->ntno = 5; $$->procno = 2;
                                    $$->lineno = yylineno;
                                }
    | error
    ;

fun_decl
    : type_spec IDENT '(' params ')' compound_stmt
                                {   $$ = makeNode(3); $$->child[0] = $1; $1->parent = $$;
                                    $$->child[1] = $4; $4->parent = $$;
                                    $$->child[2] = $6; $6->parent = $$;
                                    $$->ntno = 6; $$->procno = 1; strcpy($$->txt, $2);
                                    ALL[funcount] = (struct allFunc *)malloc(sizeof(struct allFunc));
                                    strcpy(ALL[funcount]->name, $2);
                                    ALL[funcount]->t = $$; funcount++;
                                    $$->lineno = yylineno;
                                }
    | type_spec IDENT '(' params ')' ';'
                                {   $$ = makeNode(2); $$->child[0] = $1; $1->parent = $$;
                                    $$->child[1] = $4; $4->parent = $$;
                                    $$->ntno = 6; $$->procno = 2; strcpy($$->txt, $2);
                                    $$->lineno = yylineno;
                                }
    | error
    ;

params
    : param_list                {   $$ = makeNode(1); $$->child[0] = $1; $1->parent = $$;
                                    $$->ntno = 7; $$->procno = 1;
                                    $$->lineno = yylineno;
                                }
    | VOID                      {   $$ = makeNode(0); $$->ntno = 7; $$->procno = 2;
                                    $$->lineno = yylineno;
                                }
    | error
    ;
    
param_list
    : param_list ',' param      {   $$ = makeNode(2); $$->child[0] = $1; $1->parent = $$;
                                    $$->child[1] = $3; $3->parent = $$;
                                    $$->ntno = 8; $$->procno = 1;
                                    $$->multiplicity = $1->multiplicity + 1;
                                    $$->lineno = yylineno;
                                }
    | param                     {   $$ = makeNode(1); $$->child[0] = $1; $1->parent = $$;
                                    $$->ntno = 8; $$->procno = 2;
                                    $$->multiplicity = 1;
                                    $$->lineno = yylineno;
                                }
    | error
    ;
    
param
    : type_spec IDENT           {   $$ = makeNode(1); $$->child[0] = $1; $1->parent = $$;
                                    $$->ntno = 9; $$->procno = 1;
                                    strcpy($$->txt, $2);
                                    $$->lineno = yylineno;
                                }
    | type_spec IDENT '[' DECNUM ']'
                                {   $$ = makeNode(1); $$->child[0] = $1; $1->parent = $$;
                                    $$->ntno = 9; $$->procno = 2;
                                    strcpy($$->txt, $2); strcpy($$->numtxt, $4);
                                    $$->lineno = yylineno;
                                }
    | error
    ;

stmt_list
    : stmt_list stmt            {   $$ = makeNode(2); $$->child[0] = $1; $1->parent = $$;
                                    $$->child[1] = $2; $2->parent = $$;
                                    $$->ntno = 10; $$->procno = 1;
                                    $$->multiplicity = $1->multiplicity + 1;
                                    $$->lineno = yylineno;
                                }
    | stmt                      {   $$ = makeNode(1); $$->child[0] = $1; $1->parent = $$;
                                    $$->ntno = 10; $$->procno = 2;
                                    $$->multiplicity = 1;
                                    $$->lineno = yylineno;
                                }
    | error
    ;
    
stmt
    : expr_stmt                 {   $$ = makeNode(1); $$->child[0] = $1; $1->parent = $$;
                                    $$->ntno = 11; $$->procno = 1;
                                    $$->lineno = yylineno;
                                }
    | block_stmt                {   $$ = makeNode(1); $$->child[0] = $1; $1->parent = $$;
                                    $$->ntno = 11; $$->procno = 2;
                                    $$->lineno = yylineno;
                                }
    | if_stmt                   {   $$ = makeNode(1); $$->child[0] = $1; $1->parent = $$;
                                    $$->ntno = 11; $$->procno = 3;
                                    $$->lineno = yylineno;
                                }
    | while_stmt                {   $$ = makeNode(1); $$->child[0] = $1; $1->parent = $$;
                                    $$->ntno = 11; $$->procno = 4;
                                    $$->lineno = yylineno;
                                }
    | return_stmt               {   $$ = makeNode(1); $$->child[0] = $1; $1->parent = $$;
                                    $$->ntno = 11; $$->procno = 5;
                                    $$->lineno = yylineno;
                                }
    | continue_stmt             {   $$ = makeNode(1); $$->child[0] = $1; $1->parent = $$;
                                    $$->ntno = 11; $$->procno = 6;
                                    $$->lineno = yylineno;
                                }
    | break_stmt                {   $$ = makeNode(1); $$->child[0] = $1; $1->parent = $$;
                                    $$->ntno = 11; $$->procno = 7;
                                    $$->lineno = yylineno;
                                }
    | error
    ;
    
expr_stmt
    : IDENT '=' expr ';'        {   $$ = makeNode(1); $$->child[0] = $3; $3->parent = $$;
                                    $$->ntno = 12; $$->procno = 1;
                                    strcpy($$->txt, $1);
                                    $$->lineno = yylineno;
                                }
    | IDENT '[' DECNUM ']' '=' expr ';'
                                {   $$ = makeNode(1); $$->child[0] = $6; $6->parent = $$;
                                    $$->ntno = 12; $$->procno = 2;
                                    strcpy($$->txt, $1); strcpy($$->numtxt, $3);
                                    $$->lineno = yylineno;
                                }
    | '$' HEXNUM '=' expr ';'   {   $$ = makeNode(1); $$->child[0] = $4; $4->parent = $$;
                                    $$->ntno = 12; $$->procno = 3;
                                    strcpy($$->numtxt, $2);
                                    $$->lineno = yylineno;
                                }
    | IDENT '(' arg_list ')' ';'
                                {   $$ = makeNode(1); $$->child[0] = $3; $3->parent = $$;
                                    $$->ntno = 12; $$->procno = 4;
                                    strcpy($$->txt, $1);
                                    $$->lineno = yylineno;
                                }
    | IDENT '(' ')' ';'
                                {   $$ = makeNode(0);
                                    $$->ntno = 12; $$->procno = 5;
                                    strcpy($$->txt, $1);
                                    $$->lineno = yylineno;
                                }
    | error
    ;

while_stmt
    : WHILE '(' expr ')' stmt   {   $$ = makeNode(2); $$->child[0] = $3; $3->parent = $$;
                                    $$->child[1] = $5; $5->parent = $$;
                                    $$->ntno = 13; $$->procno = 1;
                                    $$->lineno = yylineno;
                                }
    | error
    ;

block_stmt
    : '{' stmt_list '}'         {   $$ = makeNode(1); $$->child[0] = $2; $2->parent = $$;
                                    $$->ntno = 14; $$->procno = 1;
                                    $$->lineno = yylineno;
                                }
    | error
    ;
    
compound_stmt
    : '{' local_decls stmt_list '}'
                                {   $$ = makeNode(2); $$->child[0] = $2; $2->parent = $$;
                                    $$->child[1] = $3; $3->parent = $$;
                                    $$->ntno = 15; $$->procno = 1;
                                    $$->lineno = yylineno;
                                }
    | '{' local_decls '}'       {   $$ = makeNode(1); $$->child[0] = $2; $2->parent = $$;
                                    $$->ntno = 15; $$->procno = 2;
                                    $$->lineno = yylineno;
                                }
    | '{' stmt_list '}'         {   $$ = makeNode(1); $$->child[0] = $2; $2->parent = $$;
                                    $$->ntno = 15; $$->procno = 3;
                                    $$->lineno = yylineno;
                                }
    | '{' '}'                   {   $$ = makeNode(0);
                                    $$->ntno = 15; $$->procno = 4;
                                    $$->lineno = yylineno;
                                }
    | error
    ;

local_decls
    : local_decls local_decl    {   $$ = makeNode(2); $$->child[0] = $1; $1->parent = $$;
                                    $$->child[1] = $2; $2->parent = $$;
                                    $$->ntno = 16; $$->procno = 1;
                                    $$->multiplicity = $1->multiplicity + 1;
                                    $$->lineno = yylineno;
                                }
    | local_decl                {   $$ = makeNode(1); $$->child[0] = $1; $1->parent = $$;
                                    $$->ntno = 16; $$->procno = 2;
                                    $$->multiplicity = 1;
                                    $$->lineno = yylineno;
                                }
    | error
    ;
    
local_decl
    : type_spec IDENT ';'       {   $$ = makeNode(1); $$->child[0] = $1; $1->parent = $$;
                                    $$->ntno = 17; $$->procno = 1;
                                    strcpy($$->txt, $2);
                                    $$->lineno = yylineno;
                                }
    | type_spec IDENT '[' DECNUM ']' ';'
                                {   $$ = makeNode(1); $$->child[0] = $1; $1->parent = $$;
                                    $$->ntno = 17; $$->procno = 2;
                                    strcpy($$->txt, $2); strcpy($$->numtxt, $4);
                                    $$->lineno = yylineno;
                                }
    | error
    ;
    
if_stmt
    : IF '(' expr ')' stmt %prec UMINUS
                                {   $$ = makeNode(2); $$->child[0] = $3; $3->parent = $$;
                                    $$->child[1] = $5; $5->parent = $$;
                                    $$->ntno = 18; $$->procno = 1;
                                    $$->lineno = yylineno;
                                }
    | IF '(' expr ')' stmt ELSE stmt
                                {   $$ = makeNode(3); $$->child[0] = $3; $3->parent = $$;
                                    $$->child[1] = $5; $5->parent = $$;
                                    $$->child[2] = $7; $7->parent = $$;
                                    $$->ntno = 18; $$->procno = 2;
                                    $$->lineno = yylineno;
                                }
    | error
    ;

return_stmt
    : RETURN ';' 				{   $$ = makeNode(0);
                                    $$->ntno = 19; $$->procno = 1;
                                    $$->lineno = yylineno;
                                }
    | RETURN expr ';'           {   $$ = makeNode(1); $$->child[0] = $2; $2->parent = $$;
                                    $$->ntno = 19; $$->procno = 2;
                                    $$->lineno = yylineno;
                                }
    | error
    ;

expr
    : expr OR expr              {   $$ = makeNode(2); $$->child[0] = $1; $1->parent = $$;
                                    $$->child[1] = $3; $3->parent = $$;
                                    $$->ntno = 20; $$->procno = 1;
                                    $$->contain_expr = 1;
                                    $$->lineno = yylineno;
                                }
    | expr EQ expr              {   $$ = makeNode(2); $$->child[0] = $1; $1->parent = $$;
                                    $$->child[1] = $3; $3->parent = $$;
                                    $$->ntno = 20; $$->procno = 2;
                                    $$->contain_expr = 1;
                                    $$->lineno = yylineno;
                                }
    | expr NE expr              {   $$ = makeNode(2); $$->child[0] = $1; $1->parent = $$;
                                    $$->child[1] = $3; $3->parent = $$;
                                    $$->ntno = 20; $$->procno = 3;
                                    $$->contain_expr = 1;
                                    $$->lineno = yylineno;
                                }
    | expr LE expr              {   $$ = makeNode(2); $$->child[0] = $1; $1->parent = $$;
                                    $$->child[1] = $3; $3->parent = $$;
                                    $$->ntno = 20; $$->procno = 4;
                                    $$->contain_expr = 1;
                                    $$->lineno = yylineno;
                                }
    | expr '<' expr             {   $$ = makeNode(2); $$->child[0] = $1; $1->parent = $$;
                                    $$->child[1] = $3; $3->parent = $$;
                                    $$->ntno = 20; $$->procno = 5;
                                    $$->contain_expr = 1;
                                    $$->lineno = yylineno;
                                }
    | expr GE expr              {   $$ = makeNode(2); $$->child[0] = $1; $1->parent = $$;
                                    $$->child[1] = $3; $3->parent = $$;
                                    $$->ntno = 20; $$->procno = 6;
                                    $$->contain_expr = 1;
                                    $$->lineno = yylineno;
                                }
    | expr '>' expr             {   $$ = makeNode(2); $$->child[0] = $1; $1->parent = $$;
                                    $$->child[1] = $3; $3->parent = $$;
                                    $$->ntno = 20; $$->procno = 7;
                                    $$->contain_expr = 1;
                                    $$->lineno = yylineno;
                                }
    | expr AND expr             {   $$ = makeNode(2); $$->child[0] = $1; $1->parent = $$;
                                    $$->child[1] = $3; $3->parent = $$;
                                    $$->ntno = 20; $$->procno = 8;
                                    $$->contain_expr = 1;
                                    $$->lineno = yylineno;
                                }
    | expr '+' expr             {   $$ = makeNode(2); $$->child[0] = $1; $1->parent = $$;
                                    $$->child[1] = $3; $3->parent = $$;
                                    $$->ntno = 20; $$->procno = 9;
                                    $$->contain_expr = 1;
                                    $$->lineno = yylineno;
                                }
    | expr '-' expr             {   $$ = makeNode(2); $$->child[0] = $1; $1->parent = $$;
                                    $$->child[1] = $3; $3->parent = $$;
                                    $$->ntno = 20; $$->procno = 10;
                                    $$->contain_expr = 1;
                                    $$->lineno = yylineno;
                                }
    | expr '*' expr             {   $$ = makeNode(2); $$->child[0] = $1; $1->parent = $$;
                                    $$->child[1] = $3; $3->parent = $$;
                                    $$->ntno = 20; $$->procno = 11;
                                    $$->contain_expr = 1;
                                    $$->lineno = yylineno;
                                }
    | expr '/' expr             {   $$ = makeNode(2); $$->child[0] = $1; $1->parent = $$;
                                    $$->child[1] = $3; $3->parent = $$;
                                    $$->ntno = 20; $$->procno = 12;
                                    $$->contain_expr = 1;
                                    $$->lineno = yylineno;
                                }
    | expr '%' expr             {   $$ = makeNode(2); $$->child[0] = $1; $1->parent = $$;
                                    $$->child[1] = $3; $3->parent = $$;
                                    $$->ntno = 20; $$->procno = 13;
                                    $$->contain_expr = 1;
                                    $$->lineno = yylineno;
                                }
    | '!' expr %prec UMINUS     {   $$ = makeNode(1); $$->child[0] = $2; $2->parent = $$;
                                    $$->ntno = 20; $$->procno = 14;
                                    $$->contain_expr = 1;
                                    $$->lineno = yylineno;
                                }
    | '-' expr %prec UMINUS     {   $$ = makeNode(1); $$->child[0] = $2; $2->parent = $$;
                                    $$->ntno = 20; $$->procno = 15;
                                    $$->contain_expr = 1;
                                    $$->lineno = yylineno;
                                }
    | '+' expr %prec UMINUS     {   $$ = makeNode(1); $$->child[0] = $2; $2->parent = $$;
                                    $$->ntno = 20; $$->procno = 16;
                                    $$->contain_expr = 1;
                                    $$->lineno = yylineno;
                                }
    | '$' HEXNUM %prec UMINUS   {   $$ = makeNode(0); $$->ntno = 20; $$->procno = 17;
                                    strcpy($$->numtxt, $2);
                                    $$->lineno = yylineno;
                                }
    | '(' expr ')'              {   $$ = makeNode(1); $$->child[0] = $2; $2->parent = $$;
                                    $$->ntno = 20; $$->procno = 18;
                                    $$->contain_expr = 1;
                                    $$->lineno = yylineno;
                                }
    | IDENT                     {   $$ = makeNode(0); $$->ntno = 20; $$->procno = 19;
                                    strcpy($$->txt, $1);
                                    $$->lineno = yylineno;
                                }
    | IDENT '[' DECNUM ']'      {   $$ = makeNode(0); $$->ntno = 20; $$->procno = 20;
                                    strcpy($$->txt, $1); strcpy($$->numtxt, $3);
                                    $$->lineno = yylineno;
        
                                }
    | IDENT '(' arg_list ')'  	{   $$ = makeNode(1); $$->child[0] = $3; $3->parent = $$;
                                    $$->ntno = 20; $$->procno = 21; strcpy($$->txt, $1);
                                    $$->lineno = yylineno;
                                }
    | IDENT '(' ')'             {   $$ = makeNode(0); $$->ntno = 20; $$->procno = 22;
                                    strcpy($$->txt, $1);
                                    $$->lineno = yylineno;
                                }
    | int_literal               {   $$ = makeNode(1); $$->child[0] = $1; $1->parent = $$;
                                    $$->ntno = 20; $$->procno = 23;
                                    $$->lineno = yylineno;
                                }
    | expr '&' expr             {   $$ = makeNode(2); $$->child[0] = $1; $1->parent = $$;
                                    $$->child[1] = $3; $3->parent = $$;
                                    $$->ntno = 20; $$->procno = 24;
                                    $$->contain_expr = 1;
                                    $$->lineno = yylineno;
                                }
    | expr '^' expr             {   $$ = makeNode(2); $$->child[0] = $1; $1->parent = $$;
                                    $$->child[1] = $3; $3->parent = $$;
                                    $$->ntno = 20; $$->procno = 25;
                                    $$->contain_expr = 1;
                                    $$->lineno = yylineno;
                                }
    | '~' expr                  {   $$ = makeNode(1); $$->child[0] = $2; $2->parent = $$;
                                    $$->ntno = 20; $$->procno = 26;
                                    $$->contain_expr = 1;
                                    $$->lineno = yylineno;
                                }
    | expr LSHIFT expr          {   $$ = makeNode(2); $$->child[0] = $1; $1->parent = $$;
                                    $$->child[1] = $3; $3->parent = $$;
                                    $$->ntno = 20; $$->procno = 27;
                                    $$->contain_expr = 1;
                                    $$->lineno = yylineno;
                                }
    | expr RSHIFT expr          {   $$ = makeNode(2); $$->child[0] = $1; $1->parent = $$;
                                    $$->child[1] = $3; $3->parent = $$;
                                    $$->ntno = 20; $$->procno = 28;
                                    $$->contain_expr = 1;
                                    $$->lineno = yylineno;
                                }
    | expr '|' expr             {   $$ = makeNode(2); $$->child[0] = $1; $1->parent = $$;
                                    $$->child[1] = $3; $3->parent = $$;
                                    $$->ntno = 20; $$->procno = 29;
                                    $$->contain_expr = 1;
                                    $$->lineno = yylineno;
                                }
    | error
    ;
    
int_literal
    : DECNUM                    {   $$ = makeNode(0); $$->ntno = 21; $$->procno = 1;
                                    strcpy($$->numtxt, $1);
                                    $$->lineno = yylineno;
                                }
    | HEXNUM                    {   $$ = makeNode(0); $$->ntno = 21; $$->procno = 2;
                                    strcpy($$->numtxt, $1);
                                    $$->lineno = yylineno;
                                }
    | error
    ;

arg_list
    : arg_list ',' expr         {   $$ = makeNode(2); $$->child[0] = $1; $1->parent = $$;
                                    $$->child[1] = $3; $3->parent = $$;
                                    $$->ntno = 22; $$->procno = 1;
                                    $$->multiplicity = $1->multiplicity + 1;
                                    $$->lineno = yylineno;
                                }
    | expr                      {   $$ = makeNode(1); $$->child[0] = $1; $1->parent = $$;
                                    $$->ntno = 22; $$->procno = 2;
                                    $$->multiplicity = 1;
                                    $$->lineno = yylineno;
                                }
    | error
    ;

continue_stmt
    : CONTINUE ';'              {   $$ = makeNode(0); $$->ntno = 23; $$->procno = 1;
                                    $$->lineno = yylineno;
                                }
    | error
    ;

break_stmt
    : BREAK ';'                 {   $$ = makeNode(0); $$->ntno = 24; $$->procno = 1;
                                    $$->lineno = yylineno;
                                }
    | error
    ;
%%
/* 错误处理 */
yyerror(s)
char *s;
{
    fprintf(stderr, "line %d: syntax error: unexpected token '%s'\n", yylineno, yytext);
    syntax_err++;
}

int main()
{
    syntax_err = 0;
    funcount = 0;
    gcount = 0;
    ALL = (struct allFunc **)malloc(20 * sizeof(struct allFunc *));
    gVar = (struct globalVar **)malloc(20 * sizeof(struct globalVar *));
    printf("Generating MIPS code...\n");
    yyparse();
    prg_err = generateMIPS();
    total_err = lex_err + syntax_err + prg_err;
    if (total_err > 0)
        fprintf(stderr, "%d error(s) generated.\n", total_err);
    else
        printf("MIPS code generated.\n");
    return 0;
}
