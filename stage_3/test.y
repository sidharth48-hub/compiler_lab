%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include "exptree.h"
    #include "exptree.c"
    extern FILE* yyin;
    int yylex(void);
    int yyerror();
%}

%union{
    struct tnode *no;
};

%type <no> program Slist InputStmt OutputStmt AssgStmt expr stmt
%token NUM PLUS MINUS MUL DIV END READ WRITE START ID SEMICOLON EQUAL
%left PLUS MINUS
%left MUL DIV
%right EQUAL

%%

program : START Slist END SEMICOLON {$$=$<no>2;
                inorder($<no>2);
                exit(1);}
        | START END SEMICOLON {exit(1);}        
        ;

Slist : Slist stmt {$$=makeConnectorNode('.',$<no>1,$<no>2);}
      | stmt {$$=$<no>1;}
      ;

stmt : InputStmt {$$=$<no>1;}
     | OutputStmt {$$=$<no>1;}
     | AssgStmt {$$=$<no>1;}
     ;

InputStmt : READ'(' ID ')' SEMICOLON {$$=makereadNode($<no>3);}
          ;


OutputStmt : WRITE'(' expr ')' SEMICOLON {$$=makewriteNode($<no>3);}
           ;

AssgStmt : ID EQUAL expr SEMICOLON {$$=makeOperatorNode('=',$<no>1,$<no>3);}
         ;


expr : expr PLUS expr {$$ = makeOperatorNode('+',$<no>1,$<no>3);}
    | expr MINUS expr {$$ = makeOperatorNode('-',$<no>1,$<no>3);}
    | expr MUL expr {$$ = makeOperatorNode('*',$<no>1,$<no>3);}
    | expr DIV expr {$$ = makeOperatorNode('/',$<no>1,$<no>3);}
    | '(' expr ')' {$$=$<no>2;}
    | ID {$$=$<no>1;}
    | NUM {$$=$<no>1;}
    ;
%%

int yyerror(char const *s)
{
    printf("yyerror %s",s);
    return 0;
}

int main(void)
{
    yyin=fopen("input.txt","r");
    yyparse();
    return 0;
}