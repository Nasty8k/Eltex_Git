OBJ = main.o
CC = gcc
CFLAGS = -Wall -Werror -std=c99

.PHONY: clean run

default: main

main: $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o main

main.o: main.c
	$(CC) -c main.c -o main.o

clean:
	rm main.o main

run:
	./main
