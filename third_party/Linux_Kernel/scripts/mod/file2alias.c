#include "modpost.h"
#include "devicetable-offsets.h"
/* We use the ELF typedefs for kernel_ulong_t but bite the bullet and
 * use either stdint.h or inttypes.h for the rest. */
#if KERNEL_ELFCLASS == ELFCLASS32
typedef Elf32_Addr	kernel_ulong_t;
#define BITS_PER_LONG 32
#else
typedef Elf64_Addr	kernel_ulong_t;
#define BITS_PER_LONG 64
#endif
#ifdef __sun__
#include <inttypes.h>
#else
#include <stdint.h>
#endif

#include <ctype.h>
#include <stdbool.h>

typedef uint32_t	__u32;
typedef uint16_t	__u16;
typedef unsigned char	__u8;
typedef struct {
	__u8 b[16];
} uuid_le;
#include "../../include/linux/mod_devicetable.h"
#define ___cat(a,b) a ## b
#define __cat(a,b) ___cat(a,b)
#if defined(__MACH__)
#include <mach-o/getsect.h>
#define INIT_SECTION(name)  do {					\
#define SECTION(name)   __attribute__((section("__TEXT, " #name)))
#else
#define INIT_SECTION(name) /* no-op for ELF */
#define SECTION(name)   __attribute__((section(#name)))
#endif /* __MACH__ */
#if !defined(__used)
# if __GNUC__ == 3 && __GNUC_MINOR__ < 3
#  define __used			__attribute__((__unused__))
# else
#  define __used			__attribute__((__used__))
# endif
#endif
#define DEF_FIELD(m, devid, f) \
#define DEF_FIELD_ADDR(m, devid, f) \
#define ADD_TO_DEVTABLE(device_id, type, function) \
#define ADD(str, sep, cond, field)                              \
#define ARRAY_SIZE(x) (sizeof(x) / sizeof((x)[0]))
