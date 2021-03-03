#include <common.h>
#include <dm.h>
#include <i2c.h>
#include <asm/io.h>
#include "mv_i2c.h"
#ifdef CONFIG_ARMADA_3700
#else
#endif
#ifndef CONFIG_DM_I2C
#ifdef CONFIG_SYS_I2C_INIT_BOARD
#endif
#ifdef CONFIG_I2C_MULTI_BUS
#endif
#ifdef CONFIG_I2C_MULTI_BUS
#else
#endif
#else /* CONFIG_DM_I2C */
#endif /* CONFIG_DM_I2C */
