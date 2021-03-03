#include <asm/unaligned.h>
#include <linux/errno.h>
#include <linux/compiler.h>
#include <linux/kernel.h>
#include <linux/compat.h>
#include <linux/string.h>
#include <linux/xxhash.h>
#define xxh_rotl32(x, r) ((x << r) | (x >> (32 - r)))
#define xxh_rotl64(x, r) ((x << r) | (x >> (64 - r)))
#ifdef __LITTLE_ENDIAN
# define XXH_CPU_LITTLE_ENDIAN 1
#else
# define XXH_CPU_LITTLE_ENDIAN 0
#endif
