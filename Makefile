
CC=gcc
CFLAGS=-g

all: demo-gdb demo-gdb1 demo-valgrind

clean:
	rm demo-gdb demo-valgrind

demo-gdb: demo-gdb.c
	gcc $(CFLAGS) -o $@ $<

demo-gdb1: demo-gdb1.c
	gcc $(CFLAGS) -o $@ $<

demo-valgrind: demo-valgrind.c
	gcc $(CFLAGS) -o $@ $<

