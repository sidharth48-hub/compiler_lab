%{  
#ifndef STARTER_H
#define STARTER_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#endif

#ifndef CODEGEN_H
#define CODEGEN_H
#include "codegen.h"
#include "codegen.c"
#endif

#ifndef EXPR_TREE_H
#define EXPR_TREE_H
#include "expr_tree.h"
#include "expr_tree.c"
#endif

#define FIRST_VARIABLE 4096


void yyerror(char const *s);
extern FILE* yyin;

int yylex(void);

%}

%union{
  struct expr_tree_node * node;
  char c;
}


%token NUMBER MUL DIV PLUS MINUS  ID READ WRITE SEMICOLON START END EQUALS
%type <node> expr program
%left PLUS MINUS
%left MUL DIV

%%

// start : 
/*
Each node can be opertator node or a leaf Node
*/

// start : Program {
    // FILE * target_file = fopen("assemblycode.xsm","w");
  
    // printf("Generating Assembly Code... \n");
    // fprintf(target_file, "%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n",0,2056,0,0,0,0,0,0);
    // codeGen($<node>1, target_file);
    // fprintf(target_file, "INT 10\n");
    // printf("Complete \n");
    // if(target_file) fclose(target_file);

//     exit(1);
// }
// ;

/*
struct expr_tree_node * makeNode(int val, int type, char* c, struct expr_tree_node *l, struct expr_tree_node *r)
*/

program : START Slist END SEMICOLON 
{
  FILE * target_file = fopen("assemblycode.xsm","w");
  
  printInfix($<node>1);
  printf("Generating Assembly Code... \n");
  fprintf(target_file, "%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n",0,2056,0,0,0,0,0,0);
  codeGen($<node>1, target_file);
  fprintf(target_file, "INT 10\n");
  printf("Complete \n");

  if(target_file) fclose(target_file);

  exit(1);

}
| START END SEMICOLON
{
    exit(1);
};
Slist : Slist Stmt {$<node>$ = makeConnectorNode($<node>1,$<node>2);}| Stmt {$<node>$ = $<node>1;};
Stmt : InputStmt | OutputStmt | AsgStmt;
InputStmt : READ '(' ID ')' SEMICOLON {$<node>$ = makeReadNode($<node>3);};
OutputStmt : WRITE '(' expr ')' SEMICOLON {$<node>$ = makeWriteNode($<node>3);}; 
AsgStmt :  ID EQUALS expr SEMICOLON {$<node>$ = makeOperatorNode('=',$<node>1,$<node>3) ;};
expr : expr PLUS expr  {$<node>$ = makeOperatorNode('+',$<node>1,$<node>3);}
| expr MINUS expr  { $<node>$ = makeOperatorNode('-',$<node>1,$<node>3);}
| expr MUL expr {$<node>$ = makeOperatorNode('*',$<node>1,$<node>3);}
| expr DIV expr {$<node>$ = makeOperatorNode('/',$<node>1,$<node>3);}
|'(' expr ')' {$<node>$ = $<node>2;}
| NUMBER {printNode($<node>1);$<node>$ = $<node>1;}
| ID {printNode($<node>1);$<node>$ = $<node>1;}

;

%%

void yyerror(char const *s)
{
    printf("yyerror %s",s);
}
int main()
{

  FILE * input_file=fopen("input.txt","r");
  yyin = input_file;
  yyparse(); 
  fclose(input_file);  
}