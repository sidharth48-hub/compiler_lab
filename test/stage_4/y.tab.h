/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    START = 258,
    END = 259,
    DECL = 260,
    ENDDECL = 261,
    INT = 262,
    STR = 263,
    SEMICOLON = 264,
    READ = 265,
    WRITE = 266,
    IF = 267,
    THEN = 268,
    ELSE = 269,
    ENDIF = 270,
    WHILE = 271,
    DO = 272,
    ENDWHILE = 273,
    REPEAT = 274,
    UNTIL = 275,
    BREAK = 276,
    CONTINUE = 277,
    NUM = 278,
    ID = 279,
    STRING = 280,
    PLUS = 281,
    MINUS = 282,
    MUL = 283,
    DIV = 284,
    GTE = 285,
    LTE = 286,
    LT = 287,
    GT = 288,
    NE = 289,
    EQ = 290,
    EQUAL = 291
  };
#endif
/* Tokens.  */
#define START 258
#define END 259
#define DECL 260
#define ENDDECL 261
#define INT 262
#define STR 263
#define SEMICOLON 264
#define READ 265
#define WRITE 266
#define IF 267
#define THEN 268
#define ELSE 269
#define ENDIF 270
#define WHILE 271
#define DO 272
#define ENDWHILE 273
#define REPEAT 274
#define UNTIL 275
#define BREAK 276
#define CONTINUE 277
#define NUM 278
#define ID 279
#define STRING 280
#define PLUS 281
#define MINUS 282
#define MUL 283
#define DIV 284
#define GTE 285
#define LTE 286
#define LT 287
#define GT 288
#define NE 289
#define EQ 290
#define EQUAL 291

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 16 "exptree.y"

    struct tnode *no;
    struct dnode *dno;
    char* ch;
    int num;

#line 136 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
