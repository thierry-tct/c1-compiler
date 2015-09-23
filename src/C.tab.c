/* A Bison parser, made by GNU Bison 2.5.  */

/* Bison implementation for Yacc-like parsers in C
   
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
#define YYBISON_VERSION "2.5"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 1



/* Copy the first part of user declarations.  */

/* Line 268 of yacc.c  */
#line 1 "config/C.y"

#include <stdio.h>
#include <math.h>
#include <common.h>
Table symtab;
ASTTree ast;
ErrFactory errfactory;
extern int lparen_num;
bool thereareparam;	//to see if we should create a new symbol table in bloc (created in param when function with parameter)
bool is_funccc;



/* Line 268 of yacc.c  */
#line 85 "src/C.tab.c"

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

/* Line 293 of yacc.c  */
#line 14 "config/C.y"

   	float num;
	int ival;
   	char * ident; 
	char * str; 
	ASTNode node;



/* Line 293 of yacc.c  */
#line 203 "src/C.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

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


/* Copy the second part of user declarations.  */


/* Line 343 of yacc.c  */
#line 228 "src/C.tab.c"

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
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
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
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
	     && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
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
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  26
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   273

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  45
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  43
/* YYNRULES -- Number of rules.  */
#define YYNRULES  102
/* YYNRULES -- Number of states.  */
#define YYNSTATES  166

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   291

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      37,    38,     2,     2,    41,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    42,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    39,     2,    40,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    43,     2,    44,     2,     2,     2,     2,
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
      35,    36
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     7,     9,    11,    13,    15,    19,
      21,    24,    28,    33,    37,    42,    44,    48,    50,    53,
      55,    57,    59,    61,    63,    67,    71,    75,    77,    81,
      85,    87,    91,    95,    99,   103,   105,   109,   113,   115,
     119,   121,   125,   127,   129,   133,   135,   139,   143,   146,
     148,   151,   153,   157,   159,   163,   165,   167,   169,   171,
     173,   175,   178,   179,   185,   189,   193,   198,   200,   202,
     206,   209,   211,   215,   220,   222,   226,   228,   230,   232,
     234,   236,   239,   240,   245,   247,   250,   252,   254,   256,
     259,   265,   273,   279,   282,   285,   288,   292,   294,   297,
     299,   301,   305
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      85,     0,    -1,     3,    -1,     4,    -1,     5,    -1,    22,
      -1,    23,    -1,     6,    -1,    37,    61,    38,    -1,    46,
      -1,     3,    48,    -1,     3,    37,    38,    -1,     3,    37,
      49,    38,    -1,    39,    61,    40,    -1,    48,    39,    61,
      40,    -1,    60,    -1,    49,    41,    60,    -1,    47,    -1,
      51,    52,    -1,    16,    -1,    17,    -1,    15,    -1,    50,
      -1,    52,    -1,    53,    18,    52,    -1,    53,    19,    52,
      -1,    53,    20,    52,    -1,    53,    -1,    54,    16,    53,
      -1,    54,    17,    53,    -1,    54,    -1,    55,    11,    54,
      -1,    55,    12,    54,    -1,    55,     7,    54,    -1,    55,
       8,    54,    -1,    55,    -1,    56,     9,    55,    -1,    56,
      10,    55,    -1,    56,    -1,    57,    13,    56,    -1,    57,
      -1,    58,    14,    57,    -1,    58,    -1,    59,    -1,    50,
      21,    60,    -1,    60,    -1,    61,    41,    60,    -1,    63,
      64,    42,    -1,    25,    66,    -1,    66,    -1,    28,    66,
      -1,    65,    -1,    64,    41,    65,    -1,    67,    -1,    67,
      21,    74,    -1,    29,    -1,    26,    -1,    27,    -1,    30,
      -1,    68,    -1,     3,    -1,     3,    70,    -1,    -1,     3,
      37,    69,    71,    38,    -1,     3,    37,    38,    -1,    39,
      60,    40,    -1,    70,    39,    60,    40,    -1,    72,    -1,
      73,    -1,    72,    41,    73,    -1,    63,    67,    -1,    60,
      -1,    43,    75,    44,    -1,    43,    75,    41,    44,    -1,
      74,    -1,    75,    41,    74,    -1,    77,    -1,    81,    -1,
      82,    -1,    83,    -1,    84,    -1,    43,    44,    -1,    -1,
      43,    78,    79,    44,    -1,    80,    -1,    79,    80,    -1,
      62,    -1,    76,    -1,    42,    -1,    61,    42,    -1,    31,
      37,    61,    38,    76,    -1,    31,    37,    61,    38,    76,
      32,    76,    -1,    33,    37,    61,    38,    76,    -1,    34,
      42,    -1,    35,    42,    -1,    36,    42,    -1,    36,    61,
      42,    -1,    86,    -1,    85,    86,    -1,    87,    -1,    62,
      -1,    63,    67,    77,    -1,    67,    77,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    56,    56,    61,    66,    72,    77,    82,    87,    95,
     100,   105,   115,   128,   134,   142,   147,   155,   160,   168,
     169,   170,   174,   182,   187,   192,   197,   205,   210,   215,
     223,   228,   233,   238,   243,   251,   256,   261,   269,   274,
     282,   287,   295,   303,   308,   316,   321,   329,   365,   371,
     377,   386,   392,   401,   406,   415,   416,   417,   418,   424,
     433,   440,   447,   447,   455,   464,   470,   478,   486,   492,
     501,   547,   552,   557,   565,   571,   580,   585,   590,   595,
     600,   608,   621,   621,   639,   645,   654,   659,   667,   672,
     680,   685,   693,   701,   706,   711,   716,   724,   732,   743,
     748,   756,   761
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IDENTIFIER", "CONSTANT", "CONSTANTF",
  "STRING_LITERAL", "LTEQ", "GTEQ", "EQEQ", "NOTEQ", "LT", "GT", "ANDAND",
  "OROR", "NOT", "PLUS", "MINUS", "MULT", "DIV", "MOD", "EQ", "TRUETOKEN",
  "FALSETOKEN", "TYPE_NAME", "TYPEDEF", "INT", "FLOAT", "CONST", "VOID",
  "BOOL", "IF", "ELSE", "WHILE", "CONTINUE", "BREAK", "RETURN", "'('",
  "')'", "'['", "']'", "','", "';'", "'{'", "'}'", "$accept",
  "primary_expression", "postfix_expression", "ArrayDimAccess",
  "argument_expression_list", "unary_expression", "unary_operator",
  "cast_expression", "multiplicative_expression", "additive_expression",
  "relational_expression", "equality_expression", "logical_and_expression",
  "logical_or_expression", "conditional_expression",
  "assignment_expression", "expression", "declaration",
  "declaration_specifiers", "init_declarator_list", "init_declarator",
  "type_specifier", "declarator", "direct_declarator", "$@1", "ArrayDim",
  "parameter_type_list", "parameter_list", "parameter_declaration",
  "initializer", "initializer_list", "statement", "compound_statement",
  "$@2", "block_item_list", "block_item", "expression_statement",
  "selection_statement", "iteration_statement", "jump_statement",
  "translation_unit", "external_declaration", "function_definition", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,    40,    41,    91,
      93,    44,    59,   123,   125
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    45,    46,    46,    46,    46,    46,    46,    46,    47,
      47,    47,    47,    48,    48,    49,    49,    50,    50,    51,
      51,    51,    52,    53,    53,    53,    53,    54,    54,    54,
      55,    55,    55,    55,    55,    56,    56,    56,    57,    57,
      58,    58,    59,    60,    60,    61,    61,    62,    63,    63,
      63,    64,    64,    65,    65,    66,    66,    66,    66,    67,
      68,    68,    69,    68,    68,    70,    70,    71,    72,    72,
      73,    74,    74,    74,    75,    75,    76,    76,    76,    76,
      76,    77,    78,    77,    79,    79,    80,    80,    81,    81,
      82,    82,    83,    84,    84,    84,    84,    85,    85,    86,
      86,    87,    87
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     1,     1,     3,     1,
       2,     3,     4,     3,     4,     1,     3,     1,     2,     1,
       1,     1,     1,     1,     3,     3,     3,     1,     3,     3,
       1,     3,     3,     3,     3,     1,     3,     3,     1,     3,
       1,     3,     1,     1,     3,     1,     3,     3,     2,     1,
       2,     1,     3,     1,     3,     1,     1,     1,     1,     1,
       1,     2,     0,     5,     3,     3,     4,     1,     1,     3,
       2,     1,     3,     4,     1,     3,     1,     1,     1,     1,
       1,     2,     0,     4,     1,     2,     1,     1,     1,     2,
       5,     7,     5,     2,     2,     2,     3,     1,     2,     1,
       1,     3,     2
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    60,     0,    56,    57,     0,    55,    58,   100,     0,
      49,     0,    59,     0,    97,    99,    62,     0,    61,    48,
      50,     0,    51,    53,    82,   102,     1,    98,    64,     0,
       2,     3,     4,     7,    21,    19,    20,     5,     6,     0,
       9,    17,    22,     0,    23,    27,    30,    35,    38,    40,
      42,    43,     0,     0,     0,    47,     0,   101,    81,     0,
       0,     0,    67,    68,     0,     0,    10,    45,     0,     0,
      22,    18,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    65,     0,    52,    53,     0,
      71,    54,     0,     0,     0,     0,     0,    88,     0,    86,
       0,    87,    76,     0,    84,    77,    78,    79,    80,    70,
      63,     0,    11,     0,    15,     0,     0,     8,     0,    44,
      24,    25,    26,    28,    29,    33,    34,    31,    32,    36,
      37,    39,    41,    66,    74,     0,     0,     0,    93,    94,
      95,     0,    89,    83,    85,    69,    12,     0,    13,     0,
      46,     0,    72,     0,     0,    96,    16,    14,    73,    75,
       0,     0,    90,    92,     0,    91
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    40,    41,    66,   113,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    67,    98,     8,     9,    21,
      22,    10,    11,    12,    29,    18,    61,    62,    63,    91,
     135,   101,   102,    59,   103,   104,   105,   106,   107,   108,
      13,    14,    15
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -128
static const yytype_int16 yypact[] =
{
      93,    40,    56,  -128,  -128,    56,  -128,  -128,  -128,    12,
    -128,   -12,  -128,   243,  -128,  -128,    -3,    87,     2,  -128,
    -128,    29,  -128,     0,     9,  -128,  -128,  -128,  -128,   149,
      92,  -128,  -128,  -128,  -128,  -128,  -128,  -128,  -128,    87,
    -128,  -128,    36,    87,  -128,    69,    95,    48,   140,    52,
      83,  -128,    77,    87,    12,  -128,     3,  -128,  -128,   167,
      12,   104,   150,  -128,   225,    87,   160,  -128,   -24,    87,
    -128,  -128,    87,    87,    87,    87,    87,    87,    87,    87,
      87,    87,    87,    87,    87,  -128,   176,  -128,   192,     3,
    -128,  -128,   195,   197,   207,   208,    58,  -128,   114,  -128,
      12,  -128,  -128,   110,  -128,  -128,  -128,  -128,  -128,  -128,
    -128,   149,  -128,     4,  -128,   146,    87,  -128,    87,  -128,
    -128,  -128,  -128,    69,    69,    95,    95,    95,    95,    48,
      48,   140,    52,  -128,  -128,   107,    87,    87,  -128,  -128,
    -128,   139,  -128,  -128,  -128,  -128,  -128,    87,  -128,   180,
    -128,     7,  -128,   147,   173,  -128,  -128,  -128,  -128,  -128,
     202,   202,   219,  -128,   202,  -128
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -128,  -128,  -128,  -128,  -128,    85,  -128,    -5,   151,    28,
     141,   169,   170,  -128,  -128,   -17,   -38,   -54,   -27,  -128,
     199,   210,    -6,  -128,  -128,  -128,  -128,  -128,   144,   -85,
    -128,  -127,     5,  -128,  -128,   153,  -128,  -128,  -128,  -128,
    -128,   244,  -128
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      52,    68,    60,    23,   134,    99,    30,    31,    32,    33,
      30,    31,    32,    33,   117,     1,    25,   118,    34,    35,
      36,    56,    34,    35,    36,    37,    38,   115,    57,    37,
      38,    24,   100,   162,   163,    28,    86,   165,    71,    90,
      39,    53,   146,    24,    39,   147,    89,   114,    88,    99,
      89,   158,   119,    58,   109,    77,    78,    69,   141,    79,
      80,    30,    31,    32,    33,    83,   159,   120,   121,   122,
      54,    55,    90,    34,    35,    36,   100,    16,   149,    17,
      37,    38,     3,     4,    60,     6,     7,    72,    73,    74,
      30,    31,    32,    33,    88,    39,     1,    84,   153,   154,
     140,   150,    34,    35,    36,   125,   126,   127,   128,    37,
      38,    75,    76,    30,    31,    32,    33,    85,     2,     3,
       4,     5,     6,     7,    39,    34,    35,    36,    70,    64,
     156,    65,    37,    38,    90,     2,     3,     4,     5,     6,
       7,    92,   110,    93,    94,    95,    96,    39,   151,    81,
      82,   152,    97,    24,   143,   118,   142,    70,    70,    70,
      70,    70,    70,    70,    70,    70,    70,    70,    70,    70,
      30,    31,    32,    33,     2,     3,     4,     5,     6,     7,
     118,   155,    34,    35,    36,   160,   148,   118,   118,    37,
      38,   111,     2,     3,     4,     5,     6,     7,    92,   116,
      93,    94,    95,    96,    39,    30,    31,    32,    33,    97,
      24,   161,    19,    56,   118,    20,   133,    34,    35,    36,
     157,   118,   129,   130,    37,    38,   123,   124,    30,    31,
      32,    33,   136,    92,   137,    93,    94,    95,    96,    39,
      34,    35,    36,    26,    97,    24,     1,    37,    38,   138,
     139,   164,   131,    87,   132,   145,   144,    27,     0,     0,
       0,     0,    39,   112,     0,     0,     0,     0,     2,     3,
       4,     5,     6,     7
};

