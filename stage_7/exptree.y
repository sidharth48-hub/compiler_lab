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
    #include "./Functions/class.c"
    #include "./Functions/codegen.c"
    #include "./Functions/dynamic_alloc.c"
    #include "./Functions/Func_call.c"
    #include "./Functions/function.c"
    #include "./Functions/Gsymbol.c"
    #include "./Functions/Loop_func.c"
    #include "./Functions/Lsymbol.c"
    #include "./Functions/read_write_assg.c"
    #include "./Functions/TypeDef.c"
    #include "./Functions/var_op.c"
     
    int yylex(void);
    int yyerror();

    struct Classtable *Cptr;
    struct Paramstruct *paramptr;
%}

%union{
    struct tnode *no;
    char* ch;
    int num;
};

%type <no> TypeDefBlock TypeDefList TypeDef FieldDecList FieldDecL TypeName
%type <no> ClassDefBlock ClassDefList ClassDef Cname Fieldlists Fld MethodDecl MDecl MethodDefns classstmt classField classFieldFunction
%type <no> GDeclBlock DeclList Decl VarList IdDecl ParamList Param
%type <no> FdefBlock Fdef Body returnstmt
%type <no> LdeclBlock LDecList LDecl IdList
%type <no> program Slist InputStmt OutputStmt AssgStmt expr stmt Ifstmt Whilestmt breakstmt continuestmt breakpointstmt dowhilestmt repuntilstmt Identifier MainBlock Field ArgList
%token TYPE ENDTYPE ALLOC INITIALIZE FREE VAR_NULL
%token CLASS ENDCLASS SELF NEW DELETE
%token START END DECL ENDDECL INT STR SEMICOLON RETURN BREAKPOINT POINT
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

program : TypeDefBlock GDeclBlock FdefBlock MainBlock {codegenerator($<no>3,$<no>4);}
        | TypeDefBlock GDeclBlock MainBlock {codegenerator(NULL,$<no>3);}
        | TypeDefBlock FdefBlock MainBlock {codegenerator($<no>2,$<no>3);}
        | TypeDefBlock MainBlock  {codegenerator(NULL,$<no>2);}
        | GDeclBlock FdefBlock MainBlock {codegenerator($<no>2,$<no>3);}
        | GDeclBlock MainBlock {codegenerator(NULL,$<no>2);}
        | FdefBlock MainBlock {codegenerator($<no>1,$<no>2);}
        | MainBlock {codegenerator(NULL,$<no>1);}
        ;

/*----------------TYPE DEFINITION BLOCK--------------------------------*/

TypeDefBlock : TYPE TypeDefList ENDTYPE {$$=$<no>2;
                                         TypetableCreate();
                                         TypetableEntry($<no>2);
                                        }
             | TYPE ENDTYPE {}
             ;

TypeDefList : TypeDefList TypeDef {$$=makeTypeConnector(NODE_CONNECTOR,$<no>1,$<no>2);}
            | TypeDef {$$=$<no>1;}
            ;

TypeDef : ID '{' FieldDecList '}' {$$=makeTypeConnector(NODE_TYPEDEF,makeIdNode(NODE_USERID,$<ch>1,NULL,NULL),$<no>3);}
        ;

FieldDecList : FieldDecList FieldDecL {$$=makeTypeConnector(NODE_CONNECTOR,$<no>1,$<no>2);}
             | FieldDecL {$$=$<no>1;}
             ;

FieldDecL : TypeName ID SEMICOLON {$$=makeTypeConnector(NODE_TYPE_FIELD,$<no>1,makeIdNode(NODE_TYPEID,$<ch>2,NULL,NULL));}
          ;

TypeName : INT {$$=makeTypeNameNode("int",NODE_TYPENAME);}
         | STR {$$=makeTypeNameNode("string",NODE_TYPENAME);}
         | ID {$$=makeTypeNameNode($<ch>1,NODE_TYPENAME);}
         ;


/*----------------------------------------------------------------------*/

/*--------------------CLASS DEFINITION BLOCK---------------------------------*/

ClassDefBlock   : CLASS ClassDefList ENDCLASS {}
                |
                ;
ClassDefList    : ClassDefList ClassDef {}
                | ClassDef {}
                ;

ClassDef        : Cname '{'DECL Fieldlists MethodDecl ENDDECL MethodDefns '}' {}
                ;

