/* SPDX-License-Identifier: GPL-2.0 */
#ifndef __TOOLS_ASM_GENERIC_ATOMIC_H
#define __TOOLS_ASM_GENERIC_ATOMIC_H

#include <linux/bits.h>

static inline int test_and_set_bit(long nr, unsigned long *addr)
{
    unsigned long mask = BIT_MASK(nr);
    long old;

    addr += BIT_WORD(nr);

    old = __sync_fetch_and_or(addr, mask);
    return !!(old & mask);
}

static inline int test_and_clear_bit(long nr, unsigned long *addr)
{
    unsigned long mask = BIT_MASK(nr);
    long old;

    addr += BIT_WORD(nr);

    old = __sync_fetch_and_and(addr, ~mask);
    return !!(old & mask);
}

#endif /* __TOOLS_ASM_GENERIC_ATOMIC_H */
