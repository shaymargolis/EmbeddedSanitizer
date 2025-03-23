#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <unistd.h>
#include <string.h>

#define MEM_SIZE (1000 * 1024 * 1024)  // 1MB
#define MEM_ADDR (void*)0x90000000

int init() {
    // Create a memory mapping with 1MB size starting at address 0x90000000
    void* addr = mmap(MEM_ADDR, MEM_SIZE, PROT_READ | PROT_WRITE, MAP_FIXED | MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    
    if (addr == MAP_FAILED) {
        perror("mmap failed");
        return 1;
    }
    
    return 0;
}

#define REDZONE_SIZE 8  // Example size for redzone

void *my_malloc(size_t size)
{
    size_t total_size = size + 2 * REDZONE_SIZE;
    void *ptr = malloc(total_size);
    if (!ptr)
        return NULL;

    // Poison the redzones
    kasan_poison_shadow(ptr, REDZONE_SIZE, 0xFF);
    kasan_poison_shadow(ptr + REDZONE_SIZE + size, REDZONE_SIZE, 0xFF);

    // Unpoison the actual allocated memory
    kasan_unpoison_shadow(ptr + REDZONE_SIZE, size);

    // Return pointer to the actual usable memory
    return ptr + REDZONE_SIZE;
}

void my_free(void *ptr, size_t size)
{
    if (!ptr)
        return;

    // Get the original pointer with redzones
    void *original_ptr = ptr - REDZONE_SIZE;
    size_t total_size = size + 2 * REDZONE_SIZE;

    // Poison everything (including redzones and allocated area)
    kasan_poison_shadow(original_ptr, total_size, 0xFF);

    // Free the original pointer
    free(original_ptr);
}
