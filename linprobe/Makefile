CC=gcc
CFLAGS=-Wall

all: fnv.o linprobe.o main.o
	$(CC) $(CFLAGS) fnv.o linprobe.o main.o -o main

# robinhood: rh.c
# 	$(CC) $(CFLAGS) -c rh.c

fnv: fnv.c
	$(CC) $(CFLAGS) -c fnv.c

linprobe: linprobe.c
	$(CC) $(CFLAGS) -c linprobe.c

main: main.c
	$(CC) $(CFLAGS) -c main.c

clean:
	rm *.o
