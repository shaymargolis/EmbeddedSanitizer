#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    printf("Test!\n");

    int *p = malloc(5);
    p = (int *)(((char *)p) + 1);

    *p = 5;

    return 0;
}