%{
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
%}

%token INT VOID RETURN IF ELSE WHILE DO FOR BREAK CONTINUE
%token IDENTIFIER NUMBER STRING
%token LBRACE RBRACE LPAREN RPAREN SEMICOLON COMMA
%token ASSIGN PLUSASSIGN MINUSASSIGN TIMESASSIGN DIVIDEASSIGN MODEASSIGN
%token EQ NE LE GE LT GT LOGICAL_AND LOGICAL_OR
%token PLUSPLUS MINUSMINUS AND NOT
%token PLUS MINUS TIMES DIVIDE MODE

%start Program

%%

Program: FunctionList { root = $1; }
;

FunctionList: /* empty */ { $$ = createNode("FunctionList", NULL, 0); }
            | FunctionList Function { 
                $$ = createNode("FunctionList", NULL, $1->numChildren + 1);
                for (int i = 0; i < $1->numChildren; i++) $$->children[i] = $1->children[i];
                $$->children[$1->numChildren] = $2;
                free($1);
            }
;

Function: ReturnDatatype IDENTIFIER LPAREN ParametersDeclaration RPAREN CompoundStatement { 
            $$ = createNode("Function", $2, 3);
            $$->children[0] = $1;
            $$->children[1] = $4;
            $$->children[2] = $6;
        }
;

ReturnDatatype: INT { $$ = createNode("ReturnDatatype", "int", 0); }
              | VOID { $$ = createNode("ReturnDatatype", "void", 0); }
;

ParametersDeclaration: /* empty */ { $$ = createNode("ParametersDeclaration", NULL, 0); }
                     | ParameterList {
                         $$ = createNode("ParametersDeclaration", NULL, 1);
                         $$->children[0] = $1;
                     }
;

ParameterList: Parameter { 
                 $$ = createNode("ParameterList", NULL, 1);
                 $$->children[0] = $1;
             }
             | ParameterList COMMA Parameter {
                 $$ = createNode("ParameterList", NULL, $1->numChildren + 1);
                 for (int i = 0; i < $1->numChildren; i++) $$->children[i] = $1->children[i];
                 $$->children[$1->numChildren] = $3;
                 free($1);
             }
;

Parameter: DeclarationDatatype IDENTIFIER {
             $$ = createNode("Parameter", NULL, 2);
             $$->children[0] = $1;
             $$->children[1] = createNode("Identifier", $2, 0);
         }
;

/*--------------------------------------------------------------------*/

CompoundStatement: LBRACE StatementList RBRACE {
                     $$ = createNode("CompoundStatement", NULL, 1);
                     $$->children[0] = $2;
                 }
                 | error RBRACE { yyerrok; }
;

StatementList: /* empty */ { $$ = createNode("StatementList", NULL, 0); }
            | StatementList Statement { 
                $$ = createNode("StatementList", NULL, $1->numChildren + 1);
                for (int i = 0; i < $1->numChildren; i++) $$->children[i] = $1->children[i];
                $$->children[$1->numChildren] = $2;
                free($1);
            }
;

Statement: DeclarationStatement { $$ = $1; }
         | AssignmentStatement { $$ = $1; }
         | CompoundStatement { $$ = $1; }
         | IfStatement { $$ = $1; }
         | WhileStatement { $$ = $1; }
         | DoWhileStatement { $$ = $1; }
         | ForStatement { $$ = $1; }
         | JumpStatement { $$ = $1; }
         | ExpressionStatement { $$ = $1; }
         | EmptyStatement { $$ = $1; }
         | error SEMICOLON { yyerrok; }
         | error RBRACE { yyerrok; }
;

DeclarationStatement: DeclarationDatatype DeclaratorList SEMICOLON {
                        $$ = createNode("DeclarationStatement", NULL, 2);
                        $$->children[0] = $1;
                        $$->children[1] = $2;
                    }
;

DeclarationDatatype: INT { $$ = createNode("DeclarationDatatype", "int", 0); }
;

DeclaratorList: Declarator { 
                  $$ = createNode("DeclaratorList", NULL, 1);
                  $$->children[0] = $1;
              }
              | DeclaratorList COMMA Declarator {
                  $$ = createNode("DeclaratorList", NULL, $1->numChildren + 1);
                  for (int i = 0; i < $1->numChildren; i++) $$->children[i] = $1->children[i];
                  $$->children[$1->numChildren] = $3;
                  free($1);
              }
;

