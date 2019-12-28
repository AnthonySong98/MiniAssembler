digit       ([0-9])|([1-9][0-9]*)
letter      [a-zA-Z]
id          {letter}({letter}|{digit})*
num         {digit}[1-9]*
hex         0(x|X)({letter}|[0-9])*

%{
#include "minic.tab.h"
#include "definition.h"
extern YYSTYPE yylval;
int lex_err = 0;
%}

%%
"void"          { yylval.text = strdup(yytext); return VOID; }
"continue"      { yylval.text = strdup(yytext); return CONTINUE; }
"if"            { yylval.text = strdup(yytext); return IF; }
"while"         { yylval.text = strdup(yytext); return WHILE; }
"else"          { yylval.text = strdup(yytext); return ELSE; }
"break"         { yylval.text = strdup(yytext); return BREAK; }
"int"           { yylval.text = strdup(yytext); return INT; }
"return"        { yylval.text = strdup(yytext); return RETURN; }
"&&"            { yylval.text = strdup(yytext); return AND; }
"||"            { yylval.text = strdup(yytext); return OR; }
"<="            { yylval.text = strdup(yytext); return LE; }
">="            { yylval.text = strdup(yytext); return GE; }
"=="            { yylval.text = strdup(yytext); return EQ; }
"!="            { yylval.text = strdup(yytext); return NE; }
">"             { yylval.text = strdup(yytext); return '>'; }
"<"             { yylval.text = strdup(yytext); return '<'; }
","             { yylval.text = strdup(yytext); return ','; }
";"             { yylval.text = strdup(yytext); return ';'; }
"{"             { yylval.text = strdup(yytext); return '{'; }
"}"             { yylval.text = strdup(yytext); return '}'; }
"+"             { yylval.text = strdup(yytext); return '+'; }
"-"             { yylval.text = strdup(yytext); return '-'; }
"*"             { yylval.text = strdup(yytext); return '*'; }
"/"             { yylval.text = strdup(yytext); return '/'; }
"%"             { yylval.text = strdup(yytext); return '%'; }
"="             { yylval.text = strdup(yytext); return '='; }
"("             { yylval.text = strdup(yytext); return '('; }
")"             { yylval.text = strdup(yytext); return ')'; }
"&"             { yylval.text = strdup(yytext); return '&'; }
"|"             { yylval.text = strdup(yytext); return '|'; }
"^"             { yylval.text = strdup(yytext); return '^'; }
"~"             { yylval.text = strdup(yytext); return '~'; }
"["             { yylval.text = strdup(yytext); return '['; }
"]"             { yylval.text = strdup(yytext); return ']'; }
"$"             { yylval.text = strdup(yytext); return '$'; }
"<<"            { yylval.text = strdup(yytext); return LSHIFT; }
">>"            { yylval.text = strdup(yytext); return RSHIFT; }
{id}            { yylval.text = strdup(yytext); return IDENT; }
{num}           { yylval.text = strdup(yytext); return DECNUM; }
{hex}           { yylval.text = strdup(yytext); return HEXNUM; }
"/*"            { comment1(); }
"//"            { comment2(); }
[ \t\v\f]       { }
[\n\r]          { yylineno++; }
.               { lexerror(); }
%%
/* 处理多行注释 */
comment1()
{
    char c, c1;
    c = input();
    while (1) {
        c1 = input();
        if (c == '*' && c1 == '/')
            break;
        else if (c == '\n')
            yylineno++;
        c = c1;
    }
}

/* 处理单行注释 */
comment2()
{
    char c;
    while ((c = input()) != '\n');
    yylineno++;
}

/* 错误处理 */
lexerror()
{
    fprintf(stderr, "line %d: lexical error: invalid '%s'\n", yylineno, yytext);
    lex_err++;
}

yywrap()
{
    return(1);
}

