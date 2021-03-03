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
#include <asm/mach-imx/mx5_video.h>
#include <netdev.h>
#include <i2c.h>
#include <input.h>
#include <mmc.h>
#include <fsl_esdhc_imx.h>
#include <asm/gpio.h>
#include <power/pmic.h>
#include <dialog_pmic.h>
#include <fsl_pmic.h>
#include <linux/fb.h>
#include <ipu_pixfmt.h>
#define MX53LOCO_LCD_POWER		IMX_GPIO_NR(3, 24)
#define UART_PAD_CTRL	(PAD_CTL_HYS | PAD_CTL_DSE_HIGH | \
#ifdef CONFIG_USB_EHCI_MX5
#endif
#ifdef CONFIG_FSL_ESDHC_IMX
#define SD_CMD_PAD_CTRL		(PAD_CTL_HYS | PAD_CTL_DSE_HIGH | \
#define SD_PAD_CTRL		(PAD_CTL_HYS | PAD_CTL_PUS_47K_UP | \
#endif
#define I2C_PAD_CTRL	(PAD_CTL_SRE_FAST | PAD_CTL_DSE_HIGH | \
