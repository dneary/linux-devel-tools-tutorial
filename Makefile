
CC=gcc
CFLAGS=-g

all: demo-gdb demo-gdb1 demo-valgrind demo-massif demo-kcachegrind

clean:
	rm demo-gdb demo-valgrind

demo-gdb: demo-gdb.c
	gcc $(CFLAGS) -o $@ $<

demo-gdb1: demo-gdb1.c
	gcc $(CFLAGS) -o $@ $<

demo-valgrind: demo-valgrind.c
	gcc $(CFLAGS) -o $@ $<

demo-massif: demo-massif.c
	gcc $(CFLAGS) -o $@ $<

demo-kcachegrind: demo-kcachegrind.c
	gcc $(CFLAGS) -o $@ $<

