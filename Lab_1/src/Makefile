prog := test
prog_objs := test.o
CC := gcc

.PHONY: all clean

all: $(prog)

$(prog): $(prog_objs)
	$(CC) -o test $(prog_objs)

$(prog_objs): $(prog).c
	$(CC) -c $(prog).c
	
clean:
	@rm -rf $(prog_objs) $(prog)

run:
	./$(prog)
