#include <asm/arch/clock.h>
#include <asm/arch/imx-regs.h>
#include <asm/arch/iomux.h>
#include <asm/arch/mx6-pins.h>
#include <linux/errno.h>
#include <asm/gpio.h>
#include <asm/mach-imx/iomux-v3.h>
#include <asm/mach-imx/boot_mode.h>
#include <asm/mach-imx/mxc_i2c.h>
#include <asm/mach-imx/video.h>
#include <mmc.h>
#include <fsl_esdhc_imx.h>
#include <miiphy.h>
#include <netdev.h>
#include <asm/arch/mxc_hdmi.h>
#include <asm/arch/crm_regs.h>
#include <linux/fb.h>
#include <ipu_pixfmt.h>
#include <input.h>
#include <asm/io.h>
#include <asm/arch/sys_proto.h>
#include <pwm.h>
#define UART_PAD_CTRL  (PAD_CTL_PUS_100K_UP |			\
#define USDHC_PAD_CTRL (PAD_CTL_PUS_47K_UP |			\
#define ENET_PAD_CTRL  (PAD_CTL_PUS_100K_UP |			\
#define SPI_PAD_CTRL (PAD_CTL_HYS | PAD_CTL_SPEED_MED | \
#define I2C_PAD_CTRL	(PAD_CTL_PUS_100K_UP |			\
#define PC MUX_PAD_CTRL(I2C_PAD_CTRL)
#define DISP_PAD_CTRL	(0x10)
#define ECSPI4_CS1		IMX_GPIO_NR(5, 2)
#if (CONFIG_SYS_BOARD_VERSION == 1)
#include "./aristainetos-v1.c"
#elif ((CONFIG_SYS_BOARD_VERSION == 2) || (CONFIG_SYS_BOARD_VERSION == 3))
#include "./aristainetos-v2.c"
#endif
#ifdef CONFIG_FSL_ESDHC_IMX
#if (CONFIG_SYS_BOARD_VERSION == 2)
#endif
#endif
#if ((CONFIG_SYS_BOARD_VERSION == 2) || (CONFIG_SYS_BOARD_VERSION == 3))
#endif
#ifdef CONFIG_USB_EHCI_MX6
#endif
