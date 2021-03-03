#include <common.h>
#include <init.h>
#include <asm/io.h>
#include <asm/gpio.h>
#include <asm/arch/imx-regs.h>
#include <asm/arch/iomux-mx51.h>
#include <linux/errno.h>
#include <asm/arch/sys_proto.h>
#include <asm/arch/crm_regs.h>
#include <asm/arch/clock.h>
#include <asm/mach-imx/mx5_video.h>
#include <i2c.h>
#include <input.h>
#include <mmc.h>
#include <fsl_esdhc_imx.h>
#include <power/pmic.h>
#include <fsl_pmic.h>
#include <mc13892.h>
#include <usb/ehci-ci.h>
#ifdef CONFIG_FSL_ESDHC_IMX
#endif
#define UART_PAD_CTRL	(PAD_CTL_HYS | PAD_CTL_PUS_100K_DOWN | PAD_CTL_DSE_HIGH)
#ifdef CONFIG_MXC_SPI
#endif
#ifdef CONFIG_USB_EHCI_MX5
#define MX51EVK_USBH1_HUB_RST	IMX_GPIO_NR(1, 7)
#define MX51EVK_USBH1_STP	IMX_GPIO_NR(1, 27)
#define MX51EVK_USB_CLK_EN_B	IMX_GPIO_NR(2, 1)
#define MX51EVK_USB_PHY_RESET	IMX_GPIO_NR(2, 5)
#endif
#ifdef CONFIG_FSL_ESDHC_IMX
#endif
#ifdef CONFIG_USB_EHCI_MX5
#endif
#ifdef CONFIG_BOARD_LATE_INIT
#ifdef CONFIG_MXC_SPI
#endif
#endif
