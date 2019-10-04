OBJ = main.o sort.o
CC = gcc
CFLAGS = -Wall -Werror -std=c99

.PHONY: clean run txt

default: main

main: $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o main

main.o: main.c
	$(CC) -c main.c -o main.o

sort.o: sort.c
	$(CC) -c sort.c -o sort.o
		
clean:
	rm main.o sort.o main

run:
	./main

txt:
	./main < text.txt
