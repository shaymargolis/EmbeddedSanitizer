/* SPDX-License-Identifier: GPL-2.0 */
#ifndef __LINUX_BITS_H
#define __LINUX_BITS_H

#include "asm/bitsperlong.h"
#include "linux/const.h"

#define BITS_PER_BYTE (8)
#define BITS_PER_LONG (BITS_PER_BYTE * __SIZEOF_LONG__)
#define BITS_PER_LONG_LONG (BITS_PER_BYTE * __SIZEOF_LONG_LONG__)

#define BIT_MASK(nr)        (_UL(1) << ((nr) % BITS_PER_LONG))
#define BIT_WORD(nr)        ((nr) / BITS_PER_LONG)
#define BIT_ULL_MASK(nr)    (_ULL(1) << ((nr) % BITS_PER_LONG_LONG))
#define BIT_ULL_WORD(nr)    ((nr) / BITS_PER_LONG_LONG)

#endif  /* __LINUX_BITS_H */
