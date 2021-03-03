#include <common.h>
#include <init.h>
#include <asm/io.h>
#include <asm/arch/imx-regs.h>
#include <asm/arch/sys_proto.h>
#include <asm/arch/crm_regs.h>
#include <asm/arch/clock.h>
#include <asm/arch/iomux-mx53.h>
#include <asm/arch/clock.h>
#include <env.h>
#include <linux/errno.h>
#include <linux/libfdt.h>
#include <asm/mach-imx/mxc_i2c.h>
#include <asm/mach-imx/mx5_video.h>
#include <netdev.h>
#include <i2c.h>
#include <mmc.h>
#include <fsl_esdhc_imx.h>
#include <asm/gpio.h>
#include <power/pmic.h>
#include <dialog_pmic.h>
#include <fsl_pmic.h>
#include <linux/fb.h>
#include <ipu_pixfmt.h>
#include <version.h>
#include <watchdog.h>
#include "ppd_gpio.h"
#include <stdlib.h>
#include "../../ge/common/ge_common.h"
#include "../../ge/common/vpd_reader.h"
#define MX53PPD_LCD_POWER		IMX_GPIO_NR(3, 24)
#define UART_PAD_CTRL	(PAD_CTL_HYS | PAD_CTL_DSE_HIGH | \
#ifdef CONFIG_USB_EHCI_MX5
#endif
#define I2C_PAD_CTRL	(PAD_CTL_SRE_FAST | PAD_CTL_DSE_HIGH | \
#define I2C_PAD MUX_PAD_CTRL(I2C_PAD_CTRL)
#define VPD_TYPE_INVALID 0x00
#define VPD_BLOCK_NETWORK 0x20
#define VPD_BLOCK_HWID 0x44
#define VPD_PRODUCT_PPD 4
#define VPD_HAS_MAC1 0x1
#define VPD_MAC_ADDRESS_LENGTH 6
#ifdef CONFIG_OF_BOARD_SETUP
#endif
