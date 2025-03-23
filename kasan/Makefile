CFLAGS=-fPIC -g -I../include

all: kasan.o report.o
	gcc $(CFLAGS) -shared kasan.o report.o -o libkasan.so
	ar rcs libkasan.a kasan.o report.o

clean:
	rm -rf *.a *.so *.o
