
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "parser.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "tree.h"

#define YYSTYPE TreeNode*

void yyerror(const char *s);
extern int yylex();
extern FILE *yyin;
extern int yylineno;

TreeNode* root;
bool noError = true;


/* Line 189 of yacc.c  */
#line 92 "parser.tab.c"

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
     INT = 258,
     VOID = 259,
     RETURN = 260,
     IF = 261,
     ELSE = 262,
     WHILE = 263,
     DO = 264,
     FOR = 265,
     BREAK = 266,
     CONTINUE = 267,
     IDENTIFIER = 268,
     NUMBER = 269,
     STRING = 270,
     LBRACE = 271,
     RBRACE = 272,
     LPAREN = 273,
     RPAREN = 274,
     SEMICOLON = 275,
     COMMA = 276,
     ASSIGN = 277,
     PLUSASSIGN = 278,
     MINUSASSIGN = 279,
     TIMESASSIGN = 280,
     DIVIDEASSIGN = 281,
     MODEASSIGN = 282,
     EQ = 283,
     NE = 284,
     LE = 285,
     GE = 286,
     LT = 287,
     GT = 288,
     LOGICAL_AND = 289,
     LOGICAL_OR = 290,
     PLUSPLUS = 291,
     MINUSMINUS = 292,
     AND = 293,
     NOT = 294,
     PLUS = 295,
     MINUS = 296,
     TIMES = 297,
     DIVIDE = 298,
     MODE = 299
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 178 "parser.tab.c"

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
# if YYENABLE_NLS
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

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

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   165

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  45
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  38
/* YYNRULES -- Number of rules.  */
#define YYNRULES  96
/* YYNRULES -- Number of states.  */
#define YYNSTATES  157

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   299

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     6,     9,    16,    18,    20,    21,
      23,    25,    29,    32,    36,    39,    40,    43,    45,    47,
      49,    51,    53,    55,    57,    59,    61,    63,    66,    69,
      73,    75,    77,    81,    83,    87,    92,    94,    96,    98,
     100,   102,   104,   110,   118,   121,   127,   130,   138,   141,
     149,   152,   156,   159,   162,   165,   168,   171,   173,   175,
     177,   181,   183,   187,   189,   193,   197,   199,   203,   207,
     211,   215,   217,   221,   225,   227,   231,   235,   239,   241,
     244,   247,   250,   253,   255,   258,   261,   263,   265,   267,
     271,   273,   278,   279,   281,   283,   287
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      46,     0,    -1,    47,    -1,    -1,    47,    48,    -1,    49,
      13,    18,    50,    19,    53,    -1,     3,    -1,     4,    -1,
      -1,    51,    -1,    52,    -1,    51,    21,    52,    -1,    57,
      13,    -1,    16,    54,    17,    -1,     1,    17,    -1,    -1,
      54,    55,    -1,    56,    -1,    60,    -1,    53,    -1,    62,
      -1,    63,    -1,    64,    -1,    65,    -1,    66,    -1,    67,
      -1,    68,    -1,     1,    20,    -1,     1,    17,    -1,    57,
      58,    20,    -1,     3,    -1,    59,    -1,    58,    21,    59,
      -1,    13,    -1,    13,    22,    69,    -1,    13,    61,    69,
      20,    -1,    22,    -1,    23,    -1,    24,    -1,    25,    -1,
      26,    -1,    27,    -1,     6,    18,    69,    19,    55,    -1,
       6,    18,    69,    19,    55,     7,    55,    -1,     1,    17,
      -1,     8,    18,    69,    19,    55,    -1,     1,    17,    -1,
       9,    55,     8,    18,    69,    19,    20,    -1,     1,    20,
      -1,    10,    18,    55,    67,    69,    19,    55,    -1,     1,
      17,    -1,     5,    69,    20,    -1,     5,    20,    -1,    11,
      20,    -1,    12,    20,    -1,    69,    20,    -1,     1,    20,
      -1,    20,    -1,    70,    -1,    71,    -1,    70,    35,    71,
      -1,    72,    -1,    71,    34,    72,    -1,    73,    -1,    72,
      28,    73,    -1,    72,    29,    73,    -1,    74,    -1,    73,
      32,    74,    -1,    73,    33,    74,    -1,    73,    30,    74,
      -1,    73,    31,    74,    -1,    75,    -1,    74,    40,    75,
      -1,    74,    41,    75,    -1,    76,    -1,    75,    42,    76,
      -1,    75,    43,    76,    -1,    75,    44,    76,    -1,    77,
      -1,    36,    76,    -1,    37,    76,    -1,    38,    76,    -1,
      39,    76,    -1,    78,    -1,    77,    36,    -1,    77,    37,
      -1,    13,    -1,    14,    -1,    15,    -1,    18,    69,    19,
      -1,    79,    -1,    13,    18,    80,    19,    -1,    -1,    81,
      -1,    82,    -1,    81,    21,    82,    -1,    69,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    31,    31,    34,    35,    43,    51,    52,    55,    56,
      62,    66,    74,    83,    87,    90,    91,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   113,
     120,   123,   127,   135,   136,   142,   150,   151,   152,   153,
     154,   155,   158,   163,   169,   172,   177,   180,   185,   188,
     196,   199,   203,   204,   205,   208,   212,   215,   219,   222,
     223,   230,   231,   238,   239,   244,   251,   252,   257,   262,
     267,   274,   275,   280,   287,   288,   293,   298,   305,   306,
     310,   314,   318,   324,   325,   329,   335,   336,   337,   338,
     339,   344,   350,   351,   354,   358,   365
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INT", "VOID", "RETURN", "IF", "ELSE",
  "WHILE", "DO", "FOR", "BREAK", "CONTINUE", "IDENTIFIER", "NUMBER",
  "STRING", "LBRACE", "RBRACE", "LPAREN", "RPAREN", "SEMICOLON", "COMMA",
  "ASSIGN", "PLUSASSIGN", "MINUSASSIGN", "TIMESASSIGN", "DIVIDEASSIGN",
  "MODEASSIGN", "EQ", "NE", "LE", "GE", "LT", "GT", "LOGICAL_AND",
  "LOGICAL_OR", "PLUSPLUS", "MINUSMINUS", "AND", "NOT", "PLUS", "MINUS",
  "TIMES", "DIVIDE", "MODE", "$accept", "Program", "FunctionList",
  "Function", "ReturnDatatype", "ParametersDeclaration", "ParameterList",
  "Parameter", "CompoundStatement", "StatementList", "Statement",
  "DeclarationStatement", "DeclarationDatatype", "DeclaratorList",
  "Declarator", "AssignmentStatement", "AssignOperator", "IfStatement",
  "WhileStatement", "DoWhileStatement", "ForStatement", "JumpStatement",
  "ExpressionStatement", "EmptyStatement", "Expression",
  "LogicalOrExpression", "LogicalAndExpression", "EqualityExpression",
  "RelationalExpression", "AdditiveExpression", "MultiplicativeExpression",
  "PrefixExpression", "PostfixExpression", "PrimaryExpression",
  "FunctionCall", "Arguments", "ArgumentList", "Argument", 0
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
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    45,    46,    47,    47,    48,    49,    49,    50,    50,
      51,    51,    52,    53,    53,    54,    54,    55,    55,    55,
      55,    55,    55,    55,    55,    55,    55,    55,    55,    56,
      57,    58,    58,    59,    59,    60,    61,    61,    61,    61,
      61,    61,    62,    62,    62,    63,    63,    64,    64,    65,
      65,    66,    66,    66,    66,    67,    67,    68,    69,    70,
      70,    71,    71,    72,    72,    72,    73,    73,    73,    73,
      73,    74,    74,    74,    75,    75,    75,    75,    76,    76,
      76,    76,    76,    77,    77,    77,    78,    78,    78,    78,
      78,    79,    80,    80,    81,    81,    82
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     0,     2,     6,     1,     1,     0,     1,
       1,     3,     2,     3,     2,     0,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     2,     3,
       1,     1,     3,     1,     3,     4,     1,     1,     1,     1,
       1,     1,     5,     7,     2,     5,     2,     7,     2,     7,
       2,     3,     2,     2,     2,     2,     2,     1,     1,     1,
       3,     1,     3,     1,     3,     3,     1,     3,     3,     3,
       3,     1,     3,     3,     1,     3,     3,     3,     1,     2,
       2,     2,     2,     1,     2,     2,     1,     1,     1,     3,
       1,     4,     0,     1,     1,     3,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,     2,     1,     6,     7,     4,     0,     0,     8,
      30,     0,     9,    10,     0,     0,     0,    12,     0,    15,
       5,    11,    14,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    86,    87,    88,    13,     0,    57,     0,     0,
       0,     0,    19,    16,    17,     0,    18,    20,    21,    22,
      23,    24,    25,    26,     0,    58,    59,    61,    63,    66,
      71,    74,    78,    83,    90,    14,    27,    86,    52,     0,
       0,     0,     0,     0,    53,    54,    92,    36,    37,    38,
      39,    40,    41,     0,     0,    79,    80,    81,    82,    33,
       0,    31,    55,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    84,    85,    51,     0,
       0,     0,     0,    96,     0,    93,    94,     0,    89,     0,
      29,     0,    60,    62,    64,    65,    69,    70,    67,    68,
      72,    73,    75,    76,    77,     0,     0,     0,     0,     0,
      91,     0,    35,    34,    32,    42,    45,     0,    56,     0,
      95,     0,     0,     0,    43,    47,    49
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     1,     2,     6,     7,    11,    12,    13,    42,    23,
      43,    44,    45,    90,    91,    46,    83,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,   114,   115,   116
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -50
static const yytype_int16 yypact[] =
{
     -50,     7,    96,   -50,   -50,   -50,   -50,    15,    42,    30,
     -50,    56,    37,   -50,    23,     8,    30,   -50,    60,   -50,
     -50,   -50,   -50,     5,     9,    17,    62,    72,    73,    76,
      86,    98,    39,   -50,   -50,   -50,    83,   -50,    83,    83,
      83,    83,   -50,   -50,   -50,    79,   -50,   -50,   -50,   -50,
     -50,   -50,   -50,   -50,   104,    81,   105,    74,    40,    64,
      -4,   -50,    93,   -50,   -50,   -50,   -50,   120,   -50,   121,
      83,    83,   132,    73,   -50,   -50,    83,   -50,   -50,   -50,
     -50,   -50,   -50,    83,   123,   -50,   -50,   -50,   -50,   122,
     112,   -50,   -50,    83,    83,    83,    83,    83,    83,    83,
      83,    83,    83,    83,    83,    83,   -50,   -50,   -50,   124,
     126,   128,   113,   -50,   129,   133,   -50,   127,   -50,    83,
     -50,    79,   105,    74,    40,    40,    64,    64,    64,    64,
      -4,    -4,   -50,   -50,   -50,    73,    73,    83,   135,    83,
     -50,    83,   -50,   -50,   -50,   146,   -50,   137,   -50,   138,
     -50,    73,   139,    73,   -50,   -50,   -50
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -50,   -50,   -50,   -50,   -50,   -50,   -50,   142,   145,   -50,
     -28,   -50,    18,   -50,    43,   -50,   -50,   -50,   -50,   -50,
     -50,   -50,    49,   -50,   -24,   -50,    69,    71,    41,   -49,
      33,   -36,   -50,   -50,   -50,   -50,   -50,    22
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      72,    69,    85,    86,    87,    88,    24,     3,    10,    18,
      25,    26,    84,    27,    28,    29,    30,    31,    32,    33,
      34,    19,    35,    36,    19,    37,    65,    14,     8,    66,
      67,    33,    34,    10,    14,    36,    17,    68,   103,   104,
     105,    38,    39,    40,    41,   112,   109,   110,   126,   127,
     128,   129,   113,    38,    39,    40,    41,    76,    16,   117,
       9,    77,    78,    79,    80,    81,    82,   132,   133,   134,
      97,    98,    99,   100,    24,    15,    10,    22,    25,    26,
      70,    27,    28,    29,    30,    31,    32,    33,    34,    19,
      71,    36,    89,    37,    73,   143,    67,    33,    34,     4,
       5,    36,    95,    96,   101,   102,    74,   145,   146,    38,
      39,    40,    41,   147,   138,   149,    93,   113,    75,    38,
      39,    40,    41,   154,    92,   156,    67,    33,    34,   106,
     107,    36,   120,   121,   130,   131,   124,   125,    76,    94,
     111,   108,   118,   135,   119,   136,   137,   142,   140,    38,
      39,    40,    41,   151,   141,   148,   152,   153,    21,   155,
      20,   139,   122,   150,   144,   123
};

