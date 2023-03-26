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
    #include "./Functions/Func_call.c"
    #include "./Functions/function.c"
    #include "./Functions/Gsymbol.c"
    #include "./Functions/Loop_func.c"
    #include "./Functions/Lsymbol.c"
    #include "./Functions/read_write_assg.c"
    #include "./Functions/var_op.c"
     
    int yylex(void);
    int yyerror();

#line 96 "y.tab.c"

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
    START = 258,
    END = 259,
    DECL = 260,
    ENDDECL = 261,
    INT = 262,
    STR = 263,
    SEMICOLON = 264,
    RETURN = 265,
    BREAKPOINT = 266,
    READ = 267,
    WRITE = 268,
    IF = 269,
    THEN = 270,
    ELSE = 271,
    ENDIF = 272,
    WHILE = 273,
    DO = 274,
    ENDWHILE = 275,
    REPEAT = 276,
    UNTIL = 277,
    BREAK = 278,
    CONTINUE = 279,
    NUM = 280,
    ID = 281,
    STRING = 282,
    OR = 283,
    AND = 284,
    GTE = 285,
    LTE = 286,
    LT = 287,
    GT = 288,
    NE = 289,
    EQ = 290,
    PLUS = 291,
    MINUS = 292,
    MUL = 293,
    DIV = 294,
    MOD = 295,
    NOT = 296,
    EQUAL = 297
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
#define RETURN 265
#define BREAKPOINT 266
#define READ 267
#define WRITE 268
#define IF 269
#define THEN 270
#define ELSE 271
#define ENDIF 272
#define WHILE 273
#define DO 274
#define ENDWHILE 275
#define REPEAT 276
#define UNTIL 277
#define BREAK 278
#define CONTINUE 279
#define NUM 280
#define ID 281
#define STRING 282
#define OR 283
#define AND 284
#define GTE 285
#define LTE 286
#define LT 287
#define GT 288
#define NE 289
#define EQ 290
#define PLUS 291
#define MINUS 292
#define MUL 293
#define DIV 294
#define MOD 295
#define NOT 296
#define EQUAL 297

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 27 "exptree.y"

    struct tnode *no;
    char* ch;
    int num;

#line 238 "y.tab.c"

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
#define YYFINAL  13
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   539

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  50
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  33
/* YYNRULES -- Number of rules.  */
#define YYNRULES  82
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  184

#define YYUNDEFTOK  2
#define YYMAXUTOK   297


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
      46,    47,     2,     2,    43,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    44,     2,    45,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    48,     2,    49,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41,    42
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    55,    55,    56,    57,    62,    63,    66,    67,    70,
      75,    76,    79,    80,    83,    84,    85,    90,    91,    94,
     101,   102,   105,   117,   129,   140,   149,   150,   153,   160,
     163,   166,   167,   170,   175,   176,   183,   188,   189,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   203,   207,
     210,   213,   214,   217,   220,   223,   226,   229,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   253,   254,   257,
     258,   259,   260
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "START", "END", "DECL", "ENDDECL", "INT",
  "STR", "SEMICOLON", "RETURN", "BREAKPOINT", "READ", "WRITE", "IF",
  "THEN", "ELSE", "ENDIF", "WHILE", "DO", "ENDWHILE", "REPEAT", "UNTIL",
  "BREAK", "CONTINUE", "NUM", "ID", "STRING", "OR", "AND", "GTE", "LTE",
  "LT", "GT", "NE", "EQ", "PLUS", "MINUS", "MUL", "DIV", "MOD", "NOT",
  "EQUAL", "','", "'['", "']'", "'('", "')'", "'{'", "'}'", "$accept",
  "program", "GDeclBlock", "DeclList", "Decl", "Type", "VarList", "IdDecl",
  "ParamList", "Param", "FdefBlock", "Fdef", "Body", "returnstmt",
  "LdeclBlock", "LDecList", "LDecl", "IdList", "MainBlock", "Slist",
  "stmt", "InputStmt", "OutputStmt", "AssgStmt", "Ifstmt", "Whilestmt",
  "dowhilestmt", "repuntilstmt", "breakstmt", "continuestmt", "expr",
  "ArgList", "Identifier", YY_NULLPTR
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
     295,   296,   297,    44,    91,    93,    40,    41,   123,   125
};
# endif

