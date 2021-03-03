#include <common.h>
#include <i2c.h>
#include <init.h>
#include <asm/io.h>
#include <asm/arch/immap_ls102xa.h>
#include <asm/arch/clock.h>
#include <asm/arch/fsl_serdes.h>
#include <asm/arch/ls102xa_soc.h>
#include <asm/arch/ls102xa_devdis.h>
#include <hwconfig.h>
#include <mmc.h>
#include <fsl_csu.h>
#include <fsl_ifc.h>
#include <fsl_sec.h>
#include <spl.h>
#include <fsl_devdis.h>
#include <fsl_validate.h>
#include <fsl_ddr.h>
#include "../common/sleep.h"
#include "../common/qixis.h"
#include "ls1021aqds_qixis.h"
#ifdef CONFIG_U_QE
#include <fsl_qe.h>
#endif
#define PIN_MUX_SEL_CAN		0x03
#define PIN_MUX_SEL_IIC2	0xa0
#define PIN_MUX_SEL_RGMII	0x00
#define PIN_MUX_SEL_SAI		0x0c
#define PIN_MUX_SEL_SDHC	0x00
#define SET_SDHC_MUX_SEL(reg, value)	((reg & 0x0f) | value)
#define SET_EC_MUX_SEL(reg, value)	((reg & 0xf0) | value)
#if !defined(CONFIG_QSPI_BOOT) && !defined(CONFIG_SD_BOOT_QSPI)
#endif
#if !defined(CONFIG_SD_BOOT) && !defined(CONFIG_QSPI_BOOT)
#endif
#ifdef CONFIG_SD_BOOT
#elif CONFIG_QSPI_BOOT
#else
#endif
#if !defined(CONFIG_QSPI_BOOT) && !defined(CONFIG_SD_BOOT_QSPI)
#endif
#ifdef CONFIG_TSEC_ENET
#endif
#ifdef CONFIG_FSL_IFC
#endif
#if defined(CONFIG_DEEP_SLEEP)
#endif
#ifdef CONFIG_SPL_BUILD
#ifdef CONFIG_NAND_BOOT
#endif
#ifdef CONFIG_FSL_IFC
#endif
#if defined(CONFIG_DEEP_SLEEP)
#endif
#ifdef CONFIG_SPL_I2C_SUPPORT
#endif
#ifdef CONFIG_LAYERSCAPE_NS_ACCESS
#endif
#endif
#ifdef CONFIG_BOARD_LATE_INIT
#ifdef CONFIG_CHAIN_OF_TRUST
#endif
#endif
#ifdef CONFIG_FSL_DEVICE_DISABLE
#endif
#ifdef CONFIG_FSL_CAAM
#endif
#ifdef CONFIG_SYS_FSL_ERRATUM_A010315
#endif
#ifdef CONFIG_SYS_FSL_ERRATUM_A009942
#endif
#ifndef CONFIG_SYS_FSL_NO_SERDES
#endif
#ifdef CONFIG_U_QE
#endif
#if defined(CONFIG_DEEP_SLEEP)
#ifdef CONFIG_LAYERSCAPE_NS_ACCESS
#endif
#endif
#ifdef CONFIG_PCI
#endif