Declarator: IDENTIFIER { $$ = createNode("Declarator", $1, 0); }
          | IDENTIFIER ASSIGN Expression {
              $$ = createNode("DeclaratorWithValue", $1, 1);
              $$->children[0] = $3;
          }
;

AssignmentStatement: IDENTIFIER AssignOperator Expression SEMICOLON {
                       $$ = createNode("AssignmentStatement", NULL, 3);
                       $$->children[0] = createNode("Identifier", $1, 0);
                       $$->children[1] = $2;
                       $$->children[2] = $3;
                   }
;

AssignOperator: ASSIGN { $$ = createNode("AssignOperator", "=", 0); }
              | PLUSASSIGN { $$ = createNode("AssignOperator", "+=", 0); }
              | MINUSASSIGN { $$ = createNode("AssignOperator", "-=", 0); }
              | TIMESASSIGN { $$ = createNode("AssignOperator", "*=", 0); }
              | DIVIDEASSIGN { $$ = createNode("AssignOperator", "/=", 0); }
              | MODEASSIGN { $$ = createNode("AssignOperator", "%=", 0); }
;

IfStatement: IF LPAREN Expression RPAREN Statement {
               $$ = createNode("IfStatement", NULL, 2);
               $$->children[0] = $3;
               $$->children[1] = $5;
           }
           | IF LPAREN Expression RPAREN Statement ELSE Statement {
               $$ = createNode("IfElseStatement", NULL, 3);
               $$->children[0] = $3;
               $$->children[1] = $5;
               $$->children[2] = $7;
           }
           | error RBRACE { yyerrok; }
;

WhileStatement: WHILE LPAREN Expression RPAREN Statement {
                  $$ = createNode("WhileStatement", NULL, 2);
                  $$->children[0] = $3;
                  $$->children[1] = $5;
              }
              | error RBRACE { yyerrok; }
;

DoWhileStatement: DO Statement WHILE LPAREN Expression RPAREN SEMICOLON {
                    $$ = createNode("DoWhileStatement", NULL, 2);
                    $$->children[0] = $2;
                    $$->children[1] = $5;
                }
                | error SEMICOLON { yyerrok; }
;

ForStatement: FOR LPAREN Statement ExpressionStatement Expression RPAREN Statement {
                $$ = createNode("ForStatement", NULL, 4);
                $$->children[0] = $3;
                $$->children[1] = $4;
                $$->children[2] = createNode("ExpressionStatement", NULL, 1);
                $$->children[2]->children[0] = $5;
                $$->children[3] = $7;
            }
            | error RBRACE { yyerrok; }
;

JumpStatement: RETURN Expression SEMICOLON { 
                 $$ = createNode("JumpStatement", "return", 1);
                 $$->children[0] = $2;
             }
             | RETURN SEMICOLON { $$ = createNode("JumpStatement", "return", 0); }
             | BREAK SEMICOLON { $$ = createNode("JumpStatement", "break", 0); }
             | CONTINUE SEMICOLON { $$ = createNode("JumpStatement", "continue", 0); }
;

ExpressionStatement: Expression SEMICOLON {
                       $$ = createNode("ExpressionStatement", NULL, 1);
                       $$->children[0] = $1;
                   }
                   | error SEMICOLON { yyerrok; }
;

EmptyStatement: SEMICOLON { $$ = createNode("EmptyStatement", NULL, 0); }

/*--------------------------------------------------------------------*/

Expression: LogicalOrExpression { $$ = $1; }
;

LogicalOrExpression: LogicalAndExpression { $$ = $1; }
                   | LogicalOrExpression LOGICAL_OR LogicalAndExpression { 
                       $$ = createNode("LogicalExpression", "||", 2); 
                       $$->children[0] = $1;
                       $$->children[1] = $3;
                   }
;

LogicalAndExpression: EqualityExpression { $$ = $1; }
                    | LogicalAndExpression LOGICAL_AND EqualityExpression { 
                        $$ = createNode("LogicalExpression", "&&", 2); 
                        $$->children[0] = $1;
                        $$->children[1] = $3;
                    }
;

EqualityExpression: RelationalExpression { $$ = $1; }
                  | EqualityExpression EQ RelationalExpression {
                      $$ = createNode("RelationalExpression", "==", 2);
                      $$->children[0] = $1;
                      $$->children[1] = $3;
                  }
                  | EqualityExpression NE RelationalExpression {
                      $$ = createNode("RelationalExpression", "!=", 2);
                      $$->children[0] = $1;
                      $$->children[1] = $3;
                  }
