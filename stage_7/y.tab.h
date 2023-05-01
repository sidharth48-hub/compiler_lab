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
    CLASS = 264,
    ENDCLASS = 265,
    SELF = 266,
    NEW = 267,
    DELETE = 268,
    START = 269,
    END = 270,
    DECL = 271,
    ENDDECL = 272,
    INT = 273,
    STR = 274,
    SEMICOLON = 275,
    RETURN = 276,
    BREAKPOINT = 277,
    POINT = 278,
    READ = 279,
    WRITE = 280,
    IF = 281,
    THEN = 282,
    ELSE = 283,
    ENDIF = 284,
    WHILE = 285,
    DO = 286,
    ENDWHILE = 287,
    REPEAT = 288,
    UNTIL = 289,
    BREAK = 290,
    CONTINUE = 291,
    NUM = 292,
    ID = 293,
    STRING = 294,
    OR = 295,
    AND = 296,
    GTE = 297,
    LTE = 298,
    LT = 299,
    GT = 300,
    NE = 301,
    EQ = 302,
    PLUS = 303,
    MINUS = 304,
    MUL = 305,
    DIV = 306,
    MOD = 307,
    NOT = 308,
    EQUAL = 309
  };
#endif
/* Tokens.  */
#define TYPE 258
#define ENDTYPE 259
#define ALLOC 260
#define INITIALIZE 261
#define FREE 262
#define VAR_NULL 263
#define CLASS 264
#define ENDCLASS 265
#define SELF 266
#define NEW 267
#define DELETE 268
#define START 269
#define END 270
#define DECL 271
#define ENDDECL 272
#define INT 273
#define STR 274
#define SEMICOLON 275
#define RETURN 276
#define BREAKPOINT 277
#define POINT 278
#define READ 279
#define WRITE 280
#define IF 281
#define THEN 282
#define ELSE 283
#define ENDIF 284
#define WHILE 285
#define DO 286
#define ENDWHILE 287
#define REPEAT 288
#define UNTIL 289
#define BREAK 290
#define CONTINUE 291
#define NUM 292
#define ID 293
#define STRING 294
#define OR 295
#define AND 296
#define GTE 297
#define LTE 298
#define LT 299
#define GT 300
#define NE 301
#define EQ 302
#define PLUS 303
#define MINUS 304
#define MUL 305
#define DIV 306
#define MOD 307
#define NOT 308
#define EQUAL 309

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 36 "exptree.y"

    struct tnode *no;
    char* ch;
    int num;

#line 171 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
