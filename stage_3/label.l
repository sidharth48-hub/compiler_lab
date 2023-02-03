%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include "linked_list.h"
    #include "linked_list.c"
    
    int line = 0;
    int iter = 0;

    FILE* fptr;
%}

letter [a-zA-Z]
digit [0-9]+

%%

{letter}({letter}|{digit})*\n {
                                  if(iter==0)
                                  {
                                    line++;
                                  } 

                                  if(iter==1)
                                  {
                                    int len = strlen(yytext);
                                    yytext[len-1] = '\0';
                                    int addr = findout(yytext);

                                    if(addr!=-1)
                                    {
                                        fprintf(fptr,"%d\n",addr);
                                    }
                                    else
                                    {
                                        fprintf(fptr,"%s\n",yytext);
                                    }
                                  } 
                              }

{letter}({letter}|{digit})*:\n {
                                
                                if(iter==0)
                                {
                                    int addr = 2056 + (2*(line-8));

                                    struct tnode* temp = (struct tnode*)malloc(sizeof(struct tnode));

                                    int len = strlen(yytext);
                                    yytext[len-2]='\0';

                                    char *p = strdup(yytext);

                                    temp->label=p;
                                    temp->address = addr;

                                    insertlink(temp);
                                }
                                }

\n {

    if(iter==1)
    {
        fprintf(fptr,"%s",yytext);
    }

    line++;
}

. {
    if(iter==1)
    {
       fprintf(fptr,"%s",yytext); 
    }
}

%%

int yywrap(void)
{
    if(iter==1)
    {
        return 1;
    }

    iter++;

    yyin = fopen("exptree.o","r");

    return 0;
}

int main()
{
    yyin = fopen("exptree.o","r");
    fptr = fopen("exptree.xsm","w");

    yylex();

    return 1;
}