#include <common.h>
#include <cpu.h>
#include <dm.h>
#include <pci.h>
#include <asm/cpu.h>
#include <asm/cpu_x86.h>
#include <asm/io.h>
#include <asm/lapic.h>
#include <asm/msr.h>
#include <asm/turbo.h>
#define BYT_PRV_CLK			0x800
#define BYT_PRV_CLK_EN			(1 << 0)
#define BYT_PRV_CLK_M_VAL_SHIFT		1
#define BYT_PRV_CLK_N_VAL_SHIFT		16
#define BYT_PRV_CLK_UPDATE		(1 << 31)
