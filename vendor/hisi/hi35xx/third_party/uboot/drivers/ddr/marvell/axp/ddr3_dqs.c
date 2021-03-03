#include <common.h>
#include <i2c.h>
#include <spl.h>
#include <asm/io.h>
#include <asm/arch/cpu.h>
#include <asm/arch/soc.h>
#include "ddr3_hw_training.h"
#define DEBUG_DQS_C(s, d, l) \
#define DEBUG_DQS_FULL_C(s, d, l) \
#define DEBUG_DQS_RESULTS_C(s, d, l) \
#define DEBUG_PER_DQ_C(s, d, l) \
#define DEBUG_DQS_RESULTS_S(s) \
#define DEBUG_DQS_RESULTS_D(d, l) \
#define DEBUG_PER_DQ_S(s) \
#define DEBUG_PER_DQ_D(d, l) \
#define DEBUG_PER_DQ_DD(d, l) \
#ifdef MV_DEBUG_DQS
#define DEBUG_DQS_S(s)			puts(s)
#define DEBUG_DQS_D(d, l)		printf("%x", d)
#else
#define DEBUG_DQS_S(s)
#define DEBUG_DQS_D(d, l)
#endif
#ifdef MV_DEBUG_DQS_FULL
#define DEBUG_DQS_FULL_S(s)		puts(s)
#define DEBUG_DQS_FULL_D(d, l)		printf("%x", d)
#else
#define DEBUG_DQS_FULL_S(s)
#define DEBUG_DQS_FULL_D(d, l)
#endif
#ifdef MV88F78X60
#else
#if defined(MV88F672X)
#endif
#endif
#if defined(MV88F672X)
#endif
#if defined(MV88F78X60)
#endif
#if defined(MV88F78X60)
#else
#endif
#if defined(MV88F78X60)
#endif
#if defined(MV88F78X60)
#endif
#if defined(MV88F78X60)
#endif
#if defined(MV88F78X60)
#endif
