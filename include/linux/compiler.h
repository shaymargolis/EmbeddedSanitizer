#ifndef _LINUX_COMPILER_H
#define _LINUX_COMPILER_H

#define _RET_IP_        (unsigned long)__builtin_return_address(0)

#define __alias(symbol)     __attribute__((alias(#symbol)))

#define likely(x)   __builtin_expect(!!(x), 1)
#define unlikely(x) __builtin_expect(!!(x), 0)

#endif // _LINUX_COMPILER_H
