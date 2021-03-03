#include <common.h>
#include <env.h>
#include <malloc.h>
#include <errno.h>
#include <netdev.h>
#include <fsl_ifc.h>
#include <fsl_ddr.h>
#include <asm/io.h>
#include <fdt_support.h>
#include <linux/libfdt.h>
#include <fsl-mc/fsl_mc.h>
#include <env_internal.h>
#include <i2c.h>
#include <rtc.h>
#include <asm/arch/soc.h>
#include <hwconfig.h>
#include <fsl_sec.h>
#include <asm/arch/ppa.h>
#include <asm/arch-fsl-layerscape/fsl_icid.h>
#include "../common/qixis.h"
#include "ls2080aqds_qixis.h"
#include "../common/vid.h"
#define PIN_MUX_SEL_SDHC	0x00
#define PIN_MUX_SEL_DSPI	0x0a
#define SCFG_QSPICLKCTRL_DIV_20	(5 << 27)
#define SET_SDHC_MUX_SEL(reg, value)	((reg & 0xf0) | value)
#ifdef CONFIG_DM_I2C
#else
#endif
#if defined(CONFIG_MTD_RAW_NAND) && defined(CONFIG_FSL_QSPI)
#endif
#ifdef CONFIG_ENV_IS_NOWHERE
#endif
#ifdef CONFIG_RTC_ENABLE_32KHZ_OUTPUT
#ifdef CONFIG_DM_I2C
#else
#endif
#endif
#ifdef CONFIG_FSL_CAAM
#endif
#ifdef CONFIG_FSL_LS_PPA
#endif
#ifdef CONFIG_SYS_I2C_EARLY_INIT
#endif
#ifdef CONFIG_FSL_QSPI
#endif
#ifdef CONFIG_SYS_FSL_HAS_DP_DDR
#endif
#if defined(CONFIG_ARCH_MISC_INIT)
#endif
#if defined(CONFIG_FSL_MC_ENET) && !defined(CONFIG_SPL_BUILD)
#endif
#ifdef CONFIG_OF_BOARD_SETUP
#ifdef CONFIG_RESV_RAM
#endif
#if defined(CONFIG_FSL_MC_ENET) && !defined(CONFIG_SPL_BUILD)
#endif
#endif
