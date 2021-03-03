#ifndef CHAR_BIT
#define CHAR_BIT 8
#endif
#define BN_MP_INVMOD_C
#define BN_S_MP_EXPTMOD_C /* Note: #undef in tommath_superclass.h; this would
#define BN_S_MP_MUL_DIGS_C
#define BN_MP_INVMOD_SLOW_C
#define BN_S_MP_SQR_C
#define BN_S_MP_MUL_HIGH_DIGS_C /* Note: #undef in tommath_superclass.h; this
#ifdef LTM_FAST
#define BN_MP_MUL_D_C
#define BN_MP_EXPTMOD_FAST_C
#define BN_MP_MONTGOMERY_SETUP_C
#define BN_FAST_MP_MONTGOMERY_REDUCE_C
#define BN_MP_MONTGOMERY_CALC_NORMALIZATION_C
#define BN_MP_MUL_2_C
#define BN_FAST_S_MP_SQR_C
#define BN_FAST_S_MP_MUL_DIGS_C
#else /* LTM_FAST */
#define BN_MP_DIV_SMALL
#define BN_MP_INIT_MULTI_C
#define BN_MP_CLEAR_MULTI_C
#define BN_MP_ABS_C
#endif /* LTM_FAST */
#define LTM_NO_NEG_EXP
#ifndef MIN
#endif
#ifndef MAX
#endif
#define  OPT_CAST(x)
#ifdef __x86_64__
typedef unsigned long mp_digit;
typedef unsigned long mp_word __attribute__((mode(TI)));

#define DIGIT_BIT 60
#define MP_64BIT
#else
typedef unsigned long mp_digit;
typedef u64 mp_word;

#define DIGIT_BIT          28
#define MP_28BIT
#endif


#define XMALLOC  os_malloc
#define XFREE    os_free
#define XREALLOC os_realloc


#define MP_MASK          ((((mp_digit)1)<<((mp_digit)DIGIT_BIT))-((mp_digit)1))

#define MP_LT        -1   /* less than */
#define MP_EQ         0   /* equal to */
#define MP_GT         1   /* greater than */

#define MP_ZPOS       0   /* positive integer */
#define MP_NEG        1   /* negative */

#define MP_OKAY       0   /* ok result */
#define MP_MEM        -2  /* out of mem */
#define MP_VAL        -3  /* invalid input */

#define MP_YES        1   /* yes response */
#define MP_NO         0   /* no response */

typedef int           mp_err;

/* define this to use lower memory usage routines (exptmods mostly) */
#define MP_LOW_MEM

/* default precision */
#ifndef MP_PREC
   #ifndef MP_LOW_MEM
      #define MP_PREC                 32     /* default digits of precision */
   #else
      #define MP_PREC                 8      /* default digits of precision */
   #endif
#endif

/* size of comba arrays, should be at least 2 * 2**(BITS_PER_WORD - BITS_PER_DIGIT*2) */
#define MP_WARRAY               (1 << (sizeof(mp_word) * CHAR_BIT - 2 * DIGIT_BIT + 1))

