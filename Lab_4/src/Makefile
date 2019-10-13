CC = gcc
CFLAGS = -Wall -Werror -std=c99

.PHONY: clean run

default: main_t1

main_t1: main_t1.o
	$(CC) $(CFLAGS) main_t1.o -o main_t1

main_t1.o: main_t1.c
	$(CC) -c main_t1.c -o main_t1.o
		
clean:
	rm main_t1.o main_t1

t1:
	./main_t1 text.txt 15
