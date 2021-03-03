#include <common.h>
#include <env.h>
#include <malloc.h>
#include <errno.h>
#include <netdev.h>
#include <fsl_ifc.h>
#include <fsl_ddr.h>
#include <asm/io.h>
#include <hwconfig.h>
#include <fdt_support.h>
#include <linux/libfdt.h>
#include <fsl-mc/fsl_mc.h>
#include <env_internal.h>
#include <efi_loader.h>
#include <i2c.h>
#include <asm/arch/mmu.h>
#include <asm/arch/soc.h>
#include <asm/arch/ppa.h>
#include <fsl_sec.h>
#include <asm/arch-fsl-layerscape/fsl_icid.h>
#ifdef CONFIG_FSL_QIXIS
#include "../common/qixis.h"
#include "ls2080ardb_qixis.h"
#endif
#include "../common/vid.h"
#define PIN_MUX_SEL_SDHC	0x00
#define PIN_MUX_SEL_DSPI	0x0a
#define SET_SDHC_MUX_SEL(reg, value)	((reg & 0xf0) | value)
#ifdef CONFIG_FSL_QIXIS
#endif
#ifdef CONFIG_TARGET_LS2081ARDB
#ifdef CONFIG_FSL_QIXIS
#endif
#else
#ifdef CONFIG_FSL_QIXIS
#endif
#endif
#ifdef CONFIG_FSL_QIXIS
#endif
#ifndef CONFIG_DM_I2C
#else
#endif
#ifdef CONFIG_FSL_QIXIS
#endif
#ifdef CONFIG_FSL_MC_ENET
#endif
#ifdef CONFIG_ENV_IS_NOWHERE
#endif
#ifdef CONFIG_FSL_QIXIS
#endif
#ifdef CONFIG_FSL_CAAM
#endif
#ifdef CONFIG_FSL_LS_PPA
#endif
#ifdef CONFIG_FSL_MC_ENET
#endif
#ifdef CONFIG_FSL_CAAM
#endif
#ifdef CONFIG_SYS_I2C_EARLY_INIT
#endif
#ifdef CONFIG_TARGET_LS2081ARDB
#endif
#ifdef CONFIG_SYS_FSL_HAS_DP_DDR
#endif
#if defined(CONFIG_ARCH_MISC_INIT)
#endif
#ifdef CONFIG_FSL_MC_ENET
#endif
#ifdef CONFIG_OF_BOARD_SETUP
#ifdef CONFIG_TFABOOT
#endif
#ifdef CONFIG_TFABOOT
#else
#ifdef CONFIG_FSL_QSPI
#else
#endif
#endif
#ifdef CONFIG_RESV_RAM
#endif
#ifdef CONFIG_FSL_MC_ENET
#endif
#endif
#ifdef CONFIG_FSL_QIXIS
#endif
#ifndef CONFIG_TARGET_LS2081ARDB
#ifdef CONFIG_FSL_QIXIS
#endif
#endif
