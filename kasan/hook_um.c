#include "kasan.h"
#include <linux/kasan.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <unistd.h>
#include <string.h>

// extern void *malloc(size_t);
// extern void *free(void *);

#define REDZONE_SIZE 8  // Example size for redzone

typedef struct my_malloc {
    char redzone[REDZONE_SIZE];
    size_t size;
    char real_buf[];
} my_malloc_t;

void *__wrap_malloc(size_t size)
{
    size_t total_size = size + 2 * REDZONE_SIZE + sizeof(size_t);
    void *ptr = malloc(total_size);
    if (!ptr)
        return NULL;

    // Poison the redzones
    kasan_poison_shadow(ptr, sizeof(my_malloc_t), 0xFF);
    kasan_poison_shadow(ptr + sizeof(my_malloc_t) + size, REDZONE_SIZE, 0xFF);

    // Unpoison the actual allocated memory
    kasan_unpoison_shadow(ptr + sizeof(my_malloc_t), size);

    // Return pointer to the actual usable memory
    my_malloc_t *metadata = (my_malloc_t *)ptr;
    metadata->size = total_size;

    return metadata->real_buf;
}

void __wrap_free(void *ptr)
{
    if (!ptr)
        return;

    // Get the original pointer with redzones
    my_malloc_t *original_ptr = ptr - sizeof(my_malloc_t);
    size_t total_size = original_ptr->size;

    // Poison everything (including redzones and allocated area)
    kasan_poison_shadow(original_ptr, total_size, 0xFF);

    // Free the original pointer
    free(original_ptr);
}