#define yypact_value_is_default(yystate) \
  ((yystate) == (-128))

#define yytable_value_is_error(yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
      17,    39,    29,     9,    89,    59,     3,     4,     5,     6,
       3,     4,     5,     6,    38,     3,    11,    41,    15,    16,
      17,    21,    15,    16,    17,    22,    23,    65,    23,    22,
      23,    43,    59,   160,   161,    38,    53,   164,    43,    56,
      37,    39,    38,    43,    37,    41,    43,    64,    54,   103,
      43,    44,    69,    44,    60,     7,     8,    21,    96,    11,
      12,     3,     4,     5,     6,    13,   151,    72,    73,    74,
      41,    42,    89,    15,    16,    17,   103,    37,   116,    39,
      22,    23,    26,    27,   111,    29,    30,    18,    19,    20,
       3,     4,     5,     6,   100,    37,     3,    14,   136,   137,
      42,   118,    15,    16,    17,    77,    78,    79,    80,    22,
      23,    16,    17,     3,     4,     5,     6,    40,    25,    26,
      27,    28,    29,    30,    37,    15,    16,    17,    43,    37,
     147,    39,    22,    23,   151,    25,    26,    27,    28,    29,
      30,    31,    38,    33,    34,    35,    36,    37,    41,     9,
      10,    44,    42,    43,    44,    41,    42,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
       3,     4,     5,     6,    25,    26,    27,    28,    29,    30,
      41,    42,    15,    16,    17,    38,    40,    41,    41,    22,
      23,    41,    25,    26,    27,    28,    29,    30,    31,    39,
      33,    34,    35,    36,    37,     3,     4,     5,     6,    42,
      43,    38,     2,    21,    41,     5,    40,    15,    16,    17,
      40,    41,    81,    82,    22,    23,    75,    76,     3,     4,
       5,     6,    37,    31,    37,    33,    34,    35,    36,    37,
      15,    16,    17,     0,    42,    43,     3,    22,    23,    42,
      42,    32,    83,    54,    84,   111,   103,    13,    -1,    -1,
      -1,    -1,    37,    38,    -1,    -1,    -1,    -1,    25,    26,
      27,    28,    29,    30
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    25,    26,    27,    28,    29,    30,    62,    63,
      66,    67,    68,    85,    86,    87,    37,    39,    70,    66,
      66,    64,    65,    67,    43,    77,     0,    86,    38,    69,
       3,     4,     5,     6,    15,    16,    17,    22,    23,    37,
      46,    47,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    39,    41,    42,    21,    77,    44,    78,
      63,    71,    72,    73,    37,    39,    48,    60,    61,    21,
      50,    52,    18,    19,    20,    16,    17,     7,     8,    11,
      12,     9,    10,    13,    14,    40,    60,    65,    67,    43,
      60,    74,    31,    33,    34,    35,    36,    42,    61,    62,
      63,    76,    77,    79,    80,    81,    82,    83,    84,    67,
      38,    41,    38,    49,    60,    61,    39,    38,    41,    60,
      52,    52,    52,    53,    53,    54,    54,    54,    54,    55,
      55,    56,    57,    40,    74,    75,    37,    37,    42,    42,
      42,    61,    42,    44,    80,    73,    38,    41,    40,    61,
      60,    41,    44,    61,    61,    42,    60,    40,    44,    74,
      38,    38,    76,    76,    32,    76
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
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
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
		  Type, Value, Location); \
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
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
#endif
{
  if (!yyvaluep)
    return;
  YYUSE (yylocationp);
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep, yylocationp)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
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
yy_reduce_print (YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yylsp, yyrule)
    YYSTYPE *yyvsp;
    YYLTYPE *yylsp;
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
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       , &(yylsp[(yyi + 1) - (yynrhs)])		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, yylsp, Rule); \
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

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (0, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  YYSIZE_T yysize1;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = 0;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
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
      int yyn = yypact[*yyssp];
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
                yysize1 = yysize + yytnamerr (0, yytname[yyx]);
                if (! (yysize <= yysize1
                       && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                  return 2;
                yysize = yysize1;
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  yysize1 = yysize + yystrlen (yyformat);
  if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
    return 2;
  yysize = yysize1;

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
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
#else
static void
yydestruct (yymsg, yytype, yyvaluep, yylocationp)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
    YYLTYPE *yylocationp;
#endif
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);

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


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Location data for the lookahead symbol.  */
YYLTYPE yylloc;

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
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.
       `yyls': related to locations.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[3];

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;
  yylsp = yyls;

#if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  /* Initialize the default location before parsing starts.  */
  yylloc.first_line   = yylloc.last_line   = 1;
  yylloc.first_column = yylloc.last_column = 1;
#endif

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
	YYLTYPE *yyls1 = yyls;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yyls1, yysize * sizeof (*yylsp),
		    &yystacksize);

	yyls = yyls1;
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
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
	YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;
  *++yylsp = yylloc;
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

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:

/* Line 1806 of yacc.c  */
#line 57 "config/C.y"
    {
	    	(yyval.node) = newgetVarName(symtab, (yyvsp[(1) - (1)].ident)); 
	    	setLoc((yyval.node), (Loc)&((yyloc)));
	  }
    break;

  case 3:

/* Line 1806 of yacc.c  */
#line 62 "config/C.y"
    {
	    	(yyval.node) = newNumber((yyvsp[(1) - (1)].num));
	   	setLoc((yyval.node), (Loc)&((yyloc)));
	   }
    break;

  case 4:

/* Line 1806 of yacc.c  */
#line 67 "config/C.y"
    {
	    	(yyval.node) = newNumber((yyvsp[(1) - (1)].num));
		(yyval.node)->NodeType = newType("float");
	   	setLoc((yyval.node), (Loc)&((yyloc)));
	   }
    break;

  case 5:

/* Line 1806 of yacc.c  */
#line 73 "config/C.y"
    {
	    	(yyval.node) = newBool(1);
	   	setLoc((yyval.node), (Loc)&((yyloc)));
	  }
    break;

  case 6:

/* Line 1806 of yacc.c  */
#line 78 "config/C.y"
    {
	    	(yyval.node) = newBool(0);
	   	setLoc((yyval.node), (Loc)&((yyloc)));
	  }
    break;

  case 7:

/* Line 1806 of yacc.c  */
#line 83 "config/C.y"
    {
	    	(yyval.node) = newConstString((yyvsp[(1) - (1)].str)); 
	    	setLoc((yyval.node), (Loc)&((yyloc)));
	  }
    break;

  case 8:

/* Line 1806 of yacc.c  */
#line 88 "config/C.y"
    {
	    	(yyval.node) = newParenExp((yyvsp[(2) - (3)].node));
	    	setLoc((yyval.node), (Loc)&((yyloc)));
	  }
    break;

  case 9:

/* Line 1806 of yacc.c  */
#line 96 "config/C.y"
    {
		(yyval.node)=(yyvsp[(1) - (1)].node);
		setLoc((yyval.node), (Loc)&((yyloc)));
	  }
    break;

  case 10:

/* Line 1806 of yacc.c  */
#line 101 "config/C.y"
    {
		(yyval.node) = newArrayAccess(newgetVarName(symtab, (yyvsp[(1) - (2)].ident)),(yyvsp[(2) - (2)].node));
		setLoc((yyval.node), (Loc)&((yyloc)));
	  }
    break;

  case 11:

/* Line 1806 of yacc.c  */
#line 106 "config/C.y"
    {	
		if(!strcmp((yyvsp[(1) - (3)].ident),"write"))
			(yyval.node)=newWrite(NULL);
		else if(!strcmp((yyvsp[(1) - (3)].ident),"read"))
			(yyval.node)=newRead(NULL);
		else	
			(yyval.node) = newCall(newgetFuncName(symtab, (yyvsp[(1) - (3)].ident)),newArgList()); 
	    	setLoc((yyval.node), (Loc)&((yyloc)));
	  }
    break;

  case 12:

/* Line 1806 of yacc.c  */
#line 116 "config/C.y"
    {
		if(!strcmp((yyvsp[(1) - (4)].ident),"write"))
			(yyval.node)=newWrite((yyvsp[(3) - (4)].node));
		else if(!strcmp((yyvsp[(1) - (4)].ident),"read"))
			(yyval.node)=newRead((yyvsp[(3) - (4)].node));
		else
			(yyval.node) = newCall(newgetFuncName(symtab, (yyvsp[(1) - (4)].ident)),(yyvsp[(3) - (4)].node)); 
		setLoc((yyval.node), (Loc)&((yyloc)));
	  }
    break;

  case 13:

/* Line 1806 of yacc.c  */
#line 129 "config/C.y"
    {
		(yyval.node) = newArrayDim();
		addLast((yyval.node)->list, (yyvsp[(2) - (3)].node));
		setLoc((yyval.node), (Loc)&((yyloc)));
	}
    break;

  case 14:

/* Line 1806 of yacc.c  */
#line 135 "config/C.y"
    {
		addLast((yyvsp[(1) - (4)].node)->list, (yyvsp[(3) - (4)].node));
		(yyval.node)=(yyvsp[(1) - (4)].node);
	}
    break;

  case 15:

/* Line 1806 of yacc.c  */
#line 143 "config/C.y"
    {
		(yyval.node)=newArgList();
		addLast((yyval.node)->list, (yyvsp[(1) - (1)].node));
	  }
    break;

  case 16:

/* Line 1806 of yacc.c  */
#line 148 "config/C.y"
    {
		addLast((yyvsp[(1) - (3)].node)->list, (yyvsp[(3) - (3)].node));
		(yyval.node)=(yyvsp[(1) - (3)].node);
	   }
    break;

  case 17:

/* Line 1806 of yacc.c  */
#line 156 "config/C.y"
    {
		(yyval.node)=newPrimary((yyvsp[(1) - (1)].node));
		setLoc((yyval.node), (Loc)&((yyloc)));
	  }
    break;

  case 18:

/* Line 1806 of yacc.c  */
#line 161 "config/C.y"
    {
	    	(yyval.node) = newUnaryExp((yyvsp[(1) - (2)].ival), (yyvsp[(2) - (2)].node)); 
	    	setLoc((yyval.node), (Loc)&((yyloc)));
	  }
    break;

  case 19:

/* Line 1806 of yacc.c  */
#line 168 "config/C.y"
    {(yyval.ival) = (yyvsp[(1) - (1)].ival);}
    break;

  case 20:

/* Line 1806 of yacc.c  */
#line 169 "config/C.y"
    {(yyval.ival) = (yyvsp[(1) - (1)].ival);}
    break;

  case 21:

/* Line 1806 of yacc.c  */
#line 170 "config/C.y"
    {(yyval.ival) = (yyvsp[(1) - (1)].ival);}
    break;

  case 22:

/* Line 1806 of yacc.c  */
#line 175 "config/C.y"
    {
		(yyval.node)=(yyvsp[(1) - (1)].node);
		setLoc((yyval.node), (Loc)&((yyloc)));
	  }
    break;

  case 23:

/* Line 1806 of yacc.c  */
#line 183 "config/C.y"
    {
		(yyval.node)=(yyvsp[(1) - (1)].node);
		setLoc((yyval.node), (Loc)&((yyloc)));
	  }
    break;

  case 24:

/* Line 1806 of yacc.c  */
#line 188 "config/C.y"
    {
	    	(yyval.node) = newInfixExp((yyvsp[(2) - (3)].ival), (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); 
	    	setLoc((yyval.node), (Loc)&((yyloc)));
	  }
    break;

  case 25:

/* Line 1806 of yacc.c  */
#line 193 "config/C.y"
    {
	    	(yyval.node) = newInfixExp((yyvsp[(2) - (3)].ival), (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); 
	    	setLoc((yyval.node), (Loc)&((yyloc)));
	  }
    break;

  case 26:

/* Line 1806 of yacc.c  */
#line 198 "config/C.y"
    {
	    	(yyval.node) = newInfixExp((yyvsp[(2) - (3)].ival), (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); 
	    	setLoc((yyval.node), (Loc)&((yyloc)));
	  }
    break;

  case 27:

/* Line 1806 of yacc.c  */
#line 206 "config/C.y"
    {
		(yyval.node)=(yyvsp[(1) - (1)].node);
		setLoc((yyval.node), (Loc)&((yyloc)));
	  }
    break;

  case 28:

/* Line 1806 of yacc.c  */
#line 211 "config/C.y"
    {
	    	(yyval.node) = newInfixExp((yyvsp[(2) - (3)].ival), (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); 
	    	setLoc((yyval.node), (Loc)&((yyloc)));
	  }
    break;

  case 29:

/* Line 1806 of yacc.c  */
#line 216 "config/C.y"
    {
	    	(yyval.node) = newInfixExp((yyvsp[(2) - (3)].ival), (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); 
	    	setLoc((yyval.node), (Loc)&((yyloc)));
	  }
    break;

  case 30:

/* Line 1806 of yacc.c  */
#line 224 "config/C.y"
    {
		(yyval.node)=(yyvsp[(1) - (1)].node);
		setLoc((yyval.node), (Loc)&((yyloc)));
	  }
    break;

  case 31:

/* Line 1806 of yacc.c  */
#line 229 "config/C.y"
    {
	    	(yyval.node) = newInfixExp((yyvsp[(2) - (3)].ival), (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); 
	    	setLoc((yyval.node), (Loc)&((yyloc)));
	  }
    break;

  case 32:

/* Line 1806 of yacc.c  */
#line 234 "config/C.y"
    {
	    	(yyval.node) = newInfixExp((yyvsp[(2) - (3)].ival), (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); 
	    	setLoc((yyval.node), (Loc)&((yyloc)));
	  }
    break;

  case 33:

/* Line 1806 of yacc.c  */
#line 239 "config/C.y"
    {
	    	(yyval.node) = newInfixExp((yyvsp[(2) - (3)].ival), (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); 
	    	setLoc((yyval.node), (Loc)&((yyloc)));
	  }
    break;

  case 34:

/* Line 1806 of yacc.c  */
#line 244 "config/C.y"
    {
	    	(yyval.node) = newInfixExp((yyvsp[(2) - (3)].ival), (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); 
	    	setLoc((yyval.node), (Loc)&((yyloc)));
	  }
    break;

  case 35:

/* Line 1806 of yacc.c  */
#line 252 "config/C.y"
    {
		(yyval.node)=(yyvsp[(1) - (1)].node);
		setLoc((yyval.node), (Loc)&((yyloc)));
	  }
    break;

  case 36:

/* Line 1806 of yacc.c  */
#line 257 "config/C.y"
    {
	    	(yyval.node) = newInfixExp((yyvsp[(2) - (3)].ival), (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); 
	    	setLoc((yyval.node), (Loc)&((yyloc)));
	  }
    break;

  case 37:

/* Line 1806 of yacc.c  */
#line 262 "config/C.y"
    {
	    	(yyval.node) = newInfixExp((yyvsp[(2) - (3)].ival), (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); 
	    	setLoc((yyval.node), (Loc)&((yyloc)));
	  }
    break;

  case 38:

/* Line 1806 of yacc.c  */
#line 270 "config/C.y"
    {
		(yyval.node)=(yyvsp[(1) - (1)].node);
		setLoc((yyval.node), (Loc)&((yyloc)));
	  }
    break;

  case 39:

/* Line 1806 of yacc.c  */
#line 275 "config/C.y"
    {
	    	(yyval.node) = newInfixExp((yyvsp[(2) - (3)].ival), (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); 
	    	setLoc((yyval.node), (Loc)&((yyloc)));
	  }
    break;

  case 40:

/* Line 1806 of yacc.c  */
#line 283 "config/C.y"
    {
		(yyval.node)=(yyvsp[(1) - (1)].node);
		setLoc((yyval.node), (Loc)&((yyloc)));
	  }
    break;

  case 41:

/* Line 1806 of yacc.c  */
#line 288 "config/C.y"
    {
	    	(yyval.node) = newInfixExp((yyvsp[(2) - (3)].ival), (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); 
	    	setLoc((yyval.node), (Loc)&((yyloc)));
	  }
    break;

  case 42:

/* Line 1806 of yacc.c  */
#line 296 "config/C.y"
    {
		(yyval.node)=(yyvsp[(1) - (1)].node);
		setLoc((yyval.node), (Loc)&((yyloc)));
	  }
    break;

  case 43:

/* Line 1806 of yacc.c  */
#line 304 "config/C.y"
    {
		(yyval.node)=(yyvsp[(1) - (1)].node);
		setLoc((yyval.node), (Loc)&((yyloc)));
	  }
    break;

  case 44:

/* Line 1806 of yacc.c  */
#line 309 "config/C.y"
    {
	    	(yyval.node) = newAssignment((yyvsp[(2) - (3)].ival), (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
	    	setLoc((yyval.node), (Loc)&((yyloc)));
	  }
    break;

  case 45:

/* Line 1806 of yacc.c  */
#line 317 "config/C.y"
    {
		(yyval.node)=(yyvsp[(1) - (1)].node);
		setLoc((yyval.node), (Loc)&((yyloc)));
	  }
    break;

  case 46:

/* Line 1806 of yacc.c  */
#line 322 "config/C.y"
    {
	    	(yyval.node) = newCommaExp((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); 
	    	setLoc((yyval.node), (Loc)&((yyloc)));
	  }
    break;

  case 47:

/* Line 1806 of yacc.c  */
#line 330 "config/C.y"
    {
		if(thereareparam==1)
		{
			yyerror("\nerror : function declaration doesn't have parameters\n");
			return 0;
		}		
		if(!strcmp((yyvsp[(1) - (3)].node)->type,"void") && !is_funccc)
		{
			yyerror("\nerror : variable cannot be void\n");
			return 0;
		}
		switch((yyvsp[(1) - (3)].node)->type0_const1_typedef2)
		{	
			case 0:{
				setListType((yyvsp[(2) - (3)].node)->list,(yyvsp[(1) - (3)].node));
				(yyval.node) = newDeclaration(symtab,(yyvsp[(1) - (3)].node),(yyvsp[(2) - (3)].node));
				break;
			}
			case 1:{
				setListType((yyvsp[(2) - (3)].node)->list,(yyvsp[(1) - (3)].node));
				(yyval.node) = newConstDeclaration(symtab,(yyvsp[(1) - (3)].node),(yyvsp[(2) - (3)].node));
				break;
			}
			case 2:{
				setRenameListType((yyvsp[(2) - (3)].node)->list,(yyvsp[(1) - (3)].node));
				(yyval.node) = newTypedefDeclaration((yyvsp[(1) - (3)].node),(yyvsp[(2) - (3)].node));
				break;
			}
			default: yyerror("\nerror : type problem\n");return 0;break;
		}
		setLoc((yyval.node), (Loc)&((yyloc)));
	  }
    break;

  case 48:

/* Line 1806 of yacc.c  */
#line 366 "config/C.y"
    {
		(yyvsp[(2) - (2)].node)->type0_const1_typedef2 = 2;
		(yyval.node)=(yyvsp[(2) - (2)].node);
		setLoc((yyval.node), (Loc)&((yyloc)));
	  }
    break;

  case 49:

/* Line 1806 of yacc.c  */
#line 372 "config/C.y"
    {
		(yyvsp[(1) - (1)].node)->type0_const1_typedef2 = 0;
		(yyval.node)=(yyvsp[(1) - (1)].node);
		setLoc((yyval.node), (Loc)&((yyloc)));
	  }
    break;

  case 50:

/* Line 1806 of yacc.c  */
#line 378 "config/C.y"
    {
		(yyvsp[(2) - (2)].node)->type0_const1_typedef2 = 1;
		(yyval.node)=(yyvsp[(2) - (2)].node);
		setLoc((yyval.node), (Loc)&((yyloc)));
	  }
    break;

  case 51:

/* Line 1806 of yacc.c  */
#line 387 "config/C.y"
    {
		(yyval.node)=newDeclList();
		addLast((yyval.node)->list, (yyvsp[(1) - (1)].node));
		setLoc((yyval.node), (Loc)&((yyloc)));
	  }
    break;

  case 52:

/* Line 1806 of yacc.c  */
#line 393 "config/C.y"
    {
		addLast((yyvsp[(1) - (3)].node)->list, (yyvsp[(3) - (3)].node));
		(yyval.node)=(yyvsp[(1) - (3)].node);
		setLoc((yyval.node), (Loc)&((yyloc)));
	  }
    break;

  case 53:

/* Line 1806 of yacc.c  */
#line 402 "config/C.y"
    {
		(yyval.node)=(yyvsp[(1) - (1)].node);
		setLoc((yyval.node), (Loc)&((yyloc)));
	  }
    break;

  case 54:

/* Line 1806 of yacc.c  */
#line 407 "config/C.y"
    {
		SetInitialValue(symtab,(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node));
		(yyval.node)=(yyvsp[(1) - (3)].node);
		setLoc((yyval.node), (Loc)&((yyloc)));
	  }
    break;

  case 55:

/* Line 1806 of yacc.c  */
#line 415 "config/C.y"
    {(yyval.node) = newType("void");}
    break;

  case 56:

/* Line 1806 of yacc.c  */
#line 416 "config/C.y"
    {(yyval.node) = newType("int");}
    break;

  case 57:

/* Line 1806 of yacc.c  */
#line 417 "config/C.y"
    {(yyval.node) = newType("float");}
    break;

  case 58:

/* Line 1806 of yacc.c  */
#line 418 "config/C.y"
    {(yyval.node) = newType("bool");}
    break;

  case 59:

/* Line 1806 of yacc.c  */
#line 425 "config/C.y"
    {
		(yyval.node)=(yyvsp[(1) - (1)].node);
		setLoc((yyval.node), (Loc)&((yyloc)));
	  }
    break;

  case 60:

/* Line 1806 of yacc.c  */
#line 434 "config/C.y"
    {
		is_funccc=FALSE;
		(yyval.node) = newVarName(symtab,(yyvsp[(1) - (1)].ident));
		SetArrayDim(symtab,(yyval.node),newArrayDim());
		setLoc((yyval.node), (Loc)&((yyloc)));
	  }
    break;

  case 61:

/* Line 1806 of yacc.c  */
#line 441 "config/C.y"
    {
		is_funccc=FALSE;
		(yyval.node) = newVarName(symtab,(yyvsp[(1) - (2)].ident));
		SetArrayDim(symtab,(yyval.node),(yyvsp[(2) - (2)].node));
		setLoc((yyval.node), (Loc)&((yyloc)));
	  }
    break;

  case 62:

/* Line 1806 of yacc.c  */
#line 447 "config/C.y"
    {	symtab=newTable(symtab);				////// newtable
				thereareparam=1;	}
    break;

  case 63:

/* Line 1806 of yacc.c  */
#line 450 "config/C.y"
    {
		is_funccc=TRUE;
		(yyval.node) = newFuncDecl(symtab->parent,(yyvsp[(1) - (5)].ident),(yyvsp[(4) - (5)].node));
		setLoc((yyval.node), (Loc)&((yyloc)));
	  }
    break;

  case 64:

/* Line 1806 of yacc.c  */
#line 456 "config/C.y"
    {
		is_funccc=TRUE;
		(yyval.node) = newFuncDecl(symtab,(yyvsp[(1) - (3)].ident),NULL);
		setLoc((yyval.node), (Loc)&((yyloc)));
	  }
    break;

  case 65:

/* Line 1806 of yacc.c  */
#line 465 "config/C.y"
    { 
		(yyval.node)=newArrayDim();
		addLast((yyval.node)->list, newNumber(EvalExp((yyvsp[(2) - (3)].node))));
		setLoc((yyval.node), (Loc)&((yyloc)));
	  }
    break;

  case 66:

/* Line 1806 of yacc.c  */
#line 471 "config/C.y"
    {
		addLast((yyvsp[(1) - (4)].node)->list, newNumber(EvalExp((yyvsp[(3) - (4)].node))));
		(yyval.node)=(yyvsp[(1) - (4)].node);
		setLoc((yyval.node), (Loc)&((yyloc)));
	  }
    break;

  case 67:

/* Line 1806 of yacc.c  */
#line 479 "config/C.y"
    {
		(yyval.node)=(yyvsp[(1) - (1)].node);
		setLoc((yyval.node), (Loc)&((yyloc)));
	  }
    break;

  case 68:

/* Line 1806 of yacc.c  */
#line 487 "config/C.y"
    {
		(yyval.node)=newParamList();
		addLast((yyval.node)->list, (yyvsp[(1) - (1)].node));
		setLoc((yyval.node), (Loc)&((yyloc)));
	  }
    break;

  case 69:

/* Line 1806 of yacc.c  */
#line 493 "config/C.y"
    {
		addLast((yyvsp[(1) - (3)].node)->list, (yyvsp[(3) - (3)].node));
		(yyval.node)=(yyvsp[(1) - (3)].node);
		setLoc((yyval.node), (Loc)&((yyloc)));
	  }
    break;

  case 70:

/* Line 1806 of yacc.c  */
#line 502 "config/C.y"
    {	
		if(!strcmp((yyvsp[(1) - (2)].node)->type,"void"))
		{
			yyerror("\nerror : variable cannot be void\n");
			return 0;
		}
		if(is_funccc)		
		{
			yyerror("\nerror : parameter cannot be function\n");
			return 0;
		}
		switch((yyvsp[(1) - (2)].node)->type0_const1_typedef2)
		{	
			case 0:{
				if((yyvsp[(2) - (2)].node)->kind!=KVarName || (yyvsp[(2) - (2)].node)->sym->dim > 0){
					yyerror("\nerror: not allowed kind of parameter!\n");return 0;}
				if((yyvsp[(1) - (2)].node)->NodeType)
					if(type_exist_sym(symtab,(yyvsp[(1) - (2)].node)->type)->dim > 0){
						yyerror("\nerror: not allowed parameter type(cannot be array)!\n");return 0;}
			//in the var
				(yyvsp[(2) - (2)].node)->NodeType = (yyvsp[(1) - (2)].node);
				(yyvsp[(2) - (2)].node)->sym->type = 1;		//becomes var
				(yyvsp[(2) - (2)].node)->sym->addr = symtab->dx;
				symtab->dx = symtab->dx + 1;
				(yyvsp[(2) - (2)].node)->sym->lev = symtab->lev;
			//
				(yyvsp[(2) - (2)].node)->sym->symType = (yyvsp[(1) - (2)].node);
				(yyval.node)=newParam((yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].node)); 
				break;
			}
			case 1:{
				yyerror("\nerror: not allowed parameter type(cannot be const)!\n");return 0;
				break;
			}
			case 2:{
				yyerror("\nerror: not allowed parameter type(cannot be typedef)!\n");return 0;
				break;
			}
			default: yyerror("\nerror : type problem\n");return 0;break;
		}
		setLoc((yyval.node), (Loc)&((yyloc)));
	  }
    break;

  case 71:

/* Line 1806 of yacc.c  */
#line 548 "config/C.y"
    {
		(yyval.node)=(yyvsp[(1) - (1)].node);	
		setLoc((yyval.node), (Loc)&((yyloc)));
	  }
    break;

  case 72:

/* Line 1806 of yacc.c  */
#line 553 "config/C.y"
    {
		(yyval.node)=(yyvsp[(2) - (3)].node);	
		setLoc((yyval.node), (Loc)&((yyloc)));
	  }
    break;

  case 73:

/* Line 1806 of yacc.c  */
#line 558 "config/C.y"
    {
		(yyval.node)=(yyvsp[(2) - (4)].node);	
		setLoc((yyval.node), (Loc)&((yyloc)));
	  }
    break;

  case 74:

/* Line 1806 of yacc.c  */
#line 566 "config/C.y"
    {
		(yyval.node)=newListInitExp();	
		addLast((yyval.node)->list, (yyvsp[(1) - (1)].node));
		setLoc((yyval.node), (Loc)&((yyloc)));
	 }
    break;

  case 75:

/* Line 1806 of yacc.c  */
#line 572 "config/C.y"
    {	
		addLast((yyvsp[(1) - (3)].node)->list, (yyvsp[(3) - (3)].node));
		(yyval.node)=(yyvsp[(1) - (3)].node);
		setLoc((yyval.node), (Loc)&((yyloc)));
	  }
    break;

  case 76:

/* Line 1806 of yacc.c  */
#line 581 "config/C.y"
    {
		(yyval.node) = newStmt((yyvsp[(1) - (1)].node)); 
	    	setLoc((yyval.node), (Loc)&((yyloc)));
	  }
    break;

  case 77:

/* Line 1806 of yacc.c  */
#line 586 "config/C.y"
    {
		(yyval.node) = newStmt((yyvsp[(1) - (1)].node)); 
	    	setLoc((yyval.node), (Loc)&((yyloc)));
	  }
    break;

  case 78:

/* Line 1806 of yacc.c  */
#line 591 "config/C.y"
    {
		(yyval.node) = newStmt((yyvsp[(1) - (1)].node)); 
	    	setLoc((yyval.node), (Loc)&((yyloc)));
	  }
    break;

  case 79:

/* Line 1806 of yacc.c  */
#line 596 "config/C.y"
    {
		(yyval.node) = newStmt((yyvsp[(1) - (1)].node)); 
	    	setLoc((yyval.node), (Loc)&((yyloc)));
	  }
    break;

  case 80:

/* Line 1806 of yacc.c  */
#line 601 "config/C.y"
    {
		(yyval.node) = newStmt((yyvsp[(1) - (1)].node)); 
	    	setLoc((yyval.node), (Loc)&((yyloc)));
	  }
    break;

  case 81:

/* Line 1806 of yacc.c  */
#line 609 "config/C.y"
    {
		(yyval.node)=newBlock();
		(yyval.node)->dx = symtab->dx;			//dx
		if(thereareparam)
		{
			thereareparam=0;
			if(symtab->parent->parent != NULL)
				symtab->parent->dx = symtab->dx;
			symtab=symtab->parent;			/////////////// parent table
		}
		setLoc((yyval.node), (Loc)&((yyloc)));
	  }
    break;

  case 82:

/* Line 1806 of yacc.c  */
#line 621 "config/C.y"
    {	 
			 if(thereareparam==0)
				symtab=newTable(symtab);			////// newtable
			 else
				thereareparam=0;
		}
    break;

  case 83:

/* Line 1806 of yacc.c  */
#line 628 "config/C.y"
    {
		(yyval.node)=(yyvsp[(3) - (4)].node);
		(yyval.node)->dx = symtab->dx;			//dx
		if(symtab->parent->parent != NULL)
				symtab->parent->dx = symtab->dx;
		symtab=symtab->parent;			/////////////// parent table
		setLoc((yyval.node), (Loc)&((yyloc)));
	  }
    break;

  case 84:

/* Line 1806 of yacc.c  */
#line 640 "config/C.y"
    {
		(yyval.node)=newBlock();
		addLast((yyval.node)->list, (yyvsp[(1) - (1)].node));
		setLoc((yyval.node), (Loc)&((yyloc)));
	  }
    break;

  case 85:

/* Line 1806 of yacc.c  */
#line 646 "config/C.y"
    {
		addLast((yyvsp[(1) - (2)].node)->list, (yyvsp[(2) - (2)].node));
		(yyval.node)=(yyvsp[(1) - (2)].node);
		setLoc((yyval.node), (Loc)&((yyloc)));
	  }
    break;

  case 86:

/* Line 1806 of yacc.c  */
#line 655 "config/C.y"
    {
	    	(yyval.node) = (yyvsp[(1) - (1)].node); 
	    	setLoc((yyval.node), (Loc)&((yyloc)));
	  }
    break;

  case 87:

/* Line 1806 of yacc.c  */
#line 660 "config/C.y"
    {
	    	(yyval.node) = (yyvsp[(1) - (1)].node); 
	    	setLoc((yyval.node), (Loc)&((yyloc)));
	  }
    break;

  case 88:

/* Line 1806 of yacc.c  */
#line 668 "config/C.y"
    {
	    	(yyval.node) = newExpStmt(NULL); 
	    	setLoc((yyval.node), (Loc)&((yyloc)));
	  }
    break;

  case 89:

/* Line 1806 of yacc.c  */
#line 673 "config/C.y"
    {
		(yyval.node) = newExpStmt((yyvsp[(1) - (2)].node)); 
	    	setLoc((yyval.node), (Loc)&((yyloc)));
	  }
    break;

  case 90:

/* Line 1806 of yacc.c  */
#line 681 "config/C.y"
    {
	    	(yyval.node) = newIfStmt((yyvsp[(3) - (5)].node), (yyvsp[(5) - (5)].node)); 
	    	setLoc((yyval.node), (Loc)&((yyloc)));
	  }
    break;

  case 91:

/* Line 1806 of yacc.c  */
#line 686 "config/C.y"
    {
	    	(yyval.node) = newIfElseStmt((yyvsp[(3) - (7)].node), (yyvsp[(5) - (7)].node), (yyvsp[(7) - (7)].node)); 
	    	setLoc((yyval.node), (Loc)&((yyloc)));
	  }
    break;

  case 92:

/* Line 1806 of yacc.c  */
#line 694 "config/C.y"
    {
	    	(yyval.node) = newWhileStmt((yyvsp[(3) - (5)].node), (yyvsp[(5) - (5)].node)); 
	    	setLoc((yyval.node), (Loc)&((yyloc)));
	  }
    break;

  case 93:

/* Line 1806 of yacc.c  */
#line 702 "config/C.y"
    {
	    	(yyval.node) = newContinue(); 
	    	setLoc((yyval.node), (Loc)&((yyloc)));
	  }
    break;

  case 94:

/* Line 1806 of yacc.c  */
#line 707 "config/C.y"
    {
	    	(yyval.node) = newBreak(); 
	    	setLoc((yyval.node), (Loc)&((yyloc)));
	  }
    break;

  case 95:

/* Line 1806 of yacc.c  */
#line 712 "config/C.y"
    {
	    	(yyval.node) = newReturn(NULL); 
	    	setLoc((yyval.node), (Loc)&((yyloc)));
	  }
    break;

  case 96:

/* Line 1806 of yacc.c  */
#line 717 "config/C.y"
    {
	    	(yyval.node) = newReturn((yyvsp[(2) - (3)].node)); 
	    	setLoc((yyval.node), (Loc)&((yyloc)));
	  }
    break;

  case 97:

/* Line 1806 of yacc.c  */
#line 725 "config/C.y"
    {
	    	(yyval.node) = newProgram();
		addLast((yyval.node)->list, (yyvsp[(1) - (1)].node));
		(yyval.node)->dx = symtab->dx;			//dx
		(yyval.node)->num_funcs = symtab->func_num;
		ast->root = (yyval.node);
	  }
    break;

  case 98:

/* Line 1806 of yacc.c  */
#line 733 "config/C.y"
    {
	    	addLast((yyvsp[(1) - (2)].node)->list, (yyvsp[(2) - (2)].node));
	   	(yyval.node) = (yyvsp[(1) - (2)].node);
		(yyval.node)->dx = symtab->dx;			//dx
		(yyval.node)->num_funcs = symtab->func_num;
	   	setLoc((yyval.node), (Loc)&((yyloc)));
	  }
    break;

  case 99:

/* Line 1806 of yacc.c  */
#line 744 "config/C.y"
    {
		(yyval.node)=(yyvsp[(1) - (1)].node);
		setLoc((yyval.node), (Loc)&((yyloc)));
	  }
    break;

  case 100:

/* Line 1806 of yacc.c  */
#line 749 "config/C.y"
    {
		(yyval.node)=(yyvsp[(1) - (1)].node);
		setLoc((yyval.node), (Loc)&((yyloc)));
	  }
    break;

  case 101:

/* Line 1806 of yacc.c  */
#line 757 "config/C.y"
    {
		(yyval.node) = newFuncDef((yyvsp[(1) - (3)].node),(yyvsp[(2) - (3)].node),(yyvsp[(3) - (3)].node));
	   	setLoc((yyval.node), (Loc)&((yyloc)));
	  }
    break;

  case 102:

/* Line 1806 of yacc.c  */
#line 762 "config/C.y"
    {
		(yyval.node) = newFuncDef(newType("int"),(yyvsp[(1) - (2)].node),(yyvsp[(2) - (2)].node));
	   	setLoc((yyval.node), (Loc)&((yyloc)));
	  }
    break;



/* Line 1806 of yacc.c  */
#line 2793 "src/C.tab.c"
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
  *++yylsp = yyloc;

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
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
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

  yyerror_range[1] = yylloc;

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
		      yytoken, &yylval, &yylloc);
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  yyerror_range[1] = yylsp[1-yylen];
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

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;

  yyerror_range[2] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
  *++yylsp = yyloc;

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

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp, yylsp);
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



/* Line 2067 of yacc.c  */
#line 769 "config/C.y"


extern char yytext[];
extern int column;

int yyerror(char const *s)
{
	fflush(stdout);
	printf("\n%*s\n%*s\n", column, "^", column, s);
}

int main(int argc, char *argv[])
{
	thereareparam = 0;	
	symtab = newTable(NULL);//newFuncName(symtab, "write");newFuncName(symtab, "read");
	errfactory = newErrFactory();
	ast = newAST();
	printf("Parsing ...\n");
  	yyparse();
	printf("\n\nDump the program from the generated AST:\n");
	printf("\n==========================================\n");
	dumpAST(ast->root);
	binarycode(ast->root);
	//destroyAST(&ast->root);
	dumpErrors(errfactory);
	dumpWarnings(errfactory);
	if(symtab)
		destroyTable(&symtab);
	destroyErrFactory(&errfactory);
 	return(0);
}



