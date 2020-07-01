#a single c.file makefile   
CC=clang
CFLAGS=-Wall -O
LDFLAGS=
EXEC=myapp
SRC=$(wildcard *.c)

all: $(EXEC)

myapp: $(SRC)
			$(CC) -o $@ $^ $(LDFLAGS) 
			

