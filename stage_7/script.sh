#!/bin/sh
lex exptree.l
yacc -d exptree.y
gcc -g lex.yy.c y.tab.c
#./a.out
#lex label.l
#gcc lex.yy.c
#./a.out