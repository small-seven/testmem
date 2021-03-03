#include <asm/arch/clock.h>
#include <asm/arch/crm_regs.h>
#include <asm/arch/imx-regs.h>
#include <asm/arch/mx7-pins.h>
#include <asm/arch/sys_proto.h>
#include <asm/gpio.h>
#include <asm/mach-imx/iomux-v3.h>
#include <asm/io.h>
#include <common.h>
#include <dm.h>
#include <dm/platform_data/serial_mxc.h>
#include <fdt_support.h>
#include <fsl_esdhc_imx.h>
#include <jffs2/load_kernel.h>
#include <linux/sizes.h>
#include <mmc.h>
#include <miiphy.h>
#include <mtd_node.h>
#include <netdev.h>
#include <power/pmic.h>
#include <power/rn5t567_pmic.h>
#include <usb.h>
#include <usb/ehci-ci.h>
#include "../common/tdx-common.h"
#define UART_PAD_CTRL  (PAD_CTL_DSE_3P3V_49OHM | \
#define ENET_PAD_CTRL  (PAD_CTL_PUS_PU100KOHM | PAD_CTL_DSE_3P3V_49OHM)
#define ENET_PAD_CTRL_MII  (PAD_CTL_DSE_3P3V_32OHM)
#define ENET_RX_PAD_CTRL  (PAD_CTL_PUS_PU100KOHM | PAD_CTL_DSE_3P3V_49OHM)
#define LCD_PAD_CTRL    (PAD_CTL_HYS | PAD_CTL_PUS_PU100KOHM | \
#define NAND_PAD_CTRL (PAD_CTL_DSE_3P3V_49OHM | PAD_CTL_SRE_SLOW | PAD_CTL_HYS)
#define NAND_PAD_READY0_CTRL (PAD_CTL_DSE_3P3V_49OHM | PAD_CTL_PUS_PU5KOHM)
#define USB_CDET_GPIO	IMX_GPIO_NR(7, 14)
#ifdef CONFIG_USB_EHCI_MX7
#endif
#ifdef CONFIG_TARGET_COLIBRI_IMX7_NAND
#endif
#ifdef CONFIG_VIDEO_MXS
#define GPIO_BL_ON IMX_GPIO_NR(5, 1)
#define GPIO_PWM_A IMX_GPIO_NR(1, 8)
#endif
#ifdef CONFIG_FEC_MXC
#ifndef CONFIG_COLIBRI_IMX7_EXT_PHYCLK
#else
#endif
#endif
#ifdef CONFIG_FEC_MXC
#ifndef CONFIG_COLIBRI_IMX7_EXT_PHYCLK
#else
#endif
#endif
#ifdef CONFIG_FEC_MXC
#endif
#ifdef CONFIG_TARGET_COLIBRI_IMX7_NAND
#endif
#ifdef CONFIG_VIDEO_MXS
#endif
#ifdef CONFIG_USB_EHCI_MX7
#endif
#ifdef CONFIG_DM_PMIC
#endif
#if defined(CONFIG_OF_LIBFDT) && defined(CONFIG_OF_BOARD_SETUP)
#if defined(CONFIG_IMX_BOOTAUX) && defined(CONFIG_ARCH_FIXUP_FDT_MEMORY)
#endif
#if defined(CONFIG_FDT_FIXUP_PARTITIONS)
#endif
#endif
#ifdef CONFIG_USB_EHCI_MX7
#endif
