
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
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

extern YYSTYPE yylval;


