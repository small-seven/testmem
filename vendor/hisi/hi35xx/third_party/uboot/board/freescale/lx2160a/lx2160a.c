#include <common.h>
#include <dm.h>
#include <dm/platform_data/serial_pl01x.h>
#include <i2c.h>
#include <malloc.h>
#include <errno.h>
#include <netdev.h>
#include <fsl_ddr.h>
#include <fsl_sec.h>
#include <asm/io.h>
#include <fdt_support.h>
#include <linux/libfdt.h>
#include <fsl-mc/fsl_mc.h>
#include <env_internal.h>
#include <efi_loader.h>
#include <asm/arch/mmu.h>
#include <hwconfig.h>
#include <asm/arch/clock.h>
#include <asm/arch/config.h>
#include <asm/arch/fsl_serdes.h>
#include <asm/arch/soc.h>
#include "../common/qixis.h"
#include "../common/vid.h"
#include <fsl_immap.h>
#include <asm/arch-fsl-layerscape/fsl_icid.h>
#ifdef CONFIG_EMC2305
#include "../common/emc2305.h"
#endif
#ifdef CONFIG_TARGET_LX2160AQDS
#define CFG_MUX_I2C_SDHC(reg, value)		((reg & 0x3f) | value)
#define SET_CFG_MUX1_SDHC1_SDHC(reg)		(reg & 0x3f)
#define SET_CFG_MUX2_SDHC1_SPI(reg, value)	((reg & 0xcf) | value)
#define SET_CFG_MUX3_SDHC1_SPI(reg, value)	((reg & 0xf8) | value)
#define SET_CFG_MUX_SDHC2_DSPI(reg, value)	((reg & 0xf8) | value)
#define SET_CFG_MUX1_SDHC1_DSPI(reg, value)	((reg & 0x3f) | value)
#define SDHC1_BASE_PMUX_DSPI			2
#define SDHC2_BASE_PMUX_DSPI			2
#define IIC5_PMUX_SPI3				3
#endif /* CONFIG_TARGET_LX2160AQDS */
#if CONFIG_CONS_INDEX == 0
#elif CONFIG_CONS_INDEX == 1
#else
#error "Unsupported console index value."
#endif
#ifndef CONFIG_DM_I2C
#else
#endif
#ifdef CONFIG_SYS_I2C_EARLY_INIT
#endif
#ifdef CONFIG_EMC2305
#endif
#ifdef CONFIG_OF_BOARD_FIXUP
#endif
#if defined(CONFIG_TARGET_LX2160AQDS)
#endif
#if defined(CONFIG_TARGET_LX2160AQDS)
#else
#endif
#if defined(CONFIG_VID)
#endif
#ifdef CONFIG_TARGET_LX2160AQDS
#endif
#ifdef CONFIG_TARGET_LX2160AQDS
#else
#endif
#ifdef CONFIG_TARGET_LX2160AQDS
#else
#endif
#ifdef CONFIG_TARGET_LX2160AQDS
#elif defined(CONFIG_TARGET_LX2160ARDB)
#else
#endif
#ifdef CONFIG_TARGET_LX2160AQDS
#else
#endif
#ifdef CONFIG_TARGET_LX2160AQDS
#else
#endif
#if defined(CONFIG_FSL_MC_ENET) && defined(CONFIG_TARGET_LX2160ARDB)
#endif
#ifdef CONFIG_ENV_IS_NOWHERE
#endif
#if defined(CONFIG_FSL_MC_ENET) && defined(CONFIG_TARGET_LX2160ARDB)
#endif
#ifdef CONFIG_FSL_CAAM
#endif
#if defined(CONFIG_ARCH_MISC_INIT)
#endif
#ifdef CONFIG_FSL_MC_ENET
#endif
#ifdef CONFIG_OF_BOARD_SETUP
#ifdef CONFIG_RESV_RAM
#endif
#ifdef CONFIG_USB
#endif
#ifdef CONFIG_FSL_MC_ENET
#endif
#endif
