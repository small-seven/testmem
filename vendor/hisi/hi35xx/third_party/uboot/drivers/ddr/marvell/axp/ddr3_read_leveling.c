#include <common.h>
#include <i2c.h>
#include <spl.h>
#include <asm/io.h>
#include <asm/arch/cpu.h>
#include <asm/arch/soc.h>
#include "ddr3_hw_training.h"
#define DEBUG_RL_C(s, d, l) \
#define DEBUG_RL_FULL_C(s, d, l) \
#ifdef MV_DEBUG_RL
#define DEBUG_RL_S(s) \
#define DEBUG_RL_D(d, l) \
#else
#define DEBUG_RL_S(s)
#define DEBUG_RL_D(d, l)
#endif
#ifdef MV_DEBUG_RL_FULL
#define DEBUG_RL_FULL_S(s)		puts(s)
#define DEBUG_RL_FULL_D(d, l)		printf("%x", d)
#else
#define DEBUG_RL_FULL_S(s)
#define DEBUG_RL_FULL_D(d, l)
#endif
#ifdef RL_MODE
#else
#endif
#ifdef MV_DEBUG_RL
#endif
#ifdef MV_DEBUG_RL
#endif
#ifdef RL_MODE
#endif
#ifdef RL_MODE
#else
#endif
#ifdef RL_MODE
#endif
#ifdef RL_MODE
#else
#ifdef RL_WINDOW_WA
#else
#endif
#ifdef RL_WINDOW_WA
#else
#endif
#ifdef RL_WINDOW_WA
#else
#endif
#endif
