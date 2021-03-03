#include <assert.h>
#include <stdlib.h>
#include <openssl/aes.h>
#include "aes_local.h"
#define AES_COMPACT_IN_OUTER_ROUNDS
#ifdef  AES_COMPACT_IN_OUTER_ROUNDS
# undef  AES_COMPACT_IN_INNER_ROUNDS
#endif
#if 1
#else
# define prefetch256(t)
#endif
#undef GETU32
#define GETU32(p) (*((u32*)(p)))
#if (defined(_WIN32) || defined(_WIN64)) && !defined(__MINGW32__)
typedef unsigned __int64 u64;
#define U64(C)  C##UI64
#elif defined(__arch64__)
typedef unsigned long u64;
#define U64(C)  C##UL
#else
typedef unsigned long long u64;
#define U64(C)  C##ULL
#endif

#undef ROTATE
#if defined(_MSC_VER)
# define ROTATE(a,n)    _lrotl(a,n)
#elif defined(__ICC)
# define ROTATE(a,n)    _rotl(a,n)
#elif defined(__GNUC__) && __GNUC__>=2
# if defined(__i386) || defined(__i386__) || defined(__x86_64) || defined(__x86_64__)
#   define ROTATE(a,n)  ({ register unsigned int ret;   \
                asm (           \
                "roll %1,%0"        \
                : "=r"(ret)     \
                : "I"(n), "0"(a)    \
                : "cc");        \
               ret;             \
            })
# endif
#endif
#define Te0 (u32)((u64*)((u8*)Te+0))
#define Te1 (u32)((u64*)((u8*)Te+3))
#define Te2 (u32)((u64*)((u8*)Te+2))
#define Te3 (u32)((u64*)((u8*)Te+1))
#define Td0 (u32)((u64*)((u8*)Td+0))
#define Td1 (u32)((u64*)((u8*)Td+3))
#define Td2 (u32)((u64*)((u8*)Td+2))
#define Td3 (u32)((u64*)((u8*)Td+1))
#if 1
#if defined(ROTATE)
#else
#endif
#else
#endif
#if defined(AES_COMPACT_IN_OUTER_ROUNDS)
#if defined(ROTATE)
#else
#endif
#else
#endif
#if defined(AES_COMPACT_IN_INNER_ROUNDS)
#if defined(ROTATE)
#else
#endif
#else
#endif
#if defined(AES_COMPACT_IN_OUTER_ROUNDS)
#else
#endif
#if defined(AES_COMPACT_IN_OUTER_ROUNDS)
#if defined(ROTATE)
#else
#endif
#else
#endif
#if defined(AES_COMPACT_IN_INNER_ROUNDS)
#if defined(ROTATE)
#else
#endif
#else
#endif
