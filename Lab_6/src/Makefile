CC = gcc
CFLAGS = -Wall -Werror -std=c99

.PHONY: clean run

default: warcraft

warcraft: warcraft.o
	$(CC) $(CFLAGS) warcraft.o -o warcraft

warcraft.o: warcraft.c
	$(CC) -c warcraft.c -o warcraft.o

clean:
	rm warcraft.o warcraft

run:
	./warcraft 5 10

