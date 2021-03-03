#include <init.h>
#include <asm/arch/clock.h>
#include <asm/arch/imx-regs.h>
#include <asm/arch/iomux.h>
#include <env.h>
#include <malloc.h>
#include <asm/arch/mx6-pins.h>
#include <linux/errno.h>
#include <asm/gpio.h>
#include <asm/mach-imx/iomux-v3.h>
#include <asm/mach-imx/sata.h>
#include <mmc.h>
#include <fsl_esdhc_imx.h>
#include <asm/arch/crm_regs.h>
#include <asm/io.h>
#include <asm/arch/sys_proto.h>
#include <micrel.h>
#include <miiphy.h>
#include <netdev.h>
#define UART_PAD_CTRL  (PAD_CTL_PUS_100K_UP |			\
#define ENET_PAD_CTRL  (PAD_CTL_PUS_100K_UP |                   \
#define USDHC_PAD_CTRL (PAD_CTL_PUS_47K_UP |			\
#define WDT_EN		IMX_GPIO_NR(5, 4)
#define WDT_TRG		IMX_GPIO_NR(3, 19)
#ifdef CONFIG_FEC_MXC
#endif
#ifdef CONFIG_SATA
#endif
#ifdef CONFIG_ENV_VARS_UBOOT_RUNTIME_CONFIG
#endif
