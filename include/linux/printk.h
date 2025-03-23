#ifndef _LINUX_PRINTK_H
#define _LINUX_PRINTK_H

enum {
    DUMP_PREFIX_NONE,
    DUMP_PREFIX_ADDRESS,
    DUMP_PREFIX_OFFSET
};

extern void print_hex_dump(const char *level, const char *prefix_str,
               int prefix_type, int rowsize, int groupsize,
               const void *buf, size_t len, bool ascii);

#endif // _LINUX_PRINTK_H
