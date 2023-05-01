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
    #include "./Functions/class.c"
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

    struct Classtable *Cptr;
    struct Typetable *Tptr;
    char *Gname;
    struct Paramstruct *paramptr = NULL;
    struct Fieldlist *typefieldlist = NULL;

#line 105 "y.tab.c"

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

#line 271 "y.tab.c"

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
typedef yytype_int16 yy_state_t;

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
#define YYFINAL  30
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   762

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  62
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  53
/* YYNRULES -- Number of rules.  */
#define YYNRULES  134
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  300

#define YYUNDEFTOK  2
#define YYMAXUTOK   309


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
      57,    58,     2,     2,    59,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    60,     2,    61,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    55,     2,    56,     2,     2,     2,     2,
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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    67,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    83,    84,    87,    88,    91,    94,
     100,   101,   104,   107,   108,   109,   117,   118,   120,   121,
     124,   125,   128,   131,   132,   135,   138,   139,   142,   145,
     148,   151,   152,   153,   156,   157,   158,   161,   162,   163,
     172,   173,   176,   177,   180,   183,   186,   187,   190,   191,
     192,   195,   196,   199,   206,   207,   210,   222,   234,   246,
     255,   256,   259,   266,   269,   272,   273,   276,   281,   282,
     289,   294,   295,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   311,   315,   318,   321,   322,   325,
     328,   331,   334,   337,   340,   343,   344,   345,   346,   347,
     348,   349,   350,   351,   352,   353,   354,   355,   356,   357,
     358,   359,   360,   361,   362,   363,   364,   365,   366,   373,
     374,   377,   378,   379,   380
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TYPE", "ENDTYPE", "ALLOC", "INITIALIZE",
  "FREE", "VAR_NULL", "CLASS", "ENDCLASS", "SELF", "NEW", "DELETE",
  "START", "END", "DECL", "ENDDECL", "INT", "STR", "SEMICOLON", "RETURN",
  "BREAKPOINT", "POINT", "READ", "WRITE", "IF", "THEN", "ELSE", "ENDIF",
  "WHILE", "DO", "ENDWHILE", "REPEAT", "UNTIL", "BREAK", "CONTINUE", "NUM",
  "ID", "STRING", "OR", "AND", "GTE", "LTE", "LT", "GT", "NE", "EQ",
  "PLUS", "MINUS", "MUL", "DIV", "MOD", "NOT", "EQUAL", "'{'", "'}'",
  "'('", "')'", "','", "'['", "']'", "$accept", "program", "TypeDefBlock",
  "TypeDefList", "TypeDef", "TName", "FieldDecList", "FieldDecL",
  "TypeName", "ClassDefBlock", "ClassDefList", "ClassDef", "Cname",
  "Fieldlists", "Fld", "MethodDecl", "MDecl", "MethodDefns", "classstmt",
  "classField", "classFieldFunction", "GDeclBlock", "DeclList", "Decl",
  "GDeclTypeName", "VarList", "IdDecl", "ParamList", "Param", "FdefBlock",
  "Fdef", "Body", "returnstmt", "LdeclBlock", "LDecList", "LDecl",
  "IdList", "MainBlock", "Slist", "stmt", "InputStmt", "OutputStmt",
  "AssgStmt", "Ifstmt", "Whilestmt", "dowhilestmt", "repuntilstmt",
  "breakstmt", "continuestmt", "breakpointstmt", "expr", "ArgList",
  "Identifier", YY_NULLPTR
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
     305,   306,   307,   308,   309,   123,   125,    40,    41,    44,
      91,    93
};
# endif

