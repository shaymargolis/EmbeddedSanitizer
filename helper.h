#ifndef EMBEDDED_SANITIZER_HELPER_H
#define EMBEDDED_SANITIZER_HELPER_H

#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>

typedef int8_t  s8;   // Signed 8-bit
typedef uint8_t u8;   // Unsigned 8-bit

typedef int16_t s16;  // Signed 16-bit
typedef uint16_t u16; // Unsigned 16-bit

typedef int32_t s32;  // Signed 32-bit
typedef uint32_t u32; // Unsigned 32-bit

typedef int64_t s64;  // Signed 64-bit
typedef uint64_t u64; // Unsigned 64-bit

// #define CONFIG_UBSAN_TRAP
#define CONFIG_UBSAN_ALIGNMENT
#define CONFIG_UBSAN_BOOL
#define CONFIG_UBSAN_BOUNDS
#define CONFIG_UBSAN_DIV_ZERO
#define CONFIG_UBSAN_ENUM
#define CONFIG_UBSAN_SHIFT
#define CONFIG_UBSAN_SIGNED_WRAP
#define CONFIG_UBSAN_UNREACHABLE

#define user_access_save() (0)
#define user_access_restore(...) do {} while(0)
#define dump_stack(...) do {} while(0)
#define check_panic_on_warn(...) do {} while (0)
#define pr_warn(...) do {} while(0)
#define pr_err(...) printf("ERR: " __VA_ARGS__)
#define panic(...) printf("PANIC: " __VA_ARGS__)
#define kunit_fail_current_test(...) do {} while(0)
#define EXPORT_SYMBOL(...) 
#define WARN_ON(...) do {} while (0)

#define BIT(x) _BITUL(x)

#endif // EMBEDDED_SANITIZER_HELPER_H
