/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "exptree.y"

    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <limits.h>

    extern FILE* yyin;
    FILE* fptr;

    #include "exptree.h"
    #include "typedef.h"
    #include "./Functions/exptree.c"
    #include "./Functions/break_cont.c"
    #include "./Functions/codegen.c"
    #include "./Functions/dynamic_alloc.c"
    #include "./Functions/Func_call.c"
    #include "./Functions/function.c"
    #include "./Functions/Gsymbol.c"
    #include "./Functions/Loop_func.c"
    #include "./Functions/Lsymbol.c"
    #include "./Functions/read_write_assg.c"
    #include "./Functions/TypeDef.c"
    #include "./Functions/var_op.c"
     
    int yylex(void);
    int yyerror();

#line 98 "y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
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

#line 254 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */



#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))

/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
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
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
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
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  21
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   704

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  57
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  40
/* YYNRULES -- Number of rules.  */
#define YYNRULES  104
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  227

#define YYUNDEFTOK  2
#define YYMAXUTOK   304


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      55,    56,     2,     2,    52,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    53,     2,    54,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    50,     2,    51,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    58,    58,    59,    60,    61,    62,    63,    64,    65,
      70,    74,    77,    78,    81,    84,    85,    88,    91,    92,
      93,   101,   102,   105,   106,   109,   115,   116,   119,   120,
     121,   126,   127,   130,   137,   138,   141,   153,   165,   177,
     186,   187,   190,   197,   200,   203,   204,   207,   212,   213,
     220,   225,   226,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   241,   245,   248,   251,   252,   255,   258,
     261,   264,   267,   270,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   300,   301,   304,
     305,   308,   309,   310,   311
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TYPE", "ENDTYPE", "ALLOC", "INITIALIZE",
  "FREE", "VAR_NULL", "START", "END", "DECL", "ENDDECL", "INT", "STR",
  "SEMICOLON", "RETURN", "BREAKPOINT", "POINT", "READ", "WRITE", "IF",
  "THEN", "ELSE", "ENDIF", "WHILE", "DO", "ENDWHILE", "REPEAT", "UNTIL",
  "BREAK", "CONTINUE", "NUM", "ID", "STRING", "OR", "AND", "GTE", "LTE",
  "LT", "GT", "NE", "EQ", "PLUS", "MINUS", "MUL", "DIV", "MOD", "NOT",
  "EQUAL", "'{'", "'}'", "','", "'['", "']'", "'('", "')'", "$accept",
  "program", "TypeDefBlock", "TypeDefList", "TypeDef", "FieldDecList",
  "FieldDecL", "TypeName", "GDeclBlock", "DeclList", "Decl", "VarList",
  "IdDecl", "ParamList", "Param", "FdefBlock", "Fdef", "Body",
  "returnstmt", "LdeclBlock", "LDecList", "LDecl", "IdList", "MainBlock",
  "Slist", "stmt", "InputStmt", "OutputStmt", "AssgStmt", "Ifstmt",
  "Whilestmt", "dowhilestmt", "repuntilstmt", "breakstmt", "continuestmt",
  "breakpointstmt", "expr", "Field", "ArgList", "Identifier", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     123,   125,    44,    91,    93,    40,    41
};
# endif

