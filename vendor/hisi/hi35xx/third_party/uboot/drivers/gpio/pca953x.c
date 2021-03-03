#include <common.h>
#include <i2c.h>
#include <pca953x.h>
#ifndef CONFIG_SYS_I2C_PCA953X_ADDR
#define CONFIG_SYS_I2C_PCA953X_ADDR	(~0)
#endif
#ifdef CONFIG_SYS_I2C_PCA953X_WIDTH
#else
#endif
#if defined(CONFIG_CMD_PCA953X) && !defined(CONFIG_SPL_BUILD)
#endif /* CONFIG_CMD_PCA953X */
