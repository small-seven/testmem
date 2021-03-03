#ifndef GF_BITS
#define GF_BITS  8	/* code over GF(2**GF_BITS) - change to suit */
#endif
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libfec.h"
#ifdef	TEST
#define DEB(x)
#define DDB(x) x
#define	DEBUG	0	/* minimal debugging */
#ifdef	MSDOS
#include <time.h>
#define gettimeofday(x, dummy) { (x)->ticks = clock() ; }
#define DIFF_T(a,b) (1+ 1000000*(a.ticks - b.ticks) / CLOCKS_PER_SEC )
#else /* typically, unix systems */
#include <sys/time.h>
#define DIFF_T(a,b) \
#endif
#define TICK(t) \
#define TOCK(t) \
#else
#define DEB(x)
#define DDB(x)
#define TICK(x)
#define TOCK(x)
#endif /* TEST */
#if (GF_BITS < 2  && GF_BITS >16)
#error "GF_BITS must be 2 .. 16"
#endif
#if (GF_BITS <= 8)
typedef unsigned char gf;
#else
typedef unsigned short gf;
#endif

#define	GF_SIZE ((1 << GF_BITS) - 1)	/* powers of \alpha */

/*
 * Primitive polynomials - see Lin & Costello, Appendix A,
 * and  Lee & Messerschmitt, p. 453.
 */
static const char *allPp[] = {    /* GF_BITS	polynomial		*/
    NULL,		    /*  0	no code			*/
    NULL,		    /*  1	no code			*/
    "111",		    /*  2	1+x+x^2			*/
    "1101",		    /*  3	1+x+x^3			*/
    "11001",		    /*  4	1+x+x^4			*/
    "101001",		    /*  5	1+x^2+x^5		*/
    "1100001",		    /*  6	1+x+x^6			*/
    "10010001",		    /*  7	1 + x^3 + x^7		*/
    "101110001",	    /*  8	1+x^2+x^3+x^4+x^8	*/
    "1000100001",	    /*  9	1+x^4+x^9		*/
    "10010000001",	    /* 10	1+x^3+x^10		*/
    "101000000001",	    /* 11	1+x^2+x^11		*/
    "1100101000001",	    /* 12	1+x+x^4+x^6+x^12	*/
    "11011000000001",	    /* 13	1+x+x^3+x^4+x^13	*/
    "110000100010001",	    /* 14	1+x+x^6+x^10+x^14	*/
    "1100000000000001",	    /* 15	1+x+x^15		*/
    "11010000000010001"	    /* 16	1+x+x^3+x^12+x^16	*/
};
#define SWAP(a,b,t) {t tmp; tmp=a; a=b; b=tmp;}
#if (GF_BITS <= 8)
#define gf_mul(x,y) gf_mul_table[x][y]
#define USE_GF_MULC register gf * __gf_mulc_
#define GF_MULC0(c) __gf_mulc_ = gf_mul_table[c]
#define GF_ADDMULC(dst, x) dst ^= __gf_mulc_[x]
#else	/* GF_BITS > 8 */
#define init_mul_table()
#define USE_GF_MULC register gf * __gf_mulc_
#define GF_MULC0(c) __gf_mulc_ = &gf_exp[ gf_log[c] ]
#define GF_ADDMULC(dst, x) { if (x) dst ^= __gf_mulc_[ gf_log[x] ] ; }
#endif
my_malloc(int sz, const char *err_string)
{
    void *p = malloc( sz );
    if (p == NULL) {
	fprintf(stderr, "-- malloc failure allocating %s\n", err_string);
	exit(1) ;
    }
    return p ;
}
#define NEW_GF_MATRIX(rows, cols) \
#define addmul(dst, src, c, sz) \
#define UNROLL 16 /* 1, 4, 8, 16 */
#if (UNROLL > 1) /* unrolling by 8/16 is quite effective on the pentium */
#if (UNROLL > 4)
#endif
#if (UNROLL > 8)
#endif
#endif
#ifdef DEBUG
#endif /* debug */
#define FEC_MAGIC	0xFECC0DEC
#define COMP_FEC_MAGIC(fec) \
fec_free(struct fec_parms *p)
{
    if (p==NULL || p->magic != COMP_FEC_MAGIC(p)) {
	fprintf(stderr, "bad parameters to fec_free\n");
	return ;
    }
    free(p->enc_matrix);
    free(p);
}
#if 1 /* this is simply an optimization, not very useful indeed */
#endif
#if (TEST || DEBUG)
#endif /* TEST */