Cname           : ID        {Cptr = Cinstall($<ch>1,NULL);}
                ;

Fieldlists      : Fieldlists Fld {}
                | Fld {}
                ;

Fld             : ID ID SEMICOLON  {Class_Finstall(Cptr,$<ch>1,$<ch>2);} //Installing the field to the class
                ;

MethodDecl      : MethodDecl MDecl {}
                | MDecl {}
                ;

MDecl           : ID ID '(' ParamList ')' SEMICOLON {
                                                     paramptr = NULL;
                                                     Class_Minstall(Cptr,$<ch>2,TLookup($<ch>1),paramptr);
                                                     }
                | ID ID '('')' SEMICOLON {Class_Minstall(Cptr,$<ch>2,TLookup($<ch>1),NULL);}
                ;

MethodDefns     : FdefBlock
                ;

classstmt       : expr SEMICOLON
                | NEW '(' ID ')' SEMICOLON
                | NEW '(' ID ')' SEMICOLON
                | DELETE '(' classField ')' SEMICOLON
                ;

classField      : SELF POINT ID
                | ID POINT ID   //This will not occur inside a class.
                | classField POINT ID
                ;

classFieldFunction   : SELF POINT ID '(' Arglist ')'
                     | ID POINT ID '(' Arglist ')'   //This will not occur inside a class.
                     | classField POINT ID '(' Arglist ')'
                     ;


/*---------------------------------------------------------------------------*/


/*-----------------GLOBAL DECL BLOCK-----------------------------------*/

GDeclBlock : DECL DeclList ENDDECL {$$=$<no>2;}
           | DECL ENDDECL {}
           ;

DeclList : DeclList Decl {$$=makeDeclNode(NODE_CONNECTOR,$<no>1,$<no>2);}
         | Decl {$$=$<no>1;}
         ;

Decl : TypeName VarList SEMICOLON {$$=makeDataTypeNode(NODE_CONNECTOR,$<no>1,$<no>2);
                               struct Typetable *type = TLookup($<no>1->varname);
                               GsymbolEntry(type,$<no>2);
                               }
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

Param : TypeName ID {$$=makeParamNode(NODE_PARAM,$<no>1,makeIdNodeDecl(NODE_PARAM_VARIABLE,$<ch>2,0,NULL));
                     Param_Install(paramptr,$<ch>1,$<ch>2);
                    }
      ;              

/*---------------------------------------------------------------------------*/

/*---------------------FUNCTION BLOCK----------------------------------------*/

FdefBlock : FdefBlock Fdef {$$=makeFuncConnectorNode(NODE_CONNECTOR,$<no>1,$<no>2);}
          | Fdef {$$=$<no>1;}
          ;

