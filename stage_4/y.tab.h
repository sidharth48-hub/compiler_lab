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
    GTE = 281,
    LTE = 282,
    LT = 283,
    GT = 284,
    NE = 285,
    EQ = 286,
    PLUS = 287,
    MINUS = 288,
    MUL = 289,
    DIV = 290,
    MOD = 291,
    EQUAL = 292
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
#define GTE 281
#define LTE 282
#define LT 283
#define GT 284
#define NE 285
#define EQ 286
#define PLUS 287
#define MINUS 288
#define MUL 289
#define DIV 290
#define MOD 291
#define EQUAL 292

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 16 "exptree.y"

    struct tnode *no;
    struct dnode *dno;
    char* ch;
    int num;

#line 138 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
