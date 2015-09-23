CINC	 = -Iinclude
CONF	 = config
SRC	 = src
BIN	 = bin
UTILSRC  = $(SRC)/list.c $(SRC)/error.c $(SRC)/ast.c

CC       = gcc -g $(CINC)
LEX      = flex -i -I 
YACC     = bison -d -y

all: C 

# Generates a compiler for a simple expression language,
# the grammar is ambiguous, and uses precedence declarations
C:   $(CONF)/C.y $(CONF)/C.lex
	$(YACC) -b C -o $(SRC)/C.tab.c $(CONF)/C.y
	$(LEX) -o$(SRC)/C.lex.c $(CONF)/C.lex
	$(CC) -DDEBUG -DBINARYCODE -o $(BIN)/C $(SRC)/C.lex.c $(SRC)/symtab.c $(SRC)/C.tab.c $(UTILSRC) $(SRC)/codegen.c -ll -lm

clean:
	rm -f *.BAK *.o core *~* *.a 
	rm -f $(SRC)/*.tab.h $(SRC)/*.tab.c
	rm -f $(SRC)/*.lex.c *.out
