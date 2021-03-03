#include <common.h>
#include <i2c.h>
#include <init.h>
#include <asm/io.h>
#include <asm/arch/immap_ls102xa.h>
#include <asm/arch/clock.h>
#include <asm/arch/fsl_serdes.h>
#include <asm/arch/ls102xa_devdis.h>
#include <asm/arch/ls102xa_soc.h>
#include <hwconfig.h>
#include <mmc.h>
#include <fsl_csu.h>
#include <fsl_ifc.h>
#include <fsl_immap.h>
#include <netdev.h>
#include <fsl_mdio.h>
#include <tsec.h>
#include <fsl_sec.h>
#include <fsl_devdis.h>
#include <spl.h>
#include "../common/sleep.h"
#ifdef CONFIG_U_QE
#include <fsl_qe.h>
#endif
#include <fsl_validate.h>
#define VERSION_MASK		0x00FF
#define BANK_MASK		0x0001
#define CONFIG_RESET		0x1
#define INIT_RESET		0x1
#define CPLD_SET_MUX_SERDES	0x20
#define CPLD_SET_BOOT_BANK	0x40
#define BOOT_FROM_UPPER_BANK	0x0
#define BOOT_FROM_LOWER_BANK	0x1
#define LANEB_SATA		(0x01)
#define LANEB_SGMII1		(0x02)
#define LANEC_SGMII1		(0x04)
#define LANEC_PCIEX1		(0x08)
#define LANED_PCIEX2		(0x10)
#define LANED_SGMII2		(0x20)
#define MASK_LANE_B		0x1
#define MASK_LANE_C		0x2
#define MASK_LANE_D		0x4
#define MASK_SGMII		0x8
#define KEEP_STATUS		0x0
#define NEED_RESET		0x1
#define SOFT_MUX_ON_I2C3_IFC	0x2
#define SOFT_MUX_ON_CAN3_USB2	0x8
#define SOFT_MUX_ON_QE_LCD	0x10
#define PIN_I2C3_IFC_MUX_I2C3	0x0
#define PIN_I2C3_IFC_MUX_IFC	0x1
#define PIN_CAN3_USB2_MUX_USB2	0x0
#define PIN_CAN3_USB2_MUX_CAN3	0x1
#define PIN_QE_LCD_MUX_LCD	0x0
#define PIN_QE_LCD_MUX_QE	0x1
#if !defined(CONFIG_QSPI_BOOT) && !defined(CONFIG_SD_BOOT_QSPI)
#ifdef CONFIG_DEBUG
#endif
#endif
#if !defined(CONFIG_QSPI_BOOT) && !defined(CONFIG_SD_BOOT_QSPI)
#endif
#ifdef CONFIG_DEEP_SLEEP
#endif
#ifdef CONFIG_DEEP_SLEEP
#endif
#ifdef CONFIG_DEEP_SLEEP
#endif
#if (!defined(CONFIG_SPL) || defined(CONFIG_SPL_BUILD))
#endif
#if defined(CONFIG_DEEP_SLEEP) && !defined(CONFIG_SPL_BUILD)
#endif
#if !defined(CONFIG_QSPI_BOOT) && !defined(CONFIG_SD_BOOT_QSPI)
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
#if defined(CONFIG_DEEP_SLEEP)
#endif
#ifdef CONFIG_LAYERSCAPE_NS_ACCESS
#endif
#endif
#ifdef CONFIG_DEEP_SLEEP
#define LS1TWR_I2C_BUS_MC34VR500	1
#define MC34VR500_ADDR			0x8
#define MC34VR500_DEVICEID		0x4
#define MC34VR500_DEVICEID_MASK		0x0f
#endif
#ifdef CONFIG_SYS_FSL_ERRATUM_A010315
#endif
#ifndef CONFIG_SYS_FSL_NO_SERDES
#if !defined(CONFIG_QSPI_BOOT) && !defined(CONFIG_SD_BOOT_QSPI)
#endif
#endif
#ifdef CONFIG_U_QE
#endif
#ifdef CONFIG_DEEP_SLEEP
#endif
#if defined(CONFIG_SPL_BUILD)
#endif
#ifdef CONFIG_BOARD_LATE_INIT
#ifdef CONFIG_CHAIN_OF_TRUST
#endif
#endif
#if defined(CONFIG_MISC_INIT_R)
#ifdef CONFIG_FSL_DEVICE_DISABLE
#endif
#if !defined(CONFIG_QSPI_BOOT) && !defined(CONFIG_SD_BOOT_QSPI)
#endif
#ifdef CONFIG_FSL_CAAM
#endif
#endif
#if defined(CONFIG_DEEP_SLEEP)
#ifdef CONFIG_LAYERSCAPE_NS_ACCESS
#endif
#endif
#ifdef CONFIG_PCI
#endif
#if !defined(CONFIG_QSPI_BOOT) && !defined(CONFIG_SD_BOOT_QSPI) \
#endif
