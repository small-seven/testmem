#ifndef SI_TYPE_SIZE
#define SI_TYPE_SIZE 32
#endif
#define __ll_B (1L << (SI_TYPE_SIZE / 2))
#define __ll_lowpart(t) ((USItype) (t) % __ll_B)
#define __ll_highpart(t) ((USItype) (t) / __ll_B)
#define BITS_PER_UNIT 8
#if !defined(umul_ppmm)
#define umul_ppmm(w1, w0, u, v)						\
#endif
#if !defined(__umulsidi3)
#define __umulsidi3(u, v)						\
#endif
typedef unsigned int USItype __attribute__ ((mode(SI)));
typedef int SItype __attribute__ ((mode(SI)));
typedef int DItype __attribute__ ((mode(DI)));
typedef int word_type __attribute__ ((mode(__word__)));

struct DIstruct {
	SItype low, high;
};
typedef union {
	struct DIstruct s;
	DItype ll;
} DIunion;
