#include "kasan.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <unistd.h>
#include <string.h>

#define MEM_SIZE (1 * 1024 * 1024 * 1024)  // 1 GB
#define MEM_ADDR (void*)0x90000000

void *g_kasan_shadow_offset = NULL;

void kasan_init(void)
{
    g_kasan_shadow_offset = mmap(
        MEM_ADDR,
        MEM_SIZE,
        PROT_READ | PROT_WRITE, MAP_FIXED | MAP_PRIVATE | MAP_ANONYMOUS,
        -1,
        0
    );
    
    if (g_kasan_shadow_offset == MAP_FAILED) {
        perror("mmap failed");
        return;
    }
    
    return;
}