#define YYPACT_NINF (-125)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-81)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     164,     8,    30,    62,  -125,  -125,  -125,    31,   443,     0,
    -125,   137,   137,   125,  -125,  -125,  -125,    65,  -125,    80,
    -125,  -125,    91,  -125,    83,  -125,  -125,   188,  -125,    24,
    -125,  -125,   137,   137,  -125,    87,   137,  -125,   125,  -125,
    -125,  -125,   137,  -125,  -125,   141,  -125,  -125,   -44,   -15,
    -125,   137,  -125,  -125,     7,  -125,    40,  -125,   121,   137,
     137,   127,  -125,    24,  -125,   123,   128,   -36,  -125,  -125,
    -125,   159,   149,   137,  -125,    18,   134,  -125,   118,  -125,
     154,   137,  -125,   169,   158,  -125,   413,  -125,  -125,  -125,
     115,   436,   157,   204,   118,  -125,  -125,    10,    86,   182,
    -125,   170,   183,   184,  -125,   219,   189,   193,  -125,   231,
     195,   198,   200,   206,   367,   367,   248,   249,  -125,    76,
    -125,   438,   438,  -125,   250,  -125,   223,  -125,  -125,  -125,
    -125,  -125,  -125,  -125,  -125,  -125,  -125,  -125,   458,  -125,
    -125,   236,   446,  -125,  -125,   221,   222,   204,    15,  -125,
     226,   137,  -125,   218,   228,   229,   438,   241,   253,   120,
    -125,   438,   438,   438,   438,   403,   259,  -125,  -125,   261,
      13,   438,  -125,   526,   266,   438,   273,  -125,  -125,   438,
     438,   438,   438,   438,   438,   438,   438,   438,   438,   438,
     438,   438,   438,  -125,    -3,  -125,  -125,  -125,  -125,   254,
     285,   111,  -125,  -125,  -125,  -125,   545,   252,   255,   288,
     291,    14,   564,   583,   602,   621,   258,   265,   267,  -125,
     678,   142,   504,  -125,   272,   473,  -125,   690,   701,   710,
     710,   420,   420,   437,   437,    34,    34,  -125,  -125,  -125,
     491,  -125,   280,  -125,  -125,   303,  -125,   438,   315,   302,
     307,   308,   321,   327,   329,   323,   320,   438,   438,   438,
    -125,   438,  -125,   438,  -125,  -125,  -125,  -125,   145,  -125,
    -125,  -125,  -125,  -125,  -125,  -125,   367,   367,   640,   659,
     174,   678,   179,  -125,   186,   295,    44,   334,  -125,  -125,
     367,   338,   339,  -125,  -125,   331,  -125,  -125,   343,  -125
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,    23,    24,    25,     0,    10,     0,
      11,     0,     0,    65,     9,    15,    19,     0,    17,     0,
      27,    32,     0,    29,     0,    51,    55,     0,    53,     0,
       1,    13,    12,     0,     5,     0,     0,     7,    64,     8,
      14,    16,     0,    26,    28,     0,    50,    52,    58,     0,
      57,     0,     3,     4,     0,     6,     0,    21,     0,     0,
       0,     0,    54,     0,     2,     0,     0,     0,    62,    18,
      20,     0,     0,     0,    34,     0,     0,    56,     0,    63,
       0,     0,    22,     0,     0,    33,     0,    37,    60,    59,
       0,     0,     0,     0,     0,    61,    35,     0,     0,     0,
      36,     0,     0,     0,   126,     0,     0,     0,    71,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   121,   131,
     122,     0,     0,    93,   127,   128,     0,    82,    83,    84,
      85,    86,    87,    91,    92,    88,    89,    90,     0,   120,
      74,     0,     0,    76,    69,     0,     0,     0,     0,    31,
       0,    40,    65,     0,     0,     0,     0,     0,     0,     0,
     104,     0,     0,     0,     0,     0,     0,   102,   103,     0,
       0,     0,   118,     0,     0,     0,     0,    81,    41,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    79,     0,    73,    75,    68,    67,     0,
       0,     0,    30,    64,   123,   124,     0,    44,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    46,   133,
     130,     0,     0,   119,    45,     0,    70,   117,   116,   114,
     113,   110,   111,   112,   115,   105,   106,   107,   108,   109,
       0,    77,     0,    66,    39,     0,   125,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     134,     0,   132,     0,    72,    96,    78,    38,     0,    42,
      44,    46,    45,    43,    94,    95,     0,     0,     0,     0,
       0,   129,     0,    47,     0,     0,     0,     0,    48,    49,
       0,     0,     0,   100,   101,     0,    98,    99,     0,    97
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -125,  -125,  -125,  -125,   348,  -125,  -125,   325,     1,   363,
    -125,   354,  -125,  -125,   304,  -125,   296,  -125,  -125,   224,
    -125,   377,  -125,   359,  -125,  -125,   324,   -53,   309,    -5,
      -4,   -84,  -125,   300,  -125,   257,  -125,     3,  -114,  -124,
    -125,  -125,  -125,  -125,  -125,  -125,  -125,  -125,  -125,  -125,
     -73,   -82,  -125
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     7,     8,    17,    18,    19,    56,    57,     9,    10,
      22,    23,    24,    73,    74,    86,    87,   150,   123,   124,
     125,    11,    27,    28,    29,    49,    50,    67,    68,    12,
      13,    92,   176,    93,   142,   143,   194,    14,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   221,   139
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     165,   166,   177,    33,    26,    62,    36,    75,    38,   145,
     146,    34,    15,    60,    37,    39,    61,   241,   101,   102,
     103,   104,    80,    81,   105,     4,     5,    51,    26,    38,
      96,    30,    38,     4,     5,    52,    53,   251,    35,    55,
      20,   177,   177,    58,    63,     6,    16,    38,   172,   173,
     118,   119,   120,     6,    64,    66,   242,    58,     4,     5,
      72,    66,    48,   199,   293,    65,   121,   148,    21,    40,
     122,   219,   252,   200,    84,   277,    88,    81,     6,    25,
       4,     5,    66,   206,   189,   190,   191,    99,   212,   213,
     214,   215,   141,   151,   152,   201,    69,   220,   222,   169,
       6,    43,   225,    16,     4,     5,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     101,   102,   103,   104,     6,   -80,   105,   106,   107,    21,
     108,   209,    90,   170,    91,    42,   171,   109,    45,   110,
     111,   112,   149,   141,    54,   113,   114,   203,   115,    66,
     116,   117,   118,   119,   120,     4,     5,    59,   210,    71,
     177,   177,   284,   285,    76,   268,    79,     1,   121,   245,
      81,   177,   122,     2,   220,     6,   295,   280,    78,    82,
       3,   282,     4,     5,   278,   279,   220,    83,   281,    96,
     220,   101,   102,   103,   104,    89,    97,   105,   106,   107,
     260,   261,     6,   283,   261,    46,     4,     5,   109,    94,
     110,   111,   112,   144,   290,   291,   113,   114,    90,   115,
     153,   116,   117,   118,   119,   120,     6,   154,   101,   102,
     103,   104,   288,   261,   105,   106,   107,   289,   261,   121,
     155,   156,   157,   122,   175,   109,   158,   110,   111,   112,
     159,   160,   161,   113,   114,   162,   115,   163,   116,   117,
     118,   119,   120,   164,   101,   102,   103,   104,   167,   168,
     105,   106,   107,   174,   193,   148,   121,   197,   198,   207,
     122,   109,   202,   110,   111,   112,   204,   205,   226,   113,
     114,   208,   115,   217,   116,   117,   118,   119,   120,   218,
     101,   102,   103,   104,   224,   244,   105,   106,   107,   247,
     243,   249,   121,   248,   250,   257,   122,   109,   266,   110,
     111,   112,   258,   267,   259,   113,   114,   292,   115,   263,
     116,   117,   118,   119,   120,   269,   101,   102,   103,   104,
     270,   273,   105,   106,   107,   271,   272,   274,   121,   275,
     276,   277,   122,   109,   294,   110,   111,   112,   296,   297,
     298,   113,   114,   299,   115,    41,   116,   117,   118,   119,
     120,    31,   101,   102,   103,   104,    44,    85,   105,   106,
     107,    70,   100,   211,   121,    32,    47,    77,   122,   109,
      95,   110,   111,   112,   147,     0,     0,   113,   114,   196,
     115,     0,   116,   117,   118,   119,   120,     0,   101,   102,
     103,   104,     0,     0,   105,   106,   107,     0,     0,     0,
     121,     0,     0,     0,   122,   109,     0,   110,   111,   112,
      98,     4,     5,   216,   114,     0,   115,     0,   116,   117,
     118,   119,   120,   101,   102,   103,   104,     0,     0,   105,
       0,     6,     2,   140,     4,     5,   121,     0,     0,     3,
     122,     4,     5,   195,     4,     5,   185,   186,   187,   188,
     189,   190,   191,     0,     6,   118,   119,   120,   178,     0,
       0,     6,     0,     0,     6,   187,   188,   189,   190,   191,
       0,   121,     0,   264,     0,   122,     0,     0,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   265,   192,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,     0,     0,     0,     0,
       0,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,     0,     0,     0,
       0,     0,     0,     0,     0,   262,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,     0,
       0,     0,     0,     0,   223,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,     0,     0,
       0,     0,     0,   246,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,     0,     0,     0,
       0,     0,   253,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,     0,     0,     0,     0,
       0,   254,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,     0,     0,     0,     0,     0,
     255,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,     0,     0,     0,     0,     0,   256,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,     0,     0,     0,     0,     0,   286,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,     0,     0,     0,     0,     0,   287,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   183,   184,   185,   186,   187,   188,
     189,   190,   191
};

