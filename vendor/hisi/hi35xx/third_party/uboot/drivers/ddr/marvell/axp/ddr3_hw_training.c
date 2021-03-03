#include <common.h>
#include <i2c.h>
#include <spl.h>
#include <asm/io.h>
#include <asm/arch/cpu.h>
#include <asm/arch/soc.h>
#include "ddr3_init.h"
#include "ddr3_hw_training.h"
#include "xor.h"
#ifdef MV88F78X60
#include "ddr3_patterns_64bit.h"
#else
#include "ddr3_patterns_16bit.h"
#if defined(MV88F672X)
#include "ddr3_patterns_16bit.h"
#endif
#endif
#define DEBUG_MAIN_C(s, d, l) \
#define DEBUG_MAIN_FULL_C(s, d, l) \
#ifdef MV_DEBUG_MAIN
#define DEBUG_MAIN_S(s)			puts(s)
#define DEBUG_MAIN_D(d, l)		printf("%x", d)
#else
#define DEBUG_MAIN_S(s)
#define DEBUG_MAIN_D(d, l)
#endif
#ifdef MV_DEBUG_MAIN_FULL
#define DEBUG_MAIN_FULL_S(s)		puts(s)
#define DEBUG_MAIN_FULL_D(d, l)		printf("%x", d)
#else
#define DEBUG_MAIN_FULL_S(s)
#define DEBUG_MAIN_FULL_D(d, l)
#endif
#ifdef MV_DEBUG_SUSPEND_RESUME
#define DEBUG_SUSPEND_RESUME_S(s)	puts(s)
#define DEBUG_SUSPEND_RESUME_D(d, l)	printf("%x", d)
#else
#define DEBUG_SUSPEND_RESUME_S(s)
#define DEBUG_SUSPEND_RESUME_D(d, l)
#endif
#ifdef MV88F67XX
#endif
#ifdef MV88F67XX
#else
#endif
#ifdef MV88F67XX
#else
#endif
#if !defined(MV88F67XX)
#if defined(MV88F78X60)
#else
#endif
#endif
#ifdef MV88F67XX
#else
#endif
#if defined(MV88F78X60)
#endif
#ifdef MV88F67XX
#else
#endif
#if !defined(MV88F67XX)
#if defined(MV88F78X60) || defined(MV88F672X)
#endif
#endif
#if defined(MV88F78X60)
#endif
#if defined(MV88F78X60) || defined(MV88F672X)
#endif
#if defined(MV88F67XX)
#else
#endif
#if !defined(MV88F67XX)
#endif
