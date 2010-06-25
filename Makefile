all:stack_hetero.h
	gcc -Wall -o output stack_hetero.c main.c 
clean:
	rm -rf a.out output 
