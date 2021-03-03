#include <common.h>
#include <asm/arch/clock.h>
#include <asm/arch/crm_regs.h>
#include <asm/arch/iomux.h>
#include <asm/arch/mx6-pins.h>
#include <asm/arch/mxc_hdmi.h>
#include <asm/arch/sys_proto.h>
#include <asm/gpio.h>
#include <asm/mach-imx/boot_mode.h>
#include <asm/mach-imx/sata.h>
#include <asm/mach-imx/spi.h>
#include <asm/mach-imx/video.h>
#include <asm/io.h>
#include <asm/setup.h>
#include <dm.h>
#include <dm/platform_data/serial_mxc.h>
#include <env.h>
#include <hwconfig.h>
#include <i2c.h>
#include <fdt_support.h>
#include <fsl_esdhc_imx.h>
#include <jffs2/load_kernel.h>
#include <linux/ctype.h>
#include <miiphy.h>
#include <mtd_node.h>
#include <netdev.h>
#include <pci.h>
#include <power/pmic.h>
#include <power/ltc3676_pmic.h>
#include <power/pfuze100_pmic.h>
#include <fdt_support.h>
#include <jffs2/load_kernel.h>
#include <spi_flash.h>
#include "gsc.h"
#include "common.h"
#ifdef CONFIG_CMD_NAND
#endif
#ifdef CONFIG_USB_EHCI_MX6
#endif /* CONFIG_USB_EHCI_MX6 */
#ifdef CONFIG_MXC_SPI
#endif
#ifdef CONFIG_MV88E61XX_SWITCH
#endif // CONFIG_MV88E61XX_SWITCH
#ifdef CONFIG_FEC_MXC
#endif
#ifdef CONFIG_E1000
#endif
#ifdef CONFIG_CI_UDC
#endif
#if defined(CONFIG_VIDEO_IPUV3)
#endif /* CONFIG_VIDEO_IPUV3 */
#if defined(CONFIG_CMD_PCI)
#define MAX_PCI_DEVS	32
#endif /* CONFIG_CMD_PCI */
#ifdef CONFIG_SERIAL_TAG
#endif
#if defined(CONFIG_VIDEO_IPUV3)
#endif
#ifdef CONFIG_CMD_NAND
#endif
#ifdef CONFIG_MXC_SPI
#endif
#ifdef CONFIG_SATA
#endif
#if defined(CONFIG_DISPLAY_BOARDINFO_LATE)
#endif
#ifdef CONFIG_CMD_BMODE
#endif
#ifdef CONFIG_CMD_BMODE
#endif
#ifdef CONFIG_OF_BOARD_SETUP
#if defined(CONFIG_CMD_PCI)
#define PCI_ID(x) ( \
#endif /* if defined(CONFIG_CMD_PCI) */
#define WDOG1_ADDR	0x20bc000
#define WDOG2_ADDR	0x20c0000
#define GPIO3_ADDR	0x20a4000
#define USDHC3_ADDR	0x2198000
#define PWM0_ADDR	0x2080000
#if defined(CONFIG_CMD_PCI)
#endif
#endif /* CONFIG_OF_BOARD_SETUP */
