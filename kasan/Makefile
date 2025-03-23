CFLAGS=-fPIC -g -I../include

all: kasan.o report.o shadow_um.o hook_um.o
	gcc $(CFLAGS) -shared kasan.o report.o shadow_um.o hook_um.o -o libkasan.so
	ar rcs libkasan.a kasan.o report.o shadow_um.o hook_um.o

clean:
	rm -rf *.a *.so *.o
