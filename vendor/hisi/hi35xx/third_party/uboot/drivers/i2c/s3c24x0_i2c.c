#include <common.h>
#include <errno.h>
#include <dm.h>
#include <fdtdec.h>
#if (defined CONFIG_EXYNOS4 || defined CONFIG_EXYNOS5)
#include <asm/arch/clk.h>
#include <asm/arch/cpu.h>
#include <asm/arch/pinmux.h>
#else
#include <asm/arch/s3c24x0_cpu.h>
#endif
#include <asm/io.h>
#include <i2c.h>
#include "s3c24x0_i2c.h"
#ifndef CONFIG_SYS_I2C_S3C24X0_SLAVE
#define SYS_I2C_S3C24X0_SLAVE_ADDR	0
#else
#define SYS_I2C_S3C24X0_SLAVE_ADDR	CONFIG_SYS_I2C_S3C24X0_SLAVE
#endif
#if (defined CONFIG_EXYNOS4 || defined CONFIG_EXYNOS5)
#else
#endif
