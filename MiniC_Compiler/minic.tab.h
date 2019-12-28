/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

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




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 33 "minic.y"
{
    char *text;         /* 终结符语义值类型 */
    struct AST *node;	/* 非终结符语义值类型 */
}
/* Line 1529 of yacc.c.  */
#line 98 "minic.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

