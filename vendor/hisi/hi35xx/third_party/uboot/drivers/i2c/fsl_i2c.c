#include <common.h>
#include <command.h>
#include <i2c.h>		/* Functional interface */
#include <time.h>
#include <asm/io.h>
#include <asm/fsl_i2c.h>	/* HW definitions */
#include <clk.h>
#include <dm.h>
#include <mapmem.h>
#ifndef CONFIG_I2C_MBB_TIMEOUT
#define CONFIG_I2C_MBB_TIMEOUT	100000
#endif
#ifndef CONFIG_I2C_TIMEOUT
#define CONFIG_I2C_TIMEOUT	100000
#endif
#define I2C_READ_BIT  1
#define I2C_WRITE_BIT 0
#ifndef CONFIG_DM_I2C
#ifdef CONFIG_SYS_FSL_I2C2_OFFSET
#endif
#ifdef CONFIG_SYS_FSL_I2C3_OFFSET
#endif
#ifdef CONFIG_SYS_FSL_I2C4_OFFSET
#endif
#endif
#ifdef __M68K__
#endif
#ifdef __PPC__
#ifdef CONFIG_FSL_I2C_CUSTOM_DFSR
#else
#endif
#ifdef CONFIG_FSL_I2C_CUSTOM_FDR
#else
#endif
#else
#endif
#ifndef CONFIG_DM_I2C
#endif
#ifdef CONFIG_SYS_FSL_ERRATUM_I2C_A004447
#endif
#ifdef CONFIG_SYS_I2C_INIT_BOARD
#endif
#ifndef CONFIG_DM_I2C
#ifdef CONFIG_SYS_FSL_I2C2_OFFSET
#endif
#ifdef CONFIG_SYS_FSL_I2C3_OFFSET
#endif
#ifdef CONFIG_SYS_FSL_I2C4_OFFSET
#endif
#else /* CONFIG_DM_I2C */
#endif /* CONFIG_DM_I2C */
