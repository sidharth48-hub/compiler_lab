%{
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
    #include "./Functions/codegen.c"
    #include "./Functions/Func_call.c"
    #include "./Functions/function.c"
    #include "./Functions/Gsymbol.c"
    #include "./Functions/Loop_func.c"
    #include "./Functions/Lsymbol.c"
    #include "./Functions/read_write_assg.c"
    #include "./Functions/var_op.c"
     
    int yylex(void);
    int yyerror();
%}

%union{
    struct tnode *no;
    char* ch;
    int num;
};

%type <no> GDeclBlock DeclList Decl VarList IdDecl ParamList Param
%type <no> FdefBlock Fdef Body returnstmt
%type <no> LdeclBlock LDecList LDecl IdList
%type <no> program Slist InputStmt OutputStmt AssgStmt expr stmt Ifstmt Whilestmt breakstmt continuestmt dowhilestmt repuntilstmt Identifier MainBlock ArgList
%type <num> Type
%token START END DECL ENDDECL INT STR SEMICOLON RETURN BREAKPOINT
%token READ WRITE 
%token IF THEN ELSE ENDIF
%token WHILE DO ENDWHILE REPEAT UNTIL BREAK CONTINUE
%token NUM ID STRING
%left OR
%left AND
%left GTE LTE 
%left LT GT
%left NE EQ
%left PLUS MINUS
%left MUL DIV MOD
%left NOT
%right EQUAL

%%

program : GDeclBlock FdefBlock MainBlock {codegenerator($<no>2,$<no>3);}
        | GDeclBlock MainBlock {codegenerator(NULL,$<no>2);}
        | MainBlock  {codegenerator(NULL,$<no>1);}
        ;

/*-----------------GLOBAL DECL BLOCK-----------------------------------*/

GDeclBlock : DECL DeclList ENDDECL {$$=$<no>2;}
           | DECL ENDDECL {}
           ;

DeclList : DeclList Decl {$$=makeDeclNode(NODE_CONNECTOR,$<no>1,$<no>2);}
         | Decl {$$=$<no>1;}
         ;

Decl : Type VarList SEMICOLON {$$=makeDataTypeNode($<num>1,$<no>2);
                               GsymbolEntry($<num>1,$<no>2);
                               }
     ;

Type : INT {$$=$<num>1;}
     | STR {$$=$<num>1;}
     ;

VarList : VarList ',' IdDecl {$$=makeDeclNode(NODE_CONNECTOR,$<no>1,$<no>3);}
        | IdDecl {$$=$<no>1;}
        ;

IdDecl : ID {$$=makeIdNodeDecl(NODE_VARIABLE,$<ch>1,0,NULL);}
        | ID'[' NUM ']' {$$=makeIdNodeDecl(NODE_VAR_ARRAY,$<ch>1,$<num>3,NULL);}
        | ID'(' ParamList ')' {
                                $$=makeIdNodeDecl(NODE_VAR_PARAMLIST,$<ch>1,0,$<no>3);
                              }                                      
        ;

ParamList : ParamList ',' Param {$$=makeDeclNode(NODE_CONNECTOR,$<no>1,$<no>3);}
          | Param  {$$=$<no>1;}
          ;

Param : Type ID {$$=makeParamNode(NODE_PARAM,$<num>1,makeIdNodeDecl(NODE_PARAM_VARIABLE,$<ch>2,0,NULL));}
      ;              

/*---------------------------------------------------------------------------*/

/*---------------------FUNCTION BLOCK----------------------------------------*/

FdefBlock : FdefBlock Fdef {$$=makeFuncConnectorNode(NODE_CONNECTOR,$<no>1,$<no>2);}
          | Fdef {$$=$<no>1;}
          ;