Fdef : TypeName ID '('ParamList')''{' LdeclBlock Body '}' {
                                                          struct tnode *temp1 = $<no>1;
                                                          struct tnode *temp2 = makeFuncConnectorNode(NODE_CONNECTOR,$<no>7,$<no>8);
                                                          struct tnode *temp3 = makeFuncConnectorNode(NODE_CONNECTOR,$<no>4,temp2); 
                                                          struct tnode *temp4 = makeFuncIdNode(NODE_FUNCTION,$<ch>2,temp1,temp3);

                                                          $$ = temp4;

                                                          struct Lsymbol *temp =  LsymbolEntry($<no>4,$<no>7);

                                                          LinkLocalTable(temp,$<no>8);    
                                                       }
     | TypeName ID '('ParamList')' '{' Body '}' {
                                                          struct tnode *temp1 = $<no>1;
                                                          struct tnode *temp2 = makeFuncConnectorNode(NODE_CONNECTOR,NULL,$<no>7);
                                                          struct tnode *temp3 = makeFuncConnectorNode(NODE_CONNECTOR,$<no>4,temp2);

                                                          struct tnode *temp4 = makeFuncIdNode(NODE_FUNCTION,$<ch>2,temp1,temp3);
                                                          
                                                          $$ = temp4;

                                                          struct Lsymbol *temp =  LsymbolEntry($<no>4,NULL);
                                                          LinkLocalTable(temp,$<no>7);
                                            }
     | TypeName ID '('')' '{' LdeclBlock Body '}' {
                                                          struct tnode *temp1 = $<no>1;
                                                          struct tnode *temp2 = makeFuncConnectorNode(NODE_CONNECTOR,$<no>6,$<no>7);
                                                          struct tnode *temp3 = makeFuncConnectorNode(NODE_CONNECTOR,NULL,temp2);
                                                          struct tnode *temp4 = makeFuncIdNode(NODE_FUNCTION,$<ch>2,temp1,temp3);

                                                          $$ = temp4;

                                                          struct Lsymbol *temp =  LsymbolEntry(NULL,$<no>6);
                                                          
                                                          LinkLocalTable(temp,$<no>7);
                                               }
     | TypeName ID '('')' '{' Body '}' {
                                                          struct tnode *temp1 = $<no>1;
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

LDecl : TypeName IdList SEMICOLON {
                               $$=makeLDeclTypeNode(NODE_LTYPE,$<no>1,$<no>2);
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
     | breakpointstmt {$$=$<no>1;}
     | dowhilestmt {$$=$<no>1;}
     | repuntilstmt {$$=$<no>1;}
     | classstmt {$$=$<no>1;}
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

breakpointstmt :  BREAKPOINT SEMICOLON {$$=makeIdNode(NODE_BREAK_POINT,$<ch>1,NULL,NULL);}
               ;

expr : expr PLUS expr {$$ = makeOperatorNode(NODE_ADD,"+",$<no>1,$<no>3);$$->type = intType;}
    | expr MINUS expr {$$ = makeOperatorNode(NODE_SUB,"-",$<no>1,$<no>3);$$->type = intType;}
    | expr MUL expr {$$ = makeOperatorNode(NODE_MUL,"*",$<no>1,$<no>3); $$->type = intType;}
    | expr DIV expr {$$ = makeOperatorNode(NODE_DIV,"/",$<no>1,$<no>3);$$->type = intType;}
    | expr MOD expr {$$ = makeOperatorNode(NODE_MOD,"%",$<no>1,$<no>3);$$->type = intType;}
    | expr LT expr {$$ = makeOperatorNode(NODE_LT,"<",$<no>1,$<no>3); $$->type = boolType;}
    | expr GT expr {$$ = makeOperatorNode(NODE_GT,">",$<no>1,$<no>3); $$->type = boolType;}
    | expr NE expr {$$ = makeOperatorNode(NODE_NE,"!=",$<no>1,$<no>3); $$->type = boolType;}
    | expr LTE expr {$$ = makeOperatorNode(NODE_LTE,"<=",$<no>1,$<no>3); $$->type = boolType;}
    | expr GTE expr {$$ = makeOperatorNode(NODE_GTE,">=",$<no>1,$<no>3); $$->type = boolType;}
    | expr EQ expr {$$ = makeOperatorNode(NODE_EQ,"==",$<no>1,$<no>3); $$->type = boolType;}
    | expr AND expr {$$ = makeOperatorNode(NODE_AND,"&&",$<no>1,$<no>3);$$->type = boolType;}
    | expr OR expr {$$ = makeOperatorNode(NODE_OR,"||",$<no>1,$<no>3);$$->type = boolType;}
    | NOT expr {$$ = makeOperatorNode(NODE_NOT,"!",NULL,$<no>2);$$->type = boolType;}
    | '(' expr ')' {$$=$<no>2;}
    | Identifier {$$=$<no>1;}
    | NUM {$$=makeNumberNode(NODE_CONSTANT,$<num>1);}
    | STRING {$$=$<no>1;}
    | ALLOC'('')' {$$=makeIdNode(NODE_ALLOC,"alloc",NULL,NULL);}
    | INITIALIZE'('')' {$$=makeIdNode(NODE_INITIALIZE,"initialize",NULL,NULL);}
    | FREE'(' expr ')' {$$=makeIdNode(NODE_FREE,"free",$<no>3,NULL);}       
    | VAR_NULL {$$=makeIdNode(NODE_VAR_NULL,"null",NULL,NULL);} 
    | Field {
               $$=$<no>1;
            }
    | classField {$$=$<no>1;}
    | classFieldFunction {$$=$<no>1;}        
    ;

Field : Field POINT ID {$$=makeConnectorNode(NODE_FIELD,".",$<no>1,makeIdNode(NODE_FIELD_VAR,$<ch>3,NULL,NULL));}
      | ID POINT ID {$$=makeConnectorNode(NODE_FIELD,".",makeIdNode(NODE_FIELD_VAR,$<ch>1,NULL,NULL),makeIdNode(NODE_FIELD_VAR,$<ch>3,NULL,NULL));}
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