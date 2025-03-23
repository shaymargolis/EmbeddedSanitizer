#include <stddef.h>
#include <stdbool.h>
#include <linux/printk.h>

#include "helper.h"

/**
 * print_hex_dump - print a text hex dump to syslog for a binary blob of data
 * @level: kernel log level (e.g. KERN_DEBUG)
 * @prefix_str: string to prefix each line with;
 *  caller supplies trailing spaces for alignment if desired
 * @prefix_type: controls whether prefix of an offset, address, or none
 *  is printed (%DUMP_PREFIX_OFFSET, %DUMP_PREFIX_ADDRESS, %DUMP_PREFIX_NONE)
 * @rowsize: number of bytes to print per line; must be 16 or 32
 * @groupsize: number of bytes to print at a time (1, 2, 4, 8; default = 1)
 * @buf: data blob to dump
 * @len: number of bytes in the @buf
 * @ascii: include ASCII after the hex output
 *
 * Given a buffer of u8 data, print_hex_dump() prints a hex + ASCII dump
 * to the kernel log at the specified kernel log level, with an optional
 * leading prefix.
 *
 * print_hex_dump() works on one "line" of output at a time, i.e.,
 * 16 or 32 bytes of input data converted to hex + ASCII output.
 * print_hex_dump() iterates over the entire input @buf, breaking it into
 * "line size" chunks to format and print.
 *
 * E.g.:
 *   print_hex_dump(KERN_DEBUG, "raw data: ", DUMP_PREFIX_ADDRESS,
 *          16, 1, frame->data, frame->len, true);
 *
 * Example output using %DUMP_PREFIX_OFFSET and 1-byte mode:
 * 0009ab42: 40 41 42 43 44 45 46 47 48 49 4a 4b 4c 4d 4e 4f  @ABCDEFGHIJKLMNO
 * Example output using %DUMP_PREFIX_ADDRESS and 4-byte mode:
 * ffffffff88089af0: 73727170 77767574 7b7a7978 7f7e7d7c  pqrstuvwxyz{|}~.
 */
void print_hex_dump(const char *level, const char *prefix_str, int prefix_type,
            int rowsize, int groupsize,
            const void *buf, size_t len, bool ascii)
{
    for (int i = 0; i < len; i++) {
        if (i%0x10 == 0) {
            printf("\n%s %08X: ", prefix_str, i);
        }

        printf("%02X ", ((char *)buf)[i]);
    }

    printf("\n");
    // const u8 *ptr = buf;
    // int i, linelen, remaining = len;
    // unsigned char linebuf[32 * 3 + 2 + 32 + 1];

    // if (rowsize != 16 && rowsize != 32)
    //     rowsize = 16;

    // for (i = 0; i < len; i += rowsize) {
    //     linelen = min(remaining, rowsize);
    //     remaining -= rowsize;

    //     hex_dump_to_buffer(ptr + i, linelen, rowsize, groupsize,
    //                linebuf, sizeof(linebuf), ascii);

    //     switch (prefix_type) {
    //     case DUMP_PREFIX_ADDRESS:
    //         printk("%s%s%p: %s\n",
    //                level, prefix_str, ptr + i, linebuf);
    //         break;
    //     case DUMP_PREFIX_OFFSET:
    //         printk("%s%s%.8x: %s\n", level, prefix_str, i, linebuf);
    //         break;
    //     default:
    //         printk("%s%s%s\n", level, prefix_str, linebuf);
    //         break;
    //     }
    // }
}
EXPORT_SYMBOL(print_hex_dump);
