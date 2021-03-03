#include <common.h>
#include <i2c.h>
#include <spl.h>
#include <asm/io.h>
#include <asm/arch/cpu.h>
#include <asm/arch/soc.h>
#include "ddr3_hw_training.h"
#define DEBUG_WL_C(s, d, l) \
#define DEBUG_WL_FULL_C(s, d, l) \
#ifdef MV_DEBUG_WL
#define DEBUG_WL_S(s)			puts(s)
#define DEBUG_WL_D(d, l)		printf("%x", d)
#define DEBUG_RL_S(s) \
#define DEBUG_RL_D(d, l) \
#else
#define DEBUG_WL_S(s)
#define DEBUG_WL_D(d, l)
#endif
#ifdef MV_DEBUG_WL_FULL
#define DEBUG_WL_FULL_S(s)		puts(s)
#define DEBUG_WL_FULL_D(d, l)		printf("%x", d)
#else
#define DEBUG_WL_FULL_S(s)
#define DEBUG_WL_FULL_D(d, l)
#endif
#define WL_SUP_EXPECTED_DATA		0x21
#define WL_SUP_READ_DRAM_ENTRY		0x8
#ifdef MV88F67XX
#endif
#ifdef MV88F67XX
#endif
#ifdef MV_DEBUG_WL
#endif
#ifdef MV88F67XX
#endif
#ifdef MV88F67XX
#endif
#ifdef MV_DEBUG_WL
#endif
#ifdef MV88F67XX
#endif
#ifdef MV88F67XX
#endif
#ifdef MV88F67XX
#endif
#if !defined(MV88F672X)
#ifdef MV88F67XX
#endif
#ifdef MV88F67XX
#endif
#endif
