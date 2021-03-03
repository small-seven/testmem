#include <common.h>
#include <malloc.h>
#include <asm/arch/clock.h>
#include <asm/arch/imx-regs.h>
#include <linux/errno.h>
#include <asm/gpio.h>
#include <asm/mach-imx/mxc_i2c.h>
#include <watchdog.h>
#ifdef I2C3_BASE_ADDR
#endif
#ifdef I2C4_BASE_ADDR
#endif
#ifndef CONFIG_DM_I2C
#endif
