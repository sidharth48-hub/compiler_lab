%{
#ifndef YTAB_H
#define YTAB_H
#include "y.tab.h"
#endif


#ifndef EXPR_TREE_H
#define EXPR_TREE_H
#include "expr_tree.h"
#include "expr_tree.c"
#endif

%}


%%

[0-9]+ {
    yylval.node = makeNumberNode(atoi((yytext)));
    return NUMBER;
}
    
"+" {
    return PLUS;
}
    
"-" {
    return MINUS;
}
    
"*" {
    return MUL;
}
    
"/" {
    return DIV;
}

"=" {
    return EQUALS;
}

";" {
    return SEMICOLON;
}
    
"read" {
    return READ;
}

"write" {
    return WRITE;
}

"begin" {
    return START;
}

"end" {
    return END;
}

[\t] {}
    
[()] {
    return *yytext;
}

[\n] {
    
}
    
[a-z] {
    yylval.node = makeIdNode(*yytext);
    return ID;
}

%%

int yywrap(void){
    return 1;
}