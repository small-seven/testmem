#if !(defined(__GNUC__) && __GNUC__>=2)
# error "this is gcc-specific template"
#endif
#include <stdlib.h>
typedef unsigned char u8;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef union { double d; u64 u; } elem64;
#define TWO(p)          ((double)(1ULL<<(p)))
#define TWO0            TWO(0)
#define TWO32           TWO(32)
#define TWO64           (TWO32*TWO(32))
#define TWO96           (TWO64*TWO(32))
#define TWO130          (TWO96*TWO(34))
#define EXP(p)          ((1023ULL+(p))<<52)
#if defined(__x86_64__) || (defined(__PPC__) && defined(__LITTLE_ENDIAN__))
# define U8TOU32(p)     (*(const u32 *)(p))
# define U32TO8(p,v)    (*(u32 *)(p) = (v))
#elif defined(__PPC__)
# define U8TOU32(p)     ({u32 ret; asm ("lwbrx	%0,0,%1":"=r"(ret):"b"(p)); ret; })
# define U32TO8(p,v)    asm ("stwbrx %0,0,%1"::"r"(v),"b"(p):"memory")
#elif defined(__s390x__)
# define U8TOU32(p)     ({u32 ret; asm ("lrv	%0,%1":"=d"(ret):"m"(*(u32 *)(p))); ret; })
# define U32TO8(p,v)    asm ("strv	%1,%0":"=m"(*(u32 *)(p)):"d"(v))
#endif
#ifndef U8TOU32
# define U8TOU32(p)     ((u32)(p)[0]     | (u32)(p)[1]<<8 |     \
#endif
#ifndef U32TO8
# define U32TO8(p,v)    ((p)[0] = (u8)(v),       (p)[1] = (u8)((v)>>8), \
#endif
typedef struct {
    elem64 h[4];
    double r[8];
    double s[6];
} poly1305_internal;
#if defined(__x86_64__)
#elif defined(__PPC__)
#elif defined(__s390x__)
#elif defined(__sparc__)
#elif defined(__mips__)
#else
#error "unrecognized platform"
#endif
#if 0
#else
#endif
#if defined(__x86_64__)
#elif defined(__PPC__)
#elif defined(__s390x__)
#elif defined(__sparc__)
#elif defined(__mips__)
#endif
#if defined(__x86_64__)
#elif defined(__PPC__)
#elif defined(__s390x__)
#elif defined(__sparc__)
#elif defined(__mips__)
#endif
#if defined(__x86_64__)
#elif defined(__PPC__)
#elif defined(__s390x__)
#elif defined(__sparc__)
#elif defined(__mips__)
#endif
#ifdef __clang__
#else
#endif
#ifndef __clang__
#endif
#if defined(__x86_64__)
#elif defined(__PPC__)
#elif defined(__s390x__)
#elif defined(__sparc__)
#elif defined(__mips__)
#endif
