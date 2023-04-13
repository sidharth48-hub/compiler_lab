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
    TYPE = 258,
    ENDTYPE = 259,
    ALLOC = 260,
    INITIALIZE = 261,
    FREE = 262,
    VAR_NULL = 263,
    START = 264,
    END = 265,
    DECL = 266,
    ENDDECL = 267,
    INT = 268,
    STR = 269,
    SEMICOLON = 270,
    RETURN = 271,
    BREAKPOINT = 272,
    POINT = 273,
    READ = 274,
    WRITE = 275,
    IF = 276,
    THEN = 277,
    ELSE = 278,
    ENDIF = 279,
    WHILE = 280,
    DO = 281,
    ENDWHILE = 282,
    REPEAT = 283,
    UNTIL = 284,
    BREAK = 285,
    CONTINUE = 286,
    NUM = 287,
    ID = 288,
    STRING = 289,
    OR = 290,
    AND = 291,
    GTE = 292,
    LTE = 293,
    LT = 294,
    GT = 295,
    NE = 296,
    EQ = 297,
    PLUS = 298,
    MINUS = 299,
    MUL = 300,
    DIV = 301,
    MOD = 302,
    NOT = 303,
    EQUAL = 304
  };
#endif
/* Tokens.  */
#define TYPE 258
#define ENDTYPE 259
#define ALLOC 260
#define INITIALIZE 261
#define FREE 262
#define VAR_NULL 263
#define START 264
#define END 265
#define DECL 266
#define ENDDECL 267
#define INT 268
#define STR 269
#define SEMICOLON 270
#define RETURN 271
#define BREAKPOINT 272
#define POINT 273
#define READ 274
#define WRITE 275
#define IF 276
#define THEN 277
#define ELSE 278
#define ENDIF 279
#define WHILE 280
#define DO 281
#define ENDWHILE 282
#define REPEAT 283
#define UNTIL 284
#define BREAK 285
#define CONTINUE 286
#define NUM 287
#define ID 288
#define STRING 289
#define OR 290
#define AND 291
#define GTE 292
#define LTE 293
#define LT 294
#define GT 295
#define NE 296
#define EQ 297
#define PLUS 298
#define MINUS 299
#define MUL 300
#define DIV 301
#define MOD 302
#define NOT 303
#define EQUAL 304

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 29 "exptree.y"

    struct tnode *no;
    char* ch;
    int num;

#line 161 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
