
.PHONY: clean run

default: libvar5D.so main.o prog

var5.o: var5.c
	gcc -fPIC -c var5.c

libvar5D.so: var5.o
	gcc -shared -o libvar5D.so var5.o

main.o: main.c
	gcc -c main.c
	
prog: main.c
	gcc -static main.o -L. -lvar5D -o prog
		
clean:
	rm *.o *.so prog

run:
	./prog
