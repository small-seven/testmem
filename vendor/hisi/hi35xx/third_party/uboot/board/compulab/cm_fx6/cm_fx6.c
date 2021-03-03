#include <common.h>
#include <ahci.h>
#include <dm.h>
#include <dwc_ahsata.h>
#include <env.h>
#include <fsl_esdhc_imx.h>
#include <init.h>
#include <miiphy.h>
#include <mtd_node.h>
#include <netdev.h>
#include <errno.h>
#include <usb.h>
#include <fdt_support.h>
#include <sata.h>
#include <splash.h>
#include <asm/arch/crm_regs.h>
#include <asm/arch/sys_proto.h>
#include <asm/arch/iomux.h>
#include <asm/arch/mxc_hdmi.h>
#include <asm/mach-imx/mxc_i2c.h>
#include <asm/mach-imx/sata.h>
#include <asm/mach-imx/video.h>
#include <asm/io.h>
#include <asm/gpio.h>
#include <dm/platform_data/serial_mxc.h>
#include <dm/device-internal.h>
#include <jffs2/load_kernel.h>
#include "common.h"
#include "../common/eeprom.h"
#include "../common/common.h"
#ifdef CONFIG_SPLASH_SCREEN
#endif
#ifdef CONFIG_IMX_HDMI
#else
#endif /* CONFIG_VIDEO_IPUV3 */
#ifdef CONFIG_DWC_AHSATA
#define CM_FX6_SATA_INIT_RETRIES	10
#else
#endif
#ifdef CONFIG_SYS_I2C_MXC
#define I2C_PAD_CTRL	(PAD_CTL_PUS_100K_UP | PAD_CTL_SPEED_MED | \
#else
#endif
#ifdef CONFIG_USB_EHCI_MX6
#define WEAK_PULLDOWN	(PAD_CTL_PUS_100K_DOWN |		\
#define MX6_USBNC_BASEADDR	0x2184800
#define USBNC_USB_H1_PWR_POL	(1 << 9)
#else
#endif
#ifdef CONFIG_FEC_MXC
#define ENET_PAD_CTRL		(PAD_CTL_PUS_100K_UP | PAD_CTL_SPEED_MED | \
#define SB_FX6_I2C_EEPROM_BUS	0
#define NO_MAC_ADDR		"No MAC address found for %s\n"
#endif
#ifdef CONFIG_NAND_MXS
#else
#endif
#ifdef CONFIG_MXC_SPI
#else
#endif
#ifdef CONFIG_OF_BOARD_SETUP
#define USDHC3_PATH	"/soc/aips-bus@02100000/usdhc@02198000/"
#endif
#ifdef CONFIG_FSL_ESDHC_IMX
#endif
#ifdef CONFIG_ENV_VARS_UBOOT_RUNTIME_CONFIG
#endif
#if CONFIG_IS_ENABLED(AHCI)
static int sata_imx_remove(struct udevice *dev)
{
	cm_fx6_sata_power(0);
	mdelay(250);

	return 0;
}
#endif /* AHCI */
