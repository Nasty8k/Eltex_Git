CC = gcc
CFLAGS = -Wall -Werror -std=c99

.PHONY: clean run

default: obj prog

prog: obj/pipe_many.o
	$(CC) $(CFLAGS) obj/pipe_many.o -o prog

obj/pipe_many.o: src/pipe_many.c
	$(CC) -c src/pipe_many.c -o obj/pipe_many.o

obj:
	mkdir obj
clean:
	rm prog obj/*.o
	rmdir obj
#./prog <количество пчел> <производительность пчел> <потребление меда> <за какое время сек>
run:
	./prog 3 2 1 0.001
