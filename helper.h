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

#define CONFIG_KASAN
#define CONFIG_KASAN_SHADOW_OFFSET 0x90000000
#define KASAN_SHADOW_START 0x90000000

#define user_access_save() (0)
#define user_access_restore(...) do {} while(0)
#define dump_stack(...) do {} while(0)
#define check_panic_on_warn(...) do {} while (0)
#define pr_warn(...) do {} while(0)
#define printk(...) printf(__VA_ARGS__)
#define pr_err(...) printk("ERR: " __VA_ARGS__)
#define panic(...) printk("PANIC: " __VA_ARGS__)
#define kunit_fail_current_test(...) do {} while(0)
#define EXPORT_SYMBOL(...) 
#define WARN_ON(...) do {} while (0)
#define BUILD_BUG(...) do {} while (0)

#define BIT(x) _BITUL(x)

#define KERN_ERR "ERR: "

#endif // EMBEDDED_SANITIZER_HELPER_H
