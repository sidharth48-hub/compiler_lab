%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include "exptree.h"
    #include "exptree.c"
    #include "codegen.c"
    extern FILE* yyin;
    int yylex(void);
    int yyerror();
%}

%union{
    struct tnode *no;
};

%type <no> program Slist InputStmt OutputStmt AssgStmt expr stmt Ifstmt Whilestmt breakstmt contstmt dowhilestmt repuntilstmt
%token NUM PLUS MINUS MUL DIV END READ WRITE START ID SEMICOLON EQUAL BREAK CONTINUE 
%token IF THEN ELSE ENDIF WHILE DO ENDWHILE REPEAT UNTIL
%token LT GT LTE GTE NE EQ
%left PLUS MINUS
%left MUL DIV
%left GTE LTE 
%left LT GT
%left NE EQ
%right EQUAL

%%

program : START Slist END SEMICOLON {$$=$<no>2;
                codegenerator($<no>2);
                exit(1);}
        | START END SEMICOLON {exit(1);}        
        ;

Slist : Slist stmt {$$=makeConnectorNode('.',$<no>1,$<no>2);}
      | stmt {$$=$<no>1;}
      ;

stmt : InputStmt {$$=$<no>1;}
     | OutputStmt {$$=$<no>1;}
     | AssgStmt {$$=$<no>1;}
     | Ifstmt {$$=$<no>1;}
     | Whilestmt {$$=$<no>1;}
     | breakstmt {$$=$<no>1;}
     | contstmt {$$=$<no>1;}
     | dowhilestmt {$$=$<no>1;}
     | repuntilstmt {$$=$<no>1;}
     ;

InputStmt : READ'(' ID ')' SEMICOLON {$$=makereadNode($<no>3);}
          ;


OutputStmt : WRITE'(' expr ')' SEMICOLON {$$=makewriteNode($<no>3);}
           ;

AssgStmt : ID EQUAL expr SEMICOLON {$$=makeOperatorNode("=",$<no>1,$<no>3);}
         ;

Ifstmt : IF'(' expr ')' THEN Slist ELSE Slist ENDIF SEMICOLON {$$=makeIfNode($<no>3,$<no>6,$<no>8);}
       | IF'(' expr ')' THEN Slist ENDIF SEMICOLON {$$=makeNoElseNode($<no>3,$<no>6);}
       ;

Whilestmt : WHILE'(' expr ')' DO Slist ENDWHILE SEMICOLON {$$=makeWhileNode($<no>3,$<no>6);}
          ;

dowhilestmt : DO Slist WHILE'(' expr ')' SEMICOLON {$$=makedowhileNode($<no>2,$<no>5);}
            ;

repuntilstmt : REPEAT Slist UNTIL'(' expr ')' SEMICOLON {$$=makerepuntilNode($<no>2,$<no>5);}
             ;

breakstmt : BREAK SEMICOLON {$$=makebreakNode();}
          ;

contstmt : CONTINUE SEMICOLON {$$=makecontNode();}
         ;

expr : expr PLUS expr {$$ = makeOperatorNode("+",$<no>1,$<no>3); $$->type = inttype;}
    | expr MINUS expr {$$ = makeOperatorNode("-",$<no>1,$<no>3); $$->type = inttype;}
    | expr MUL expr {$$ = makeOperatorNode("*",$<no>1,$<no>3); $$->type = inttype;}
    | expr DIV expr {$$ = makeOperatorNode("/",$<no>1,$<no>3); $$->type = inttype;}
    | expr LT expr {$$ = makeOperatorNode("<",$<no>1,$<no>3); $$->type = booltype;}
    | expr GT expr {$$ = makeOperatorNode(">",$<no>1,$<no>3); $$->type = booltype;}
    | expr NE expr {$$ = makeOperatorNode("!=",$<no>1,$<no>3); $$->type = booltype;}
    | expr LTE expr {$$ = makeOperatorNode("<=",$<no>1,$<no>3); $$->type = booltype;}
    | expr GTE expr {$$ = makeOperatorNode(">=",$<no>1,$<no>3); $$->type = booltype;}
    | expr EQ expr {$$ = makeOperatorNode("==",$<no>1,$<no>3); $$->type = booltype;}
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