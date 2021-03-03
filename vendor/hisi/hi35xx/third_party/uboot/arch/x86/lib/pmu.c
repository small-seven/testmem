#include <common.h>
#include <dm.h>
#include <regmap.h>
#include <syscon.h>
#include <asm/cpu.h>
#include <asm/pmu.h>
#include <linux/errno.h>
#include <linux/io.h>
#define PMU_REGS_STS_BUSY		(1 << 8)
