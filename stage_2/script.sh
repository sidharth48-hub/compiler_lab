#!/bin/sh
lex exptree.l
yacc -d exptree.y
gcc lex.yy.c y.tab.c