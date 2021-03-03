#include <common.h>
#include <dm.h>
#include <errno.h>
#include <asm/io.h>
#include <asm/arch/hi3660.h>
#include <asm/armv8/mmu.h>
#include <asm/psci.h>
#include <linux/arm-smccc.h>
#include <linux/psci.h>
#define PMIC_REG_TO_BUS_ADDR(x) (x << 2)
#define PMIC_VSEL_MASK		0x7
#if !CONFIG_IS_ENABLED(OF_CONTROL)
#include <dm/platform_data/serial_pl01x.h>
#endif
