%{
    #include <stdio.h>
    #include <stdlib.h>
    #include "y.tab.h"
    #include "exptree.h"

    #define intType 1
    #define stringType 2
     
    void yyerror(char*); 
    char* error;
%}

identifier ([a-zA-Z]|_[a-zA-Z])[a-zA-Z0-9_]*
strings \"((\\\")|[^"])*\"
numbers [0-9]+ 

%%

begin           {return START;}
end             {return END;}
decl            {return DECL;}
enddecl         {return ENDDECL;}
int             {yylval.num = intType;return INT;}
string          {yylval.num = stringType;return STR;}
read            {return READ;}
write           {return WRITE;}
if              {return IF;}
then            {return THEN;}
else            {return ELSE;}
endif           {return ENDIF;}
while           {return WHILE;}
do              {return DO;}
endwhile        {return ENDWHILE;}
repeat          {return REPEAT;}
until           {return UNTIL;}
break           {return BREAK;}
continue        {return CONTINUE;}
{numbers}       {yylval.num = atoi(yytext); return NUM;}
{identifier}    {yylval.ch = strdup(yytext); return ID;}
{strings}       {yylval.no = makeStringsNode(strdup(yytext)); return STRING;}
"+"             {return PLUS;}
"-"             {return MINUS;}
"*"             {return MUL;}
"/"             {return DIV;}
"%"             {return MOD;}
"="             {return EQUAL;}
";"             {return SEMICOLON;}
"<"             {return LT;}
">"             {return GT;}
"<="            {return LTE;}
">="            {return GTE;}
"!="            {return NE;}
"=="            {return EQ;}
[ \t]           {}
[\n]            {}
[,()\[\]]	    {return *yytext;}
.		        {}
%%

int yywrap(void)
{
    return 1;
}