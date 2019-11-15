CC = gcc
CFLAGS = -Wall -Werror -std=c99

.PHONY: clean run

default: tmp main read_from_FIFO write_to_FIFO

main: main.o
	$(CC) $(CFLAGS) main.o -o main

main.o: main.c
	$(CC) -c main.c -o main.o

write_to_FIFO.o: write_to_FIFO.c
	$(CC) -c write_to_FIFO.c -o write_to_FIFO.o

read_from_FIFO.o: read_from_FIFO.c
	$(CC) -c read_from_FIFO.c -o read_from_FIFO.o

tmp:
	mkdir tmp
		
clean:
	rm *.o read_from_FIFO write_to_FIFO main
	rmdir tmp

run:
	./main 3 4 2 15.0

# kill -SIGUSR1 3542
# ps -ax
