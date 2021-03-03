#include <common.h>
#include <i2c.h>
#include <spl.h>
#include <asm/io.h>
#include <asm/arch/cpu.h>
#include <asm/arch/soc.h>
#include "ddr3_hw_training.h"
#include "xor.h"
#include "xor_regs.h"
#if defined(MV88F78X60)
#endif
#if defined(MV88F78X60) || defined(MV88F672X)
#endif
#define XOR_TIMEOUT 0x8000000
#define XOR_CAUSE_DONE_MASK(chan)	((0x1 | 0x2) << (chan * 16))
#ifdef MV_DEBUG_DQS
#endif
#if !defined(MV88F67XX)
#endif
#if defined(MV88F78X60) || defined(MV88F672X)
#elif defined(MV88F67XX)
#endif
#if defined(MV88F78X60) || defined(MV88F672X)
#if defined(MV88F672X)
#endif
#if defined(MV88F78X60)
#endif
#endif
#if defined(MV88F672X)
#else
#ifdef MV88F67XX
#endif
#endif
