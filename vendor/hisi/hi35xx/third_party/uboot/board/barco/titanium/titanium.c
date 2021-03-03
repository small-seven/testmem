#include <common.h>
#include <asm/io.h>
#include <asm/arch/clock.h>
#include <asm/arch/imx-regs.h>
#include <asm/arch/iomux.h>
#include <asm/arch/mx6-pins.h>
#include <asm/arch/crm_regs.h>
#include <asm/arch/sys_proto.h>
#include <asm/gpio.h>
#include <asm/mach-imx/iomux-v3.h>
#include <asm/mach-imx/mxc_i2c.h>
#include <asm/mach-imx/boot_mode.h>
#include <mmc.h>
#include <fsl_esdhc_imx.h>
#include <micrel.h>
#include <miiphy.h>
#include <netdev.h>
#define UART_PAD_CTRL  (PAD_CTL_PUS_100K_UP | PAD_CTL_SPEED_MED |	\
#define USDHC_PAD_CTRL (PAD_CTL_PUS_47K_UP  | PAD_CTL_SPEED_LOW |	\
#define ENET_PAD_CTRL  (PAD_CTL_PUS_100K_UP | PAD_CTL_SPEED_MED	  |	\
#define I2C_PAD_CTRL	(PAD_CTL_PUS_100K_UP | PAD_CTL_SPEED_MED |	\
#define PC MUX_PAD_CTRL(I2C_PAD_CTRL)
#ifdef CONFIG_USB_EHCI_MX6
#endif
#ifdef CONFIG_FSL_ESDHC_IMX
#endif
#ifdef CONFIG_CMD_BMODE
#endif
#ifdef CONFIG_CMD_BMODE
#endif
