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

"if" {return IF;}
"then" {return THEN;}
"else" {return ELSE;}
"endif" {return ENDIF;}

"while" {return WHILE;}
"do" {return DO;}
"endwhile" {return ENDWHILE;}

"break" {return BREAK;}
"continue" {return CONTINUE;}

"repeat" {return REPEAT;}
"until" {return UNTIL;}

"+" {return PLUS;}
"-" {return MINUS;}
"*" {return MUL;}
"/" {return DIV;}
"=" {return EQUAL;}
";" {return SEMICOLON;}

"<" {return LT;}
">" {return GT;}
"<=" {return LTE;}
">=" {return GTE;}
"!=" {return NE;}
"==" {return EQ;}

[ \t] {}
[\n] {;}
[()] {return *yytext;}

%%

int yywrap(void)
{
    return 1;
}