static const yytype_uint8 yycheck[] =
{
      28,    25,    38,    39,    40,    41,     1,     0,     3,     1,
       5,     6,    36,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    16,    20,    17,     9,    13,    20,
      13,    14,    15,     3,    16,    18,    13,    20,    42,    43,
      44,    36,    37,    38,    39,    73,    70,    71,    97,    98,
      99,   100,    76,    36,    37,    38,    39,    18,    21,    83,
      18,    22,    23,    24,    25,    26,    27,   103,   104,   105,
      30,    31,    32,    33,     1,    19,     3,    17,     5,     6,
      18,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      18,    18,    13,    20,    18,   119,    13,    14,    15,     3,
       4,    18,    28,    29,    40,    41,    20,   135,   136,    36,
      37,    38,    39,   137,     1,   139,    35,   141,    20,    36,
      37,    38,    39,   151,    20,   153,    13,    14,    15,    36,
      37,    18,    20,    21,   101,   102,    95,    96,    18,    34,
       8,    20,    19,    19,    22,    19,    18,    20,    19,    36,
      37,    38,    39,     7,    21,    20,    19,    19,    16,    20,
      15,   112,    93,   141,   121,    94
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    46,    47,     0,     3,     4,    48,    49,    13,    18,
       3,    50,    51,    52,    57,    19,    21,    13,     1,    16,
      53,    52,    17,    54,     1,     5,     6,     8,     9,    10,
      11,    12,    13,    14,    15,    17,    18,    20,    36,    37,
      38,    39,    53,    55,    56,    57,    60,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    17,    20,    13,    20,    69,
      18,    18,    55,    18,    20,    20,    18,    22,    23,    24,
      25,    26,    27,    61,    69,    76,    76,    76,    76,    13,
      58,    59,    20,    35,    34,    28,    29,    30,    31,    32,
      33,    40,    41,    42,    43,    44,    36,    37,    20,    69,
      69,     8,    55,    69,    80,    81,    82,    69,    19,    22,
      20,    21,    71,    72,    73,    73,    74,    74,    74,    74,
      75,    75,    76,    76,    76,    19,    19,    18,     1,    67,
      19,    21,    20,    69,    59,    55,    55,    69,    20,    69,
      82,     7,    19,    19,    55,    20,    55
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
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
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
# if YYLTYPE_IS_TRIVIAL
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
		  Type, Value); \
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
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
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
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
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
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

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

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

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

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
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

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

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
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

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
  if (yyn == YYPACT_NINF)
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
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


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:

