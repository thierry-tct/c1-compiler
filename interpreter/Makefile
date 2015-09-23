CC=g++
CFLAGS=-O2 -Wall -static #-Weffc++
INTERPRETER=interpreter

all:interpreter

interpreter:interpreter.c defs.h
	$(CC) $(CFLAGS) interpreter.c  -o $(INTERPRETER)

clean:
	rm -rf $(INTERPRETER)