Fdef : Type ID '('ParamList')''{' LdeclBlock Body '}' {
                                                          struct tnode *temp1 = makeFuncTypeNode($<num>1);
                                                          struct tnode *temp2 = makeFuncConnectorNode(NODE_CONNECTOR,$<no>7,$<no>8);
                                                          struct tnode *temp3 = makeFuncConnectorNode(NODE_CONNECTOR,$<no>4,temp2); 
                                                          struct tnode *temp4 = makeFuncIdNode(NODE_FUNCTION,$<ch>2,temp1,temp3);

                                                          $$ = temp4;

                                                          struct Lsymbol *temp =  LsymbolEntry($<no>4,$<no>7);

                                                          LinkLocalTable(temp,$<no>8);    
                                                       }
     | Type ID '('ParamList')' '{' Body '}' {
                                                          struct tnode *temp1 = makeFuncTypeNode($<num>1);
                                                          struct tnode *temp2 = makeFuncConnectorNode(NODE_CONNECTOR,NULL,$<no>7);
                                                          struct tnode *temp3 = makeFuncConnectorNode(NODE_CONNECTOR,$<no>4,temp2);

                                                          struct tnode *temp4 = makeFuncIdNode(NODE_FUNCTION,$<ch>2,temp1,temp3);
                                                          
                                                          $$ = temp4;

                                                          struct Lsymbol *temp =  LsymbolEntry($<no>4,NULL);
                                                          LinkLocalTable(temp,$<no>7);
                                            }
     | Type ID '('')' '{' LdeclBlock Body '}' {
                                                          struct tnode *temp1 = makeFuncTypeNode($<num>1);
                                                          struct tnode *temp2 = makeFuncConnectorNode(NODE_CONNECTOR,$<no>6,$<no>7);
                                                          struct tnode *temp3 = makeFuncConnectorNode(NODE_CONNECTOR,NULL,temp2);
                                                          struct tnode *temp4 = makeFuncIdNode(NODE_FUNCTION,$<ch>2,temp1,temp3);

                                                          $$ = temp4;

                                                          struct Lsymbol *temp =  LsymbolEntry(NULL,$<no>6);
                                                          LinkLocalTable(temp,$<no>7);
                                               }
     | Type ID '('')' '{' Body '}' {
                                                          struct tnode *temp1 = makeFuncTypeNode($<num>1);
                                                          struct tnode *temp2 = makeFuncConnectorNode(NODE_CONNECTOR,NULL,$<no>6);
                                                          struct tnode *temp3 = makeFuncConnectorNode(NODE_CONNECTOR,NULL,temp2);

                                                          $$ = makeFuncIdNode(NODE_FUNCTION,$<ch>2,temp1,temp3);
                                   }                                                                                                                                   
     ;

Body : START Slist returnstmt END {$$=makeFuncConnectorNode(NODE_CONNECTOR,$<no>2,$<no>3);}
     | START END {}
     ;

returnstmt : RETURN expr SEMICOLON {$$=makeReturnNode(NODE_RETURN,$<no>2);}
           ;     

/*---------------------------------------------------------------------------*/

/*----------------------LOCAL DECL BLOCK-------------------------------------*/

LdeclBlock : DECL LDecList ENDDECL {
                                    $$=$<no>2;
                                    }
           | DECL ENDDECL {}
           ;

LDecList : LDecList LDecl {$$=makeLDeclConnectorNode(NODE_LCONNECTOR,$<no>1,$<no>2);}
         | LDecl {$$=$<no>1;}
         ;

LDecl : Type IdList SEMICOLON {
                               $$=makeLDeclTypeNode($<num>1,$<no>2);
                               }
      ;

IdList : IdList ',' ID {$$=makeLDeclConnectorNode(NODE_CONNECTOR,$<no>1,makeLDeclIdNode(NODE_VARIABLE,$<ch>3));}
       | ID {$$=makeLDeclIdNode(NODE_VARIABLE,$<ch>1);}
       ;

/*---------------------------------------------------------------------------*/

/*-----------------------MAIN BLOCK------------------------------------------*/

MainBlock : Fdef {$$=$<no>1;}
          ;



Slist : Slist stmt {$$=makeConnectorNode(NODE_CONNECTOR,".",$<no>1,$<no>2);}
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

InputStmt : READ'(' expr ')' SEMICOLON {$$=makereadNode(NODE_READ,$<no>3);}
          ;


OutputStmt : WRITE'(' expr ')' SEMICOLON {$$=makewriteNode(NODE_WRITE,$<no>3);}
           ;

AssgStmt : expr EQUAL expr SEMICOLON {$$=makeOperatorNode(NODE_ASSG_EQ,"=",$<no>1,$<no>3);}
         ;

