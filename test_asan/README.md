# KASan example

run the following:

```bash
pushd ../kasan && \
    make clean && \
    make && \
    popd && \
    gcc -g -c -fsanitize=kernel-address main.c -o main.o && \
    ld -r main.o -o main.rel.o --wrap=malloc --wrap=free && \
    gcc -g -static main.rel.o -L../kasan -lkasan -lpthread ../utils.o -o main
```
