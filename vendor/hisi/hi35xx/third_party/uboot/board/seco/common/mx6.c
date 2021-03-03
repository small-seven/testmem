#include <asm/arch/clock.h>
#include <asm/arch/imx-regs.h>
#include <asm/arch/iomux.h>
#include <asm/arch/mx6-pins.h>
#include <linux/errno.h>
#include <asm/gpio.h>
#include <asm/mach-imx/iomux-v3.h>
#include <asm/mach-imx/boot_mode.h>
#include <mmc.h>
#include <fsl_esdhc_imx.h>
#include <miiphy.h>
#include <netdev.h>
#include <asm/arch/mxc_hdmi.h>
#include <asm/arch/crm_regs.h>
#include <linux/fb.h>
#include <ipu_pixfmt.h>
#include <asm/io.h>
#include <asm/arch/sys_proto.h>
#include <micrel.h>
#include <asm/mach-imx/mxc_i2c.h>
#include <i2c.h>
#define UART_PAD_CTRL  (PAD_CTL_PUS_100K_UP |			\
#define ENET_PAD_CTRL	(PAD_CTL_PUS_47K_UP |	\
#define USDHC_PAD_CTRL (PAD_CTL_PUS_47K_UP |	\
