flex minic.l
bison -d -v minic.y
gcc -c -g minic.tab.c lex.yy.c definition.c CtoMIPS.c
gcc -o compiler minic.tab.o lex.yy.o definition.o CtoMIPS.o