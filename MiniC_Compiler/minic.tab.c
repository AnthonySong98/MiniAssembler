/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     IDENT = 258,
     VOID = 259,
     INT = 260,
     WHILE = 261,
     IF = 262,
     ELSE = 263,
     RETURN = 264,
     EQ = 265,
     NE = 266,
     LE = 267,
     GE = 268,
     AND = 269,
     OR = 270,
     DECNUM = 271,
     CONTINUE = 272,
     BREAK = 273,
     HEXNUM = 274,
     LSHIFT = 275,
     RSHIFT = 276,
     UMINUS = 277
   };
#endif
/* Tokens.  */
#define IDENT 258
#define VOID 259
#define INT 260
#define WHILE 261
#define IF 262
#define ELSE 263
#define RETURN 264
#define EQ 265
#define NE 266
#define LE 267
#define GE 268
#define AND 269
#define OR 270
#define DECNUM 271
#define CONTINUE 272
#define BREAK 273
#define HEXNUM 274
#define LSHIFT 275
#define RSHIFT 276
#define UMINUS 277




/* Copy the first part of user declarations.  */
#line 1 "minic.y"

#include "definition.h"
extern char *yytext;
extern int yylineno;
extern int lex_err;
int funcount, gcount, syntax_err, prg_err, total_err;
struct allFunc **ALL;
struct globalVar **gVar;


