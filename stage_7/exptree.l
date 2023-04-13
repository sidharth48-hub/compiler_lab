%{
    #include <stdio.h>
    #include <stdlib.h>
    #include "y.tab.h"
    #include "exptree.h"
    #include "typedef.h"
    void yyerror(char*); 
    char* error;
%}

identifier ([a-zA-Z]|_[a-zA-Z])[a-zA-Z0-9_]*
strings \"((\\\")|[^"])*\"
numbers [0-9]+ 

%%

type            {return TYPE;}
endtype         {return ENDTYPE;}
alloc           {return ALLOC;}
initialize      {return INITIALIZE;}
free            {return FREE;}
null            {return VAR_NULL;}
class           {return CLASS;}
endclass        {return ENDCLASS;}
self            {return SELF;}
delete          {return DELETE;}
new             {return NEW;}
begin           {return START;}
end             {return END;}
decl            {return DECL;}
enddecl         {return ENDDECL;}
return          {return RETURN;}
int             {return INT;}
string          {return STR;}
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
breakpoint      {return BREAKPOINT;}
{numbers}       {yylval.num = atoi(yytext); return NUM;}
{identifier}    {yylval.ch = strdup(yytext); return ID;}
{strings}       {yylval.no = makeStringsNode(NODE_STRINGS,strdup(yytext)); return STRING;}
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
"&&"            {return AND;}
"||"            {return OR;}
"!"             {return NOT;}
"."             {return POINT;}
[ \t]           {}
[\n]            {yylineno++;}
[,()\[\]{}]	    {return *yytext;}
%%

int yywrap(void)
{
    return 1;
}