/* the infamous mp_int structure */
typedef struct  {
    int used, alloc, sign;
    mp_digit *dp;
} mp_int;
#define mp_iszero(a) (((a)->used == 0) ? MP_YES : MP_NO)
#define mp_iseven(a) (((a)->used > 0 && (((a)->dp[0] & 1) == 0)) ? MP_YES : MP_NO)
#define mp_isodd(a)  (((a)->used > 0 && (((a)->dp[0] & 1) == 1)) ? MP_YES : MP_NO)
#define s_mp_mul(a, b, c) s_mp_mul_digs(a, b, c, (a)->used + (b)->used + 1)
#ifdef BN_FAST_S_MP_MUL_DIGS_C
#endif
#ifdef BN_MP_INIT_MULTI_C
#endif
#ifdef BN_MP_CLEAR_MULTI_C
#endif
#ifndef LTM_NO_NEG_EXP
#endif /* LTM_NO_NEG_EXP */
#ifdef BN_MP_ABS_C
#endif
#ifdef BN_MP_EXPTMOD_FAST_C
#endif /* BN_MP_EXPTMOD_FAST_C */
#ifdef BN_FAST_S_MP_SQR_C
#endif /* BN_FAST_S_MP_SQR_C */
#ifdef BN_MP_MUL_D_C
#endif /* BN_MP_MUL_D_C */
#ifdef BN_MP_TOOM_MUL_C
#endif
#ifdef BN_MP_KARATSUBA_MUL_C
#endif
#ifdef BN_FAST_S_MP_MUL_DIGS_C
#endif
#ifdef BN_S_MP_MUL_DIGS_C
#else
#error mp_mul could fail
#endif
#ifdef LTM_NO_NEG_EXP
#else /* LTM_NO_NEG_EXP */
#ifdef BN_MP_INVMOD_C
#else
#error mp_exptmod would always fail
#endif
#endif /* LTM_NO_NEG_EXP */
#if defined(BN_MP_REDUCE_IS_2K_L_C) && defined(BN_MP_REDUCE_2K_L_C) && defined(BN_S_MP_EXPTMOD_C)
#endif
#ifdef BN_MP_DR_IS_MODULUS_C
#else
#endif
#ifdef BN_MP_REDUCE_IS_2K_C
#endif
#ifdef BN_MP_EXPTMOD_FAST_C
#endif
#ifdef BN_S_MP_EXPTMOD_C
#else
#error mp_exptmod could fail
#endif
#ifdef BN_MP_EXPTMOD_FAST_C
#endif
#ifndef LTM_NO_NEG_EXP
#ifdef BN_FAST_MP_INVMOD_C
#endif
#ifdef BN_MP_INVMOD_SLOW_C
#endif
#ifndef BN_FAST_MP_INVMOD_C
#ifndef BN_MP_INVMOD_SLOW_C
#error mp_invmod would always fail
#endif
#endif
#endif /* LTM_NO_NEG_EXP */
#ifndef LTM_NO_NEG_EXP
#endif /* LTM_NO_NEG_EXP */
#ifndef MP_8BIT
#else
#endif
#ifndef MP_8BIT
#else
#endif
#ifdef BN_MP_ABS_C
#endif
#ifndef LTM_NO_NEG_EXP
#endif /* LTM_NO_NEG_EXP */
#ifdef BN_MP_INIT_MULTI_C
#endif
#ifdef BN_MP_CLEAR_MULTI_C
#endif
#ifdef BN_MP_DIV_SMALL
#else
#endif
#ifdef MP_LOW_MEM
#else
#endif
#ifdef MP_LOW_MEM
#endif
#ifdef BN_MP_TOOM_SQR_C
#endif
#ifdef BN_MP_KARATSUBA_SQR_C
#endif
#ifdef BN_FAST_S_MP_SQR_C
#endif
#ifdef BN_S_MP_SQR_C
#else
#error mp_sqr could fail
#endif
#ifdef BN_S_MP_MUL_HIGH_DIGS_C
#elif defined(BN_FAST_S_MP_MUL_HIGH_DIGS_C)
#else
#error mp_reduce would always fail
#endif
#ifdef BN_FAST_S_MP_MUL_DIGS_C
#endif
#ifdef BN_FAST_S_MP_MUL_DIGS_C
#endif /* BN_FAST_S_MP_MUL_DIGS_C */
#ifdef BN_FAST_S_MP_MUL_HIGH_DIGS_C
#endif
#ifdef BN_MP_MONTGOMERY_SETUP_C
#if !defined(MP_8BIT)
#endif
#if defined(MP_64BIT) || !(defined(MP_8BIT) || defined(MP_16BIT))
#endif
#ifdef MP_64BIT
#endif
#endif
#ifdef BN_FAST_MP_MONTGOMERY_REDUCE_C
#endif
#ifdef BN_MP_MUL_2_C
#endif
#ifdef BN_MP_MONTGOMERY_CALC_NORMALIZATION_C
#endif
#ifdef BN_MP_EXPTMOD_FAST_C
#ifdef MP_LOW_MEM
#endif
#ifdef BN_MP_MONTGOMERY_SETUP_C
#else
#endif
#ifdef BN_FAST_MP_MONTGOMERY_REDUCE_C
#endif
#ifdef BN_MP_MONTGOMERY_REDUCE_C
#else
#endif
#if defined(BN_MP_DR_SETUP_C) && defined(BN_MP_DR_REDUCE_C)
#else
#endif
#if defined(BN_MP_REDUCE_2K_SETUP_C) && defined(BN_MP_REDUCE_2K_C)
#else
#endif
#ifdef BN_MP_MONTGOMERY_CALC_NORMALIZATION_C
#else
#endif
#endif
#ifdef BN_FAST_S_MP_SQR_C
#endif
#ifdef BN_MP_MUL_D_C
#endif
