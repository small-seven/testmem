#include <common.h>
#include <malloc.h>
#include <errno.h>
#include <fsl_ddr.h>
#include <asm/io.h>
#include <hwconfig.h>
#include <fdt_support.h>
#include <linux/libfdt.h>
#include <env_internal.h>
#include <asm/arch-fsl-layerscape/soc.h>
#include <asm/arch-fsl-layerscape/fsl_icid.h>
#include <i2c.h>
#include <asm/arch/soc.h>
#ifdef CONFIG_FSL_LS_PPA
#include <asm/arch/ppa.h>
#endif
#include <fsl_immap.h>
#include <netdev.h>
#include <fdtdec.h>
#include <miiphy.h>
#include "../common/qixis.h"
#if defined(CONFIG_TARGET_LS1028AQDS) && defined(CONFIG_FSL_QIXIS)
#endif
#ifdef CONFIG_ENV_IS_NOWHERE
#endif
#ifdef CONFIG_FSL_CAAM
#endif
#ifdef CONFIG_FSL_LS_PPA
#endif
#ifndef CONFIG_SYS_EARLY_PCI_INIT
#endif
#if defined(CONFIG_TARGET_LS1028ARDB)
#ifndef CONFIG_DM_I2C
#else
#endif
#endif
#if defined(CONFIG_ARCH_MISC_INIT)
#endif
#ifdef CONFIG_SYS_I2C_EARLY_INIT
#endif
#ifdef CONFIG_OF_BOARD_SETUP
#ifdef CONFIG_RESV_RAM
#endif
#endif
#ifdef CONFIG_FSL_QIXIS
#ifdef CONFIG_TFABOOT
#endif
#ifdef CONFIG_TFABOOT
#endif
#ifdef CONFIG_SD_BOOT
#elif defined(CONFIG_EMMC_BOOT)
#else
#endif
#ifdef CONFIG_TFABOOT
#endif
#ifdef CONFIG_TARGET_LS1028ARDB
#else
#endif
#ifdef CONFIG_TARGET_LS1028ARDB
#else
#endif
#endif
