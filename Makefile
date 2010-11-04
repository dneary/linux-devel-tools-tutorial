
CC=gcc
CFLAGS=-g

all: demo-gdb demo-valgrind

demo-gdb: demo-gdb.c
	gcc $(CFLAGS) -o $@ $<

demo-valgrind: demo-valgrind.c
	gcc $(CFLAGS) -o $@ $<

