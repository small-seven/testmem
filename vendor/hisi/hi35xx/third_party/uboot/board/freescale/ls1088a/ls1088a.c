#include <common.h>
#include <env.h>
#include <i2c.h>
#include <malloc.h>
#include <errno.h>
#include <netdev.h>
#include <fsl_ifc.h>
#include <fsl_ddr.h>
#include <fsl_sec.h>
#include <asm/io.h>
#include <fdt_support.h>
#include <linux/libfdt.h>
#include <fsl-mc/fsl_mc.h>
#include <env_internal.h>
#include <asm/arch-fsl-layerscape/soc.h>
#include <asm/arch/ppa.h>
#include <hwconfig.h>
#include <asm/arch/fsl_serdes.h>
#include <asm/arch/soc.h>
#include <asm/arch-fsl-layerscape/fsl_icid.h>
#include "../common/qixis.h"
#include "ls1088a_qixis.h"
#include "../common/vid.h"
#include <fsl_immap.h>
#ifdef CONFIG_TARGET_LS1088AQDS
#ifdef CONFIG_TFABOOT
#endif /* CONFIG_TFABOOT */
#endif /* CONFIG_TARGET_LS1088AQDS */
#if defined(CONFIG_SYS_I2C_EARLY_INIT) && defined(CONFIG_TARGET_LS1088AQDS)
#endif
#ifdef CONFIG_FSL_QIXIS
#endif
#if defined(CONFIG_VID)
#endif
#if !defined(CONFIG_SPL_BUILD)
#ifdef CONFIG_TFABOOT
#endif
#ifdef CONFIG_TARGET_LS1088AQDS
#else
#endif
#ifdef CONFIG_TARGET_LS1088AQDS
#else
#endif
#ifdef CONFIG_TFABOOT
#else
#ifdef CONFIG_SD_BOOT
#endif
#endif /* CONFIG_TFABOOT */
#ifdef CONFIG_TARGET_LS1088AQDS
#else
#endif
#ifdef CONFIG_TARGET_LS1088AQDS
#else
#endif
#endif
#ifdef CONFIG_TARGET_LS1088AQDS
#else
#endif
#ifndef CONFIG_DM_I2C
#else
#endif
#if !defined(CONFIG_SPL_BUILD)
#ifndef CONFIG_DM_I2C
#else
#endif
#ifndef CONFIG_DM_I2C
#else
#endif
#ifndef CONFIG_DM_I2C
#else
#endif
#ifndef CONFIG_DM_I2C
#else
#endif
#ifndef CONFIG_DM_I2C
#else
#endif
#ifndef CONFIG_DM_I2C
#else
#endif
#ifndef CONFIG_DM_I2C
#else
#endif
#ifndef CONFIG_DM_I2C
#else
#endif
#ifndef CONFIG_DM_I2C
#else
#endif
#ifndef CONFIG_DM_I2C
#else
#endif
#ifndef CONFIG_DM_I2C
#else
#endif
#ifndef CONFIG_DM_I2C
#else
#endif
#ifdef	CONFIG_TARGET_LS1088AQDS
#ifndef CONFIG_DM_I2C
#else
#endif
#ifndef CONFIG_DM_I2C
#else
#endif
#ifndef CONFIG_DM_I2C
#else
#endif
#ifndef CONFIG_DM_I2C
#else
#endif
#ifndef CONFIG_DM_I2C
#else
#endif
#ifndef CONFIG_DM_I2C
#else
#endif
#ifndef CONFIG_DM_I2C
#else
#endif
#ifndef CONFIG_DM_I2C
#else
#endif
#ifndef CONFIG_DM_I2C
#else
#endif
#ifndef CONFIG_DM_I2C
#else
#endif
#ifndef CONFIG_DM_I2C
#else
#endif
#ifndef CONFIG_DM_I2C
#else
#endif
#endif
#ifdef CONFIG_MISC_INIT_R
#ifdef CONFIG_TARGET_LS1088ARDB
#endif
#ifdef CONFIG_TARGET_LS1088AQDS
#endif
#endif
#endif
#ifdef CONFIG_TARGET_LS1088AQDS
#ifndef CONFIG_DM_I2C
#else
#endif
#ifndef CONFIG_DM_I2C
#else
#endif
#ifndef CONFIG_DM_I2C
#else
#endif
#else
#ifndef CONFIG_DM_I2C
#else
#endif
#ifndef CONFIG_DM_I2C
#else
#endif
#endif
#if !defined(CONFIG_SPL_BUILD)
#if defined(CONFIG_TARGET_LS1088ARDB) && defined(CONFIG_FSL_MC_ENET)
#endif
#ifdef CONFIG_ENV_IS_NOWHERE
#endif
#if defined(CONFIG_TARGET_LS1088ARDB) && defined(CONFIG_FSL_MC_ENET)
#endif
#ifdef CONFIG_FSL_CAAM
#endif
#ifdef CONFIG_FSL_LS_PPA
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
#endif /* defined(CONFIG_SPL_BUILD) */
#ifdef CONFIG_TFABOOT
#ifdef CONFIG_MTD_NOR_FLASH
#endif
#ifdef CONFIG_ENV_IS_IN_SPI_FLASH
#endif
#endif