#define YYPACT_NINF (-63)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-37)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     145,    57,   -63,   -63,     3,   186,    -3,   -63,   -63,   -63,
      99,   -63,     7,   -63,   186,     4,   -63,    24,   -63,   -63,
      69,    -4,   -63,     4,   -63,    14,    72,   186,   -63,     7,
      50,   100,    -7,   -63,    82,    28,   -63,   127,   -63,   186,
      68,   -63,   -63,    55,   223,   105,   135,   -63,   127,   -63,
     -63,   103,   120,   125,   164,   251,   251,   202,   207,   -63,
     191,   -63,   279,   279,   110,   -63,   -63,   -63,   -63,   -63,
     -63,   -63,   -63,   -63,   -63,   484,   -63,   -63,   210,   226,
     -63,   -63,   124,   168,   135,   279,   279,   279,   279,   275,
     177,   -63,   -63,   279,   114,   -63,   326,   279,   239,   -63,
     279,   279,   279,   279,   279,   279,   279,   279,   279,   279,
     279,   279,   279,   279,   -63,    -1,   -63,   -63,   -63,   -63,
     200,   346,   366,   386,   406,   209,   211,   466,   -63,   499,
      71,   -63,   298,   -63,   -20,    53,   147,   147,   108,   108,
     169,   169,   119,   119,   -63,   -63,   -63,   313,   -63,   230,
     -63,   249,   250,   245,   242,   279,   279,   -63,   279,   -63,
     -63,   -63,   -63,   -63,   -63,   251,   251,   426,   446,   499,
     151,   201,    16,   257,   251,   258,   262,   -63,   -63,   227,
     -63,   -63,   270,   -63
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,    10,    11,     0,     0,     0,    36,     4,     6,
       0,     8,     0,     1,     0,    21,     3,     0,     5,     7,
      14,     0,    13,    20,     2,     0,     0,     0,     9,     0,
       0,     0,     0,    18,     0,     0,    12,     0,    19,     0,
       0,    15,    16,     0,     0,     0,     0,    17,     0,    27,
      76,     0,     0,     0,     0,     0,     0,     0,     0,    74,
      79,    75,     0,     0,     0,    38,    39,    40,    41,    42,
      43,    46,    47,    44,    45,     0,    73,    30,     0,     0,
      32,    25,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    56,    57,     0,     0,    71,     0,     0,     0,    37,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    35,     0,    29,    31,    24,    23,
       0,     0,     0,     0,     0,     0,     0,     0,    81,    78,
       0,    72,     0,    26,    70,    69,    67,    66,    63,    64,
      65,    68,    58,    59,    60,    61,    62,     0,    33,     0,
      22,     0,     0,     0,     0,     0,     0,    80,     0,    82,
      28,    50,    34,    48,    49,     0,     0,     0,     0,    77,
       0,     0,     0,     0,     0,     0,     0,    54,    55,     0,
      52,    53,     0,    51
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -63,   -63,   -63,   -63,   271,    33,   -63,   253,   256,   241,
     -63,    89,   -22,   -63,   236,   -63,   206,   -63,    90,   -55,
     -62,   -63,   -63,   -63,   -63,   -63,   -63,   -63,   -63,   -63,
     -56,   -63,   -63
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     4,     5,    10,    11,     6,    21,    22,    32,    33,
      14,     7,    45,    98,    46,    79,    80,   115,     8,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,   130,    76
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      89,    90,    99,    13,   -36,    28,    95,    96,   148,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,     2,     3,    17,    82,   177,    83,    99,    99,   121,
     122,   123,   124,    20,    12,   166,    39,   127,   129,    29,
      40,   132,   149,    12,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,    31,    49,
      31,    30,   120,     9,     2,     3,    50,    51,    52,    53,
      25,    39,    31,    54,    55,    42,    56,    78,    57,    58,
      59,    60,    61,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,    15,    16,    62,    34,    37,   167,
     168,    63,   169,    23,    24,    18,     2,     3,    99,    99,
     170,   171,    78,    26,   158,    27,    48,    99,   159,   179,
      97,    50,    51,    52,    53,    50,    38,    41,    54,    55,
      43,    56,    44,    57,    58,    59,    60,    61,    43,    59,
      60,    61,   106,   107,   108,   109,   110,   111,   112,    85,
       1,    62,     2,     3,    81,    62,    63,   110,   111,   112,
      63,   128,    50,    51,    52,    53,    86,   174,   175,    54,
      55,    87,    56,   118,    57,    58,    59,    60,    61,   104,
     105,   106,   107,   108,   109,   110,   111,   112,    50,    51,
      52,    53,    62,     2,     3,    54,    55,    63,    56,   126,
      57,    58,    59,    60,    61,   108,   109,   110,   111,   112,
      88,    91,    50,    51,    52,    53,    92,   119,    62,    54,
      55,   176,    56,    63,    57,    58,    59,    60,    61,    77,
       2,     3,   116,     2,     3,    93,   114,    94,    50,    51,
      52,    53,    62,   133,   182,    54,    55,    63,    56,   150,
      57,    58,    59,    60,    61,   155,   162,   156,   163,   164,
     165,   166,    50,    51,    52,    53,   178,   180,    62,    54,
      55,   181,    56,    63,    57,    58,    59,    60,    61,   183,
      47,    19,    36,    35,    84,   117,    50,    51,    52,    53,
      50,     0,    62,   125,    55,     0,    56,    63,    57,    58,
      59,    60,    61,     0,    59,    60,    61,   160,     0,     0,
       0,     0,     0,     0,     0,     0,    62,     0,     0,     0,
      62,    63,   161,     0,     0,    63,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,     0,
       0,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,     0,     0,     0,
       0,     0,     0,   131,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,     0,     0,     0,
       0,     0,     0,   151,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,     0,     0,     0,
       0,     0,     0,   152,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,     0,     0,     0,
       0,     0,     0,   153,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,     0,     0,     0,
       0,     0,     0,   154,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,     0,     0,     0,
       0,     0,     0,   172,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,     0,     0,     0,
       0,     0,     0,   173,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,     0,     0,     0,
       0,   157,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,     0,   113,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112
};

