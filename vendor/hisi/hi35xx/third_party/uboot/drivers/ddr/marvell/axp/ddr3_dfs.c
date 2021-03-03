#include <common.h>
#include <i2c.h>
#include <spl.h>
#include <asm/io.h>
#include <asm/arch/cpu.h>
#include <asm/arch/soc.h>
#include "ddr3_hw_training.h"
#define DEBUG_DFS_C(s, d, l) \
#define DEBUG_DFS_FULL_C(s, d, l) \
#ifdef MV_DEBUG_DFS
#define DEBUG_DFS_S(s)			puts(s)
#define DEBUG_DFS_D(d, l)		printf("%x", d)
#else
#define DEBUG_DFS_S(s)
#define DEBUG_DFS_D(d, l)
#endif
#ifdef MV_DEBUG_DFS_FULL
#define DEBUG_DFS_FULL_S(s)		puts(s)
#define DEBUG_DFS_FULL_D(d, l)		printf("%x", d)
#else
#define DEBUG_DFS_FULL_S(s)
#define DEBUG_DFS_FULL_D(d, l)
#endif
#if defined(MV88F672X)
#else
#endif
#ifdef MV_DEBUG_DFS
#else
#endif
#if defined(MV88F672X)
#else
#endif
#if defined(MV88F78X60) || defined(MV88F672X)
#if defined(MV88F672X)
#endif
#if defined(MV88F672X)
#else
#endif
#else
#endif
#if defined(MV88F78X60) || defined(MV88F672X)
#if defined(MV88F672X)
#endif
#if defined(MV88F672X)
#else
#endif
#else
#endif
