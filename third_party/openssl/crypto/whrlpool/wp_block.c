#include "wp_local.h"
#include <string.h>
typedef unsigned char u8;
#if (defined(_WIN32) || defined(_WIN64)) && !defined(__MINGW32)
typedef unsigned __int64 u64;
#elif defined(__arch64__)
typedef unsigned long u64;
#else
typedef unsigned long long u64;
#endif

#define ROUNDS  10

#define STRICT_ALIGNMENT
#if !defined(PEDANTIC) && (defined(__i386) || defined(__i386__) || \
                           defined(__x86_64) || defined(__x86_64__) || \
                           defined(_M_IX86) || defined(_M_AMD64) || \
                           defined(_M_X64))
/*
 * Well, formally there're couple of other architectures, which permit
 * unaligned loads, specifically those not crossing cache lines, IA-64 and
 * PowerPC...
 */
# undef STRICT_ALIGNMENT
#endif

#undef SMALL_REGISTER_BANK
#if defined(__i386) || defined(__i386__) || defined(_M_IX86)
# define SMALL_REGISTER_BANK
# if defined(WHIRLPOOL_ASM)
#  ifndef OPENSSL_SMALL_FOOTPRINT
/*
 * it appears that for elder non-MMX
 * CPUs this is actually faster!
 */
#   define OPENSSL_SMALL_FOOTPRINT
#  endif
#  define GO_FOR_MMX(ctx,inp,num)     do {                    \
        extern unsigned long OPENSSL_ia32cap_P[];               \
        void whirlpool_block_mmx(void *,const void *,size_t);   \
        if (!(OPENSSL_ia32cap_P[0] & (1<<23)))  break;          \
        whirlpool_block_mmx(ctx->H.c,inp,num);  return;         \
                                        } while (0)
# endif
#endif
#undef ROTATE
#ifndef PEDANTIC
# if defined(_MSC_VER)
#  if defined(_WIN64)            /* applies to both IA-64 and AMD64 */
#   include <stdlib.h>
#   pragma intrinsic(_rotl64)
#   define ROTATE(a,n) _rotl64((a),n)
#  endif
# elif defined(__GNUC__) && __GNUC__>=2
#  if defined(__x86_64) || defined(__x86_64__)
#   if defined(L_ENDIAN)
#    define ROTATE(a,n)       ({ u64 ret; asm ("rolq %1,%0"   \
#   elif defined(B_ENDIAN)
#    define ROTATE(a,n)       ({ u64 ret; asm ("rorq %1,%0"   \
#   endif
#  elif defined(__ia64) || defined(__ia64__)
#   if defined(L_ENDIAN)
#    define ROTATE(a,n)       ({ u64 ret; asm ("shrp %0=%1,%1,%2"     \
#   elif defined(B_ENDIAN)
#    define ROTATE(a,n)       ({ u64 ret; asm ("shrp %0=%1,%1,%2"     \
#   endif
#  endif
# endif
#endif
#if defined(OPENSSL_SMALL_FOOTPRINT)
# if !defined(ROTATE)
#  if defined(L_ENDIAN)         /* little-endians have to rotate left */
#   define ROTATE(i,n)       ((i)<<(n) ^ (i)>>(64-n))
#  elif defined(B_ENDIAN)       /* big-endians have to rotate right */
#   define ROTATE(i,n)       ((i)>>(n) ^ (i)<<(64-n))
#  endif
# endif
# if defined(ROTATE) && !defined(STRICT_ALIGNMENT)
#  define STRICT_ALIGNMENT      /* ensure smallest table size */
# endif
#endif
#ifdef STRICT_ALIGNMENT
# if defined(ROTATE)
#  define N   1
#  define LL(c0,c1,c2,c3,c4,c5,c6,c7) c0,c1,c2,c3,c4,c5,c6,c7
#  define C0(K,i)     (Cx.q[K.c[(i)*8+0]])
#  define C1(K,i)     ROTATE(Cx.q[K.c[(i)*8+1]],8)
#  define C2(K,i)     ROTATE(Cx.q[K.c[(i)*8+2]],16)
#  define C3(K,i)     ROTATE(Cx.q[K.c[(i)*8+3]],24)
#  define C4(K,i)     ROTATE(Cx.q[K.c[(i)*8+4]],32)
#  define C5(K,i)     ROTATE(Cx.q[K.c[(i)*8+5]],40)
#  define C6(K,i)     ROTATE(Cx.q[K.c[(i)*8+6]],48)
#  define C7(K,i)     ROTATE(Cx.q[K.c[(i)*8+7]],56)
# else
#  define N   8
#  define LL(c0,c1,c2,c3,c4,c5,c6,c7) c0,c1,c2,c3,c4,c5,c6,c7, \
#  define C0(K,i)     (Cx.q[0+8*K.c[(i)*8+0]])
#  define C1(K,i)     (Cx.q[1+8*K.c[(i)*8+1]])
#  define C2(K,i)     (Cx.q[2+8*K.c[(i)*8+2]])
#  define C3(K,i)     (Cx.q[3+8*K.c[(i)*8+3]])
#  define C4(K,i)     (Cx.q[4+8*K.c[(i)*8+4]])
#  define C5(K,i)     (Cx.q[5+8*K.c[(i)*8+5]])
#  define C6(K,i)     (Cx.q[6+8*K.c[(i)*8+6]])
#  define C7(K,i)     (Cx.q[7+8*K.c[(i)*8+7]])
# endif
#else
# define N     2
# define LL(c0,c1,c2,c3,c4,c5,c6,c7)   c0,c1,c2,c3,c4,c5,c6,c7, \
# define C0(K,i)       (((u64*)(Cx.c+0))[2*K.c[(i)*8+0]])
# define C1(K,i)       (((u64*)(Cx.c+7))[2*K.c[(i)*8+1]])
# define C2(K,i)       (((u64*)(Cx.c+6))[2*K.c[(i)*8+2]])
# define C3(K,i)       (((u64*)(Cx.c+5))[2*K.c[(i)*8+3]])
# define C4(K,i)       (((u64*)(Cx.c+4))[2*K.c[(i)*8+4]])
# define C5(K,i)       (((u64*)(Cx.c+3))[2*K.c[(i)*8+5]])
# define C6(K,i)       (((u64*)(Cx.c+2))[2*K.c[(i)*8+6]])
# define C7(K,i)       (((u64*)(Cx.c+1))[2*K.c[(i)*8+7]])
#endif
#define RC      (&(Cx.q[256*N]))
#ifdef GO_FOR_MMX
#endif
#ifdef OPENSSL_SMALL_FOOTPRINT
#else
# ifdef STRICT_ALIGNMENT
# endif
# ifdef SMALL_REGISTER_BANK
# else
# endif
# ifdef STRICT_ALIGNMENT
# endif
#endif
