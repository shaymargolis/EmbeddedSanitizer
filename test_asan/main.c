#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
    kasan_init();

    int *a = malloc(sizeof(int));
    *a = 5;
    *(a+1) = 6;

    free(a);

    *a = 6;

    return 0;
}