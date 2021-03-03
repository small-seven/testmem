#include <common.h>
#include <asm/io.h>
#include <asm/arch/cpu.h>
#include <asm/arch/soc.h>
#include <asm/arch/mpp.h>
#define MPP_CTRL(i)	(KW_MPP_BASE + (i* 4))
#define MPP_NR_REGS	(1 + MPP_MAX/8)