static const yytype_int16 yycheck[] =
{
     114,   115,   126,     8,     3,    20,    11,    60,    12,    93,
      94,     8,     4,    57,    11,    12,    60,    20,     5,     6,
       7,     8,    58,    59,    11,    18,    19,    32,    27,    33,
      20,     0,    36,    18,    19,    32,    33,    23,    38,    36,
      10,   165,   166,    42,    59,    38,    38,    51,   121,   122,
      37,    38,    39,    38,    51,    54,    59,    56,    18,    19,
      59,    60,    38,   147,    20,    58,    53,    57,    38,     4,
      57,    58,    58,    58,    73,    31,    58,    59,    38,    17,
      18,    19,    81,   156,    50,    51,    52,    86,   161,   162,
     163,   164,    91,    98,    98,   148,    56,   170,   171,    23,
      38,    10,   175,    38,    18,    19,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
       5,     6,     7,     8,    38,     0,    11,    12,    13,    38,
      15,    11,    14,    57,    16,    55,    60,    22,    55,    24,
      25,    26,    56,   142,    57,    30,    31,   151,    33,   148,
      35,    36,    37,    38,    39,    18,    19,    16,    38,    38,
     284,   285,   276,   277,    37,   247,    38,     3,    53,    58,
      59,   295,    57,     9,   247,    38,   290,   259,    55,    20,
      16,   263,    18,    19,   257,   258,   259,    38,   261,    20,
     263,     5,     6,     7,     8,    61,    38,    11,    12,    13,
      58,    59,    38,    58,    59,    17,    18,    19,    22,    55,
      24,    25,    26,    56,    28,    29,    30,    31,    14,    33,
      38,    35,    36,    37,    38,    39,    38,    57,     5,     6,
       7,     8,    58,    59,    11,    12,    13,    58,    59,    53,
      57,    57,    23,    57,    21,    22,    57,    24,    25,    26,
      57,    20,    57,    30,    31,    57,    33,    57,    35,    36,
      37,    38,    39,    57,     5,     6,     7,     8,    20,    20,
      11,    12,    13,    23,    38,    57,    53,    56,    56,    38,
      57,    22,    56,    24,    25,    26,    58,    58,    15,    30,
      31,    38,    33,    34,    35,    36,    37,    38,    39,    38,
       5,     6,     7,     8,    38,    20,    11,    12,    13,    57,
      56,    23,    53,    58,    23,    57,    57,    22,    38,    24,
      25,    26,    57,    20,    57,    30,    31,    32,    33,    57,
      35,    36,    37,    38,    39,    20,     5,     6,     7,     8,
      38,    20,    11,    12,    13,    38,    38,    20,    53,    20,
      27,    31,    57,    22,    20,    24,    25,    26,    20,    20,
      29,    30,    31,    20,    33,    17,    35,    36,    37,    38,
      39,     8,     5,     6,     7,     8,    22,    73,    11,    12,
      13,    56,    86,   159,    53,     8,    27,    63,    57,    22,
      81,    24,    25,    26,    94,    -1,    -1,    30,    31,   142,
      33,    -1,    35,    36,    37,    38,    39,    -1,     5,     6,
       7,     8,    -1,    -1,    11,    12,    13,    -1,    -1,    -1,
      53,    -1,    -1,    -1,    57,    22,    -1,    24,    25,    26,
      17,    18,    19,    30,    31,    -1,    33,    -1,    35,    36,
      37,    38,    39,     5,     6,     7,     8,    -1,    -1,    11,
      -1,    38,     9,    17,    18,    19,    53,    -1,    -1,    16,
      57,    18,    19,    17,    18,    19,    46,    47,    48,    49,
      50,    51,    52,    -1,    38,    37,    38,    39,    20,    -1,
      -1,    38,    -1,    -1,    38,    48,    49,    50,    51,    52,
      -1,    53,    -1,    20,    -1,    57,    -1,    -1,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    20,    54,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    -1,    -1,    -1,    -1,
      -1,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    61,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    -1,
      -1,    -1,    -1,    -1,    58,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    -1,    -1,
      -1,    -1,    -1,    58,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    -1,    -1,    -1,
      -1,    -1,    58,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    -1,    -1,    -1,    -1,
      -1,    58,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    -1,    -1,    -1,    -1,    -1,
      58,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    -1,    -1,    -1,    -1,    -1,    58,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    -1,    -1,    -1,    -1,    -1,    58,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    -1,    -1,    -1,    -1,    -1,    58,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    44,    45,    46,    47,    48,    49,
      50,    51,    52
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     9,    16,    18,    19,    38,    63,    64,    70,
      71,    83,    91,    92,    99,     4,    38,    65,    66,    67,
      10,    38,    72,    73,    74,    17,    70,    84,    85,    86,
       0,    71,    83,    91,    99,    38,    91,    99,    92,    99,
       4,    66,    55,    10,    73,    55,    17,    85,    38,    87,
      88,    91,    99,    99,    57,    99,    68,    69,    70,    16,
      57,    60,    20,    59,    99,    58,    70,    89,    90,    56,
      69,    38,    70,    75,    76,    89,    37,    88,    55,    38,
      58,    59,    20,    38,    70,    76,    77,    78,    58,    61,
      14,    16,    93,    95,    55,    90,    20,    38,    17,    70,
      78,     5,     6,     7,     8,    11,    12,    13,    15,    22,
      24,    25,    26,    30,    31,    33,    35,    36,    37,    38,
      39,    53,    57,    80,    81,    82,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   114,
      17,    70,    96,    97,    56,    93,    93,    95,    57,    56,
      79,    91,    92,    38,    57,    57,    57,    23,    57,    57,
      20,    57,    57,    57,    57,   100,   100,    20,    20,    23,
      57,    60,   112,   112,    23,    21,    94,   101,    20,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    54,    38,    98,    17,    97,    56,    56,    93,
      58,    89,    56,    92,    58,    58,   112,    38,    38,    11,
      38,    81,   112,   112,   112,   112,    30,    34,    38,    58,
     112,   113,   112,    58,    38,   112,    15,   112,   112,   112,
     112,   112,   112,   112,   112,   112,   112,   112,   112,   112,
     112,    20,    59,    56,    20,    58,    58,    57,    58,    23,
      23,    23,    58,    58,    58,    58,    58,    57,    57,    57,
      58,    59,    61,    57,    20,    20,    38,    20,   113,    20,
      38,    38,    38,    20,    20,    20,    27,    31,   112,   112,
     113,   112,   113,    58,   100,   100,    58,    58,    58,    58,
      28,    29,    32,    20,    20,   100,    20,    20,    29,    20
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    62,    63,    63,    63,    63,    63,    63,    63,    63,
      63,    63,    63,    63,    64,    64,    65,    65,    66,    67,
      68,    68,    69,    70,    70,    70,    71,    71,    72,    72,
      73,    73,    74,    75,    75,    76,    77,    77,    78,    78,
      79,    80,    80,    80,    81,    81,    81,    82,    82,    82,
      83,    83,    84,    84,    85,    86,    87,    87,    88,    88,
      88,    89,    89,    90,    91,    91,    92,    92,    92,    92,
      93,    93,    94,    95,    95,    96,    96,    97,    98,    98,
      99,   100,   100,   101,   101,   101,   101,   101,   101,   101,
     101,   101,   101,   101,   102,   103,   104,   105,   105,   106,
     107,   108,   109,   110,   111,   112,   112,   112,   112,   112,
     112,   112,   112,   112,   112,   112,   112,   112,   112,   112,
     112,   112,   112,   112,   112,   112,   112,   112,   112,   113,
     113,   114,   114,   114,   114
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     4,     3,     3,     2,     3,     2,     2,     1,
       1,     1,     2,     2,     3,     2,     2,     1,     4,     1,
       2,     1,     3,     1,     1,     1,     3,     2,     2,     1,
       8,     7,     1,     2,     1,     3,     2,     1,     6,     5,
       1,     2,     5,     5,     3,     3,     3,     6,     6,     6,
       3,     2,     2,     1,     3,     1,     3,     1,     1,     4,
       4,     3,     1,     2,     2,     1,     9,     8,     8,     7,
       4,     2,     3,     3,     2,     2,     1,     3,     3,     1,
       1,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     5,     5,     4,    10,     8,     8,
       7,     7,     2,     2,     2,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     2,     3,
       1,     1,     1,     3,     3,     4,     1,     1,     1,     3,
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
#line 67 "exptree.y"
                                                      {codegenerator((yyvsp[-1].no),(yyvsp[0].no));}
#line 1748 "y.tab.c"
    break;

  case 3:
#line 68 "exptree.y"
                                            {codegenerator(NULL,(yyvsp[0].no));}
#line 1754 "y.tab.c"
    break;

  case 4:
#line 69 "exptree.y"
                                           {codegenerator((yyvsp[-1].no),(yyvsp[0].no));}
#line 1760 "y.tab.c"
    break;

  case 5:
#line 70 "exptree.y"
                                  {codegenerator(NULL,(yyvsp[0].no));}
#line 1766 "y.tab.c"
    break;

  case 6:
#line 71 "exptree.y"
                                         {codegenerator((yyvsp[-1].no),(yyvsp[0].no));}
#line 1772 "y.tab.c"
    break;

  case 7:
#line 72 "exptree.y"
                               {codegenerator(NULL,(yyvsp[0].no));}
#line 1778 "y.tab.c"
    break;

  case 8:
#line 73 "exptree.y"
                              {codegenerator((yyvsp[-1].no),(yyvsp[0].no));}
#line 1784 "y.tab.c"
    break;

  case 9:
#line 74 "exptree.y"
                    {codegenerator(NULL,(yyvsp[0].no));}
#line 1790 "y.tab.c"
    break;

  case 10:
#line 75 "exptree.y"
                       {}
#line 1796 "y.tab.c"
    break;

  case 11:
#line 76 "exptree.y"
                        {}
#line 1802 "y.tab.c"
    break;

  case 12:
#line 77 "exptree.y"
                                  {}
#line 1808 "y.tab.c"
    break;

  case 13:
#line 78 "exptree.y"
                                     {}
#line 1814 "y.tab.c"
    break;

  case 14:
#line 83 "exptree.y"
                                        {}
#line 1820 "y.tab.c"
    break;

  case 15:
#line 84 "exptree.y"
                            {if(Thead == NULL) TypetableCreate();}
#line 1826 "y.tab.c"
    break;

  case 16:
#line 87 "exptree.y"
                                  {}
#line 1832 "y.tab.c"
    break;

  case 17:
#line 88 "exptree.y"
                      {}
#line 1838 "y.tab.c"
    break;

  case 18:
#line 91 "exptree.y"
                                     {Tptr->fields = typefieldlist;}
#line 1844 "y.tab.c"
    break;

  case 19:
#line 94 "exptree.y"
           {
             if(Thead == NULL) TypetableCreate(); 
             Tptr = TInstall((yyvsp[0].ch));
            }
#line 1853 "y.tab.c"
    break;

  case 20:
#line 100 "exptree.y"
                                      {}
#line 1859 "y.tab.c"
    break;

  case 21:
#line 101 "exptree.y"
                         {}
#line 1865 "y.tab.c"
    break;

  case 22:
#line 104 "exptree.y"
                                  {typefieldlist = Type_FieldInstall((yyvsp[-2].no)->varname,(yyvsp[-1].ch));}
#line 1871 "y.tab.c"
    break;

  case 23:
#line 107 "exptree.y"
               {(yyval.no)=makeTypeNameNode("int",NODE_TYPENAME);}
#line 1877 "y.tab.c"
    break;

  case 24:
#line 108 "exptree.y"
               {(yyval.no)=makeTypeNameNode("string",NODE_TYPENAME);}
#line 1883 "y.tab.c"
    break;

  case 25:
#line 109 "exptree.y"
              {(yyval.no)=makeTypeNameNode((yyvsp[0].ch),NODE_TYPENAME);}
#line 1889 "y.tab.c"
    break;

  case 26:
#line 117 "exptree.y"
                                              {printClasstable();}
#line 1895 "y.tab.c"
    break;

  case 27:
#line 118 "exptree.y"
                                 {}
#line 1901 "y.tab.c"
    break;

  case 28:
#line 120 "exptree.y"
                                        {}
#line 1907 "y.tab.c"
    break;

  case 29:
#line 121 "exptree.y"
                           {}
#line 1913 "y.tab.c"
    break;

  case 30:
#line 124 "exptree.y"
                                                                              {}
#line 1919 "y.tab.c"
    break;

  case 31:
#line 125 "exptree.y"
                                                                  {}
#line 1925 "y.tab.c"
    break;

  case 32:
#line 128 "exptree.y"
                            {Cptr = CInstall((yyvsp[0].ch),NULL);}
#line 1931 "y.tab.c"
    break;

  case 33:
#line 131 "exptree.y"
                                 {}
#line 1937 "y.tab.c"
    break;

  case 34:
#line 132 "exptree.y"
                      {}
#line 1943 "y.tab.c"
    break;

  case 35:
#line 135 "exptree.y"
                                         {Class_Finstall(Cptr,(yyvsp[-2].no)->varname,(yyvsp[-1].ch));}
#line 1949 "y.tab.c"
    break;

  case 36:
#line 138 "exptree.y"
                                   {}
#line 1955 "y.tab.c"
    break;

  case 37:
#line 139 "exptree.y"
                        {}
#line 1961 "y.tab.c"
    break;

  case 38:
#line 142 "exptree.y"
                                                          {Class_Minstall(Cptr,(yyvsp[-4].ch),TLookup((yyvsp[-5].no)->varname),paramptr);
                                                            paramptr = NULL;
                                                          }
#line 1969 "y.tab.c"
    break;

  case 39:
#line 145 "exptree.y"
                                               {Class_Minstall(Cptr,(yyvsp[-3].ch),TLookup((yyvsp[-4].no)->varname),NULL);}
#line 1975 "y.tab.c"
    break;

  case 41:
#line 151 "exptree.y"
                                 {}
#line 1981 "y.tab.c"
    break;

  case 42:
#line 152 "exptree.y"
                                           {}
#line 1987 "y.tab.c"
    break;

  case 43:
#line 153 "exptree.y"
                                                      {}
#line 1993 "y.tab.c"
    break;

  case 44:
#line 156 "exptree.y"
                                {}
#line 1999 "y.tab.c"
    break;

  case 45:
#line 157 "exptree.y"
                                      {}
#line 2005 "y.tab.c"
    break;

  case 46:
#line 158 "exptree.y"
                               {}
#line 2011 "y.tab.c"
    break;

  case 47:
#line 161 "exptree.y"
                                                     {}
#line 2017 "y.tab.c"
    break;

  case 48:
#line 162 "exptree.y"
                                                     {}
#line 2023 "y.tab.c"
    break;

  case 49:
#line 163 "exptree.y"
                                                           {}
#line 2029 "y.tab.c"
    break;

  case 50:
#line 172 "exptree.y"
                                   {}
#line 2035 "y.tab.c"
    break;

  case 51:
#line 173 "exptree.y"
                          {}
#line 2041 "y.tab.c"
    break;

  case 52:
#line 176 "exptree.y"
                         {}
#line 2047 "y.tab.c"
    break;

  case 53:
#line 177 "exptree.y"
                {}
#line 2053 "y.tab.c"
    break;

  case 54:
#line 180 "exptree.y"
                                       {}
#line 2059 "y.tab.c"
    break;

  case 55:
#line 183 "exptree.y"
                         {Gname = (yyvsp[0].no)->varname;}
#line 2065 "y.tab.c"
    break;

  case 56:
#line 186 "exptree.y"
                             {}
#line 2071 "y.tab.c"
    break;

  case 57:
#line 187 "exptree.y"
                 {}
#line 2077 "y.tab.c"
    break;

  case 58:
#line 190 "exptree.y"
            {GInstall((yyvsp[0].ch),TLookup(Gname),0,NULL,NODE_VARIABLE);}
#line 2083 "y.tab.c"
    break;

  case 59:
#line 191 "exptree.y"
                        {GInstall((yyvsp[-3].ch),TLookup(Gname),(yyvsp[-1].num),NULL,NODE_VAR_ARRAY);}
#line 2089 "y.tab.c"
    break;

  case 60:
#line 192 "exptree.y"
                              {GInstall((yyvsp[-3].ch),TLookup(Gname),(yyvsp[-1].num),paramptr,NODE_VAR_PARAMLIST);}
#line 2095 "y.tab.c"
    break;

  case 61:
#line 195 "exptree.y"
                                {}
#line 2101 "y.tab.c"
    break;

  case 62:
#line 196 "exptree.y"
                   {}
#line 2107 "y.tab.c"
    break;

  case 63:
#line 199 "exptree.y"
                    {paramptr = Param_Install(paramptr,(yyvsp[-1].no)->varname,(yyvsp[0].ch));}
#line 2113 "y.tab.c"
    break;

  case 64:
#line 206 "exptree.y"
                           {(yyval.no)=makeFuncConnectorNode(NODE_CONNECTOR,(yyvsp[-1].no),(yyvsp[0].no));}
#line 2119 "y.tab.c"
    break;

  case 65:
#line 207 "exptree.y"
                 {(yyval.no)=(yyvsp[0].no);}
#line 2125 "y.tab.c"
    break;

  case 66:
#line 210 "exptree.y"
                                                          {
                                                          struct tnode *temp1 = (yyvsp[-8].no);
                                                          struct tnode *temp2 = makeFuncConnectorNode(NODE_CONNECTOR,(yyvsp[-2].no),(yyvsp[-1].no));
                                                          struct tnode *temp3 = makeFuncConnectorNode(NODE_CONNECTOR,(yyvsp[-5].no),temp2); 
                                                          struct tnode *temp4 = makeFuncIdNode(NODE_FUNCTION,(yyvsp[-7].ch),temp1,temp3);

                                                          (yyval.no) = temp4;

                                                          struct Lsymbol *temp =  LsymbolEntry((yyvsp[-5].no),(yyvsp[-2].no));

                                                          LinkLocalTable(temp,(yyvsp[-1].no));    
                                                       }
#line 2142 "y.tab.c"
    break;

  case 67:
#line 222 "exptree.y"
                                                {
                                                          struct tnode *temp1 = (yyvsp[-7].no);
                                                          struct tnode *temp2 = makeFuncConnectorNode(NODE_CONNECTOR,NULL,(yyvsp[-1].no));
                                                          struct tnode *temp3 = makeFuncConnectorNode(NODE_CONNECTOR,(yyvsp[-4].no),temp2);

                                                          struct tnode *temp4 = makeFuncIdNode(NODE_FUNCTION,(yyvsp[-6].ch),temp1,temp3);
                                                          
                                                          (yyval.no) = temp4;

                                                          struct Lsymbol *temp =  LsymbolEntry((yyvsp[-4].no),NULL);
                                                          LinkLocalTable(temp,(yyvsp[-1].no));
                                            }
#line 2159 "y.tab.c"
    break;

  case 68:
#line 234 "exptree.y"
                                                  {
                                                          struct tnode *temp1 = (yyvsp[-7].no);
                                                          struct tnode *temp2 = makeFuncConnectorNode(NODE_CONNECTOR,(yyvsp[-2].no),(yyvsp[-1].no));
                                                          struct tnode *temp3 = makeFuncConnectorNode(NODE_CONNECTOR,NULL,temp2);
                                                          struct tnode *temp4 = makeFuncIdNode(NODE_FUNCTION,(yyvsp[-6].ch),temp1,temp3);

                                                          (yyval.no) = temp4;

                                                          struct Lsymbol *temp =  LsymbolEntry(NULL,(yyvsp[-2].no));
                                                          
                                                          LinkLocalTable(temp,(yyvsp[-1].no));
                                               }
#line 2176 "y.tab.c"
    break;

  case 69:
#line 246 "exptree.y"
                                       {
                                                          struct tnode *temp1 = (yyvsp[-6].no);
                                                          struct tnode *temp2 = makeFuncConnectorNode(NODE_CONNECTOR,NULL,(yyvsp[-1].no));
                                                          struct tnode *temp3 = makeFuncConnectorNode(NODE_CONNECTOR,NULL,temp2);

                                                          (yyval.no) = makeFuncIdNode(NODE_FUNCTION,(yyvsp[-5].ch),temp1,temp3);
                                   }
#line 2188 "y.tab.c"
    break;

  case 70:
#line 255 "exptree.y"
                                  {(yyval.no)=makeFuncConnectorNode(NODE_CONNECTOR,(yyvsp[-2].no),(yyvsp[-1].no));}
#line 2194 "y.tab.c"
    break;

  case 71:
#line 256 "exptree.y"
                 {}
#line 2200 "y.tab.c"
    break;

  case 72:
#line 259 "exptree.y"
                                   {(yyval.no)=makeReturnNode(NODE_RETURN,(yyvsp[-1].no));}
#line 2206 "y.tab.c"
    break;

  case 73:
#line 266 "exptree.y"
                                   {
                                    (yyval.no)=(yyvsp[-1].no);
                                    }
#line 2214 "y.tab.c"
    break;

  case 74:
#line 269 "exptree.y"
                          {}
#line 2220 "y.tab.c"
    break;

  case 75:
#line 272 "exptree.y"
                          {(yyval.no)=makeLDeclConnectorNode(NODE_LCONNECTOR,(yyvsp[-1].no),(yyvsp[0].no));}
#line 2226 "y.tab.c"
    break;

  case 76:
#line 273 "exptree.y"
                 {(yyval.no)=(yyvsp[0].no);}
#line 2232 "y.tab.c"
    break;

  case 77:
#line 276 "exptree.y"
                                  {
                               (yyval.no)=makeLDeclTypeNode(NODE_LTYPE,(yyvsp[-2].no),(yyvsp[-1].no));
                               }
#line 2240 "y.tab.c"
    break;

  case 78:
#line 281 "exptree.y"
                       {(yyval.no)=makeLDeclConnectorNode(NODE_CONNECTOR,(yyvsp[-2].no),makeLDeclIdNode(NODE_VARIABLE,(yyvsp[0].ch)));}
#line 2246 "y.tab.c"
    break;

  case 79:
#line 282 "exptree.y"
            {(yyval.no)=makeLDeclIdNode(NODE_VARIABLE,(yyvsp[0].ch));}
#line 2252 "y.tab.c"
    break;

  case 80:
#line 289 "exptree.y"
                 {(yyval.no)=(yyvsp[0].no);}
#line 2258 "y.tab.c"
    break;

  case 81:
#line 294 "exptree.y"
                   {(yyval.no)=makeConnectorNode(NODE_CONNECTOR,".",(yyvsp[-1].no),(yyvsp[0].no));}
#line 2264 "y.tab.c"
    break;

  case 82:
#line 295 "exptree.y"
             {(yyval.no)=(yyvsp[0].no);}
#line 2270 "y.tab.c"
    break;

  case 83:
#line 298 "exptree.y"
                 {(yyval.no)=(yyvsp[0].no);}
#line 2276 "y.tab.c"
    break;

  case 84:
#line 299 "exptree.y"
                  {(yyval.no)=(yyvsp[0].no);}
#line 2282 "y.tab.c"
    break;

  case 85:
#line 300 "exptree.y"
                {(yyval.no)=(yyvsp[0].no);}
#line 2288 "y.tab.c"
    break;

  case 86:
#line 301 "exptree.y"
              {(yyval.no)=(yyvsp[0].no);}
#line 2294 "y.tab.c"
    break;

  case 87:
#line 302 "exptree.y"
                 {(yyval.no)=(yyvsp[0].no);}
#line 2300 "y.tab.c"
    break;

  case 88:
#line 303 "exptree.y"
                 {(yyval.no)=(yyvsp[0].no);}
#line 2306 "y.tab.c"
    break;

  case 89:
#line 304 "exptree.y"
                    {(yyval.no)=(yyvsp[0].no);}
#line 2312 "y.tab.c"
    break;

  case 90:
#line 305 "exptree.y"
                      {(yyval.no)=(yyvsp[0].no);}
#line 2318 "y.tab.c"
    break;

  case 91:
#line 306 "exptree.y"
                   {(yyval.no)=(yyvsp[0].no);}
#line 2324 "y.tab.c"
    break;

  case 92:
#line 307 "exptree.y"
                    {(yyval.no)=(yyvsp[0].no);}
#line 2330 "y.tab.c"
    break;

  case 93:
#line 308 "exptree.y"
                 {(yyval.no)=(yyvsp[0].no);}
#line 2336 "y.tab.c"
    break;

  case 94:
#line 311 "exptree.y"
                                       {(yyval.no)=makereadNode(NODE_READ,(yyvsp[-2].no));}
#line 2342 "y.tab.c"
    break;

  case 95:
#line 315 "exptree.y"
                                         {(yyval.no)=makewriteNode(NODE_WRITE,(yyvsp[-2].no));}
#line 2348 "y.tab.c"
    break;

  case 96:
#line 318 "exptree.y"
                                     {(yyval.no)=makeOperatorNode(NODE_ASSG_EQ,"=",(yyvsp[-3].no),(yyvsp[-1].no));}
#line 2354 "y.tab.c"
    break;

  case 97:
#line 321 "exptree.y"
                                                              {(yyval.no)=makeIfNode(NODE_IF,(yyvsp[-7].no),(yyvsp[-4].no),(yyvsp[-2].no));}
#line 2360 "y.tab.c"
    break;

  case 98:
#line 322 "exptree.y"
                                                   {(yyval.no)=makeIfNode(NODE_IF,(yyvsp[-5].no),(yyvsp[-2].no),NULL);}
#line 2366 "y.tab.c"
    break;

  case 99:
#line 325 "exptree.y"
                                                          {(yyval.no)=makeWhileNode(NODE_WHILE,(yyvsp[-5].no),(yyvsp[-2].no));}
#line 2372 "y.tab.c"
    break;

  case 100:
#line 328 "exptree.y"
                                                   {(yyval.no)=makedowhileNode(NODE_DO,(yyvsp[-5].no),(yyvsp[-2].no));}
#line 2378 "y.tab.c"
    break;

  case 101:
#line 331 "exptree.y"
                                                        {(yyval.no)=makerepuntilNode(NODE_REPEAT,(yyvsp[-5].no),(yyvsp[-2].no));}
#line 2384 "y.tab.c"
    break;

  case 102:
#line 334 "exptree.y"
                            {(yyval.no)=makebreakNode(NODE_BREAK);}
#line 2390 "y.tab.c"
    break;

  case 103:
#line 337 "exptree.y"
                                  {(yyval.no)=makecontNode(NODE_CONTINUE);}
#line 2396 "y.tab.c"
    break;

  case 104:
#line 340 "exptree.y"
                                       {(yyval.no)=makeIdNode(NODE_BREAK_POINT,(yyvsp[-1].ch),NULL,NULL);}
#line 2402 "y.tab.c"
    break;

  case 105:
#line 343 "exptree.y"
                      {(yyval.no) = makeOperatorNode(NODE_ADD,"+",(yyvsp[-2].no),(yyvsp[0].no));(yyval.no)->type = intType;}
#line 2408 "y.tab.c"
    break;

  case 106:
#line 344 "exptree.y"
                      {(yyval.no) = makeOperatorNode(NODE_SUB,"-",(yyvsp[-2].no),(yyvsp[0].no));(yyval.no)->type = intType;}
#line 2414 "y.tab.c"
    break;

  case 107:
#line 345 "exptree.y"
                    {(yyval.no) = makeOperatorNode(NODE_MUL,"*",(yyvsp[-2].no),(yyvsp[0].no)); (yyval.no)->type = intType;}
#line 2420 "y.tab.c"
    break;

  case 108:
#line 346 "exptree.y"
                    {(yyval.no) = makeOperatorNode(NODE_DIV,"/",(yyvsp[-2].no),(yyvsp[0].no));(yyval.no)->type = intType;}
#line 2426 "y.tab.c"
    break;

  case 109:
#line 347 "exptree.y"
                    {(yyval.no) = makeOperatorNode(NODE_MOD,"%",(yyvsp[-2].no),(yyvsp[0].no));(yyval.no)->type = intType;}
#line 2432 "y.tab.c"
    break;

  case 110:
#line 348 "exptree.y"
                   {(yyval.no) = makeOperatorNode(NODE_LT,"<",(yyvsp[-2].no),(yyvsp[0].no)); (yyval.no)->type = boolType;}
#line 2438 "y.tab.c"
    break;

  case 111:
#line 349 "exptree.y"
                   {(yyval.no) = makeOperatorNode(NODE_GT,">",(yyvsp[-2].no),(yyvsp[0].no)); (yyval.no)->type = boolType;}
#line 2444 "y.tab.c"
    break;

  case 112:
#line 350 "exptree.y"
                   {(yyval.no) = makeOperatorNode(NODE_NE,"!=",(yyvsp[-2].no),(yyvsp[0].no)); (yyval.no)->type = boolType;}
#line 2450 "y.tab.c"
    break;

  case 113:
#line 351 "exptree.y"
                    {(yyval.no) = makeOperatorNode(NODE_LTE,"<=",(yyvsp[-2].no),(yyvsp[0].no)); (yyval.no)->type = boolType;}
#line 2456 "y.tab.c"
    break;

  case 114:
#line 352 "exptree.y"
                    {(yyval.no) = makeOperatorNode(NODE_GTE,">=",(yyvsp[-2].no),(yyvsp[0].no)); (yyval.no)->type = boolType;}
#line 2462 "y.tab.c"
    break;

  case 115:
#line 353 "exptree.y"
                   {(yyval.no) = makeOperatorNode(NODE_EQ,"==",(yyvsp[-2].no),(yyvsp[0].no)); (yyval.no)->type = boolType;}
#line 2468 "y.tab.c"
    break;

  case 116:
#line 354 "exptree.y"
                    {(yyval.no) = makeOperatorNode(NODE_AND,"&&",(yyvsp[-2].no),(yyvsp[0].no));(yyval.no)->type = boolType;}
#line 2474 "y.tab.c"
    break;

  case 117:
#line 355 "exptree.y"
                   {(yyval.no) = makeOperatorNode(NODE_OR,"||",(yyvsp[-2].no),(yyvsp[0].no));(yyval.no)->type = boolType;}
#line 2480 "y.tab.c"
    break;

  case 118:
#line 356 "exptree.y"
               {(yyval.no) = makeOperatorNode(NODE_NOT,"!",NULL,(yyvsp[0].no));(yyval.no)->type = boolType;}
#line 2486 "y.tab.c"
    break;

  case 119:
#line 357 "exptree.y"
                   {(yyval.no)=(yyvsp[-1].no);}
#line 2492 "y.tab.c"
    break;

  case 120:
#line 358 "exptree.y"
                 {(yyval.no)=(yyvsp[0].no);}
#line 2498 "y.tab.c"
    break;

  case 121:
#line 359 "exptree.y"
          {(yyval.no)=makeNumberNode(NODE_CONSTANT,(yyvsp[0].num));}
#line 2504 "y.tab.c"
    break;

  case 122:
#line 360 "exptree.y"
             {(yyval.no)=(yyvsp[0].no);}
#line 2510 "y.tab.c"
    break;

  case 123:
#line 361 "exptree.y"
                  {(yyval.no)=makeIdNode(NODE_ALLOC,"alloc",NULL,NULL);}
#line 2516 "y.tab.c"
    break;

  case 124:
#line 362 "exptree.y"
                       {(yyval.no)=makeIdNode(NODE_INITIALIZE,"initialize",NULL,NULL);}
#line 2522 "y.tab.c"
    break;

  case 125:
#line 363 "exptree.y"
                       {(yyval.no)=makeIdNode(NODE_FREE,"free",(yyvsp[-1].no),NULL);}
#line 2528 "y.tab.c"
    break;

  case 126:
#line 364 "exptree.y"
               {(yyval.no)=makeIdNode(NODE_VAR_NULL,"null",NULL,NULL);}
#line 2534 "y.tab.c"
    break;

  case 127:
#line 365 "exptree.y"
                 {(yyval.no)=(yyvsp[0].no);}
#line 2540 "y.tab.c"
    break;

  case 128:
#line 366 "exptree.y"
                         {(yyval.no)=(yyvsp[0].no);}
#line 2546 "y.tab.c"
    break;

  case 129:
#line 373 "exptree.y"
                           {(yyval.no)=makeConnectorNode(NODE_ARGLIST,".",(yyvsp[-2].no),(yyvsp[0].no));}
#line 2552 "y.tab.c"
    break;

  case 130:
#line 374 "exptree.y"
               {(yyval.no)=(yyvsp[0].no);}
#line 2558 "y.tab.c"
    break;

  case 131:
#line 377 "exptree.y"
                              {(yyval.no)=makeIdNode(NODE_VARIABLE,(yyvsp[0].ch),NULL,NULL);}
#line 2564 "y.tab.c"
    break;

  case 132:
#line 378 "exptree.y"
                              {(yyval.no)=makeIdNode(NODE_VAR_ARRAY,(yyvsp[-3].ch),(yyvsp[-1].no),NULL);}
#line 2570 "y.tab.c"
    break;

  case 133:
#line 379 "exptree.y"
                              {(yyval.no)=makeIdNode(NODE_VAR_FUNC_CALL,(yyvsp[-2].ch),NULL,NULL);}
#line 2576 "y.tab.c"
    break;

  case 134:
#line 380 "exptree.y"
                              {(yyval.no)=makeIdNode(NODE_VAR_FUNC_CALL,(yyvsp[-3].ch),(yyvsp[-1].no),NULL);}
#line 2582 "y.tab.c"
    break;


#line 2586 "y.tab.c"

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
#line 382 "exptree.y"


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