/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 33 "minic.y"
{
    char *text;         /* 终结符语义值类型 */
    struct AST *node;	/* 非终结符语义值类型 */
}
/* Line 193 of yacc.c.  */
#line 155 "minic.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 168 "minic.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  10
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   553

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  45
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  25
/* YYNRULES -- Number of rules.  */
#define YYNRULES  104
/* YYNRULES -- Number of states.  */
#define YYNSTATES  176

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   277

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    32,     2,     2,    42,    31,    27,     2,
      38,    39,    29,    24,    40,    25,     2,    30,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    35,
      22,    41,    23,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    36,     2,    37,    28,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    43,    26,    44,    33,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    34
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     8,    10,    12,    14,    16,    18,
      22,    29,    31,    33,    35,    37,    44,    51,    53,    55,
      57,    59,    63,    65,    67,    70,    76,    78,    81,    83,
      85,    87,    89,    91,    93,    95,    97,    99,   101,   106,
     114,   120,   126,   131,   133,   139,   141,   145,   147,   152,
     156,   160,   163,   165,   168,   170,   172,   176,   183,   185,
     191,   199,   201,   204,   208,   210,   214,   218,   222,   226,
     230,   234,   238,   242,   246,   250,   254,   258,   262,   265,
     268,   271,   274,   278,   280,   285,   290,   294,   296,   300,
     304,   307,   311,   315,   319,   321,   323,   325,   327,   331,
     333,   335,   338,   340,   343
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      46,     0,    -1,    47,    -1,    47,    48,    -1,    48,    -1,
       1,    -1,    49,    -1,    51,    -1,     1,    -1,    50,     3,
      35,    -1,    50,     3,    36,    16,    37,    35,    -1,     1,
      -1,     4,    -1,     5,    -1,     1,    -1,    50,     3,    38,
      52,    39,    60,    -1,    50,     3,    38,    52,    39,    35,
      -1,     1,    -1,    53,    -1,     4,    -1,     1,    -1,    53,
      40,    54,    -1,    54,    -1,     1,    -1,    50,     3,    -1,
      50,     3,    36,    16,    37,    -1,     1,    -1,    55,    56,
      -1,    56,    -1,     1,    -1,    57,    -1,    59,    -1,    63,
      -1,    58,    -1,    64,    -1,    68,    -1,    69,    -1,     1,
      -1,     3,    41,    65,    35,    -1,     3,    36,    16,    37,
      41,    65,    35,    -1,    42,    19,    41,    65,    35,    -1,
       3,    38,    67,    39,    35,    -1,     3,    38,    39,    35,
      -1,     1,    -1,     6,    38,    65,    39,    56,    -1,     1,
      -1,    43,    55,    44,    -1,     1,    -1,    43,    61,    55,
      44,    -1,    43,    61,    44,    -1,    43,    55,    44,    -1,
      43,    44,    -1,     1,    -1,    61,    62,    -1,    62,    -1,
       1,    -1,    50,     3,    35,    -1,    50,     3,    36,    16,
      37,    35,    -1,     1,    -1,     7,    38,    65,    39,    56,
      -1,     7,    38,    65,    39,    56,     8,    56,    -1,     1,
      -1,     9,    35,    -1,     9,    65,    35,    -1,     1,    -1,
      65,    15,    65,    -1,    65,    10,    65,    -1,    65,    11,
      65,    -1,    65,    12,    65,    -1,    65,    22,    65,    -1,
      65,    13,    65,    -1,    65,    23,    65,    -1,    65,    14,
      65,    -1,    65,    24,    65,    -1,    65,    25,    65,    -1,
      65,    29,    65,    -1,    65,    30,    65,    -1,    65,    31,
      65,    -1,    32,    65,    -1,    25,    65,    -1,    24,    65,
      -1,    42,    19,    -1,    38,    65,    39,    -1,     3,    -1,
       3,    36,    16,    37,    -1,     3,    38,    67,    39,    -1,
       3,    38,    39,    -1,    66,    -1,    65,    27,    65,    -1,
      65,    28,    65,    -1,    33,    65,    -1,    65,    20,    65,
      -1,    65,    21,    65,    -1,    65,    26,    65,    -1,     1,
      -1,    16,    -1,    19,    -1,     1,    -1,    67,    40,    65,
      -1,    65,    -1,     1,    -1,    17,    35,    -1,     1,    -1,
      18,    35,    -1,     1,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    70,    70,    77,    83,    88,    92,    96,   100,   104,
     112,   121,   125,   128,   131,   135,   145,   151,   155,   159,
     162,   166,   172,   177,   181,   186,   192,   196,   202,   207,
     211,   215,   219,   223,   227,   231,   235,   239,   243,   248,
     254,   259,   265,   271,   275,   280,   284,   288,   292,   298,
     302,   306,   310,   314,   320,   325,   329,   334,   340,   344,
     350,   357,   361,   365,   369,   373,   379,   385,   391,   397,
     403,   409,   415,   421,   427,   433,   439,   445,   451,   456,
     461,   466,   470,   475,   479,   484,   488,   492,   496,   502,
     508,   513,   519,   525,   531,   535,   539,   543,   547,   553,
     558,   562,   565,   569,   572
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IDENT", "VOID", "INT", "WHILE", "IF",
  "ELSE", "RETURN", "EQ", "NE", "LE", "GE", "AND", "OR", "DECNUM",
  "CONTINUE", "BREAK", "HEXNUM", "LSHIFT", "RSHIFT", "'<'", "'>'", "'+'",
  "'-'", "'|'", "'&'", "'^'", "'*'", "'/'", "'%'", "'!'", "'~'", "UMINUS",
  "';'", "'['", "']'", "'('", "')'", "','", "'='", "'$'", "'{'", "'}'",
  "$accept", "program", "decl_list", "decl", "var_decl", "type_spec",
  "fun_decl", "params", "param_list", "param", "stmt_list", "stmt",
  "expr_stmt", "while_stmt", "block_stmt", "compound_stmt", "local_decls",
  "local_decl", "if_stmt", "return_stmt", "expr", "int_literal",
  "arg_list", "continue_stmt", "break_stmt", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,    60,    62,    43,    45,   124,    38,    94,    42,
      47,    37,    33,   126,   277,    59,    91,    93,    40,    41,
      44,    61,    36,   123,   125
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    45,    46,    47,    47,    47,    48,    48,    48,    49,
      49,    49,    50,    50,    50,    51,    51,    51,    52,    52,
      52,    53,    53,    53,    54,    54,    54,    55,    55,    55,
      56,    56,    56,    56,    56,    56,    56,    56,    57,    57,
      57,    57,    57,    57,    58,    58,    59,    59,    60,    60,
      60,    60,    60,    61,    61,    61,    62,    62,    62,    63,
      63,    63,    64,    64,    64,    65,    65,    65,    65,    65,
      65,    65,    65,    65,    65,    65,    65,    65,    65,    65,
      65,    65,    65,    65,    65,    65,    65,    65,    65,    65,
      65,    65,    65,    65,    65,    66,    66,    66,    67,    67,
      67,    68,    68,    69,    69
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     1,     3,
       6,     1,     1,     1,     1,     6,     6,     1,     1,     1,
       1,     3,     1,     1,     2,     5,     1,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     4,     7,
       5,     5,     4,     1,     5,     1,     3,     1,     4,     3,
       3,     2,     1,     2,     1,     1,     3,     6,     1,     5,
       7,     1,     2,     3,     1,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     2,     2,
       2,     2,     3,     1,     4,     4,     3,     1,     3,     3,
       2,     3,     3,     3,     1,     1,     1,     1,     3,     1,
       1,     2,     1,     2,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     5,    12,    13,     0,     0,     4,     6,     0,     7,
       1,     8,     3,     0,     9,     0,     0,     0,    14,    12,
       0,     0,    18,    22,     0,    24,     0,     0,    10,     0,
      52,    16,     0,    15,    26,    21,     0,    29,     0,     0,
       0,     0,     0,     0,     0,     0,    51,     0,     0,    28,
      30,    33,    31,     0,    54,    32,    34,    35,    36,    25,
       0,     0,     0,     0,     0,    94,    83,    95,    96,     0,
       0,     0,     0,    62,     0,     0,     0,    87,   101,   103,
       0,    29,     0,     0,    37,    50,    27,    29,    49,     0,
      53,     0,    94,     0,    99,     0,     0,     0,     0,     0,
       0,    80,    79,    78,    90,     0,    81,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    63,     0,    46,    56,     0,
      48,     0,    42,     0,     0,    38,     0,     0,     0,    86,
       0,    82,    66,    67,    68,    70,    72,    65,    91,    92,
      69,    71,    73,    74,    93,    88,    89,    75,    76,    77,
       0,     0,     0,    41,    98,    44,    59,    84,    85,    40,
       0,     0,     0,    57,    39,    60
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     4,     5,     6,     7,     8,     9,    21,    22,    23,
      48,    49,    50,    51,    52,    33,    53,    54,    55,    56,
      94,    77,    95,    57,    58
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -49
static const yytype_int16 yypact[] =
{
     164,     8,   -49,   -49,    19,    58,   -49,   -49,    26,   -49,
     -49,     8,   -49,   -23,   -49,    34,   172,    27,     6,    28,
      83,    54,    68,   -49,    78,    76,    13,   177,   -49,    99,
     -49,   -49,     0,   -49,     8,   -49,    84,   135,    91,    87,
      88,   169,    98,   106,   109,   144,   -49,   131,    93,   -49,
     -49,   -49,   -49,    48,   -49,   -49,   -49,   -49,   -49,   -49,
     130,   189,   239,   239,   239,   -49,   -16,   -49,   -49,   239,
     239,   239,   239,   -49,   239,   129,   338,   -49,   -49,   -49,
     108,   -49,   100,     4,   -49,   -49,   -49,   192,   -49,   113,
     -49,   115,   -49,   119,   442,    21,   364,   272,   294,   143,
     214,   -49,   -49,   -49,   -49,   316,   -49,   239,   239,   239,
     239,   239,   239,   239,   239,   239,   239,   239,   239,   239,
     239,   239,   239,   239,   239,   -49,   239,   -49,   -49,   151,
     -49,   138,   -49,   136,   239,   -49,   157,   157,   146,   -49,
      65,   -49,   498,   498,   498,   498,   486,   464,    77,    77,
     498,   498,   510,   510,   522,     7,     7,    77,    77,    77,
     390,   147,   239,   -49,   442,   -49,   181,   -49,   -49,   -49,
     145,   416,   157,   -49,   -49,   -49
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -49,   -49,   -49,   186,   -49,    -6,   -49,   -49,   -49,   171,
     -37,   -48,   -49,   -49,   -49,   -49,   -49,   150,   -49,   -49,
     -39,   -49,   110,   -49,   -49
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -59
static const yytype_int16 yytable[] =
{
      86,    37,    76,    38,     2,     3,    39,    40,    82,    41,
      20,   -14,    14,    15,    30,    16,    89,    42,    43,    10,
      99,    20,   100,    96,    97,    98,    47,   113,   114,    13,
     101,   102,   103,   104,    86,   105,   122,   123,   124,   128,
     129,    86,    44,    45,    46,   -20,   -23,    47,    31,    87,
      17,    38,     2,     3,    39,    40,    32,    41,    -2,    11,
     133,   134,     2,     3,    24,    42,    43,   -19,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,    25,   160,   165,   166,
      44,    45,    88,    26,    84,   164,    38,   113,   114,    39,
      40,    84,    41,    38,   168,   134,    39,    40,    27,    41,
      42,    43,    29,    28,    84,    36,    38,    42,    43,    39,
      40,    59,    41,   171,   175,    63,    64,    60,    80,    61,
      42,    43,    62,    78,    83,    44,    45,    85,   -14,   -55,
     -55,    79,    44,    45,   127,    81,    91,    38,   106,   126,
      39,    40,   131,    41,   132,    44,    45,   130,    84,   138,
      38,    42,    43,    39,    40,     1,    41,   161,     2,     3,
      65,   163,    66,    18,    42,    43,    19,     3,    34,   162,
     173,     2,     3,   167,   170,    67,    44,    45,    68,   172,
      92,    12,    66,    69,    70,   -14,   -58,   -58,    35,    44,
      45,    71,    72,    90,    73,    67,     0,    74,    68,     0,
     140,    75,     0,    69,    70,    92,     0,    66,     0,     0,
       0,    71,    72,     0,     0,     0,     0,    74,    93,     0,
      67,    75,     0,    68,     0,     0,     0,     0,    69,    70,
      65,     0,    66,     0,     0,     0,    71,    72,     0,     0,
       0,     0,    74,   139,     0,    67,    75,     0,    68,     0,
       0,     0,     0,    69,    70,     0,     0,     0,     0,     0,
       0,    71,    72,     0,     0,     0,     0,    74,     0,     0,
       0,    75,   107,   108,   109,   110,   111,   112,     0,     0,
       0,     0,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   107,   108,   109,   110,   111,   112,
       0,   136,     0,     0,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   107,   108,   109,   110,
     111,   112,     0,   137,     0,     0,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   107,   108,
     109,   110,   111,   112,     0,   141,     0,     0,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
       0,     0,     0,   125,   107,   108,   109,   110,   111,   112,
       0,     0,     0,     0,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,     0,     0,     0,   135,
     107,   108,   109,   110,   111,   112,     0,     0,     0,     0,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,     0,     0,     0,   169,   107,   108,   109,   110,
     111,   112,     0,     0,     0,     0,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,     0,     0,
       0,   174,   107,   108,   109,   110,   111,   112,     0,     0,
       0,     0,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   107,   108,   109,   110,   111,     0,
       0,     0,     0,     0,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   107,   108,   109,   110,
       0,     0,     0,     0,     0,     0,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   113,   114,
       0,     0,   117,   118,   119,   120,   121,   122,   123,   124,
     113,   114,     0,     0,     0,     0,   119,   120,   121,   122,
     123,   124,   113,   114,     0,     0,     0,     0,     0,   120,
     121,   122,   123,   124
};

static const yytype_int16 yycheck[] =
{
      48,     1,    41,     3,     4,     5,     6,     7,    45,     9,
      16,     3,    35,    36,     1,    38,    53,    17,    18,     0,
      36,    27,    38,    62,    63,    64,    32,    20,    21,     3,
      69,    70,    71,    72,    82,    74,    29,    30,    31,    35,
      36,    89,    42,    43,    44,    39,    40,    53,    35,     1,
      16,     3,     4,     5,     6,     7,    43,     9,     0,     1,
      39,    40,     4,     5,    37,    17,    18,    39,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,     3,   126,   136,   137,
      42,    43,    44,    39,     1,   134,     3,    20,    21,     6,
       7,     1,     9,     3,    39,    40,     6,     7,    40,     9,
      17,    18,    36,    35,     1,    16,     3,    17,    18,     6,
       7,    37,     9,   162,   172,    38,    38,    36,    19,    38,
      17,    18,    41,    35,     3,    42,    43,    44,     3,     4,
       5,    35,    42,    43,    44,     1,    16,     3,    19,    41,
       6,     7,    37,     9,    35,    42,    43,    44,     1,    16,
       3,    17,    18,     6,     7,     1,     9,    16,     4,     5,
       1,    35,     3,     1,    17,    18,     4,     5,     1,    41,
      35,     4,     5,    37,    37,    16,    42,    43,    19,     8,
       1,     5,     3,    24,    25,     3,     4,     5,    27,    42,
      43,    32,    33,    53,    35,    16,    -1,    38,    19,    -1,
     100,    42,    -1,    24,    25,     1,    -1,     3,    -1,    -1,
      -1,    32,    33,    -1,    -1,    -1,    -1,    38,    39,    -1,
      16,    42,    -1,    19,    -1,    -1,    -1,    -1,    24,    25,
       1,    -1,     3,    -1,    -1,    -1,    32,    33,    -1,    -1,
      -1,    -1,    38,    39,    -1,    16,    42,    -1,    19,    -1,
      -1,    -1,    -1,    24,    25,    -1,    -1,    -1,    -1,    -1,
      -1,    32,    33,    -1,    -1,    -1,    -1,    38,    -1,    -1,
      -1,    42,    10,    11,    12,    13,    14,    15,    -1,    -1,
      -1,    -1,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    10,    11,    12,    13,    14,    15,
      -1,    39,    -1,    -1,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    10,    11,    12,    13,
      14,    15,    -1,    39,    -1,    -1,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    10,    11,
      12,    13,    14,    15,    -1,    39,    -1,    -1,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      -1,    -1,    -1,    35,    10,    11,    12,    13,    14,    15,
      -1,    -1,    -1,    -1,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    -1,    -1,    -1,    35,
      10,    11,    12,    13,    14,    15,    -1,    -1,    -1,    -1,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    -1,    -1,    -1,    35,    10,    11,    12,    13,
      14,    15,    -1,    -1,    -1,    -1,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    -1,    -1,
      -1,    35,    10,    11,    12,    13,    14,    15,    -1,    -1,
      -1,    -1,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    10,    11,    12,    13,    14,    -1,
      -1,    -1,    -1,    -1,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    10,    11,    12,    13,
      -1,    -1,    -1,    -1,    -1,    -1,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    20,    21,
      -1,    -1,    24,    25,    26,    27,    28,    29,    30,    31,
      20,    21,    -1,    -1,    -1,    -1,    26,    27,    28,    29,
      30,    31,    20,    21,    -1,    -1,    -1,    -1,    -1,    27,
      28,    29,    30,    31
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,     4,     5,    46,    47,    48,    49,    50,    51,
       0,     1,    48,     3,    35,    36,    38,    16,     1,     4,
      50,    52,    53,    54,    37,     3,    39,    40,    35,    36,
       1,    35,    43,    60,     1,    54,    16,     1,     3,     6,
       7,     9,    17,    18,    42,    43,    44,    50,    55,    56,
      57,    58,    59,    61,    62,    63,    64,    68,    69,    37,
      36,    38,    41,    38,    38,     1,     3,    16,    19,    24,
      25,    32,    33,    35,    38,    42,    65,    66,    35,    35,
      19,     1,    55,     3,     1,    44,    56,     1,    44,    55,
      62,    16,     1,    39,    65,    67,    65,    65,    65,    36,
      38,    65,    65,    65,    65,    65,    19,    10,    11,    12,
      13,    14,    15,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    35,    41,    44,    35,    36,
      44,    37,    35,    39,    40,    35,    39,    39,    16,    39,
      67,    39,    65,    65,    65,    65,    65,    65,    65,    65,
      65,    65,    65,    65,    65,    65,    65,    65,    65,    65,
      65,    16,    41,    35,    65,    56,    56,    37,    39,    35,
      37,    65,     8,    35,    35,    56
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;


      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 70 "minic.y"
    {   (yyval.node) = makeNode(1); (yyval.node)->child[0] = (yyvsp[(1) - (1)].node); (yyvsp[(1) - (1)].node)->parent = (yyval.node);
                                    (yyval.node)->ntno = 1; (yyval.node)->procno = 1;
                                    (yyval.node)->lineno = yylineno;
                                ;}
    break;

  case 3:
#line 77 "minic.y"
    {   (yyval.node) = makeNode(2); (yyval.node)->child[0] = (yyvsp[(1) - (2)].node); (yyvsp[(1) - (2)].node)->parent = (yyval.node);
                                    (yyval.node)->child[1] = (yyvsp[(2) - (2)].node); (yyvsp[(2) - (2)].node)->parent = (yyval.node);
                                    (yyval.node)->ntno = 2; (yyval.node)->procno = 1;
                                    (yyval.node)->multiplicity = (yyvsp[(1) - (2)].node)->multiplicity + 1;
                                    (yyval.node)->lineno = yylineno;
                                ;}
    break;

  case 4:
#line 83 "minic.y"
    {   (yyval.node) = makeNode(1); (yyval.node)->child[0] = (yyvsp[(1) - (1)].node); (yyvsp[(1) - (1)].node)->parent = (yyval.node);
                                    (yyval.node)->ntno = 2; (yyval.node)->procno = 2;
                                    (yyval.node)->multiplicity = 1;
                                    (yyval.node)->lineno = yylineno;
                                ;}
    break;

  case 6:
#line 92 "minic.y"
    {   (yyval.node) = makeNode(1); (yyval.node)->child[0] = (yyvsp[(1) - (1)].node); (yyvsp[(1) - (1)].node)->parent = (yyval.node);
                                    (yyval.node)->ntno = 3; (yyval.node)->procno = 1;
                                    (yyval.node)->lineno = yylineno;
                                ;}
    break;

  case 7:
#line 96 "minic.y"
    {   (yyval.node) = makeNode(1); (yyval.node)->child[0] = (yyvsp[(1) - (1)].node); (yyvsp[(1) - (1)].node)->parent = (yyval.node);
                                    (yyval.node)->ntno = 3; (yyval.node)->procno = 2;
                                    (yyval.node)->lineno = yylineno;
                                ;}
    break;

  case 9:
#line 104 "minic.y"
    {   (yyval.node) = makeNode(1); (yyval.node)->child[0] = (yyvsp[(1) - (3)].node); (yyvsp[(1) - (3)].node)->parent = (yyval.node);
                                    (yyval.node)->ntno = 4; (yyval.node)->procno = 1;
                                    strcpy((yyval.node)->txt, (yyvsp[(2) - (3)].text));
                                    (yyval.node)->lineno = yylineno;
                                    gVar[gcount] = (struct globalVar *)malloc(sizeof(struct globalVar));
                                    strcpy(gVar[gcount]->name, (yyvsp[(2) - (3)].text)); gVar[gcount]->space = 1;
                                    gVar[gcount]->t = (yyval.node); gcount++;
                                ;}
    break;

  case 10:
#line 113 "minic.y"
    {   (yyval.node) = makeNode(1); (yyval.node)->child[0] = (yyvsp[(1) - (6)].node); (yyvsp[(1) - (6)].node)->parent = (yyval.node);
                                    (yyval.node)->ntno = 4; (yyval.node)->procno = 2;
                                    strcpy((yyval.node)->txt, (yyvsp[(2) - (6)].text)); strcpy((yyval.node)->numtxt, (yyvsp[(4) - (6)].text));
                                    (yyval.node)->lineno = yylineno;
                                    gVar[gcount] = (struct globalVar *)malloc(sizeof(struct globalVar));
                                    strcpy(gVar[gcount]->name, (yyvsp[(2) - (6)].text)); gVar[gcount]->space = atoi((yyvsp[(4) - (6)].text));
                                    gVar[gcount]->t = (yyval.node); gcount++;
                                ;}
    break;

  case 12:
#line 125 "minic.y"
    {   (yyval.node) = makeNode(0); (yyval.node)->ntno = 5; (yyval.node)->procno = 1;
                                    (yyval.node)->lineno = yylineno;
                                ;}
    break;

  case 13:
#line 128 "minic.y"
    {   (yyval.node) = makeNode(0); (yyval.node)->ntno = 5; (yyval.node)->procno = 2;
                                    (yyval.node)->lineno = yylineno;
                                ;}
    break;

  case 15:
#line 136 "minic.y"
    {   (yyval.node) = makeNode(3); (yyval.node)->child[0] = (yyvsp[(1) - (6)].node); (yyvsp[(1) - (6)].node)->parent = (yyval.node);
                                    (yyval.node)->child[1] = (yyvsp[(4) - (6)].node); (yyvsp[(4) - (6)].node)->parent = (yyval.node);
                                    (yyval.node)->child[2] = (yyvsp[(6) - (6)].node); (yyvsp[(6) - (6)].node)->parent = (yyval.node);
                                    (yyval.node)->ntno = 6; (yyval.node)->procno = 1; strcpy((yyval.node)->txt, (yyvsp[(2) - (6)].text));
                                    ALL[funcount] = (struct allFunc *)malloc(sizeof(struct allFunc));
                                    strcpy(ALL[funcount]->name, (yyvsp[(2) - (6)].text));
                                    ALL[funcount]->t = (yyval.node); funcount++;
                                    (yyval.node)->lineno = yylineno;
                                ;}
    break;

  case 16:
#line 146 "minic.y"
    {   (yyval.node) = makeNode(2); (yyval.node)->child[0] = (yyvsp[(1) - (6)].node); (yyvsp[(1) - (6)].node)->parent = (yyval.node);
                                    (yyval.node)->child[1] = (yyvsp[(4) - (6)].node); (yyvsp[(4) - (6)].node)->parent = (yyval.node);
                                    (yyval.node)->ntno = 6; (yyval.node)->procno = 2; strcpy((yyval.node)->txt, (yyvsp[(2) - (6)].text));
                                    (yyval.node)->lineno = yylineno;
                                ;}
    break;

  case 18:
#line 155 "minic.y"
    {   (yyval.node) = makeNode(1); (yyval.node)->child[0] = (yyvsp[(1) - (1)].node); (yyvsp[(1) - (1)].node)->parent = (yyval.node);
                                    (yyval.node)->ntno = 7; (yyval.node)->procno = 1;
                                    (yyval.node)->lineno = yylineno;
                                ;}
    break;

  case 19:
#line 159 "minic.y"
    {   (yyval.node) = makeNode(0); (yyval.node)->ntno = 7; (yyval.node)->procno = 2;
                                    (yyval.node)->lineno = yylineno;
                                ;}
    break;

  case 21:
#line 166 "minic.y"
    {   (yyval.node) = makeNode(2); (yyval.node)->child[0] = (yyvsp[(1) - (3)].node); (yyvsp[(1) - (3)].node)->parent = (yyval.node);
                                    (yyval.node)->child[1] = (yyvsp[(3) - (3)].node); (yyvsp[(3) - (3)].node)->parent = (yyval.node);
                                    (yyval.node)->ntno = 8; (yyval.node)->procno = 1;
                                    (yyval.node)->multiplicity = (yyvsp[(1) - (3)].node)->multiplicity + 1;
                                    (yyval.node)->lineno = yylineno;
                                ;}
    break;

  case 22:
#line 172 "minic.y"
    {   (yyval.node) = makeNode(1); (yyval.node)->child[0] = (yyvsp[(1) - (1)].node); (yyvsp[(1) - (1)].node)->parent = (yyval.node);
                                    (yyval.node)->ntno = 8; (yyval.node)->procno = 2;
                                    (yyval.node)->multiplicity = 1;
                                    (yyval.node)->lineno = yylineno;
                                ;}
    break;

  case 24:
#line 181 "minic.y"
    {   (yyval.node) = makeNode(1); (yyval.node)->child[0] = (yyvsp[(1) - (2)].node); (yyvsp[(1) - (2)].node)->parent = (yyval.node);
                                    (yyval.node)->ntno = 9; (yyval.node)->procno = 1;
                                    strcpy((yyval.node)->txt, (yyvsp[(2) - (2)].text));
                                    (yyval.node)->lineno = yylineno;
                                ;}
    break;

  case 25:
#line 187 "minic.y"
    {   (yyval.node) = makeNode(1); (yyval.node)->child[0] = (yyvsp[(1) - (5)].node); (yyvsp[(1) - (5)].node)->parent = (yyval.node);
                                    (yyval.node)->ntno = 9; (yyval.node)->procno = 2;
                                    strcpy((yyval.node)->txt, (yyvsp[(2) - (5)].text)); strcpy((yyval.node)->numtxt, (yyvsp[(4) - (5)].text));
                                    (yyval.node)->lineno = yylineno;
                                ;}
    break;

  case 27:
#line 196 "minic.y"
    {   (yyval.node) = makeNode(2); (yyval.node)->child[0] = (yyvsp[(1) - (2)].node); (yyvsp[(1) - (2)].node)->parent = (yyval.node);
                                    (yyval.node)->child[1] = (yyvsp[(2) - (2)].node); (yyvsp[(2) - (2)].node)->parent = (yyval.node);
                                    (yyval.node)->ntno = 10; (yyval.node)->procno = 1;
                                    (yyval.node)->multiplicity = (yyvsp[(1) - (2)].node)->multiplicity + 1;
                                    (yyval.node)->lineno = yylineno;
                                ;}
    break;

  case 28:
#line 202 "minic.y"
    {   (yyval.node) = makeNode(1); (yyval.node)->child[0] = (yyvsp[(1) - (1)].node); (yyvsp[(1) - (1)].node)->parent = (yyval.node);
                                    (yyval.node)->ntno = 10; (yyval.node)->procno = 2;
                                    (yyval.node)->multiplicity = 1;
                                    (yyval.node)->lineno = yylineno;
                                ;}
    break;

  case 30:
#line 211 "minic.y"
    {   (yyval.node) = makeNode(1); (yyval.node)->child[0] = (yyvsp[(1) - (1)].node); (yyvsp[(1) - (1)].node)->parent = (yyval.node);
                                    (yyval.node)->ntno = 11; (yyval.node)->procno = 1;
                                    (yyval.node)->lineno = yylineno;
                                ;}
    break;

  case 31:
#line 215 "minic.y"
    {   (yyval.node) = makeNode(1); (yyval.node)->child[0] = (yyvsp[(1) - (1)].node); (yyvsp[(1) - (1)].node)->parent = (yyval.node);
                                    (yyval.node)->ntno = 11; (yyval.node)->procno = 2;
                                    (yyval.node)->lineno = yylineno;
                                ;}
    break;

  case 32:
#line 219 "minic.y"
    {   (yyval.node) = makeNode(1); (yyval.node)->child[0] = (yyvsp[(1) - (1)].node); (yyvsp[(1) - (1)].node)->parent = (yyval.node);
                                    (yyval.node)->ntno = 11; (yyval.node)->procno = 3;
                                    (yyval.node)->lineno = yylineno;
                                ;}
    break;

  case 33:
#line 223 "minic.y"
    {   (yyval.node) = makeNode(1); (yyval.node)->child[0] = (yyvsp[(1) - (1)].node); (yyvsp[(1) - (1)].node)->parent = (yyval.node);
                                    (yyval.node)->ntno = 11; (yyval.node)->procno = 4;
                                    (yyval.node)->lineno = yylineno;
                                ;}
    break;

  case 34:
#line 227 "minic.y"
    {   (yyval.node) = makeNode(1); (yyval.node)->child[0] = (yyvsp[(1) - (1)].node); (yyvsp[(1) - (1)].node)->parent = (yyval.node);
                                    (yyval.node)->ntno = 11; (yyval.node)->procno = 5;
                                    (yyval.node)->lineno = yylineno;
                                ;}
    break;

  case 35:
#line 231 "minic.y"
    {   (yyval.node) = makeNode(1); (yyval.node)->child[0] = (yyvsp[(1) - (1)].node); (yyvsp[(1) - (1)].node)->parent = (yyval.node);
                                    (yyval.node)->ntno = 11; (yyval.node)->procno = 6;
                                    (yyval.node)->lineno = yylineno;
                                ;}
    break;

  case 36:
#line 235 "minic.y"
    {   (yyval.node) = makeNode(1); (yyval.node)->child[0] = (yyvsp[(1) - (1)].node); (yyvsp[(1) - (1)].node)->parent = (yyval.node);
                                    (yyval.node)->ntno = 11; (yyval.node)->procno = 7;
                                    (yyval.node)->lineno = yylineno;
                                ;}
    break;

  case 38:
#line 243 "minic.y"
    {   (yyval.node) = makeNode(1); (yyval.node)->child[0] = (yyvsp[(3) - (4)].node); (yyvsp[(3) - (4)].node)->parent = (yyval.node);
                                    (yyval.node)->ntno = 12; (yyval.node)->procno = 1;
                                    strcpy((yyval.node)->txt, (yyvsp[(1) - (4)].text));
                                    (yyval.node)->lineno = yylineno;
                                ;}
    break;

  case 39:
#line 249 "minic.y"
    {   (yyval.node) = makeNode(1); (yyval.node)->child[0] = (yyvsp[(6) - (7)].node); (yyvsp[(6) - (7)].node)->parent = (yyval.node);
                                    (yyval.node)->ntno = 12; (yyval.node)->procno = 2;
                                    strcpy((yyval.node)->txt, (yyvsp[(1) - (7)].text)); strcpy((yyval.node)->numtxt, (yyvsp[(3) - (7)].text));
                                    (yyval.node)->lineno = yylineno;
                                ;}
    break;

  case 40:
#line 254 "minic.y"
    {   (yyval.node) = makeNode(1); (yyval.node)->child[0] = (yyvsp[(4) - (5)].node); (yyvsp[(4) - (5)].node)->parent = (yyval.node);
                                    (yyval.node)->ntno = 12; (yyval.node)->procno = 3;
                                    strcpy((yyval.node)->numtxt, (yyvsp[(2) - (5)].text));
                                    (yyval.node)->lineno = yylineno;
                                ;}
    break;

  case 41:
#line 260 "minic.y"
    {   (yyval.node) = makeNode(1); (yyval.node)->child[0] = (yyvsp[(3) - (5)].node); (yyvsp[(3) - (5)].node)->parent = (yyval.node);
                                    (yyval.node)->ntno = 12; (yyval.node)->procno = 4;
                                    strcpy((yyval.node)->txt, (yyvsp[(1) - (5)].text));
                                    (yyval.node)->lineno = yylineno;
                                ;}
    break;

  case 42:
#line 266 "minic.y"
    {   (yyval.node) = makeNode(0);
                                    (yyval.node)->ntno = 12; (yyval.node)->procno = 5;
                                    strcpy((yyval.node)->txt, (yyvsp[(1) - (4)].text));
                                    (yyval.node)->lineno = yylineno;
                                ;}
    break;

  case 44:
#line 275 "minic.y"
    {   (yyval.node) = makeNode(2); (yyval.node)->child[0] = (yyvsp[(3) - (5)].node); (yyvsp[(3) - (5)].node)->parent = (yyval.node);
                                    (yyval.node)->child[1] = (yyvsp[(5) - (5)].node); (yyvsp[(5) - (5)].node)->parent = (yyval.node);
                                    (yyval.node)->ntno = 13; (yyval.node)->procno = 1;
                                    (yyval.node)->lineno = yylineno;
                                ;}
    break;

  case 46:
#line 284 "minic.y"
    {   (yyval.node) = makeNode(1); (yyval.node)->child[0] = (yyvsp[(2) - (3)].node); (yyvsp[(2) - (3)].node)->parent = (yyval.node);
                                    (yyval.node)->ntno = 14; (yyval.node)->procno = 1;
                                    (yyval.node)->lineno = yylineno;
                                ;}
    break;

  case 48:
#line 293 "minic.y"
    {   (yyval.node) = makeNode(2); (yyval.node)->child[0] = (yyvsp[(2) - (4)].node); (yyvsp[(2) - (4)].node)->parent = (yyval.node);
                                    (yyval.node)->child[1] = (yyvsp[(3) - (4)].node); (yyvsp[(3) - (4)].node)->parent = (yyval.node);
                                    (yyval.node)->ntno = 15; (yyval.node)->procno = 1;
                                    (yyval.node)->lineno = yylineno;
                                ;}
    break;

  case 49:
#line 298 "minic.y"
    {   (yyval.node) = makeNode(1); (yyval.node)->child[0] = (yyvsp[(2) - (3)].node); (yyvsp[(2) - (3)].node)->parent = (yyval.node);
                                    (yyval.node)->ntno = 15; (yyval.node)->procno = 2;
                                    (yyval.node)->lineno = yylineno;
                                ;}
    break;

  case 50:
#line 302 "minic.y"
    {   (yyval.node) = makeNode(1); (yyval.node)->child[0] = (yyvsp[(2) - (3)].node); (yyvsp[(2) - (3)].node)->parent = (yyval.node);
                                    (yyval.node)->ntno = 15; (yyval.node)->procno = 3;
                                    (yyval.node)->lineno = yylineno;
                                ;}
    break;

  case 51:
#line 306 "minic.y"
    {   (yyval.node) = makeNode(0);
                                    (yyval.node)->ntno = 15; (yyval.node)->procno = 4;
                                    (yyval.node)->lineno = yylineno;
                                ;}
    break;

  case 53:
#line 314 "minic.y"
    {   (yyval.node) = makeNode(2); (yyval.node)->child[0] = (yyvsp[(1) - (2)].node); (yyvsp[(1) - (2)].node)->parent = (yyval.node);
                                    (yyval.node)->child[1] = (yyvsp[(2) - (2)].node); (yyvsp[(2) - (2)].node)->parent = (yyval.node);
                                    (yyval.node)->ntno = 16; (yyval.node)->procno = 1;
                                    (yyval.node)->multiplicity = (yyvsp[(1) - (2)].node)->multiplicity + 1;
                                    (yyval.node)->lineno = yylineno;
                                ;}
    break;

  case 54:
#line 320 "minic.y"
    {   (yyval.node) = makeNode(1); (yyval.node)->child[0] = (yyvsp[(1) - (1)].node); (yyvsp[(1) - (1)].node)->parent = (yyval.node);
                                    (yyval.node)->ntno = 16; (yyval.node)->procno = 2;
                                    (yyval.node)->multiplicity = 1;
                                    (yyval.node)->lineno = yylineno;
                                ;}
    break;

  case 56:
#line 329 "minic.y"
    {   (yyval.node) = makeNode(1); (yyval.node)->child[0] = (yyvsp[(1) - (3)].node); (yyvsp[(1) - (3)].node)->parent = (yyval.node);
                                    (yyval.node)->ntno = 17; (yyval.node)->procno = 1;
                                    strcpy((yyval.node)->txt, (yyvsp[(2) - (3)].text));
                                    (yyval.node)->lineno = yylineno;
                                ;}
    break;

  case 57:
#line 335 "minic.y"
    {   (yyval.node) = makeNode(1); (yyval.node)->child[0] = (yyvsp[(1) - (6)].node); (yyvsp[(1) - (6)].node)->parent = (yyval.node);
                                    (yyval.node)->ntno = 17; (yyval.node)->procno = 2;
                                    strcpy((yyval.node)->txt, (yyvsp[(2) - (6)].text)); strcpy((yyval.node)->numtxt, (yyvsp[(4) - (6)].text));
                                    (yyval.node)->lineno = yylineno;
                                ;}
    break;

  case 59:
#line 345 "minic.y"
    {   (yyval.node) = makeNode(2); (yyval.node)->child[0] = (yyvsp[(3) - (5)].node); (yyvsp[(3) - (5)].node)->parent = (yyval.node);
                                    (yyval.node)->child[1] = (yyvsp[(5) - (5)].node); (yyvsp[(5) - (5)].node)->parent = (yyval.node);
                                    (yyval.node)->ntno = 18; (yyval.node)->procno = 1;
                                    (yyval.node)->lineno = yylineno;
                                ;}
    break;

  case 60:
#line 351 "minic.y"
    {   (yyval.node) = makeNode(3); (yyval.node)->child[0] = (yyvsp[(3) - (7)].node); (yyvsp[(3) - (7)].node)->parent = (yyval.node);
                                    (yyval.node)->child[1] = (yyvsp[(5) - (7)].node); (yyvsp[(5) - (7)].node)->parent = (yyval.node);
                                    (yyval.node)->child[2] = (yyvsp[(7) - (7)].node); (yyvsp[(7) - (7)].node)->parent = (yyval.node);
                                    (yyval.node)->ntno = 18; (yyval.node)->procno = 2;
                                    (yyval.node)->lineno = yylineno;
                                ;}
    break;

  case 62:
#line 361 "minic.y"
    {   (yyval.node) = makeNode(0);
                                    (yyval.node)->ntno = 19; (yyval.node)->procno = 1;
                                    (yyval.node)->lineno = yylineno;
                                ;}
    break;

  case 63:
#line 365 "minic.y"
    {   (yyval.node) = makeNode(1); (yyval.node)->child[0] = (yyvsp[(2) - (3)].node); (yyvsp[(2) - (3)].node)->parent = (yyval.node);
                                    (yyval.node)->ntno = 19; (yyval.node)->procno = 2;
                                    (yyval.node)->lineno = yylineno;
                                ;}
    break;

  case 65:
#line 373 "minic.y"
    {   (yyval.node) = makeNode(2); (yyval.node)->child[0] = (yyvsp[(1) - (3)].node); (yyvsp[(1) - (3)].node)->parent = (yyval.node);
                                    (yyval.node)->child[1] = (yyvsp[(3) - (3)].node); (yyvsp[(3) - (3)].node)->parent = (yyval.node);
                                    (yyval.node)->ntno = 20; (yyval.node)->procno = 1;
                                    (yyval.node)->contain_expr = 1;
                                    (yyval.node)->lineno = yylineno;
                                ;}
    break;

  case 66:
#line 379 "minic.y"
    {   (yyval.node) = makeNode(2); (yyval.node)->child[0] = (yyvsp[(1) - (3)].node); (yyvsp[(1) - (3)].node)->parent = (yyval.node);
                                    (yyval.node)->child[1] = (yyvsp[(3) - (3)].node); (yyvsp[(3) - (3)].node)->parent = (yyval.node);
                                    (yyval.node)->ntno = 20; (yyval.node)->procno = 2;
                                    (yyval.node)->contain_expr = 1;
                                    (yyval.node)->lineno = yylineno;
                                ;}
    break;

  case 67:
#line 385 "minic.y"
    {   (yyval.node) = makeNode(2); (yyval.node)->child[0] = (yyvsp[(1) - (3)].node); (yyvsp[(1) - (3)].node)->parent = (yyval.node);
                                    (yyval.node)->child[1] = (yyvsp[(3) - (3)].node); (yyvsp[(3) - (3)].node)->parent = (yyval.node);
                                    (yyval.node)->ntno = 20; (yyval.node)->procno = 3;
                                    (yyval.node)->contain_expr = 1;
                                    (yyval.node)->lineno = yylineno;
                                ;}
    break;

  case 68:
#line 391 "minic.y"
    {   (yyval.node) = makeNode(2); (yyval.node)->child[0] = (yyvsp[(1) - (3)].node); (yyvsp[(1) - (3)].node)->parent = (yyval.node);
                                    (yyval.node)->child[1] = (yyvsp[(3) - (3)].node); (yyvsp[(3) - (3)].node)->parent = (yyval.node);
                                    (yyval.node)->ntno = 20; (yyval.node)->procno = 4;
                                    (yyval.node)->contain_expr = 1;
                                    (yyval.node)->lineno = yylineno;
                                ;}
    break;

  case 69:
#line 397 "minic.y"
    {   (yyval.node) = makeNode(2); (yyval.node)->child[0] = (yyvsp[(1) - (3)].node); (yyvsp[(1) - (3)].node)->parent = (yyval.node);
                                    (yyval.node)->child[1] = (yyvsp[(3) - (3)].node); (yyvsp[(3) - (3)].node)->parent = (yyval.node);
                                    (yyval.node)->ntno = 20; (yyval.node)->procno = 5;
                                    (yyval.node)->contain_expr = 1;
                                    (yyval.node)->lineno = yylineno;
                                ;}
    break;

  case 70:
#line 403 "minic.y"
    {   (yyval.node) = makeNode(2); (yyval.node)->child[0] = (yyvsp[(1) - (3)].node); (yyvsp[(1) - (3)].node)->parent = (yyval.node);
                                    (yyval.node)->child[1] = (yyvsp[(3) - (3)].node); (yyvsp[(3) - (3)].node)->parent = (yyval.node);
                                    (yyval.node)->ntno = 20; (yyval.node)->procno = 6;
                                    (yyval.node)->contain_expr = 1;
                                    (yyval.node)->lineno = yylineno;
                                ;}
    break;

  case 71:
#line 409 "minic.y"
    {   (yyval.node) = makeNode(2); (yyval.node)->child[0] = (yyvsp[(1) - (3)].node); (yyvsp[(1) - (3)].node)->parent = (yyval.node);
                                    (yyval.node)->child[1] = (yyvsp[(3) - (3)].node); (yyvsp[(3) - (3)].node)->parent = (yyval.node);
                                    (yyval.node)->ntno = 20; (yyval.node)->procno = 7;
                                    (yyval.node)->contain_expr = 1;
                                    (yyval.node)->lineno = yylineno;
                                ;}
    break;

  case 72:
#line 415 "minic.y"
    {   (yyval.node) = makeNode(2); (yyval.node)->child[0] = (yyvsp[(1) - (3)].node); (yyvsp[(1) - (3)].node)->parent = (yyval.node);
                                    (yyval.node)->child[1] = (yyvsp[(3) - (3)].node); (yyvsp[(3) - (3)].node)->parent = (yyval.node);
                                    (yyval.node)->ntno = 20; (yyval.node)->procno = 8;
                                    (yyval.node)->contain_expr = 1;
                                    (yyval.node)->lineno = yylineno;
                                ;}
    break;

  case 73:
#line 421 "minic.y"
    {   (yyval.node) = makeNode(2); (yyval.node)->child[0] = (yyvsp[(1) - (3)].node); (yyvsp[(1) - (3)].node)->parent = (yyval.node);
                                    (yyval.node)->child[1] = (yyvsp[(3) - (3)].node); (yyvsp[(3) - (3)].node)->parent = (yyval.node);
                                    (yyval.node)->ntno = 20; (yyval.node)->procno = 9;
                                    (yyval.node)->contain_expr = 1;
                                    (yyval.node)->lineno = yylineno;
                                ;}
    break;

  case 74:
#line 427 "minic.y"
    {   (yyval.node) = makeNode(2); (yyval.node)->child[0] = (yyvsp[(1) - (3)].node); (yyvsp[(1) - (3)].node)->parent = (yyval.node);
                                    (yyval.node)->child[1] = (yyvsp[(3) - (3)].node); (yyvsp[(3) - (3)].node)->parent = (yyval.node);
                                    (yyval.node)->ntno = 20; (yyval.node)->procno = 10;
                                    (yyval.node)->contain_expr = 1;
                                    (yyval.node)->lineno = yylineno;
                                ;}
    break;

  case 75:
#line 433 "minic.y"
    {   (yyval.node) = makeNode(2); (yyval.node)->child[0] = (yyvsp[(1) - (3)].node); (yyvsp[(1) - (3)].node)->parent = (yyval.node);
                                    (yyval.node)->child[1] = (yyvsp[(3) - (3)].node); (yyvsp[(3) - (3)].node)->parent = (yyval.node);
                                    (yyval.node)->ntno = 20; (yyval.node)->procno = 11;
                                    (yyval.node)->contain_expr = 1;
                                    (yyval.node)->lineno = yylineno;
                                ;}
    break;

  case 76:
#line 439 "minic.y"
    {   (yyval.node) = makeNode(2); (yyval.node)->child[0] = (yyvsp[(1) - (3)].node); (yyvsp[(1) - (3)].node)->parent = (yyval.node);
                                    (yyval.node)->child[1] = (yyvsp[(3) - (3)].node); (yyvsp[(3) - (3)].node)->parent = (yyval.node);
                                    (yyval.node)->ntno = 20; (yyval.node)->procno = 12;
                                    (yyval.node)->contain_expr = 1;
                                    (yyval.node)->lineno = yylineno;
                                ;}
    break;

  case 77:
#line 445 "minic.y"
    {   (yyval.node) = makeNode(2); (yyval.node)->child[0] = (yyvsp[(1) - (3)].node); (yyvsp[(1) - (3)].node)->parent = (yyval.node);
                                    (yyval.node)->child[1] = (yyvsp[(3) - (3)].node); (yyvsp[(3) - (3)].node)->parent = (yyval.node);
                                    (yyval.node)->ntno = 20; (yyval.node)->procno = 13;
                                    (yyval.node)->contain_expr = 1;
                                    (yyval.node)->lineno = yylineno;
                                ;}
    break;

  case 78:
#line 451 "minic.y"
    {   (yyval.node) = makeNode(1); (yyval.node)->child[0] = (yyvsp[(2) - (2)].node); (yyvsp[(2) - (2)].node)->parent = (yyval.node);
                                    (yyval.node)->ntno = 20; (yyval.node)->procno = 14;
                                    (yyval.node)->contain_expr = 1;
                                    (yyval.node)->lineno = yylineno;
                                ;}
    break;

  case 79:
#line 456 "minic.y"
    {   (yyval.node) = makeNode(1); (yyval.node)->child[0] = (yyvsp[(2) - (2)].node); (yyvsp[(2) - (2)].node)->parent = (yyval.node);
                                    (yyval.node)->ntno = 20; (yyval.node)->procno = 15;
                                    (yyval.node)->contain_expr = 1;
                                    (yyval.node)->lineno = yylineno;
                                ;}
    break;

  case 80:
#line 461 "minic.y"
    {   (yyval.node) = makeNode(1); (yyval.node)->child[0] = (yyvsp[(2) - (2)].node); (yyvsp[(2) - (2)].node)->parent = (yyval.node);
                                    (yyval.node)->ntno = 20; (yyval.node)->procno = 16;
                                    (yyval.node)->contain_expr = 1;
                                    (yyval.node)->lineno = yylineno;
                                ;}
    break;

  case 81:
#line 466 "minic.y"
    {   (yyval.node) = makeNode(0); (yyval.node)->ntno = 20; (yyval.node)->procno = 17;
                                    strcpy((yyval.node)->numtxt, (yyvsp[(2) - (2)].text));
                                    (yyval.node)->lineno = yylineno;
                                ;}
    break;

  case 82:
#line 470 "minic.y"
    {   (yyval.node) = makeNode(1); (yyval.node)->child[0] = (yyvsp[(2) - (3)].node); (yyvsp[(2) - (3)].node)->parent = (yyval.node);
                                    (yyval.node)->ntno = 20; (yyval.node)->procno = 18;
                                    (yyval.node)->contain_expr = 1;
                                    (yyval.node)->lineno = yylineno;
                                ;}
    break;

  case 83:
#line 475 "minic.y"
    {   (yyval.node) = makeNode(0); (yyval.node)->ntno = 20; (yyval.node)->procno = 19;
                                    strcpy((yyval.node)->txt, (yyvsp[(1) - (1)].text));
                                    (yyval.node)->lineno = yylineno;
                                ;}
    break;

  case 84:
#line 479 "minic.y"
    {   (yyval.node) = makeNode(0); (yyval.node)->ntno = 20; (yyval.node)->procno = 20;
                                    strcpy((yyval.node)->txt, (yyvsp[(1) - (4)].text)); strcpy((yyval.node)->numtxt, (yyvsp[(3) - (4)].text));
                                    (yyval.node)->lineno = yylineno;
        
                                ;}
    break;

  case 85:
#line 484 "minic.y"
    {   (yyval.node) = makeNode(1); (yyval.node)->child[0] = (yyvsp[(3) - (4)].node); (yyvsp[(3) - (4)].node)->parent = (yyval.node);
                                    (yyval.node)->ntno = 20; (yyval.node)->procno = 21; strcpy((yyval.node)->txt, (yyvsp[(1) - (4)].text));
                                    (yyval.node)->lineno = yylineno;
                                ;}
    break;

  case 86:
#line 488 "minic.y"
    {   (yyval.node) = makeNode(0); (yyval.node)->ntno = 20; (yyval.node)->procno = 22;
                                    strcpy((yyval.node)->txt, (yyvsp[(1) - (3)].text));
                                    (yyval.node)->lineno = yylineno;
                                ;}
    break;

  case 87:
#line 492 "minic.y"
    {   (yyval.node) = makeNode(1); (yyval.node)->child[0] = (yyvsp[(1) - (1)].node); (yyvsp[(1) - (1)].node)->parent = (yyval.node);
                                    (yyval.node)->ntno = 20; (yyval.node)->procno = 23;
                                    (yyval.node)->lineno = yylineno;
                                ;}
    break;

  case 88:
#line 496 "minic.y"
    {   (yyval.node) = makeNode(2); (yyval.node)->child[0] = (yyvsp[(1) - (3)].node); (yyvsp[(1) - (3)].node)->parent = (yyval.node);
                                    (yyval.node)->child[1] = (yyvsp[(3) - (3)].node); (yyvsp[(3) - (3)].node)->parent = (yyval.node);
                                    (yyval.node)->ntno = 20; (yyval.node)->procno = 24;
                                    (yyval.node)->contain_expr = 1;
                                    (yyval.node)->lineno = yylineno;
                                ;}
    break;

  case 89:
#line 502 "minic.y"
    {   (yyval.node) = makeNode(2); (yyval.node)->child[0] = (yyvsp[(1) - (3)].node); (yyvsp[(1) - (3)].node)->parent = (yyval.node);
                                    (yyval.node)->child[1] = (yyvsp[(3) - (3)].node); (yyvsp[(3) - (3)].node)->parent = (yyval.node);
                                    (yyval.node)->ntno = 20; (yyval.node)->procno = 25;
                                    (yyval.node)->contain_expr = 1;
                                    (yyval.node)->lineno = yylineno;
                                ;}
    break;

  case 90:
#line 508 "minic.y"
    {   (yyval.node) = makeNode(1); (yyval.node)->child[0] = (yyvsp[(2) - (2)].node); (yyvsp[(2) - (2)].node)->parent = (yyval.node);
                                    (yyval.node)->ntno = 20; (yyval.node)->procno = 26;
                                    (yyval.node)->contain_expr = 1;
                                    (yyval.node)->lineno = yylineno;
                                ;}
    break;

  case 91:
#line 513 "minic.y"
    {   (yyval.node) = makeNode(2); (yyval.node)->child[0] = (yyvsp[(1) - (3)].node); (yyvsp[(1) - (3)].node)->parent = (yyval.node);
                                    (yyval.node)->child[1] = (yyvsp[(3) - (3)].node); (yyvsp[(3) - (3)].node)->parent = (yyval.node);
                                    (yyval.node)->ntno = 20; (yyval.node)->procno = 27;
                                    (yyval.node)->contain_expr = 1;
                                    (yyval.node)->lineno = yylineno;
                                ;}
    break;

  case 92:
#line 519 "minic.y"
    {   (yyval.node) = makeNode(2); (yyval.node)->child[0] = (yyvsp[(1) - (3)].node); (yyvsp[(1) - (3)].node)->parent = (yyval.node);
                                    (yyval.node)->child[1] = (yyvsp[(3) - (3)].node); (yyvsp[(3) - (3)].node)->parent = (yyval.node);
                                    (yyval.node)->ntno = 20; (yyval.node)->procno = 28;
                                    (yyval.node)->contain_expr = 1;
                                    (yyval.node)->lineno = yylineno;
                                ;}
    break;

  case 93:
#line 525 "minic.y"
    {   (yyval.node) = makeNode(2); (yyval.node)->child[0] = (yyvsp[(1) - (3)].node); (yyvsp[(1) - (3)].node)->parent = (yyval.node);
                                    (yyval.node)->child[1] = (yyvsp[(3) - (3)].node); (yyvsp[(3) - (3)].node)->parent = (yyval.node);
                                    (yyval.node)->ntno = 20; (yyval.node)->procno = 29;
                                    (yyval.node)->contain_expr = 1;
                                    (yyval.node)->lineno = yylineno;
                                ;}
    break;

  case 95:
#line 535 "minic.y"
    {   (yyval.node) = makeNode(0); (yyval.node)->ntno = 21; (yyval.node)->procno = 1;
                                    strcpy((yyval.node)->numtxt, (yyvsp[(1) - (1)].text));
                                    (yyval.node)->lineno = yylineno;
                                ;}
    break;

  case 96:
#line 539 "minic.y"
    {   (yyval.node) = makeNode(0); (yyval.node)->ntno = 21; (yyval.node)->procno = 2;
                                    strcpy((yyval.node)->numtxt, (yyvsp[(1) - (1)].text));
                                    (yyval.node)->lineno = yylineno;
                                ;}
    break;

  case 98:
#line 547 "minic.y"
    {   (yyval.node) = makeNode(2); (yyval.node)->child[0] = (yyvsp[(1) - (3)].node); (yyvsp[(1) - (3)].node)->parent = (yyval.node);
                                    (yyval.node)->child[1] = (yyvsp[(3) - (3)].node); (yyvsp[(3) - (3)].node)->parent = (yyval.node);
                                    (yyval.node)->ntno = 22; (yyval.node)->procno = 1;
                                    (yyval.node)->multiplicity = (yyvsp[(1) - (3)].node)->multiplicity + 1;
                                    (yyval.node)->lineno = yylineno;
                                ;}
    break;

  case 99:
#line 553 "minic.y"
    {   (yyval.node) = makeNode(1); (yyval.node)->child[0] = (yyvsp[(1) - (1)].node); (yyvsp[(1) - (1)].node)->parent = (yyval.node);
                                    (yyval.node)->ntno = 22; (yyval.node)->procno = 2;
                                    (yyval.node)->multiplicity = 1;
                                    (yyval.node)->lineno = yylineno;
                                ;}
    break;

  case 101:
#line 562 "minic.y"
    {   (yyval.node) = makeNode(0); (yyval.node)->ntno = 23; (yyval.node)->procno = 1;
                                    (yyval.node)->lineno = yylineno;
                                ;}
    break;

  case 103:
#line 569 "minic.y"
    {   (yyval.node) = makeNode(0); (yyval.node)->ntno = 24; (yyval.node)->procno = 1;
                                    (yyval.node)->lineno = yylineno;
                                ;}
    break;


/* Line 1267 of yacc.c.  */
#line 2320 "minic.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse look-ahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 574 "minic.y"

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

