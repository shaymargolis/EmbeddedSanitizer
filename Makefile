all: ubsan.o
	gcc -fPIC -Iinclude -Iinclude/uapi main.c ubsan.o -fsanitize=undefined -o main

ubsan.o: ubsan.c
	gcc -fPIC -Iinclude -Iinclude/uapi -c ubsan.c -o ubsan.o

clean:
	rm -rf ubsan.o main
