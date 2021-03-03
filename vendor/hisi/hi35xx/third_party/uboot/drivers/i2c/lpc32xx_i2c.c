#include <common.h>
#include <asm/io.h>
#include <i2c.h>
#include <linux/errno.h>
#include <asm/arch/clk.h>
#include <asm/arch/i2c.h>
#include <dm.h>
#include <mapmem.h>
#if !defined(CONFIG_SYS_I2C_LPC32XX_SPEED)
#define CONFIG_SYS_I2C_LPC32XX_SPEED 350000
#endif
#if !defined(CONFIG_SYS_I2C_LPC32XX_SLAVE)
#define CONFIG_SYS_I2C_LPC32XX_SLAVE 0
#endif
#define LPC32XX_I2C_TX_START		0x00000100
#define LPC32XX_I2C_TX_STOP		0x00000200
#define LPC32XX_I2C_SOFT_RESET		0x00000100
#define LPC32XX_I2C_STAT_TFF		0x00000400
#define LPC32XX_I2C_STAT_RFE		0x00000200
#define LPC32XX_I2C_STAT_DRMI		0x00000008
#define LPC32XX_I2C_STAT_NAI		0x00000004
#define LPC32XX_I2C_STAT_TDI		0x00000001
#ifndef CONFIG_DM_I2C
#endif
#ifndef CONFIG_DM_I2C
#else /* CONFIG_DM_I2C */
#endif /* CONFIG_DM_I2C */
