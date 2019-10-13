
.PHONY: clean run

default: libvar5.so prog

var5.o: var5.c
	gcc -fPIC -c var5.c

libvar5.so: var5.o
	gcc -shared var5.o -o libvar5.so

prog: main.c
	gcc main.c -o prog -ldl
		
clean:
	rm *.o *.a prog

run:
	./prog
