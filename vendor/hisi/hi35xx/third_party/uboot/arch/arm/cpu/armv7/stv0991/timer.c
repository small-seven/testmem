#include <common.h>
#include <time.h>
#include <asm/io.h>
#include <asm/arch-stv0991/hardware.h>
#include <asm/arch-stv0991/stv0991_cgu.h>
#include <asm/arch-stv0991/stv0991_gpt.h>
#define READ_TIMER()	(readl(&gpt1_regs_ptr->cnt) & GPT_FREE_RUNNING)
#define GPT_RESOLUTION	(CONFIG_STV0991_HZ_CLOCK / CONFIG_STV0991_HZ)
#define timestamp gd->arch.tbl
#define lastdec gd->arch.lastinc