static const yytype_int16 yycheck[] =
{
      55,    56,    64,     0,     0,     9,    62,    63,     9,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,     7,     8,    26,    46,     9,    48,    89,    90,    85,
      86,    87,    88,    26,     1,    19,    43,    93,    94,    43,
      47,    97,    43,    10,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,    25,     4,
      27,    47,    84,     6,     7,     8,    11,    12,    13,    14,
      46,    43,    39,    18,    19,    47,    21,    44,    23,    24,
      25,    26,    27,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,     5,     5,    41,    25,    48,   155,
     156,    46,   158,    14,    14,     6,     7,     8,   170,   171,
     165,   166,    79,    44,    43,    46,    48,   179,    47,   174,
      10,    11,    12,    13,    14,    11,    26,    45,    18,    19,
       3,    21,     5,    23,    24,    25,    26,    27,     3,    25,
      26,    27,    34,    35,    36,    37,    38,    39,    40,    46,
       5,    41,     7,     8,    49,    41,    46,    38,    39,    40,
      46,    47,    11,    12,    13,    14,    46,    16,    17,    18,
      19,    46,    21,    49,    23,    24,    25,    26,    27,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    11,    12,
      13,    14,    41,     7,     8,    18,    19,    46,    21,    22,
      23,    24,    25,    26,    27,    36,    37,    38,    39,    40,
      46,     9,    11,    12,    13,    14,     9,    49,    41,    18,
      19,    20,    21,    46,    23,    24,    25,    26,    27,     6,
       7,     8,     6,     7,     8,    44,    26,    46,    11,    12,
      13,    14,    41,     4,    17,    18,    19,    46,    21,    49,
      23,    24,    25,    26,    27,    46,    26,    46,     9,     9,
      15,    19,    11,    12,    13,    14,     9,     9,    41,    18,
      19,     9,    21,    46,    23,    24,    25,    26,    27,     9,
      39,    10,    29,    27,    48,    79,    11,    12,    13,    14,
      11,    -1,    41,    18,    19,    -1,    21,    46,    23,    24,
      25,    26,    27,    -1,    25,    26,    27,     9,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    41,    -1,    -1,    -1,
      41,    46,     9,    -1,    -1,    46,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    -1,
      -1,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    -1,    -1,    -1,
      -1,    -1,    -1,    47,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    -1,    -1,    -1,
      -1,    -1,    -1,    47,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    -1,    -1,    -1,
      -1,    -1,    -1,    47,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    -1,    -1,    -1,
      -1,    -1,    -1,    47,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    -1,    -1,    -1,
      -1,    -1,    -1,    47,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    -1,    -1,    -1,
      -1,    -1,    -1,    47,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    -1,    -1,    -1,
      -1,    -1,    -1,    47,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    -1,    -1,    -1,
      -1,    45,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    -1,    42,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     5,     7,     8,    51,    52,    55,    61,    68,     6,
      53,    54,    55,     0,    60,    61,    68,    26,     6,    54,
      26,    56,    57,    61,    68,    46,    44,    46,     9,    43,
      47,    55,    58,    59,    25,    58,    57,    48,    26,    43,
      47,    45,    47,     3,     5,    62,    64,    59,    48,     4,
      11,    12,    13,    14,    18,    19,    21,    23,    24,    25,
      26,    27,    41,    46,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    82,     6,    55,    65,
      66,    49,    62,    62,    64,    46,    46,    46,    46,    69,
      69,     9,     9,    44,    46,    80,    80,    10,    63,    70,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    42,    26,    67,     6,    66,    49,    49,
      62,    80,    80,    80,    80,    18,    22,    80,    47,    80,
      81,    47,    80,     4,    80,    80,    80,    80,    80,    80,
      80,    80,    80,    80,    80,    80,    80,    80,     9,    43,
      49,    47,    47,    47,    47,    46,    46,    45,    43,    47,
       9,     9,    26,     9,     9,    15,    19,    80,    80,    80,
      69,    69,    47,    47,    16,    17,    20,     9,     9,    69,
       9,     9,    17,     9
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    50,    51,    51,    51,    52,    52,    53,    53,    54,
      55,    55,    56,    56,    57,    57,    57,    58,    58,    59,
      60,    60,    61,    61,    61,    61,    62,    62,    63,    64,
      64,    65,    65,    66,    67,    67,    68,    69,    69,    70,
      70,    70,    70,    70,    70,    70,    70,    70,    71,    72,
      73,    74,    74,    75,    76,    77,    78,    79,    80,    80,
      80,    80,    80,    80,    80,    80,    80,    80,    80,    80,
      80,    80,    80,    80,    80,    80,    80,    81,    81,    82,
      82,    82,    82
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     3,     2,     1,     3,     2,     2,     1,     3,
       1,     1,     3,     1,     1,     4,     4,     3,     1,     2,
       2,     1,     9,     8,     8,     7,     4,     2,     3,     3,
       2,     2,     1,     3,     3,     1,     1,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     5,     5,
       4,    10,     8,     8,     7,     7,     2,     2,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     2,     3,     1,     1,     1,     1,     3,     1,     1,
       4,     3,     4
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
#line 55 "exptree.y"
                                         {codegenerator((yyvsp[-1].no),(yyvsp[0].no));}
#line 1608 "y.tab.c"
    break;

  case 3:
#line 56 "exptree.y"
                               {codegenerator(NULL,(yyvsp[0].no));}
#line 1614 "y.tab.c"
    break;

  case 4:
#line 57 "exptree.y"
                     {codegenerator(NULL,(yyvsp[0].no));}
#line 1620 "y.tab.c"
    break;

  case 5:
#line 62 "exptree.y"
                                   {(yyval.no)=(yyvsp[-1].no);}
#line 1626 "y.tab.c"
    break;

  case 6:
#line 63 "exptree.y"
                          {}
#line 1632 "y.tab.c"
    break;

  case 7:
#line 66 "exptree.y"
                         {(yyval.no)=makeDeclNode(NODE_CONNECTOR,(yyvsp[-1].no),(yyvsp[0].no));}
#line 1638 "y.tab.c"
    break;

  case 8:
#line 67 "exptree.y"
                {(yyval.no)=(yyvsp[0].no);}
#line 1644 "y.tab.c"
    break;

  case 9:
#line 70 "exptree.y"
                              {(yyval.no)=makeDataTypeNode((yyvsp[-2].num),(yyvsp[-1].no));
                               GsymbolEntry((yyvsp[-2].num),(yyvsp[-1].no));
                               }
#line 1652 "y.tab.c"
    break;

  case 10:
#line 75 "exptree.y"
           {(yyval.num)=(yyvsp[0].num);}
#line 1658 "y.tab.c"
    break;

  case 11:
#line 76 "exptree.y"
           {(yyval.num)=(yyvsp[0].num);}
#line 1664 "y.tab.c"
    break;

  case 12:
#line 79 "exptree.y"
                             {(yyval.no)=makeDeclNode(NODE_CONNECTOR,(yyvsp[-2].no),(yyvsp[0].no));}
#line 1670 "y.tab.c"
    break;

  case 13:
#line 80 "exptree.y"
                 {(yyval.no)=(yyvsp[0].no);}
#line 1676 "y.tab.c"
    break;

  case 14:
#line 83 "exptree.y"
            {(yyval.no)=makeIdNodeDecl(NODE_VARIABLE,(yyvsp[0].ch),0,NULL);}
#line 1682 "y.tab.c"
    break;

  case 15:
#line 84 "exptree.y"
                        {(yyval.no)=makeIdNodeDecl(NODE_VAR_ARRAY,(yyvsp[-3].ch),(yyvsp[-1].num),NULL);}
#line 1688 "y.tab.c"
    break;

  case 16:
#line 85 "exptree.y"
                              {
                                (yyval.no)=makeIdNodeDecl(NODE_VAR_PARAMLIST,(yyvsp[-3].ch),0,(yyvsp[-1].no));
                              }
#line 1696 "y.tab.c"
    break;

  case 17:
#line 90 "exptree.y"
                                {(yyval.no)=makeDeclNode(NODE_CONNECTOR,(yyvsp[-2].no),(yyvsp[0].no));}
#line 1702 "y.tab.c"
    break;

  case 18:
#line 91 "exptree.y"
                   {(yyval.no)=(yyvsp[0].no);}
#line 1708 "y.tab.c"
    break;

  case 19:
#line 94 "exptree.y"
                {(yyval.no)=makeParamNode(NODE_PARAM,(yyvsp[-1].num),makeIdNodeDecl(NODE_PARAM_VARIABLE,(yyvsp[0].ch),0,NULL));}
#line 1714 "y.tab.c"
    break;

  case 20:
#line 101 "exptree.y"
                           {(yyval.no)=makeFuncConnectorNode(NODE_CONNECTOR,(yyvsp[-1].no),(yyvsp[0].no));}
#line 1720 "y.tab.c"
    break;

  case 21:
#line 102 "exptree.y"
                 {(yyval.no)=(yyvsp[0].no);}
#line 1726 "y.tab.c"
    break;

  case 22:
#line 105 "exptree.y"
                                                      {
                                                          struct tnode *temp1 = makeFuncTypeNode((yyvsp[-8].num));
                                                          struct tnode *temp2 = makeFuncConnectorNode(NODE_CONNECTOR,(yyvsp[-2].no),(yyvsp[-1].no));
                                                          struct tnode *temp3 = makeFuncConnectorNode(NODE_CONNECTOR,(yyvsp[-5].no),temp2); 
                                                          struct tnode *temp4 = makeFuncIdNode(NODE_FUNCTION,(yyvsp[-7].ch),temp1,temp3);

                                                          (yyval.no) = temp4;

                                                          struct Lsymbol *temp =  LsymbolEntry((yyvsp[-5].no),(yyvsp[-2].no));

                                                          LinkLocalTable(temp,(yyvsp[-1].no));    
                                                       }
#line 1743 "y.tab.c"
    break;

  case 23:
#line 117 "exptree.y"
                                            {
                                                          struct tnode *temp1 = makeFuncTypeNode((yyvsp[-7].num));
                                                          struct tnode *temp2 = makeFuncConnectorNode(NODE_CONNECTOR,NULL,(yyvsp[-1].no));
                                                          struct tnode *temp3 = makeFuncConnectorNode(NODE_CONNECTOR,(yyvsp[-4].no),temp2);

                                                          struct tnode *temp4 = makeFuncIdNode(NODE_FUNCTION,(yyvsp[-6].ch),temp1,temp3);
                                                          
                                                          (yyval.no) = temp4;

                                                          struct Lsymbol *temp =  LsymbolEntry((yyvsp[-4].no),NULL);
                                                          LinkLocalTable(temp,(yyvsp[-1].no));
                                            }
#line 1760 "y.tab.c"
    break;

  case 24:
#line 129 "exptree.y"
                                              {
                                                          struct tnode *temp1 = makeFuncTypeNode((yyvsp[-7].num));
                                                          struct tnode *temp2 = makeFuncConnectorNode(NODE_CONNECTOR,(yyvsp[-2].no),(yyvsp[-1].no));
                                                          struct tnode *temp3 = makeFuncConnectorNode(NODE_CONNECTOR,NULL,temp2);
                                                          struct tnode *temp4 = makeFuncIdNode(NODE_FUNCTION,(yyvsp[-6].ch),temp1,temp3);

                                                          (yyval.no) = temp4;

                                                          struct Lsymbol *temp =  LsymbolEntry(NULL,(yyvsp[-2].no));
                                                          LinkLocalTable(temp,(yyvsp[-1].no));
                                               }
#line 1776 "y.tab.c"
    break;

  case 25:
#line 140 "exptree.y"
                                   {
                                                          struct tnode *temp1 = makeFuncTypeNode((yyvsp[-6].num));
                                                          struct tnode *temp2 = makeFuncConnectorNode(NODE_CONNECTOR,NULL,(yyvsp[-1].no));
                                                          struct tnode *temp3 = makeFuncConnectorNode(NODE_CONNECTOR,NULL,temp2);

                                                          (yyval.no) = makeFuncIdNode(NODE_FUNCTION,(yyvsp[-5].ch),temp1,temp3);
                                   }
#line 1788 "y.tab.c"
    break;

  case 26:
#line 149 "exptree.y"
                                  {(yyval.no)=makeFuncConnectorNode(NODE_CONNECTOR,(yyvsp[-2].no),(yyvsp[-1].no));}
#line 1794 "y.tab.c"
    break;

  case 27:
#line 150 "exptree.y"
                 {}
#line 1800 "y.tab.c"
    break;

  case 28:
#line 153 "exptree.y"
                                   {(yyval.no)=makeReturnNode(NODE_RETURN,(yyvsp[-1].no));}
#line 1806 "y.tab.c"
    break;

  case 29:
#line 160 "exptree.y"
                                   {
                                    (yyval.no)=(yyvsp[-1].no);
                                    }
#line 1814 "y.tab.c"
    break;

  case 30:
#line 163 "exptree.y"
                          {}
#line 1820 "y.tab.c"
    break;

  case 31:
#line 166 "exptree.y"
                          {(yyval.no)=makeLDeclConnectorNode(NODE_LCONNECTOR,(yyvsp[-1].no),(yyvsp[0].no));}
#line 1826 "y.tab.c"
    break;

  case 32:
#line 167 "exptree.y"
                 {(yyval.no)=(yyvsp[0].no);}
#line 1832 "y.tab.c"
    break;

  case 33:
#line 170 "exptree.y"
                              {
                               (yyval.no)=makeLDeclTypeNode((yyvsp[-2].num),(yyvsp[-1].no));
                               }
#line 1840 "y.tab.c"
    break;

  case 34:
#line 175 "exptree.y"
                       {(yyval.no)=makeLDeclConnectorNode(NODE_CONNECTOR,(yyvsp[-2].no),makeLDeclIdNode(NODE_VARIABLE,(yyvsp[0].ch)));}
#line 1846 "y.tab.c"
    break;

  case 35:
#line 176 "exptree.y"
            {(yyval.no)=makeLDeclIdNode(NODE_VARIABLE,(yyvsp[0].ch));}
#line 1852 "y.tab.c"
    break;

  case 36:
#line 183 "exptree.y"
                 {(yyval.no)=(yyvsp[0].no);}
#line 1858 "y.tab.c"
    break;

  case 37:
#line 188 "exptree.y"
                   {(yyval.no)=makeConnectorNode(NODE_CONNECTOR,".",(yyvsp[-1].no),(yyvsp[0].no));}
#line 1864 "y.tab.c"
    break;

  case 38:
#line 189 "exptree.y"
             {(yyval.no)=(yyvsp[0].no);}
#line 1870 "y.tab.c"
    break;

  case 39:
#line 192 "exptree.y"
                 {(yyval.no)=(yyvsp[0].no);}
#line 1876 "y.tab.c"
    break;

  case 40:
#line 193 "exptree.y"
                  {(yyval.no)=(yyvsp[0].no);}
#line 1882 "y.tab.c"
    break;

  case 41:
#line 194 "exptree.y"
                {(yyval.no)=(yyvsp[0].no);}
#line 1888 "y.tab.c"
    break;

  case 42:
#line 195 "exptree.y"
              {(yyval.no)=(yyvsp[0].no);}
#line 1894 "y.tab.c"
    break;

  case 43:
#line 196 "exptree.y"
                 {(yyval.no)=(yyvsp[0].no);}
#line 1900 "y.tab.c"
    break;

  case 44:
#line 197 "exptree.y"
                 {(yyval.no)=(yyvsp[0].no);}
#line 1906 "y.tab.c"
    break;

  case 45:
#line 198 "exptree.y"
                    {(yyval.no)=(yyvsp[0].no);}
#line 1912 "y.tab.c"
    break;

  case 46:
#line 199 "exptree.y"
                   {(yyval.no)=(yyvsp[0].no);}
#line 1918 "y.tab.c"
    break;

  case 47:
#line 200 "exptree.y"
                    {(yyval.no)=(yyvsp[0].no);}
#line 1924 "y.tab.c"
    break;

  case 48:
#line 203 "exptree.y"
                                       {(yyval.no)=makereadNode(NODE_READ,(yyvsp[-2].no));}
#line 1930 "y.tab.c"
    break;

  case 49:
#line 207 "exptree.y"
                                         {(yyval.no)=makewriteNode(NODE_WRITE,(yyvsp[-2].no));}
#line 1936 "y.tab.c"
    break;

  case 50:
#line 210 "exptree.y"
                                     {(yyval.no)=makeOperatorNode(NODE_ASSG_EQ,"=",(yyvsp[-3].no),(yyvsp[-1].no));}
#line 1942 "y.tab.c"
    break;

  case 51:
#line 213 "exptree.y"
                                                              {(yyval.no)=makeIfNode(NODE_IF,(yyvsp[-7].no),(yyvsp[-4].no),(yyvsp[-2].no));}
#line 1948 "y.tab.c"
    break;

  case 52:
#line 214 "exptree.y"
                                                   {(yyval.no)=makeIfNode(NODE_IF,(yyvsp[-5].no),(yyvsp[-2].no),NULL);}
#line 1954 "y.tab.c"
    break;

  case 53:
#line 217 "exptree.y"
                                                          {(yyval.no)=makeWhileNode(NODE_WHILE,(yyvsp[-5].no),(yyvsp[-2].no));}
#line 1960 "y.tab.c"
    break;

  case 54:
#line 220 "exptree.y"
                                                   {(yyval.no)=makedowhileNode(NODE_DO,(yyvsp[-5].no),(yyvsp[-2].no));}
#line 1966 "y.tab.c"
    break;

  case 55:
#line 223 "exptree.y"
                                                        {(yyval.no)=makerepuntilNode(NODE_REPEAT,(yyvsp[-5].no),(yyvsp[-2].no));}
#line 1972 "y.tab.c"
    break;

  case 56:
#line 226 "exptree.y"
                            {(yyval.no)=makebreakNode(NODE_BREAK);}
#line 1978 "y.tab.c"
    break;

  case 57:
#line 229 "exptree.y"
                                  {(yyval.no)=makecontNode(NODE_CONTINUE);}
#line 1984 "y.tab.c"
    break;

  case 58:
#line 232 "exptree.y"
                      {(yyval.no) = makeOperatorNode(NODE_ADD,"+",(yyvsp[-2].no),(yyvsp[0].no));(yyval.no)->type = intType;}
#line 1990 "y.tab.c"
    break;

  case 59:
#line 233 "exptree.y"
                      {(yyval.no) = makeOperatorNode(NODE_SUB,"-",(yyvsp[-2].no),(yyvsp[0].no));(yyval.no)->type = intType;}
#line 1996 "y.tab.c"
    break;

  case 60:
#line 234 "exptree.y"
                    {(yyval.no) = makeOperatorNode(NODE_MUL,"*",(yyvsp[-2].no),(yyvsp[0].no)); (yyval.no)->type = intType;}
#line 2002 "y.tab.c"
    break;

  case 61:
#line 235 "exptree.y"
                    {(yyval.no) = makeOperatorNode(NODE_DIV,"/",(yyvsp[-2].no),(yyvsp[0].no));(yyval.no)->type = intType;}
#line 2008 "y.tab.c"
    break;

  case 62:
#line 236 "exptree.y"
                    {(yyval.no) = makeOperatorNode(NODE_MOD,"%",(yyvsp[-2].no),(yyvsp[0].no));(yyval.no)->type = intType;}
#line 2014 "y.tab.c"
    break;

  case 63:
#line 237 "exptree.y"
                   {(yyval.no) = makeOperatorNode(NODE_LT,"<",(yyvsp[-2].no),(yyvsp[0].no)); (yyval.no)->type = booltype;}
#line 2020 "y.tab.c"
    break;

  case 64:
#line 238 "exptree.y"
                   {(yyval.no) = makeOperatorNode(NODE_GT,">",(yyvsp[-2].no),(yyvsp[0].no)); (yyval.no)->type = booltype;}
#line 2026 "y.tab.c"
    break;

  case 65:
#line 239 "exptree.y"
                   {(yyval.no) = makeOperatorNode(NODE_NE,"!=",(yyvsp[-2].no),(yyvsp[0].no)); (yyval.no)->type = booltype;}
#line 2032 "y.tab.c"
    break;

  case 66:
#line 240 "exptree.y"
                    {(yyval.no) = makeOperatorNode(NODE_LTE,"<=",(yyvsp[-2].no),(yyvsp[0].no)); (yyval.no)->type = booltype;}
#line 2038 "y.tab.c"
    break;

  case 67:
#line 241 "exptree.y"
                    {(yyval.no) = makeOperatorNode(NODE_GTE,">=",(yyvsp[-2].no),(yyvsp[0].no)); (yyval.no)->type = booltype;}
#line 2044 "y.tab.c"
    break;

  case 68:
#line 242 "exptree.y"
                   {(yyval.no) = makeOperatorNode(NODE_EQ,"==",(yyvsp[-2].no),(yyvsp[0].no)); (yyval.no)->type = booltype;}
#line 2050 "y.tab.c"
    break;

  case 69:
#line 243 "exptree.y"
                    {(yyval.no) = makeOperatorNode(NODE_AND,"&&",(yyvsp[-2].no),(yyvsp[0].no));(yyval.no)->type = booltype;}
#line 2056 "y.tab.c"
    break;

  case 70:
#line 244 "exptree.y"
                   {(yyval.no) = makeOperatorNode(NODE_OR,"||",(yyvsp[-2].no),(yyvsp[0].no));(yyval.no)->type = booltype;}
#line 2062 "y.tab.c"
    break;

  case 71:
#line 245 "exptree.y"
               {(yyval.no) = makeOperatorNode(NODE_NOT,"!",NULL,(yyvsp[0].no));(yyval.no)->type = booltype;}
#line 2068 "y.tab.c"
    break;

  case 72:
#line 246 "exptree.y"
                   {(yyval.no)=(yyvsp[-1].no);}
#line 2074 "y.tab.c"
    break;

  case 73:
#line 247 "exptree.y"
                 {(yyval.no)=(yyvsp[0].no);}
#line 2080 "y.tab.c"
    break;

  case 74:
#line 248 "exptree.y"
          {(yyval.no)=makeNumberNode(NODE_CONSTANT,(yyvsp[0].num));}
#line 2086 "y.tab.c"
    break;

  case 75:
#line 249 "exptree.y"
             {(yyval.no)=(yyvsp[0].no);}
#line 2092 "y.tab.c"
    break;

  case 76:
#line 250 "exptree.y"
                 {(yyval.no)=makeIdNode(NODE_BREAK_POINT,(yyvsp[0].ch),NULL,NULL);}
#line 2098 "y.tab.c"
    break;

  case 77:
#line 253 "exptree.y"
                           {(yyval.no)=makeConnectorNode(NODE_ARGLIST,".",(yyvsp[-2].no),(yyvsp[0].no));}
#line 2104 "y.tab.c"
    break;

  case 78:
#line 254 "exptree.y"
               {(yyval.no)=(yyvsp[0].no);}
#line 2110 "y.tab.c"
    break;

  case 79:
#line 257 "exptree.y"
                              {(yyval.no)=makeIdNode(NODE_VARIABLE,(yyvsp[0].ch),NULL,NULL);}
#line 2116 "y.tab.c"
    break;

  case 80:
#line 258 "exptree.y"
                              {(yyval.no)=makeIdNode(NODE_VAR_ARRAY,(yyvsp[-3].ch),(yyvsp[-1].no),NULL);}
#line 2122 "y.tab.c"
    break;

  case 81:
#line 259 "exptree.y"
                              {(yyval.no)=makeIdNode(NODE_VAR_FUNC_CALL,(yyvsp[-2].ch),NULL,NULL);}
#line 2128 "y.tab.c"
    break;

  case 82:
#line 260 "exptree.y"
                              {(yyval.no)=makeIdNode(NODE_VAR_FUNC_CALL,(yyvsp[-3].ch),(yyvsp[-1].no),NULL);}
#line 2134 "y.tab.c"
    break;


#line 2138 "y.tab.c"

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
#line 262 "exptree.y"


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
