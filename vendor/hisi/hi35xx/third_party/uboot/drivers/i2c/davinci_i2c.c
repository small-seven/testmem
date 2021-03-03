#include <common.h>
#include <i2c.h>
#include <dm.h>
#include <asm/arch/hardware.h>
#include <asm/arch/i2c_defs.h>
#include <asm/io.h>
#include "davinci_i2c.h"
#ifdef CONFIG_DM_I2C
#endif
#define CHECK_NACK() \
#ifndef CONFIG_DM_I2C
#if CONFIG_SYS_I2C_BUS_MAX >= 3
#endif
#if CONFIG_SYS_I2C_BUS_MAX >= 2
#endif
#if CONFIG_SYS_I2C_BUS_MAX >= 2
#endif
#if CONFIG_SYS_I2C_BUS_MAX >= 3
#endif
#else /* CONFIG_DM_I2C */
#endif /* CONFIG_DM_I2C */
