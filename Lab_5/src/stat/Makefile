
.PHONY: clean run

default: libvar5.a prog

var5.o: var5.c
	gcc -c var5.c

libvar5.a: var5.o
	ar rc libvar5.a var5.o
	ranlib libvar5.a

prog: main.c
	gcc main.c -L. -lvar5 -o prog

main_t2.o: main_t2.c
	$(CC) -c main_t2.c -o main_t2.o
		
clean:
	rm *.o *.a prog

run:
	./prog
