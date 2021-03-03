#include <clk.h>
#include <common.h>
#include <dm.h>
#include <i2c.h>
#include <pci.h>
#include <reset.h>
#include <asm/io.h>
#include "designware_i2c.h"
#ifdef CONFIG_X86
#endif
#if CONFIG_IS_ENABLED(CLK)
#endif
#ifdef CONFIG_SYS_I2C_DW_ENABLE_STATUS_UNSUPPORTED
#else
#endif
#ifndef CONFIG_X86 /* No High-speed for BayTrail yet */
#endif
#ifdef CONFIG_SYS_I2C_EEPROM_ADDR_OVERFLOW
#endif
#ifdef CONFIG_SYS_I2C_EEPROM_ADDR_OVERFLOW
#endif
#ifndef CONFIG_DM_I2C
#endif
#ifndef CONFIG_DM_I2C
#if CONFIG_SYS_I2C_BUS_MAX >= 4
#endif
#if CONFIG_SYS_I2C_BUS_MAX >= 3
#endif
#if CONFIG_SYS_I2C_BUS_MAX >= 2
#endif
#if CONFIG_SYS_I2C_BUS_MAX >= 2
#endif
#if CONFIG_SYS_I2C_BUS_MAX >= 3
#endif
#if CONFIG_SYS_I2C_BUS_MAX >= 4
#endif
#else /* CONFIG_DM_I2C */
#if CONFIG_IS_ENABLED(CLK)
#else
#endif
#ifdef CONFIG_DM_PCI
#ifdef CONFIG_X86
#endif
#endif
#if CONFIG_IS_ENABLED(CLK)
#endif
static int designware_i2c_remove(struct udevice *dev)
{
	struct dw_i2c *priv = dev_get_priv(dev);

#if CONFIG_IS_ENABLED(CLK)
	clk_disable(&priv->clk);
	clk_free(&priv->clk);
#endif

	return reset_release_bulk(&priv->resets);
}
#ifdef CONFIG_X86
#endif
#endif /* CONFIG_DM_I2C */
