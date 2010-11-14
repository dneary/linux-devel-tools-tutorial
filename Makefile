
CC=gcc
CFLAGS=-g

TARGETS=demo-gdb demo-gdb1 demo-valgrind demo-massif demo-kcachegrind

all: $(TARGETS)

clean:
	rm $(TARGETS)

demo-gdb: demo-gdb.c
	$(CC) $(CFLAGS) -o $@ $<

demo-gdb1: demo-gdb1.c
	$(CC) $(CFLAGS) -o $@ $<

demo-valgrind: demo-valgrind.c
	$(CC) $(CFLAGS) -o $@ $<

demo-massif: demo-massif.c
	$(CC) $(CFLAGS) -o $@ $<

demo-kcachegrind: demo-kcachegrind.c
	$(CC) $(CFLAGS) -o $@ $<

