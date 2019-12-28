all:
	flex minic.l
	bison -d -v minic.y
	gcc -c -g minic.tab.c lex.yy.c definition.c CtoMIPS.c
	gcc -o compiler minic.tab.o lex.yy.o definition.o CtoMIPS.o

clean:
	rm -rf *.o
	rm -rf y.tab.c lex.yy.c y.output y.tab.h
