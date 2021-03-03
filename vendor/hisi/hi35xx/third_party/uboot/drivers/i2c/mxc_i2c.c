#include <common.h>
#include <asm/arch/clock.h>
#include <asm/arch/imx-regs.h>
#include <linux/errno.h>
#include <asm/mach-imx/mxc_i2c.h>
#include <asm/io.h>
#include <i2c.h>
#include <watchdog.h>
#include <dm.h>
#include <dm/pinctrl.h>
#include <fdtdec.h>
#define I2C_QUIRK_FLAG		(1 << 0)
#define IMX_I2C_REGSHIFT	2
#define VF610_I2C_REGSHIFT	0
#define I2C_EARLY_INIT_INDEX		0
#ifdef CONFIG_SYS_I2C_IFDR_DIV
#define I2C_IFDR_DIV_CONSERVATIVE	CONFIG_SYS_I2C_IFDR_DIV
#else
#define I2C_IFDR_DIV_CONSERVATIVE	0x7e
#endif
#define IADR	0
#define IFDR	1
#define I2CR	2
#define I2SR	3
#define I2DR	4
#define I2CR_IIEN	(1 << 6)
#define I2CR_MSTA	(1 << 5)
#define I2CR_MTX	(1 << 4)
#define I2CR_TX_NO_AK	(1 << 3)
#define I2CR_RSTA	(1 << 2)
#define I2SR_ICF	(1 << 7)
#define I2SR_IBB	(1 << 5)
#define I2SR_IAL	(1 << 4)
#define I2SR_IIF	(1 << 1)
#define I2SR_RX_NO_AK	(1 << 0)
#ifdef I2C_QUIRK_REG
#define I2CR_IEN	(0 << 7)
#define I2CR_IDIS	(1 << 7)
#define I2SR_IIF_CLEAR	(1 << 1)
#else
#define I2CR_IEN	(1 << 7)
#define I2CR_IDIS	(0 << 7)
#define I2SR_IIF_CLEAR	(0 << 1)
#endif
#ifdef I2C_QUIRK_REG
#else
#endif
#ifndef CONFIG_SYS_MXC_I2C1_SPEED
#define CONFIG_SYS_MXC_I2C1_SPEED 100000
#endif
#ifndef CONFIG_SYS_MXC_I2C2_SPEED
#define CONFIG_SYS_MXC_I2C2_SPEED 100000
#endif
#ifndef CONFIG_SYS_MXC_I2C3_SPEED
#define CONFIG_SYS_MXC_I2C3_SPEED 100000
#endif
#ifndef CONFIG_SYS_MXC_I2C4_SPEED
#define CONFIG_SYS_MXC_I2C4_SPEED 100000
#endif
#ifndef CONFIG_SYS_MXC_I2C1_SLAVE
#define CONFIG_SYS_MXC_I2C1_SLAVE 0
#endif
#ifndef CONFIG_SYS_MXC_I2C2_SLAVE
#define CONFIG_SYS_MXC_I2C2_SLAVE 0
#endif
#ifndef CONFIG_SYS_MXC_I2C3_SLAVE
#define CONFIG_SYS_MXC_I2C3_SLAVE 0
#endif
#ifndef CONFIG_SYS_MXC_I2C4_SLAVE
#define CONFIG_SYS_MXC_I2C4_SLAVE 0
#endif
#if defined(CONFIG_MX31)
#endif
#if CONFIG_IS_ENABLED(CLK)
#else
#endif
#define ST_BUS_IDLE (0 | (I2SR_IBB << 8))
#define ST_BUS_BUSY (I2SR_IBB | (I2SR_IBB << 8))
#define ST_IIF (I2SR_IIF | (I2SR_IIF << 8))
#ifndef CONFIG_DM_I2C
#else
#endif
#ifndef CONFIG_DM_I2C
#if !defined(I2C2_BASE_ADDR)
#define I2C2_BASE_ADDR	0
#endif
#if !defined(I2C3_BASE_ADDR)
#define I2C3_BASE_ADDR	0
#endif
#if !defined(I2C4_BASE_ADDR)
#define I2C4_BASE_ADDR	0
#endif
#if !defined(I2C5_BASE_ADDR)
#define I2C5_BASE_ADDR 0
#endif
#if !defined(I2C6_BASE_ADDR)
#define I2C6_BASE_ADDR 0
#endif
#if !defined(I2C7_BASE_ADDR)
#define I2C7_BASE_ADDR 0
#endif
#if !defined(I2C8_BASE_ADDR)
#define I2C8_BASE_ADDR 0
#endif
#if defined(CONFIG_ARCH_LS1021A) || defined(CONFIG_VF610) || \
#else
#endif
#ifdef CONFIG_SYS_I2C_MXC_I2C1
#endif
#ifdef CONFIG_SYS_I2C_MXC_I2C2
#endif
#ifdef CONFIG_SYS_I2C_MXC_I2C3
#endif
#ifdef CONFIG_SYS_I2C_MXC_I2C4
#endif
#ifdef CONFIG_SYS_I2C_MXC_I2C5
#endif
#ifdef CONFIG_SYS_I2C_MXC_I2C6
#endif
#ifdef CONFIG_SYS_I2C_MXC_I2C7
#endif
#ifdef CONFIG_SYS_I2C_MXC_I2C8
#endif
#else
#if CONFIG_IS_ENABLED(CLK)
#else
#endif
#endif
