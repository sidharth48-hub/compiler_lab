%{
    #include <stdio.h>
    #include <stdlib.h>
    #include "exptree.h"
    #include "exptree.c"
    #include "codegen.c"
    int yylex(void);
%}

%union{
    struct tnode *no;
}

%type <no> expr NUM program END
%token NUM PLUS MINUS MUL DIV END
%left PLUS MINUS
%left MUL DIV

%%

program : expr END {$$=$2;
                    FILE *fptr = fopen("exptree.xsm", "w");
                    fprintf(fptr, "%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n",0,2056,0,0,0,0,0,0);
                    codeGen($1,fptr);
                    fprintf(fptr,"INT 10");
                    exit(1);}
       ;

expr : PLUS expr expr {$$ = makeOperatorNode('+',$2,$3);}
    | MINUS expr expr {$$ = makeOperatorNode('-',$2,$3);}
    | MUL expr expr {$$ = makeOperatorNode('*',$2,$3);}
    | DIV expr expr {$$ = makeOperatorNode('/',$2,$3);}
    | '(' expr ')' {$$=$2;}
    | NUM {$$=$1;}
    ;
%%

yyerror(char const *s)
{
    printf("yyerror %s",s);
}

int main(void)
{
    yyparse();
    return 0;
}