#define YYPACT_NINF (-92)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-51)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      73,    12,    76,   -92,   -92,   -92,     3,   121,   -23,   123,
     123,    17,   -92,   -92,   -21,    37,   -92,   -92,    -6,   193,
     -92,   -92,   123,   123,   -92,   -12,   123,   -92,    17,   -92,
     123,   -92,   -92,    30,   -10,   -92,   -92,   -92,   123,   -92,
     -92,    11,   -92,    -2,   -92,    63,     0,   123,   -92,    -6,
     -92,    53,    71,   -26,   -92,   -92,   -92,    92,    57,    16,
     -92,    66,   -92,   123,    62,   -92,   -92,   -92,   170,   451,
      70,   105,   -92,    66,    74,    75,    86,   -92,   -92,   102,
      96,    97,    98,   110,   331,   331,   132,   133,   -92,    18,
     -92,   367,   367,   203,   -92,   -92,   -92,   -92,   -92,   -92,
     -92,   -92,   -92,   -92,   -92,   610,   149,   -92,   -92,   140,
     454,   -92,   -92,   128,   130,   105,   118,   126,   367,   -92,
     367,   367,   367,   367,   363,   235,   -92,   -92,   150,   367,
      94,   -92,   414,   367,   174,   -92,   367,   367,   367,   367,
     367,   367,   367,   367,   367,   367,   367,   367,   367,   367,
     152,   -92,    -1,   -92,   -92,   -92,   -92,   137,   -92,   -92,
     436,   458,   480,   502,   524,   139,   142,   -92,   590,   -92,
     625,    22,   -92,   388,   -92,   637,   648,   657,   657,   465,
     465,   -24,   -24,    93,    93,   -92,   -92,   -92,   401,   -92,
     -92,   159,   -92,   -92,   184,   197,   191,   188,   367,   367,
     -92,   367,   -92,   -92,   -92,   -92,   -92,   -92,   331,   331,
     546,   568,   625,   138,   267,    -8,   200,   331,   201,   202,
     -92,   -92,   299,   -92,   -92,   206,   -92
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,    18,    19,    20,     0,     0,     0,     0,
       0,    35,     9,    11,     0,     0,    13,    22,     0,     0,
      24,     1,     0,     0,     5,     0,     0,     7,    34,     8,
       0,    10,    12,    28,     0,    27,    21,    23,     0,     3,
       4,     0,     6,     0,    16,     0,     0,     0,    25,     0,
       2,     0,     0,     0,    32,    14,    15,     0,     0,     0,
      26,     0,    33,     0,     0,    17,    29,    30,     0,     0,
       0,     0,    31,     0,     0,     0,     0,    95,    41,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    90,   101,
      91,     0,     0,     0,    52,    53,    54,    55,    56,    57,
      61,    62,    58,    59,    60,     0,    96,    89,    44,     0,
       0,    46,    39,     0,     0,     0,     0,     0,     0,    73,
       0,     0,     0,     0,     0,     0,    71,    72,     0,     0,
       0,    87,     0,     0,     0,    51,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    49,     0,    43,    45,    38,    37,     0,    92,    93,
       0,     0,     0,     0,     0,     0,     0,    98,     0,   103,
     100,     0,    88,     0,    40,    86,    85,    83,    82,    79,
      80,    81,    84,    74,    75,    76,    77,    78,     0,    97,
      47,     0,    36,    94,     0,     0,     0,     0,     0,     0,
     102,     0,   104,    42,    65,    48,    63,    64,     0,     0,
       0,     0,    99,     0,     0,     0,     0,     0,     0,     0,
      69,    70,     0,    67,    68,     0,    66
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -92,   -92,   -92,   -92,   212,   -92,   187,    50,   225,   -92,
     219,   -92,   190,   198,   181,     6,    82,   -67,   -92,   173,
     -92,   143,   -92,    72,   -84,   -91,   -92,   -92,   -92,   -92,
     -92,   -92,   -92,   -92,   -92,   -92,   -83,   -92,   -92,   -92
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     6,     7,    15,    16,    43,    44,     8,     9,    19,
      20,    34,    35,    53,    54,    10,    11,    70,   134,    71,
     110,   111,   152,    12,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   171,   107
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     124,   125,   135,    21,   113,    48,   114,   220,   131,   132,
      25,     3,     4,    23,   190,    26,    13,   -50,   209,   144,
     145,   146,   147,   148,     3,     4,    63,    33,    38,    30,
      64,     5,    58,   135,   135,   160,   128,   161,   162,   163,
     164,    31,    49,    41,     5,    14,   168,   170,   157,    55,
     173,   191,    18,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,    51,    63,    18,
      14,   129,    67,   130,   201,    68,     1,    69,   202,    24,
      45,    27,    29,    46,     2,    47,     3,     4,    17,     3,
       4,    52,    28,    45,    39,    40,    57,    52,    42,    74,
      75,    76,    77,    61,    62,    28,     5,    65,    28,     5,
      50,    66,    73,    52,    68,   210,   211,   119,   212,   109,
      28,   112,   135,   135,   213,   214,    88,    89,    90,   116,
     117,   135,     2,   222,     3,     4,     3,     4,   146,   147,
     148,   118,    91,    74,    75,    76,    77,   126,   127,    92,
     169,   120,   121,   122,     5,    79,     5,    80,    81,    82,
     109,   217,   218,    83,    84,   123,    85,   150,    86,    87,
      88,    89,    90,   151,   158,    74,    75,    76,    77,   155,
      78,   156,   159,   167,   174,   189,    91,    79,   192,    80,
      81,    82,   205,    92,   198,    83,    84,   199,    85,   206,
      86,    87,    88,    89,    90,    36,     3,     4,    74,    75,
      76,    77,   207,   208,   209,   221,   223,   224,    91,   133,
      79,   226,    80,    81,    82,    92,     5,    32,    83,    84,
      56,    85,    22,    86,    87,    88,    89,    90,    37,    60,
      74,    75,    76,    77,    72,    59,   115,     0,     0,     0,
       0,    91,    79,   154,    80,    81,    82,     0,    92,     0,
      83,    84,     0,    85,   166,    86,    87,    88,    89,    90,
       0,     0,    74,    75,    76,    77,     0,     0,     0,     0,
       0,     0,     0,    91,    79,     0,    80,    81,    82,     0,
      92,     0,    83,    84,   219,    85,     0,    86,    87,    88,
      89,    90,     0,     0,    74,    75,    76,    77,     0,     0,
       0,     0,     0,     0,     0,    91,    79,     0,    80,    81,
      82,     0,    92,   225,    83,    84,     0,    85,     0,    86,
      87,    88,    89,    90,     0,     0,    74,    75,    76,    77,
       0,     0,     0,     0,     0,     0,     0,    91,    79,     0,
      80,    81,    82,     0,    92,     0,    83,    84,     0,    85,
       0,    86,    87,    88,    89,    90,     0,     0,    74,    75,
      76,    77,    74,    75,    76,    77,     0,     0,     0,    91,
      79,     0,    80,    81,    82,     0,    92,     0,   165,    84,
       0,    85,     0,    86,    87,    88,    89,    90,     0,    88,
      89,    90,     0,   203,     0,     0,     0,     0,     0,     0,
       0,    91,     0,     0,     0,    91,   204,     0,    92,     0,
       0,     0,    92,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,     0,   108,     3,     4,   153,     3,     4,     0,
     172,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,     5,     0,     0,     5,     0,     0,
       0,     0,   193,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   142,   143,   144,   145,
     146,   147,   148,     0,   194,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,     0,     0,
       0,     0,     0,     0,     0,     0,   195,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
       0,     0,     0,     0,     0,     0,     0,     0,   196,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,     0,     0,     0,     0,     0,     0,     0,     0,
     197,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,     0,     0,     0,     0,     0,     0,
       0,     0,   215,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,     0,     0,     0,     0,
       0,     0,     0,     0,   216,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,     0,     0,
       0,     0,     0,     0,   200,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,     0,   149,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   140,   141,   142,   143,
     144,   145,   146,   147,   148
};

