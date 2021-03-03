#include <common.h>
#include <i2c.h>
#include <asm/arch/imx-regs.h>
#include <asm/arch/iomux.h>
#include <asm/arch/mx6-pins.h>
#include <asm/gpio.h>
#include <asm/mach-imx/iomux-v3.h>
#include "pf0100_otp.inc"
#include "pf0100.h"
#define WARNBAR "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n"
#	define PMIC_PROG_VOLTAGE IMX_GPIO_NR(2, 3)
#ifdef DEBUG
#endif /* DEBUG */
#ifndef CONFIG_SPL_BUILD
#endif /* CONFIG_SPL_BUILD */
