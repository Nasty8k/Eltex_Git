CC = gcc
CFLAGS = -Wall -Werror -std=c99

.PHONY: clean run

default: main_t1 main_t2

main_t1: main_t1.o
	$(CC) $(CFLAGS) main_t1.o -o main_t1

main_t1.o: main_t1.c
	$(CC) -c main_t1.c -o main_t1.o

main_t2: main_t2.o
	$(CC) $(CFLAGS) main_t2.o -o main_t2

main_t2.o: main_t2.c
	$(CC) -c main_t2.c -o main_t2.o

		
clean:
	rm main_t1.o main_t1 main_t2.o main_t2

t1:
	./main_t1 file.txt 15

t2:
	./main_t2 file.txt 45
