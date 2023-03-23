%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <limits.h>
    #include "exptree.h"
    #include "exptree.c"
    #include "codegen.c"
    extern FILE* yyin;
    int yylex(void);
    int yyerror();

    int* shape; 
%}

%union{
    struct tnode *no;
    struct dnode *dno;
    char* ch;
    int num;
};

%type <no> program Slist InputStmt OutputStmt AssgStmt expr stmt Ifstmt Whilestmt breakstmt continuestmt dowhilestmt repuntilstmt Identifier
%type <dno> Declarations DeclList Decl VarList IdDecl
%type <num> Type
%token START END DECL ENDDECL INT STR SEMICOLON
%token READ WRITE 
%token IF THEN ELSE ENDIF
%token WHILE DO ENDWHILE REPEAT UNTIL BREAK CONTINUE
%token NUM ID STRING
%left GTE LTE 
%left LT GT
%left NE EQ
%left PLUS MINUS
%left MUL DIV MOD
%right EQUAL

%%

program : START Declarations Slist END SEMICOLON {$$=$<no>3;
                                                  printGsymbolTable();
                                                  LinkIdTable($<no>3);
                                                  codegenerator($<no>3);
                                                  exit(1);
                                                  }
        | START END SEMICOLON {exit(1);}        
        ;

Declarations : DECL DeclList ENDDECL {$$=$<dno>2;}
             | DECL ENDDECL {}
             ;

DeclList : DeclList Decl {$$=makeDeclNode($<dno>1,$<dno>2);}
         | Decl {$$=$<dno>1;}
         ;

Decl : Type VarList SEMICOLON {$$=makeDataTypeNode($<num>1,$<dno>2);
                               GsymbolEntry($<num>1,$<dno>2);
                               }
     ;

Type : INT {$$=$<num>1;}
     | STR {$$=$<num>1;}
     ;

VarList : VarList ',' IdDecl {$$=makeDeclNode($<dno>1,$<dno>3);}
        | IdDecl {$$=$<dno>1;}
        ;

IdDecl : ID             {
                            shape = (int*)malloc(2*sizeof(int));
                            shape[0] = 0;
                            shape[1] = 0; 
                            $$=makeIdNodeDecl($<ch>1,0,shape); 
                        }
        | ID'[' NUM ']' {
                            shape = (int*)malloc(2*sizeof(int));
                            shape[0] = $<num>3;
                            shape[1] = 0; 
                            $$=makeIdNodeDecl($<ch>1,1,shape);
                        }
        | ID'[' NUM ']''[' NUM ']' {
                            shape = (int*)malloc(2*sizeof(int));
                            shape[0] = $<num>3;
                            shape[1] = $<num>6; 
                            $$=makeIdNodeDecl($<ch>1,2,shape);
                        }                      
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
     | continuestmt {$$=$<no>1;}
     | dowhilestmt {$$=$<no>1;}
     | repuntilstmt {$$=$<no>1;}
     ;

InputStmt : READ'(' expr ')' SEMICOLON {$$=makereadNode($<no>3);}
          ;


OutputStmt : WRITE'(' expr ')' SEMICOLON {$$=makewriteNode($<no>3);}
           ;

AssgStmt : expr EQUAL expr SEMICOLON {$$=makeOperatorNode("=",$<no>1,$<no>3);}
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

continuestmt : CONTINUE SEMICOLON {$$=makecontNode();}
             ;

expr : expr PLUS expr {$$ = makeOperatorNode("+",$<no>1,$<no>3);}
    | expr MINUS expr {$$ = makeOperatorNode("-",$<no>1,$<no>3);}
    | expr MUL expr {$$ = makeOperatorNode("*",$<no>1,$<no>3);}
    | expr DIV expr {$$ = makeOperatorNode("/",$<no>1,$<no>3);}
    | expr MOD expr {$$ = makeOperatorNode("%",$<no>1,$<no>3);}
    | expr LT expr {$$ = makeOperatorNode("<",$<no>1,$<no>3); $$->type = booltype;}
    | expr GT expr {$$ = makeOperatorNode(">",$<no>1,$<no>3); $$->type = booltype;}
    | expr NE expr {$$ = makeOperatorNode("!=",$<no>1,$<no>3); $$->type = booltype;}
    | expr LTE expr {$$ = makeOperatorNode("<=",$<no>1,$<no>3); $$->type = booltype;}
    | expr GTE expr {$$ = makeOperatorNode(">=",$<no>1,$<no>3); $$->type = booltype;}
    | expr EQ expr {$$ = makeOperatorNode("==",$<no>1,$<no>3); $$->type = booltype;}
    | '(' expr ')' {$$=$<no>2;}
    | Identifier {$$=$<no>1;}
    | NUM {$$=makeNumberNode($<num>1);}
    | STRING {$$=$<no>1;}
    ;

Identifier : ID                       {$$=makeIdNode($<ch>1,NULL,NULL);}
           | ID'[' expr ']'            {$$=makeIdNode($<ch>1,$<no>3,NULL);}     
           | ID'[' expr ']''[' expr ']' {$$=makeIdNode($<ch>1,$<no>3,$<no>6);}
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