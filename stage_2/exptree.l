%{
    #include <stdio.h>
    #include <stdlib.h>
    #include "y.tab.h"
    #include "exptree.h"
    int number;
%}

%%

[0-9]+ {number = atoi(yytext);yylval.no = makeNumberNode(number); return NUM;}
[a-z]  {yylval.no = makeIdNode(*yytext); return ID;}
"read" {return READ;}
"write" {return WRITE;}
"begin" {return START;}
"end" {return END;}
"+" {return PLUS;}
"-" {return MINUS;}
"*" {return MUL;}
"/" {return DIV;}
"=" {return EQUAL;}
";" {return SEMICOLON;}
[ \t] {}
[\n] {}
[()] {return *yytext;}

%%

int yywrap(void)
{
    return 1;
}