/* Line 1455 of yacc.c  */
#line 31 "parser.y"
    { root = (yyvsp[(1) - (1)]); ;}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 34 "parser.y"
    { (yyval) = createNode("FunctionList", NULL, 0); ;}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 35 "parser.y"
    { 
                (yyval) = createNode("FunctionList", NULL, (yyvsp[(1) - (2)])->numChildren + 1);
                for (int i = 0; i < (yyvsp[(1) - (2)])->numChildren; i++) (yyval)->children[i] = (yyvsp[(1) - (2)])->children[i];
                (yyval)->children[(yyvsp[(1) - (2)])->numChildren] = (yyvsp[(2) - (2)]);
                free((yyvsp[(1) - (2)]));
            ;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 43 "parser.y"
    { 
            (yyval) = createNode("Function", (yyvsp[(2) - (6)]), 3);
            (yyval)->children[0] = (yyvsp[(1) - (6)]);
            (yyval)->children[1] = (yyvsp[(4) - (6)]);
            (yyval)->children[2] = (yyvsp[(6) - (6)]);
        ;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 51 "parser.y"
    { (yyval) = createNode("ReturnDatatype", "int", 0); ;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 52 "parser.y"
    { (yyval) = createNode("ReturnDatatype", "void", 0); ;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 55 "parser.y"
    { (yyval) = createNode("ParametersDeclaration", NULL, 0); ;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 56 "parser.y"
    {
                         (yyval) = createNode("ParametersDeclaration", NULL, 1);
                         (yyval)->children[0] = (yyvsp[(1) - (1)]);
                     ;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 62 "parser.y"
    { 
                 (yyval) = createNode("ParameterList", NULL, 1);
                 (yyval)->children[0] = (yyvsp[(1) - (1)]);
             ;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 66 "parser.y"
    {
                 (yyval) = createNode("ParameterList", NULL, (yyvsp[(1) - (3)])->numChildren + 1);
                 for (int i = 0; i < (yyvsp[(1) - (3)])->numChildren; i++) (yyval)->children[i] = (yyvsp[(1) - (3)])->children[i];
                 (yyval)->children[(yyvsp[(1) - (3)])->numChildren] = (yyvsp[(3) - (3)]);
                 free((yyvsp[(1) - (3)]));
             ;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 74 "parser.y"
    {
             (yyval) = createNode("Parameter", NULL, 2);
             (yyval)->children[0] = (yyvsp[(1) - (2)]);
             (yyval)->children[1] = createNode("Identifier", (yyvsp[(2) - (2)]), 0);
         ;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 83 "parser.y"
    {
                     (yyval) = createNode("CompoundStatement", NULL, 1);
                     (yyval)->children[0] = (yyvsp[(2) - (3)]);
                 ;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 87 "parser.y"
    { yyerrok; ;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 90 "parser.y"
    { (yyval) = createNode("StatementList", NULL, 0); ;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 91 "parser.y"
    { 
                (yyval) = createNode("StatementList", NULL, (yyvsp[(1) - (2)])->numChildren + 1);
                for (int i = 0; i < (yyvsp[(1) - (2)])->numChildren; i++) (yyval)->children[i] = (yyvsp[(1) - (2)])->children[i];
                (yyval)->children[(yyvsp[(1) - (2)])->numChildren] = (yyvsp[(2) - (2)]);
                free((yyvsp[(1) - (2)]));
            ;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 99 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 100 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 101 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 102 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 103 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 104 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 105 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 106 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 107 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 108 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 109 "parser.y"
    { yyerrok; ;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 110 "parser.y"
    { yyerrok; ;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 113 "parser.y"
    {
                        (yyval) = createNode("DeclarationStatement", NULL, 2);
                        (yyval)->children[0] = (yyvsp[(1) - (3)]);
                        (yyval)->children[1] = (yyvsp[(2) - (3)]);
                    ;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 120 "parser.y"
    { (yyval) = createNode("DeclarationDatatype", "int", 0); ;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 123 "parser.y"
    { 
                  (yyval) = createNode("DeclaratorList", NULL, 1);
                  (yyval)->children[0] = (yyvsp[(1) - (1)]);
              ;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 127 "parser.y"
    {
                  (yyval) = createNode("DeclaratorList", NULL, (yyvsp[(1) - (3)])->numChildren + 1);
                  for (int i = 0; i < (yyvsp[(1) - (3)])->numChildren; i++) (yyval)->children[i] = (yyvsp[(1) - (3)])->children[i];
                  (yyval)->children[(yyvsp[(1) - (3)])->numChildren] = (yyvsp[(3) - (3)]);
                  free((yyvsp[(1) - (3)]));
              ;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 135 "parser.y"
    { (yyval) = createNode("Declarator", (yyvsp[(1) - (1)]), 0); ;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 136 "parser.y"
    {
              (yyval) = createNode("DeclaratorWithValue", (yyvsp[(1) - (3)]), 1);
              (yyval)->children[0] = (yyvsp[(3) - (3)]);
          ;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 142 "parser.y"
    {
                       (yyval) = createNode("AssignmentStatement", NULL, 3);
                       (yyval)->children[0] = createNode("Identifier", (yyvsp[(1) - (4)]), 0);
                       (yyval)->children[1] = (yyvsp[(2) - (4)]);
                       (yyval)->children[2] = (yyvsp[(3) - (4)]);
                   ;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 150 "parser.y"
    { (yyval) = createNode("AssignOperator", "=", 0); ;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 151 "parser.y"
    { (yyval) = createNode("AssignOperator", "+=", 0); ;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 152 "parser.y"
    { (yyval) = createNode("AssignOperator", "-=", 0); ;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 153 "parser.y"
    { (yyval) = createNode("AssignOperator", "*=", 0); ;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 154 "parser.y"
    { (yyval) = createNode("AssignOperator", "/=", 0); ;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 155 "parser.y"
    { (yyval) = createNode("AssignOperator", "%=", 0); ;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 158 "parser.y"
    {
               (yyval) = createNode("IfStatement", NULL, 2);
               (yyval)->children[0] = (yyvsp[(3) - (5)]);
               (yyval)->children[1] = (yyvsp[(5) - (5)]);
           ;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 163 "parser.y"
    {
               (yyval) = createNode("IfElseStatement", NULL, 3);
               (yyval)->children[0] = (yyvsp[(3) - (7)]);
               (yyval)->children[1] = (yyvsp[(5) - (7)]);
               (yyval)->children[2] = (yyvsp[(7) - (7)]);
           ;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 169 "parser.y"
    { yyerrok; ;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 172 "parser.y"
    {
                  (yyval) = createNode("WhileStatement", NULL, 2);
                  (yyval)->children[0] = (yyvsp[(3) - (5)]);
                  (yyval)->children[1] = (yyvsp[(5) - (5)]);
              ;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 177 "parser.y"
    { yyerrok; ;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 180 "parser.y"
    {
                    (yyval) = createNode("DoWhileStatement", NULL, 2);
                    (yyval)->children[0] = (yyvsp[(2) - (7)]);
                    (yyval)->children[1] = (yyvsp[(5) - (7)]);
                ;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 185 "parser.y"
    { yyerrok; ;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 188 "parser.y"
    {
                (yyval) = createNode("ForStatement", NULL, 4);
                (yyval)->children[0] = (yyvsp[(3) - (7)]);
                (yyval)->children[1] = (yyvsp[(4) - (7)]);
                (yyval)->children[2] = createNode("ExpressionStatement", NULL, 1);
                (yyval)->children[2]->children[0] = (yyvsp[(5) - (7)]);
                (yyval)->children[3] = (yyvsp[(7) - (7)]);
            ;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 196 "parser.y"
    { yyerrok; ;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 199 "parser.y"
    { 
                 (yyval) = createNode("JumpStatement", "return", 1);
                 (yyval)->children[0] = (yyvsp[(2) - (3)]);
             ;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 203 "parser.y"
    { (yyval) = createNode("JumpStatement", "return", 0); ;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 204 "parser.y"
    { (yyval) = createNode("JumpStatement", "break", 0); ;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 205 "parser.y"
    { (yyval) = createNode("JumpStatement", "continue", 0); ;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 208 "parser.y"
    {
                       (yyval) = createNode("ExpressionStatement", NULL, 1);
                       (yyval)->children[0] = (yyvsp[(1) - (2)]);
                   ;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 212 "parser.y"
    { yyerrok; ;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 215 "parser.y"
    { (yyval) = createNode("EmptyStatement", NULL, 0); ;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 219 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 222 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 223 "parser.y"
    { 
                       (yyval) = createNode("LogicalExpression", "||", 2); 
                       (yyval)->children[0] = (yyvsp[(1) - (3)]);
                       (yyval)->children[1] = (yyvsp[(3) - (3)]);
                   ;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 230 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 231 "parser.y"
    { 
                        (yyval) = createNode("LogicalExpression", "&&", 2); 
                        (yyval)->children[0] = (yyvsp[(1) - (3)]);
                        (yyval)->children[1] = (yyvsp[(3) - (3)]);
                    ;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 238 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 239 "parser.y"
    {
                      (yyval) = createNode("RelationalExpression", "==", 2);
                      (yyval)->children[0] = (yyvsp[(1) - (3)]);
                      (yyval)->children[1] = (yyvsp[(3) - (3)]);
                  ;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 244 "parser.y"
    {
                      (yyval) = createNode("RelationalExpression", "!=", 2);
                      (yyval)->children[0] = (yyvsp[(1) - (3)]);
                      (yyval)->children[1] = (yyvsp[(3) - (3)]);
                  ;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 251 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 252 "parser.y"
    {
                        (yyval) = createNode("RelationalExpression", "<", 2);
                        (yyval)->children[0] = (yyvsp[(1) - (3)]);
                        (yyval)->children[1] = (yyvsp[(3) - (3)]);
                    ;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 257 "parser.y"
    {
                        (yyval) = createNode("RelationalExpression", ">", 2);
                        (yyval)->children[0] = (yyvsp[(1) - (3)]);
                        (yyval)->children[1] = (yyvsp[(3) - (3)]);
                    ;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 262 "parser.y"
    {
                        (yyval) = createNode("RelationalExpression", "<=", 2);
                        (yyval)->children[0] = (yyvsp[(1) - (3)]);
                        (yyval)->children[1] = (yyvsp[(3) - (3)]);
                    ;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 267 "parser.y"
    {
                        (yyval) = createNode("RelationalExpression", ">=", 2);
                        (yyval)->children[0] = (yyvsp[(1) - (3)]);
                        (yyval)->children[1] = (yyvsp[(3) - (3)]);
                    ;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 274 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 275 "parser.y"
    {
                      (yyval) = createNode("ArithmeticExpression", "+", 2);
                      (yyval)->children[0] = (yyvsp[(1) - (3)]);
                      (yyval)->children[1] = (yyvsp[(3) - (3)]);
                  ;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 280 "parser.y"
    {
                      (yyval) = createNode("ArithmeticExpression", "-", 2);
                      (yyval)->children[0] = (yyvsp[(1) - (3)]);
                      (yyval)->children[1] = (yyvsp[(3) - (3)]);
                  ;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 287 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 288 "parser.y"
    {
                            (yyval) = createNode("ArithmeticExpression", "*", 2);
                            (yyval)->children[0] = (yyvsp[(1) - (3)]);
                            (yyval)->children[1] = (yyvsp[(3) - (3)]);
                        ;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 293 "parser.y"
    {
                            (yyval) = createNode("ArithmeticExpression", "/", 2);
                            (yyval)->children[0] = (yyvsp[(1) - (3)]);
                            (yyval)->children[1] = (yyvsp[(3) - (3)]);
                        ;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 298 "parser.y"
    {
                            (yyval) = createNode("ArithmeticExpression", "%", 2);
                            (yyval)->children[0] = (yyvsp[(1) - (3)]);
                            (yyval)->children[1] = (yyvsp[(3) - (3)]);
                        ;}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 305 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 306 "parser.y"
    { 
                    (yyval) = createNode("PrefixExpression", "++", 1); 
                    (yyval)->children[0] = (yyvsp[(2) - (2)]);
                ;}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 310 "parser.y"
    { 
                    (yyval) = createNode("PrefixExpression", "--", 1); 
                    (yyval)->children[0] = (yyvsp[(2) - (2)]);
                ;}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 314 "parser.y"
    {
                    (yyval) = createNode("PrefixExpression", "&", 1);
                    (yyval)->children[0] = (yyvsp[(2) - (2)]);
                ;}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 318 "parser.y"
    {
                    (yyval) = createNode("PrefixExpression", "!", 1);
                    (yyval)->children[0] = (yyvsp[(2) - (2)]);
                ;}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 324 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 325 "parser.y"
    { 
                     (yyval) = createNode("PostfixExpression", "++", 1); 
                     (yyval)->children[0] = (yyvsp[(1) - (2)]);
                 ;}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 329 "parser.y"
    { 
                     (yyval) = createNode("PostfixExpression", "--", 1); 
                     (yyval)->children[0] = (yyvsp[(1) - (2)]);
                 ;}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 335 "parser.y"
    { (yyval) = createNode("Identifier", (yyvsp[(1) - (1)]), 0); ;}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 336 "parser.y"
    { (yyval) = createNode("ConstantNumber", (yyvsp[(1) - (1)]), 0); ;}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 337 "parser.y"
    { (yyval) = createNode("ConstantString", (yyvsp[(1) - (1)]), 0); ;}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 338 "parser.y"
    { (yyval) = (yyvsp[(2) - (3)]); ;}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 339 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 344 "parser.y"
    {
                (yyval) = createNode("FunctionCall", (yyvsp[(1) - (4)]), 1);
                (yyval)->children[0] = (yyvsp[(3) - (4)]);
            ;}
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 350 "parser.y"
    { (yyval) = createNode("ArgumentList", NULL, 0); ;}
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 351 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 94:

/* Line 1455 of yacc.c  */
#line 354 "parser.y"
    { 
                (yyval) = createNode("ArgumentList", NULL, 1);
                (yyval)->children[0] = (yyvsp[(1) - (1)]);
            ;}
    break;

  case 95:

/* Line 1455 of yacc.c  */
#line 358 "parser.y"
    {
                (yyval) = createNode("ArgumentList", NULL, (yyvsp[(1) - (3)])->numChildren + 1);
                for (int i = 0; i < (yyvsp[(1) - (3)])->numChildren; i++) (yyval)->children[i] = (yyvsp[(1) - (3)])->children[i];
                (yyval)->children[(yyvsp[(1) - (3)])->numChildren] = (yyvsp[(3) - (3)]);
                free((yyvsp[(1) - (3)]));
            ;}
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 365 "parser.y"
    {
            (yyval) = createNode("Argument", NULL, 1);
            (yyval)->children[0] = (yyvsp[(1) - (1)]);
        ;}
    break;



/* Line 1455 of yacc.c  */
#line 2357 "parser.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

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
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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
      if (yyn != YYPACT_NINF)
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

  *++yyvsp = yylval;


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
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
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



/* Line 1675 of yacc.c  */
#line 372 "parser.y"


void yyerror(const char *s) {
    fprintf(stderr, "Error at line %d: %s\n", yylineno, s);
    noError = false;
}

int main(int argc, char **argv) {
    yyin = fopen(argv[1], "r");
    if(yyin == NULL){
        printf("Can not read the file: %s", argv[1]);
        return -1;
    }
    yyparse();
    fclose(yyin);

    if(noError) {
        FILE *jsonFile = fopen("parse_tree.json", "w");
        writeJson(root, jsonFile);
        fclose(jsonFile);
    }

    freeAllNodes();
    freeAllStrings();
    printf("Finish parsing.\n");

    return 0;
}