static const yytype_int16 yycheck[] =
{
      84,    85,    93,     0,    71,    15,    73,    15,    91,    92,
      33,    13,    14,     7,    15,     9,     4,     0,    26,    43,
      44,    45,    46,    47,    13,    14,    52,    33,    22,    50,
      56,    33,    32,   124,   125,   118,    18,   120,   121,   122,
     123,     4,    52,    55,    33,    33,   129,   130,   115,    51,
     133,    52,     2,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,    56,    52,    19,
      33,    53,    56,    55,    52,     9,     3,    11,    56,     7,
      30,     9,    10,    53,    11,    55,    13,    14,    12,    13,
      14,    41,    10,    43,    22,    23,    33,    47,    26,     5,
       6,     7,     8,    50,    33,    23,    33,    15,    26,    33,
      38,    54,    50,    63,     9,   198,   199,    15,   201,    69,
      38,    51,   213,   214,   208,   209,    32,    33,    34,    55,
      55,   222,    11,   217,    13,    14,    13,    14,    45,    46,
      47,    55,    48,     5,     6,     7,     8,    15,    15,    55,
      56,    55,    55,    55,    33,    17,    33,    19,    20,    21,
     110,    23,    24,    25,    26,    55,    28,    18,    30,    31,
      32,    33,    34,    33,    56,     5,     6,     7,     8,    51,
      10,    51,    56,    33,    10,    33,    48,    17,    51,    19,
      20,    21,    33,    55,    55,    25,    26,    55,    28,    15,
      30,    31,    32,    33,    34,    12,    13,    14,     5,     6,
       7,     8,    15,    22,    26,    15,    15,    15,    48,    16,
      17,    15,    19,    20,    21,    55,    33,    15,    25,    26,
      43,    28,     7,    30,    31,    32,    33,    34,    19,    49,
       5,     6,     7,     8,    63,    47,    73,    -1,    -1,    -1,
      -1,    48,    17,   110,    19,    20,    21,    -1,    55,    -1,
      25,    26,    -1,    28,    29,    30,    31,    32,    33,    34,
      -1,    -1,     5,     6,     7,     8,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    48,    17,    -1,    19,    20,    21,    -1,
      55,    -1,    25,    26,    27,    28,    -1,    30,    31,    32,
      33,    34,    -1,    -1,     5,     6,     7,     8,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    48,    17,    -1,    19,    20,
      21,    -1,    55,    24,    25,    26,    -1,    28,    -1,    30,
      31,    32,    33,    34,    -1,    -1,     5,     6,     7,     8,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    48,    17,    -1,
      19,    20,    21,    -1,    55,    -1,    25,    26,    -1,    28,
      -1,    30,    31,    32,    33,    34,    -1,    -1,     5,     6,
       7,     8,     5,     6,     7,     8,    -1,    -1,    -1,    48,
      17,    -1,    19,    20,    21,    -1,    55,    -1,    25,    26,
      -1,    28,    -1,    30,    31,    32,    33,    34,    -1,    32,
      33,    34,    -1,    15,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    48,    -1,    -1,    -1,    48,    15,    -1,    55,    -1,
      -1,    -1,    55,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    -1,    12,    13,    14,    12,    13,    14,    -1,
      56,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    33,    -1,    -1,    33,    -1,    -1,
      -1,    -1,    56,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    41,    42,    43,    44,
      45,    46,    47,    -1,    56,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    56,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    56,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      56,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    56,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    56,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    -1,    -1,
      -1,    -1,    -1,    -1,    54,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    -1,    49,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    39,    40,    41,    42,
      43,    44,    45,    46,    47
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,    11,    13,    14,    33,    58,    59,    64,    65,
      72,    73,    80,     4,    33,    60,    61,    12,    64,    66,
      67,     0,    65,    72,    80,    33,    72,    80,    73,    80,
      50,     4,    61,    33,    68,    69,    12,    67,    72,    80,
      80,    55,    80,    62,    63,    64,    53,    55,    15,    52,
      80,    56,    64,    70,    71,    51,    63,    33,    32,    70,
      69,    50,    33,    52,    56,    15,    54,    56,     9,    11,
      74,    76,    71,    50,     5,     6,     7,     8,    10,    17,
      19,    20,    21,    25,    26,    28,    30,    31,    32,    33,
      34,    48,    55,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    96,    12,    64,
      77,    78,    51,    74,    74,    76,    55,    55,    55,    15,
      55,    55,    55,    55,    81,    81,    15,    15,    18,    53,
      55,    93,    93,    16,    75,    82,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    49,
      18,    33,    79,    12,    78,    51,    51,    74,    56,    56,
      93,    93,    93,    93,    93,    25,    29,    33,    93,    56,
      93,    95,    56,    93,    10,    93,    93,    93,    93,    93,
      93,    93,    93,    93,    93,    93,    93,    93,    93,    33,
      15,    52,    51,    56,    56,    56,    56,    56,    55,    55,
      54,    52,    56,    15,    15,    33,    15,    15,    22,    26,
      93,    93,    93,    81,    81,    56,    56,    23,    24,    27,
      15,    15,    81,    15,    15,    24,    15
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    57,    58,    58,    58,    58,    58,    58,    58,    58,
      59,    59,    60,    60,    61,    62,    62,    63,    64,    64,
      64,    65,    65,    66,    66,    67,    68,    68,    69,    69,
      69,    70,    70,    71,    72,    72,    73,    73,    73,    73,
      74,    74,    75,    76,    76,    77,    77,    78,    79,    79,
      80,    81,    81,    82,    82,    82,    82,    82,    82,    82,
      82,    82,    82,    83,    84,    85,    86,    86,    87,    88,
      89,    90,    91,    92,    93,    93,    93,    93,    93,    93,
      93,    93,    93,    93,    93,    93,    93,    93,    93,    93,
      93,    93,    93,    93,    93,    93,    93,    94,    94,    95,
      95,    96,    96,    96,    96
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     4,     3,     3,     2,     3,     2,     2,     1,
       3,     2,     2,     1,     4,     2,     1,     3,     1,     1,
       1,     3,     2,     2,     1,     3,     3,     1,     1,     4,
       4,     3,     1,     2,     2,     1,     9,     8,     8,     7,
       4,     2,     3,     3,     2,     2,     1,     3,     3,     1,
       1,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     5,     5,     4,    10,     8,     8,     7,
       7,     2,     2,     2,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     2,     3,     1,
       1,     1,     3,     3,     4,     1,     1,     3,     3,     3,
       1,     1,     4,     3,     4
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

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
#ifndef YYINITDEPTH
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
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
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
static char *
yystpcpy (char *yydest, const char *yysrc)
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
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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
            else
              goto append;

          append:
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

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
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
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

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
#line 58 "exptree.y"
                                                      {codegenerator((yyvsp[-1].no),(yyvsp[0].no));}
#line 1680 "y.tab.c"
    break;

  case 3:
#line 59 "exptree.y"
                                            {codegenerator(NULL,(yyvsp[0].no));}
#line 1686 "y.tab.c"
    break;

  case 4:
#line 60 "exptree.y"
                                           {codegenerator((yyvsp[-1].no),(yyvsp[0].no));}
#line 1692 "y.tab.c"
    break;

  case 5:
#line 61 "exptree.y"
                                  {codegenerator(NULL,(yyvsp[0].no));}
#line 1698 "y.tab.c"
    break;

  case 6:
#line 62 "exptree.y"
                                         {codegenerator((yyvsp[-1].no),(yyvsp[0].no));}
#line 1704 "y.tab.c"
    break;

  case 7:
#line 63 "exptree.y"
                               {codegenerator(NULL,(yyvsp[0].no));}
#line 1710 "y.tab.c"
    break;

  case 8:
#line 64 "exptree.y"
                              {codegenerator((yyvsp[-1].no),(yyvsp[0].no));}
#line 1716 "y.tab.c"
    break;

  case 9:
#line 65 "exptree.y"
                    {codegenerator(NULL,(yyvsp[0].no));}
#line 1722 "y.tab.c"
    break;

  case 10:
#line 70 "exptree.y"
                                        {(yyval.no)=(yyvsp[-1].no);
                                         TypetableCreate();
                                         TypetableEntry((yyvsp[-1].no));
                                        }
#line 1731 "y.tab.c"
    break;

  case 11:
#line 74 "exptree.y"
                            {}
#line 1737 "y.tab.c"
    break;

  case 12:
#line 77 "exptree.y"
                                  {(yyval.no)=makeTypeConnector(NODE_CONNECTOR,(yyvsp[-1].no),(yyvsp[0].no));}
#line 1743 "y.tab.c"
    break;

  case 13:
#line 78 "exptree.y"
                      {(yyval.no)=(yyvsp[0].no);}
#line 1749 "y.tab.c"
    break;

  case 14:
#line 81 "exptree.y"
                                  {(yyval.no)=makeTypeConnector(NODE_TYPEDEF,makeIdNode(NODE_USERID,(yyvsp[-3].ch),NULL,NULL),(yyvsp[-1].no));}
#line 1755 "y.tab.c"
    break;

  case 15:
#line 84 "exptree.y"
                                      {(yyval.no)=makeTypeConnector(NODE_CONNECTOR,(yyvsp[-1].no),(yyvsp[0].no));}
#line 1761 "y.tab.c"
    break;

  case 16:
#line 85 "exptree.y"
                         {(yyval.no)=(yyvsp[0].no);}
#line 1767 "y.tab.c"
    break;

  case 17:
#line 88 "exptree.y"
                                  {(yyval.no)=makeTypeConnector(NODE_TYPE_FIELD,(yyvsp[-2].no),makeIdNode(NODE_TYPEID,(yyvsp[-1].ch),NULL,NULL));}
#line 1773 "y.tab.c"
    break;

  case 18:
#line 91 "exptree.y"
               {(yyval.no)=makeTypeNameNode("int",NODE_TYPENAME);}
#line 1779 "y.tab.c"
    break;

  case 19:
#line 92 "exptree.y"
               {(yyval.no)=makeTypeNameNode("string",NODE_TYPENAME);}
#line 1785 "y.tab.c"
    break;

  case 20:
#line 93 "exptree.y"
              {(yyval.no)=makeTypeNameNode((yyvsp[0].ch),NODE_TYPENAME);}
#line 1791 "y.tab.c"
    break;

  case 21:
#line 101 "exptree.y"
                                   {(yyval.no)=(yyvsp[-1].no);}
#line 1797 "y.tab.c"
    break;

  case 22:
#line 102 "exptree.y"
                          {}
#line 1803 "y.tab.c"
    break;

  case 23:
#line 105 "exptree.y"
                         {(yyval.no)=makeDeclNode(NODE_CONNECTOR,(yyvsp[-1].no),(yyvsp[0].no));}
#line 1809 "y.tab.c"
    break;

  case 24:
#line 106 "exptree.y"
                {(yyval.no)=(yyvsp[0].no);}
#line 1815 "y.tab.c"
    break;

  case 25:
#line 109 "exptree.y"
                                  {(yyval.no)=makeDataTypeNode(NODE_CONNECTOR,(yyvsp[-2].no),(yyvsp[-1].no));
                               struct Typetable *type = TLookup((yyvsp[-2].no)->varname);
                               GsymbolEntry(type,(yyvsp[-1].no));
                               }
#line 1824 "y.tab.c"
    break;

  case 26:
#line 115 "exptree.y"
                             {(yyval.no)=makeDeclNode(NODE_CONNECTOR,(yyvsp[-2].no),(yyvsp[0].no));}
#line 1830 "y.tab.c"
    break;

  case 27:
#line 116 "exptree.y"
                 {(yyval.no)=(yyvsp[0].no);}
#line 1836 "y.tab.c"
    break;

  case 28:
#line 119 "exptree.y"
            {(yyval.no)=makeIdNodeDecl(NODE_VARIABLE,(yyvsp[0].ch),0,NULL);}
#line 1842 "y.tab.c"
    break;

  case 29:
#line 120 "exptree.y"
                        {(yyval.no)=makeIdNodeDecl(NODE_VAR_ARRAY,(yyvsp[-3].ch),(yyvsp[-1].num),NULL);}
#line 1848 "y.tab.c"
    break;

  case 30:
#line 121 "exptree.y"
                              {
                                (yyval.no)=makeIdNodeDecl(NODE_VAR_PARAMLIST,(yyvsp[-3].ch),0,(yyvsp[-1].no));
                              }
#line 1856 "y.tab.c"
    break;

  case 31:
#line 126 "exptree.y"
                                {(yyval.no)=makeDeclNode(NODE_CONNECTOR,(yyvsp[-2].no),(yyvsp[0].no));}
#line 1862 "y.tab.c"
    break;

  case 32:
#line 127 "exptree.y"
                   {(yyval.no)=(yyvsp[0].no);}
#line 1868 "y.tab.c"
    break;

  case 33:
#line 130 "exptree.y"
                    {(yyval.no)=makeParamNode(NODE_PARAM,(yyvsp[-1].no),makeIdNodeDecl(NODE_PARAM_VARIABLE,(yyvsp[0].ch),0,NULL));}
#line 1874 "y.tab.c"
    break;

  case 34:
#line 137 "exptree.y"
                           {(yyval.no)=makeFuncConnectorNode(NODE_CONNECTOR,(yyvsp[-1].no),(yyvsp[0].no));}
#line 1880 "y.tab.c"
    break;

  case 35:
#line 138 "exptree.y"
                 {(yyval.no)=(yyvsp[0].no);}
#line 1886 "y.tab.c"
    break;

  case 36:
#line 141 "exptree.y"
                                                          {
                                                          struct tnode *temp1 = (yyvsp[-8].no);
                                                          struct tnode *temp2 = makeFuncConnectorNode(NODE_CONNECTOR,(yyvsp[-2].no),(yyvsp[-1].no));
                                                          struct tnode *temp3 = makeFuncConnectorNode(NODE_CONNECTOR,(yyvsp[-5].no),temp2); 
                                                          struct tnode *temp4 = makeFuncIdNode(NODE_FUNCTION,(yyvsp[-7].ch),temp1,temp3);

                                                          (yyval.no) = temp4;

                                                          struct Lsymbol *temp =  LsymbolEntry((yyvsp[-5].no),(yyvsp[-2].no));

                                                          LinkLocalTable(temp,(yyvsp[-1].no));    
                                                       }
#line 1903 "y.tab.c"
    break;

  case 37:
#line 153 "exptree.y"
                                                {
                                                          struct tnode *temp1 = (yyvsp[-7].no);
                                                          struct tnode *temp2 = makeFuncConnectorNode(NODE_CONNECTOR,NULL,(yyvsp[-1].no));
                                                          struct tnode *temp3 = makeFuncConnectorNode(NODE_CONNECTOR,(yyvsp[-4].no),temp2);

                                                          struct tnode *temp4 = makeFuncIdNode(NODE_FUNCTION,(yyvsp[-6].ch),temp1,temp3);
                                                          
                                                          (yyval.no) = temp4;

                                                          struct Lsymbol *temp =  LsymbolEntry((yyvsp[-4].no),NULL);
                                                          LinkLocalTable(temp,(yyvsp[-1].no));
                                            }
#line 1920 "y.tab.c"
    break;

  case 38:
#line 165 "exptree.y"
                                                  {
                                                          struct tnode *temp1 = (yyvsp[-7].no);
                                                          struct tnode *temp2 = makeFuncConnectorNode(NODE_CONNECTOR,(yyvsp[-2].no),(yyvsp[-1].no));
                                                          struct tnode *temp3 = makeFuncConnectorNode(NODE_CONNECTOR,NULL,temp2);
                                                          struct tnode *temp4 = makeFuncIdNode(NODE_FUNCTION,(yyvsp[-6].ch),temp1,temp3);

                                                          (yyval.no) = temp4;

                                                          struct Lsymbol *temp =  LsymbolEntry(NULL,(yyvsp[-2].no));
                                                          
                                                          LinkLocalTable(temp,(yyvsp[-1].no));
                                               }
#line 1937 "y.tab.c"
    break;

  case 39:
#line 177 "exptree.y"
                                       {
                                                          struct tnode *temp1 = (yyvsp[-6].no);
                                                          struct tnode *temp2 = makeFuncConnectorNode(NODE_CONNECTOR,NULL,(yyvsp[-1].no));
                                                          struct tnode *temp3 = makeFuncConnectorNode(NODE_CONNECTOR,NULL,temp2);

                                                          (yyval.no) = makeFuncIdNode(NODE_FUNCTION,(yyvsp[-5].ch),temp1,temp3);
                                   }
#line 1949 "y.tab.c"
    break;

  case 40:
#line 186 "exptree.y"
                                  {(yyval.no)=makeFuncConnectorNode(NODE_CONNECTOR,(yyvsp[-2].no),(yyvsp[-1].no));}
#line 1955 "y.tab.c"
    break;

  case 41:
#line 187 "exptree.y"
                 {}
#line 1961 "y.tab.c"
    break;

  case 42:
#line 190 "exptree.y"
                                   {(yyval.no)=makeReturnNode(NODE_RETURN,(yyvsp[-1].no));}
#line 1967 "y.tab.c"
    break;

  case 43:
#line 197 "exptree.y"
                                   {
                                    (yyval.no)=(yyvsp[-1].no);
                                    }
#line 1975 "y.tab.c"
    break;

  case 44:
#line 200 "exptree.y"
                          {}
#line 1981 "y.tab.c"
    break;

  case 45:
#line 203 "exptree.y"
                          {(yyval.no)=makeLDeclConnectorNode(NODE_LCONNECTOR,(yyvsp[-1].no),(yyvsp[0].no));}
#line 1987 "y.tab.c"
    break;

  case 46:
#line 204 "exptree.y"
                 {(yyval.no)=(yyvsp[0].no);}
#line 1993 "y.tab.c"
    break;

  case 47:
#line 207 "exptree.y"
                                  {
                               (yyval.no)=makeLDeclTypeNode(NODE_LTYPE,(yyvsp[-2].no),(yyvsp[-1].no));
                               }
#line 2001 "y.tab.c"
    break;

  case 48:
#line 212 "exptree.y"
                       {(yyval.no)=makeLDeclConnectorNode(NODE_CONNECTOR,(yyvsp[-2].no),makeLDeclIdNode(NODE_VARIABLE,(yyvsp[0].ch)));}
#line 2007 "y.tab.c"
    break;

  case 49:
#line 213 "exptree.y"
            {(yyval.no)=makeLDeclIdNode(NODE_VARIABLE,(yyvsp[0].ch));}
#line 2013 "y.tab.c"
    break;

  case 50:
#line 220 "exptree.y"
                 {(yyval.no)=(yyvsp[0].no);}
#line 2019 "y.tab.c"
    break;

  case 51:
#line 225 "exptree.y"
                   {(yyval.no)=makeConnectorNode(NODE_CONNECTOR,".",(yyvsp[-1].no),(yyvsp[0].no));}
#line 2025 "y.tab.c"
    break;

  case 52:
#line 226 "exptree.y"
             {(yyval.no)=(yyvsp[0].no);}
#line 2031 "y.tab.c"
    break;

  case 53:
#line 229 "exptree.y"
                 {(yyval.no)=(yyvsp[0].no);}
#line 2037 "y.tab.c"
    break;

  case 54:
#line 230 "exptree.y"
                  {(yyval.no)=(yyvsp[0].no);}
#line 2043 "y.tab.c"
    break;

  case 55:
#line 231 "exptree.y"
                {(yyval.no)=(yyvsp[0].no);}
#line 2049 "y.tab.c"
    break;

  case 56:
#line 232 "exptree.y"
              {(yyval.no)=(yyvsp[0].no);}
#line 2055 "y.tab.c"
    break;

  case 57:
#line 233 "exptree.y"
                 {(yyval.no)=(yyvsp[0].no);}
#line 2061 "y.tab.c"
    break;

  case 58:
#line 234 "exptree.y"
                 {(yyval.no)=(yyvsp[0].no);}
#line 2067 "y.tab.c"
    break;

  case 59:
#line 235 "exptree.y"
                    {(yyval.no)=(yyvsp[0].no);}
#line 2073 "y.tab.c"
    break;

  case 60:
#line 236 "exptree.y"
                      {(yyval.no)=(yyvsp[0].no);}
#line 2079 "y.tab.c"
    break;

  case 61:
#line 237 "exptree.y"
                   {(yyval.no)=(yyvsp[0].no);}
#line 2085 "y.tab.c"
    break;

  case 62:
#line 238 "exptree.y"
                    {(yyval.no)=(yyvsp[0].no);}
#line 2091 "y.tab.c"
    break;

  case 63:
#line 241 "exptree.y"
                                       {(yyval.no)=makereadNode(NODE_READ,(yyvsp[-2].no));}
#line 2097 "y.tab.c"
    break;

  case 64:
#line 245 "exptree.y"
                                         {(yyval.no)=makewriteNode(NODE_WRITE,(yyvsp[-2].no));}
#line 2103 "y.tab.c"
    break;

  case 65:
#line 248 "exptree.y"
                                     {(yyval.no)=makeOperatorNode(NODE_ASSG_EQ,"=",(yyvsp[-3].no),(yyvsp[-1].no));}
#line 2109 "y.tab.c"
    break;

  case 66:
#line 251 "exptree.y"
                                                              {(yyval.no)=makeIfNode(NODE_IF,(yyvsp[-7].no),(yyvsp[-4].no),(yyvsp[-2].no));}
#line 2115 "y.tab.c"
    break;

  case 67:
#line 252 "exptree.y"
                                                   {(yyval.no)=makeIfNode(NODE_IF,(yyvsp[-5].no),(yyvsp[-2].no),NULL);}
#line 2121 "y.tab.c"
    break;

  case 68:
#line 255 "exptree.y"
                                                          {(yyval.no)=makeWhileNode(NODE_WHILE,(yyvsp[-5].no),(yyvsp[-2].no));}
#line 2127 "y.tab.c"
    break;

  case 69:
#line 258 "exptree.y"
                                                   {(yyval.no)=makedowhileNode(NODE_DO,(yyvsp[-5].no),(yyvsp[-2].no));}
#line 2133 "y.tab.c"
    break;

  case 70:
#line 261 "exptree.y"
                                                        {(yyval.no)=makerepuntilNode(NODE_REPEAT,(yyvsp[-5].no),(yyvsp[-2].no));}
#line 2139 "y.tab.c"
    break;

  case 71:
#line 264 "exptree.y"
                            {(yyval.no)=makebreakNode(NODE_BREAK);}
#line 2145 "y.tab.c"
    break;

  case 72:
#line 267 "exptree.y"
                                  {(yyval.no)=makecontNode(NODE_CONTINUE);}
#line 2151 "y.tab.c"
    break;

  case 73:
#line 270 "exptree.y"
                                       {(yyval.no)=makeIdNode(NODE_BREAK_POINT,(yyvsp[-1].ch),NULL,NULL);}
#line 2157 "y.tab.c"
    break;

  case 74:
#line 273 "exptree.y"
                      {(yyval.no) = makeOperatorNode(NODE_ADD,"+",(yyvsp[-2].no),(yyvsp[0].no));(yyval.no)->type = intType;}
#line 2163 "y.tab.c"
    break;

  case 75:
#line 274 "exptree.y"
                      {(yyval.no) = makeOperatorNode(NODE_SUB,"-",(yyvsp[-2].no),(yyvsp[0].no));(yyval.no)->type = intType;}
#line 2169 "y.tab.c"
    break;

  case 76:
#line 275 "exptree.y"
                    {(yyval.no) = makeOperatorNode(NODE_MUL,"*",(yyvsp[-2].no),(yyvsp[0].no)); (yyval.no)->type = intType;}
#line 2175 "y.tab.c"
    break;

  case 77:
#line 276 "exptree.y"
                    {(yyval.no) = makeOperatorNode(NODE_DIV,"/",(yyvsp[-2].no),(yyvsp[0].no));(yyval.no)->type = intType;}
#line 2181 "y.tab.c"
    break;

  case 78:
#line 277 "exptree.y"
                    {(yyval.no) = makeOperatorNode(NODE_MOD,"%",(yyvsp[-2].no),(yyvsp[0].no));(yyval.no)->type = intType;}
#line 2187 "y.tab.c"
    break;

  case 79:
#line 278 "exptree.y"
                   {(yyval.no) = makeOperatorNode(NODE_LT,"<",(yyvsp[-2].no),(yyvsp[0].no)); (yyval.no)->type = boolType;}
#line 2193 "y.tab.c"
    break;

  case 80:
#line 279 "exptree.y"
                   {(yyval.no) = makeOperatorNode(NODE_GT,">",(yyvsp[-2].no),(yyvsp[0].no)); (yyval.no)->type = boolType;}
#line 2199 "y.tab.c"
    break;

  case 81:
#line 280 "exptree.y"
                   {(yyval.no) = makeOperatorNode(NODE_NE,"!=",(yyvsp[-2].no),(yyvsp[0].no)); (yyval.no)->type = boolType;}
#line 2205 "y.tab.c"
    break;

  case 82:
#line 281 "exptree.y"
                    {(yyval.no) = makeOperatorNode(NODE_LTE,"<=",(yyvsp[-2].no),(yyvsp[0].no)); (yyval.no)->type = boolType;}
#line 2211 "y.tab.c"
    break;

  case 83:
#line 282 "exptree.y"
                    {(yyval.no) = makeOperatorNode(NODE_GTE,">=",(yyvsp[-2].no),(yyvsp[0].no)); (yyval.no)->type = boolType;}
#line 2217 "y.tab.c"
    break;

  case 84:
#line 283 "exptree.y"
                   {(yyval.no) = makeOperatorNode(NODE_EQ,"==",(yyvsp[-2].no),(yyvsp[0].no)); (yyval.no)->type = boolType;}
#line 2223 "y.tab.c"
    break;

  case 85:
#line 284 "exptree.y"
                    {(yyval.no) = makeOperatorNode(NODE_AND,"&&",(yyvsp[-2].no),(yyvsp[0].no));(yyval.no)->type = boolType;}
#line 2229 "y.tab.c"
    break;

  case 86:
#line 285 "exptree.y"
                   {(yyval.no) = makeOperatorNode(NODE_OR,"||",(yyvsp[-2].no),(yyvsp[0].no));(yyval.no)->type = boolType;}
#line 2235 "y.tab.c"
    break;

  case 87:
#line 286 "exptree.y"
               {(yyval.no) = makeOperatorNode(NODE_NOT,"!",NULL,(yyvsp[0].no));(yyval.no)->type = boolType;}
#line 2241 "y.tab.c"
    break;

  case 88:
#line 287 "exptree.y"
                   {(yyval.no)=(yyvsp[-1].no);}
#line 2247 "y.tab.c"
    break;

  case 89:
#line 288 "exptree.y"
                 {(yyval.no)=(yyvsp[0].no);}
#line 2253 "y.tab.c"
    break;

  case 90:
#line 289 "exptree.y"
          {(yyval.no)=makeNumberNode(NODE_CONSTANT,(yyvsp[0].num));}
#line 2259 "y.tab.c"
    break;

  case 91:
#line 290 "exptree.y"
             {(yyval.no)=(yyvsp[0].no);}
#line 2265 "y.tab.c"
    break;

  case 92:
#line 291 "exptree.y"
                  {(yyval.no)=makeIdNode(NODE_ALLOC,"alloc",NULL,NULL);}
#line 2271 "y.tab.c"
    break;

  case 93:
#line 292 "exptree.y"
                       {(yyval.no)=makeIdNode(NODE_INITIALIZE,"initialize",NULL,NULL);}
#line 2277 "y.tab.c"
    break;

  case 94:
#line 293 "exptree.y"
                       {(yyval.no)=makeIdNode(NODE_FREE,"free",(yyvsp[-1].no),NULL);}
#line 2283 "y.tab.c"
    break;

  case 95:
#line 294 "exptree.y"
               {(yyval.no)=makeIdNode(NODE_VAR_NULL,"null",NULL,NULL);}
#line 2289 "y.tab.c"
    break;

  case 96:
#line 295 "exptree.y"
            {
               (yyval.no)=(yyvsp[0].no);
            }
#line 2297 "y.tab.c"
    break;

  case 97:
#line 300 "exptree.y"
                       {(yyval.no)=makeConnectorNode(NODE_FIELD,".",(yyvsp[-2].no),makeIdNode(NODE_FIELD_VAR,(yyvsp[0].ch),NULL,NULL));}
#line 2303 "y.tab.c"
    break;

  case 98:
#line 301 "exptree.y"
                    {(yyval.no)=makeConnectorNode(NODE_FIELD,".",makeIdNode(NODE_FIELD_VAR,(yyvsp[-2].ch),NULL,NULL),makeIdNode(NODE_FIELD_VAR,(yyvsp[0].ch),NULL,NULL));}
#line 2309 "y.tab.c"
    break;

  case 99:
#line 304 "exptree.y"
                           {(yyval.no)=makeConnectorNode(NODE_ARGLIST,".",(yyvsp[-2].no),(yyvsp[0].no));}
#line 2315 "y.tab.c"
    break;

  case 100:
#line 305 "exptree.y"
               {(yyval.no)=(yyvsp[0].no);}
#line 2321 "y.tab.c"
    break;

  case 101:
#line 308 "exptree.y"
                              {(yyval.no)=makeIdNode(NODE_VARIABLE,(yyvsp[0].ch),NULL,NULL);}
#line 2327 "y.tab.c"
    break;

  case 102:
#line 309 "exptree.y"
                              {(yyval.no)=makeIdNode(NODE_VAR_ARRAY,(yyvsp[-3].ch),(yyvsp[-1].no),NULL);}
#line 2333 "y.tab.c"
    break;

  case 103:
#line 310 "exptree.y"
                              {(yyval.no)=makeIdNode(NODE_VAR_FUNC_CALL,(yyvsp[-2].ch),NULL,NULL);}
#line 2339 "y.tab.c"
    break;

  case 104:
#line 311 "exptree.y"
                              {(yyval.no)=makeIdNode(NODE_VAR_FUNC_CALL,(yyvsp[-3].ch),(yyvsp[-1].no),NULL);}
#line 2345 "y.tab.c"
    break;


#line 2349 "y.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
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

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
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
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
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

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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


#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[+*yyssp], yyvsp);
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
  return yyresult;
}
#line 313 "exptree.y"


int yyerror(char const *s)
{
    printf("yyerror %s at line: %d: %s",s,yylineno,yytext);
    return 0;
}

int main(void)
{
    yyin=fopen("input.txt","r");
    yyparse();
    return 0;
}
