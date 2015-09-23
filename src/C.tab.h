/* A Bison parser, made by GNU Bison 2.5.  */

/* Bison interface for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2011 Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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
     IDENTIFIER = 258,
     CONSTANT = 259,
     CONSTANTF = 260,
     STRING_LITERAL = 261,
     LTEQ = 262,
     GTEQ = 263,
     EQEQ = 264,
     NOTEQ = 265,
     LT = 266,
     GT = 267,
     ANDAND = 268,
     OROR = 269,
     NOT = 270,
     PLUS = 271,
     MINUS = 272,
     MULT = 273,
     DIV = 274,
     MOD = 275,
     EQ = 276,
     TRUETOKEN = 277,
     FALSETOKEN = 278,
     TYPE_NAME = 279,
     TYPEDEF = 280,
     INT = 281,
     FLOAT = 282,
     CONST = 283,
     VOID = 284,
     BOOL = 285,
     IF = 286,
     ELSE = 287,
     WHILE = 288,
     CONTINUE = 289,
     BREAK = 290,
     RETURN = 291
   };
#endif
/* Tokens.  */
#define IDENTIFIER 258
#define CONSTANT 259
#define CONSTANTF 260
#define STRING_LITERAL 261
#define LTEQ 262
#define GTEQ 263
#define EQEQ 264
#define NOTEQ 265
#define LT 266
#define GT 267
#define ANDAND 268
#define OROR 269
#define NOT 270
#define PLUS 271
#define MINUS 272
#define MULT 273
#define DIV 274
#define MOD 275
#define EQ 276
#define TRUETOKEN 277
#define FALSETOKEN 278
#define TYPE_NAME 279
#define TYPEDEF 280
#define INT 281
#define FLOAT 282
#define CONST 283
#define VOID 284
#define BOOL 285
#define IF 286
#define ELSE 287
#define WHILE 288
#define CONTINUE 289
#define BREAK 290
#define RETURN 291




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 2068 of yacc.c  */
#line 14 "config/C.y"

   	float num;
	int ival;
   	char * ident; 
	char * str; 
	ASTNode node;



/* Line 2068 of yacc.c  */
#line 132 "src/C.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;

#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
} YYLTYPE;
# define yyltype YYLTYPE /* obsolescent; will be withdrawn */
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif

extern YYLTYPE yylloc;

