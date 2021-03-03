#include <common.h>
#include <adc.h>
#include <bootm.h>
#include <clk.h>
#include <config.h>
#include <dm.h>
#include <env.h>
#include <env_internal.h>
#include <g_dnl.h>
#include <generic-phy.h>
#include <i2c.h>
#include <init.h>
#include <led.h>
#include <memalign.h>
#include <misc.h>
#include <mtd.h>
#include <mtd_node.h>
#include <netdev.h>
#include <phy.h>
#include <remoteproc.h>
#include <reset.h>
#include <syscon.h>
#include <usb.h>
#include <watchdog.h>
#include <asm/io.h>
#include <asm/gpio.h>
#include <asm/arch/stm32.h>
#include <asm/arch/sys_proto.h>
#include <jffs2/load_kernel.h>
#include <power/regulator.h>
#include <usb/dwc2_udc.h>
#define SYSCFG_BOOTR		0x00
#define SYSCFG_PMCSETR		0x04
#define SYSCFG_IOCTRLSETR	0x18
#define SYSCFG_ICNR		0x1C
#define SYSCFG_CMPCR		0x20
#define SYSCFG_CMPENSETR	0x24
#define SYSCFG_PMCCLRR		0x44
#define SYSCFG_BOOTR_BOOT_MASK		GENMASK(2, 0)
#define SYSCFG_BOOTR_BOOTPD_SHIFT	4
#define SYSCFG_IOCTRLSETR_HSLVEN_TRACE		BIT(0)
#define SYSCFG_IOCTRLSETR_HSLVEN_QUADSPI	BIT(1)
#define SYSCFG_IOCTRLSETR_HSLVEN_ETH		BIT(2)
#define SYSCFG_IOCTRLSETR_HSLVEN_SDMMC		BIT(3)
#define SYSCFG_IOCTRLSETR_HSLVEN_SPI		BIT(4)
#define SYSCFG_CMPCR_SW_CTRL		BIT(1)
#define SYSCFG_CMPCR_READY		BIT(8)
#define SYSCFG_CMPENSETR_MPU_EN		BIT(0)
#define SYSCFG_PMCSETR_ETH_CLK_SEL	BIT(16)
#define SYSCFG_PMCSETR_ETH_REF_CLK_SEL	BIT(17)
#define SYSCFG_PMCSETR_ETH_SELMII	BIT(20)
#define SYSCFG_PMCSETR_ETH_SEL_MASK	GENMASK(23, 21)
#define SYSCFG_PMCSETR_ETH_SEL_GMII_MII	0
#define SYSCFG_PMCSETR_ETH_SEL_RGMII	BIT(21)
#define SYSCFG_PMCSETR_ETH_SEL_RMII	BIT(23)
#define USB_LOW_THRESHOLD_UV		200000
#define USB_WARNING_LOW_THRESHOLD_UV	660000
#define USB_START_LOW_THRESHOLD_UV	1230000
#define USB_START_HIGH_THRESHOLD_UV	2150000
#if defined(CONFIG_FASTBOOT) || defined(CONFIG_CMD_STM32PROG)
#ifdef CONFIG_FASTBOOT
#endif
#ifdef CONFIG_CMD_STM32PROG
#endif
#endif
#if defined(CONFIG_USB_GADGET) && defined(CONFIG_USB_GADGET_DWC2_OTG)
#define STUSB1600_CC_CONNECTION_STATUS		0x0E
#define STUSB1600_CC_ATTACH			BIT(0)
#include <usb/dwc2_udc.h>
#define STM32MP1_G_DNL_DFU_PRODUCT_NUM 0xdf11
#define STM32MP1_G_DNL_FASTBOOT_PRODUCT_NUM 0x0afb
#endif /* CONFIG_USB_GADGET */
#ifdef CONFIG_LED
#endif
#ifdef CONFIG_LED
#endif
#ifdef CONFIG_LED
#endif
#ifdef CONFIG_ADC
#endif /* CONFIG_ADC */
#ifndef CONFIG_STM32MP1_TRUSTED
#ifdef CONFIG_DM_REGULATOR
#endif
#ifdef CONFIG_DM_REGULATOR
#endif
#endif
#ifdef CONFIG_DM_REGULATOR
#endif
#ifdef CONFIG_DM_REGULATOR
#endif
#ifdef CONFIG_ENV_VARS_UBOOT_RUNTIME_CONFIG
#endif
#ifdef CONFIG_ADC
#endif /* CONFIG_ADC */
#ifdef CONFIG_LED
#endif
#ifdef CONFIG_ENV_IS_IN_EXT4
#endif
#ifdef CONFIG_ENV_IS_IN_UBI
#endif
#ifdef CONFIG_ENV_IS_IN_SPI_FLASH
#endif
#if defined(CONFIG_ENV_IS_IN_EXT4)
#endif
#ifdef CONFIG_SYS_MTDPARTS_RUNTIME
#define MTDPARTS_LEN		256
#define MTDIDS_LEN		128
#endif
#if defined(CONFIG_OF_BOARD_SETUP)
#ifdef CONFIG_FDT_FIXUP_PARTITIONS
#endif
#endif
#ifdef CONFIG_SET_DFU_ALT_INFO
#define DFU_ALT_BUF_LEN SZ_1K
#ifdef CONFIG_DFU_VIRT
#endif
#if CONFIG_IS_ENABLED(DFU_VIRT)
#include <dfu.h>
#include <power/stpmic1.h>
#ifdef CONFIG_PMIC_STPMIC1
#else
#endif
#endif
#endif
