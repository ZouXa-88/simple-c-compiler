%option yylineno
%{
#include "parser.tab.h"
#define YYSTYPE char*
%}

digit       [0-9]
alpha       [a-zA-Z]
identifier  {alpha}({alpha}|{digit}|[_])*

%%

"int"           { return INT; }
"void"          { return VOID; }
"return"        { return RETURN; }
"if"            { return IF; }
"else"          { return ELSE; }
"while"         { return WHILE; }
"do"            { return DO; }
"for"           { return FOR; }
"break"         { return BREAK; }
"continue"      { return CONTINUE; }

"//".*                                  { /* Ignore single-line comment */ }
[/][*][^*]*[*]+([^*/][^*]*[*]+)*[/]     { /* Ignore multiple-line comment */ }

"{"             { return LBRACE; }
"}"             { return RBRACE; }
"("             { return LPAREN; }
")"             { return RPAREN; }
";"             { return SEMICOLON; }
","             { return COMMA; }

"="             { return ASSIGN; }
"+="            { return PLUSASSIGN; }
"-="            { return MINUSASSIGN; }
"*="            { return TIMESASSIGN; }
"/="            { return DIVIDEASSIGN; }
"%="            { return MODEASSIGN; }

"=="            { return EQ; }
"!="            { return NE; }
"<="            { return LE; }
">="            { return GE; }
"<"             { return LT; }
">"             { return GT; }
"&&"            { return LOGICAL_AND; }
"||"            { return LOGICAL_OR; }

"++"            { return PLUSPLUS; }
"--"            { return MINUSMINUS; }
"&"             { return AND; }
"!"             { return NOT; }

"+"             { return PLUS; }
"-"             { return MINUS; }
"*"             { return TIMES; }
"/"             { return DIVIDE; }
"%"             { return MODE; }

\".*\"          { yylval = my_strdup(yytext); return STRING; }
{identifier}    { yylval = my_strdup(yytext); return IDENTIFIER; }
{digit}+        { yylval = my_strdup(yytext); return NUMBER; }

[ \t]           { /* Ignore whitespace */ }
"\n"            {}

.               { printf("Unexpected character: %s\n", yytext); }

%%

int yywrap() {
    return 1;
}