Ifstmt : IF'(' expr ')' THEN Slist ELSE Slist ENDIF SEMICOLON {$$=makeIfNode(NODE_IF,$<no>3,$<no>6,$<no>8);}
       | IF'(' expr ')' THEN Slist ENDIF SEMICOLON {$$=makeIfNode(NODE_IF,$<no>3,$<no>6,NULL);}
       ;

Whilestmt : WHILE'(' expr ')' DO Slist ENDWHILE SEMICOLON {$$=makeWhileNode(NODE_WHILE,$<no>3,$<no>6);}
          ;

dowhilestmt : DO Slist WHILE'(' expr ')' SEMICOLON {$$=makedowhileNode(NODE_DO,$<no>2,$<no>5);}
            ;

repuntilstmt : REPEAT Slist UNTIL'(' expr ')' SEMICOLON {$$=makerepuntilNode(NODE_REPEAT,$<no>2,$<no>5);}
             ;

breakstmt : BREAK SEMICOLON {$$=makebreakNode(NODE_BREAK);}
          ;

continuestmt : CONTINUE SEMICOLON {$$=makecontNode(NODE_CONTINUE);}
             ;

expr : expr PLUS expr {$$ = makeOperatorNode(NODE_ADD,"+",$<no>1,$<no>3);$$->type = intType;}
    | expr MINUS expr {$$ = makeOperatorNode(NODE_SUB,"-",$<no>1,$<no>3);$$->type = intType;}
    | expr MUL expr {$$ = makeOperatorNode(NODE_MUL,"*",$<no>1,$<no>3); $$->type = intType;}
    | expr DIV expr {$$ = makeOperatorNode(NODE_DIV,"/",$<no>1,$<no>3);$$->type = intType;}
    | expr MOD expr {$$ = makeOperatorNode(NODE_MOD,"%",$<no>1,$<no>3);$$->type = intType;}
    | expr LT expr {$$ = makeOperatorNode(NODE_LT,"<",$<no>1,$<no>3); $$->type = booltype;}
    | expr GT expr {$$ = makeOperatorNode(NODE_GT,">",$<no>1,$<no>3); $$->type = booltype;}
    | expr NE expr {$$ = makeOperatorNode(NODE_NE,"!=",$<no>1,$<no>3); $$->type = booltype;}
    | expr LTE expr {$$ = makeOperatorNode(NODE_LTE,"<=",$<no>1,$<no>3); $$->type = booltype;}
    | expr GTE expr {$$ = makeOperatorNode(NODE_GTE,">=",$<no>1,$<no>3); $$->type = booltype;}
    | expr EQ expr {$$ = makeOperatorNode(NODE_EQ,"==",$<no>1,$<no>3); $$->type = booltype;}
    | expr AND expr {$$ = makeOperatorNode(NODE_AND,"&&",$<no>1,$<no>3);$$->type = booltype;}
    | expr OR expr {$$ = makeOperatorNode(NODE_OR,"||",$<no>1,$<no>3);$$->type = booltype;}
    | NOT expr {$$ = makeOperatorNode(NODE_NOT,"!",NULL,$<no>2);$$->type = booltype;}
    | '(' expr ')' {$$=$<no>2;}
    | Identifier {$$=$<no>1;}
    | NUM {$$=makeNumberNode(NODE_CONSTANT,$<num>1);}
    | STRING {$$=$<no>1;}
    | BREAKPOINT {$$=makeIdNode(NODE_BREAK_POINT,$<ch>1,NULL,NULL);}
    ;

ArgList : ArgList ',' expr {$$=makeConnectorNode(NODE_ARGLIST,".",$<no>1,$<no>3);}
        | expr {$$=$<no>1;}
        ;

Identifier : ID               {$$=makeIdNode(NODE_VARIABLE,$<ch>1,NULL,NULL);}
           | ID'[' expr ']'   {$$=makeIdNode(NODE_VAR_ARRAY,$<ch>1,$<no>3,NULL);}     
           | ID'('')'         {$$=makeIdNode(NODE_VAR_FUNC_CALL,$<ch>1,NULL,NULL);}
           | ID '('ArgList')' {$$=makeIdNode(NODE_VAR_FUNC_CALL,$<ch>1,$<no>3,NULL);}
           ;
%%

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