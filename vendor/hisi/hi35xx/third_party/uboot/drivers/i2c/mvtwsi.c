#include <common.h>
#include <i2c.h>
#include <linux/errno.h>
#include <asm/io.h>
#include <linux/bitops.h>
#include <linux/compat.h>
#ifdef CONFIG_DM_I2C
#include <dm.h>
#endif
#ifndef CONFIG_DM_I2C
#if defined(CONFIG_ORION5X)
#include <asm/arch/orion5x.h>
#elif (defined(CONFIG_KIRKWOOD) || defined(CONFIG_ARCH_MVEBU))
#include <asm/arch/soc.h>
#elif defined(CONFIG_ARCH_SUNXI)
#include <asm/arch/i2c.h>
#else
#error Driver mvtwsi not supported by SoC or board
#endif
#endif /* CONFIG_DM_I2C */
#if defined(CONFIG_DM_I2C) && defined(CONFIG_ARCH_SUNXI)
#include <asm/arch/i2c.h>
#endif
#ifdef CONFIG_ARCH_SUNXI
#else
#endif
#ifdef CONFIG_DM_I2C
#endif /* CONFIG_DM_I2C */
#ifdef CONFIG_SUNXI_GEN_SUN6I
#define	MVTWSI_CONTROL_CLEAR_IFLG	0x00000008
#else
#define	MVTWSI_CONTROL_CLEAR_IFLG	0x00000000
#endif
#ifndef CONFIG_DM_I2C
#ifdef CONFIG_I2C_MVTWSI_BASE0
#endif
#ifdef CONFIG_I2C_MVTWSI_BASE1
#endif
#ifdef CONFIG_I2C_MVTWSI_BASE2
#endif
#ifdef CONFIG_I2C_MVTWSI_BASE3
#endif
#ifdef CONFIG_I2C_MVTWSI_BASE4
#endif
#ifdef CONFIG_I2C_MVTWSI_BASE5
#endif
#endif
#ifdef CONFIG_ARCH_SUNXI
#else
#endif
#ifdef CONFIG_DM_I2C
#else
#endif
#ifdef CONFIG_DM_I2C
#else
#endif
#ifndef CONFIG_DM_I2C
#ifdef CONFIG_I2C_MVTWSI_BASE0
#endif
#ifdef CONFIG_I2C_MVTWSI_BASE1
#endif
#ifdef CONFIG_I2C_MVTWSI_BASE2
#endif
#ifdef CONFIG_I2C_MVTWSI_BASE3
#endif
#ifdef CONFIG_I2C_MVTWSI_BASE4
#endif
#ifdef CONFIG_I2C_MVTWSI_BASE5
#endif
#else /* CONFIG_DM_I2C */
#endif /* CONFIG_DM_I2C */
