#include <common.h>
#include <i2c.h>
#include <spl.h>
#include <asm/io.h>
#include <asm/arch/cpu.h>
#include <asm/arch/soc.h>
#include "ddr3_hw_training.h"
#define DEBUG_PBS_FULL_C(s, d, l) \
#define DEBUG_PBS_C(s, d, l) \
#ifdef MV_DEBUG_PBS
#define DEBUG_PBS_S(s)			puts(s)
#define DEBUG_PBS_D(d, l)		printf("%x", d)
#else
#define DEBUG_PBS_S(s)
#define DEBUG_PBS_D(d, l)
#endif
#ifdef MV_DEBUG_FULL_PBS
#define DEBUG_PBS_FULL_S(s)		puts(s)
#define DEBUG_PBS_FULL_D(d, l)		printf("%x", d)
#else
#define DEBUG_PBS_FULL_S(s)
#define DEBUG_PBS_FULL_D(d, l)
#endif
#if defined(MV88F78X60) || defined(MV88F672X)
#if defined(MV88F672X)
#else
#endif
#if defined(MV88F672X)
#endif
#if defined(MV88F78X60)
#endif
#if defined(MV88F672X)
#endif
#if defined(MV88F78X60)
#endif
#if defined(MV88F672X)
#endif
#if defined(MV88F78X60)
#endif
#endif