;

RelationalExpression: AdditiveExpression { $$ = $1; }
                    | RelationalExpression LT AdditiveExpression {
                        $$ = createNode("RelationalExpression", "<", 2);
                        $$->children[0] = $1;
                        $$->children[1] = $3;
                    }
                    | RelationalExpression GT AdditiveExpression {
                        $$ = createNode("RelationalExpression", ">", 2);
                        $$->children[0] = $1;
                        $$->children[1] = $3;
                    }
                    | RelationalExpression LE AdditiveExpression {
                        $$ = createNode("RelationalExpression", "<=", 2);
                        $$->children[0] = $1;
                        $$->children[1] = $3;
                    }
                    | RelationalExpression GE AdditiveExpression {
                        $$ = createNode("RelationalExpression", ">=", 2);
                        $$->children[0] = $1;
                        $$->children[1] = $3;
                    }
;

AdditiveExpression: MultiplicativeExpression { $$ = $1; }
                  | AdditiveExpression PLUS MultiplicativeExpression {
                      $$ = createNode("ArithmeticExpression", "+", 2);
                      $$->children[0] = $1;
                      $$->children[1] = $3;
                  }
                  | AdditiveExpression MINUS MultiplicativeExpression {
                      $$ = createNode("ArithmeticExpression", "-", 2);
                      $$->children[0] = $1;
                      $$->children[1] = $3;
                  }
;

MultiplicativeExpression: PrefixExpression { $$ = $1; }
                        | MultiplicativeExpression TIMES PrefixExpression {
                            $$ = createNode("ArithmeticExpression", "*", 2);
                            $$->children[0] = $1;
                            $$->children[1] = $3;
                        }
                        | MultiplicativeExpression DIVIDE PrefixExpression {
                            $$ = createNode("ArithmeticExpression", "/", 2);
                            $$->children[0] = $1;
                            $$->children[1] = $3;
                        }
                        | MultiplicativeExpression MODE PrefixExpression {
                            $$ = createNode("ArithmeticExpression", "%", 2);
                            $$->children[0] = $1;
                            $$->children[1] = $3;
                        }
;

PrefixExpression: PostfixExpression { $$ = $1; }
                | PLUSPLUS PrefixExpression { 
                    $$ = createNode("PrefixExpression", "++", 1); 
                    $$->children[0] = $2;
                }
                | MINUSMINUS PrefixExpression { 
                    $$ = createNode("PrefixExpression", "--", 1); 
                    $$->children[0] = $2;
                }
                | AND PrefixExpression {
                    $$ = createNode("PrefixExpression", "&", 1);
                    $$->children[0] = $2;
                }
                | NOT PrefixExpression {
                    $$ = createNode("PrefixExpression", "!", 1);
                    $$->children[0] = $2;
                }
;

PostfixExpression: PrimaryExpression { $$ = $1; }
                 | PostfixExpression PLUSPLUS { 
                     $$ = createNode("PostfixExpression", "++", 1); 
                     $$->children[0] = $1;
                 }
                 | PostfixExpression MINUSMINUS { 
                     $$ = createNode("PostfixExpression", "--", 1); 
                     $$->children[0] = $1;
                 }
;

PrimaryExpression: IDENTIFIER { $$ = createNode("Identifier", $1, 0); }
                 | NUMBER { $$ = createNode("ConstantNumber", $1, 0); }
                 | STRING { $$ = createNode("ConstantString", $1, 0); }
                 | LPAREN Expression RPAREN { $$ = $2; }
                 | FunctionCall { $$ = $1; }
;

/*--------------------------------------------------------------------*/

FunctionCall: IDENTIFIER LPAREN Arguments RPAREN {
                $$ = createNode("FunctionCall", $1, 1);
                $$->children[0] = $3;
            }
;

Arguments: /* empty */ { $$ = createNode("ArgumentList", NULL, 0); }
         | ArgumentList { $$ = $1; }
;

ArgumentList: Argument { 
                $$ = createNode("ArgumentList", NULL, 1);
                $$->children[0] = $1;
            }
            | ArgumentList COMMA Argument {
                $$ = createNode("ArgumentList", NULL, $1->numChildren + 1);
                for (int i = 0; i < $1->numChildren; i++) $$->children[i] = $1->children[i];
                $$->children[$1->numChildren] = $3;
                free($1);
            }

Argument: Expression {
            $$ = createNode("Argument", NULL, 1);
            $$->children[0] = $1;
        }
;


%%

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
