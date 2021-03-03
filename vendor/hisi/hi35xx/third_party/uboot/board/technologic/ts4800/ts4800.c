#include <common.h>
#include <asm/io.h>
#include <asm/gpio.h>
#include <asm/arch/imx-regs.h>
#include <asm/arch/iomux-mx51.h>
#include <env.h>
#include <linux/errno.h>
#include <asm/arch/sys_proto.h>
#include <asm/arch/crm_regs.h>
#include <asm/arch/clock.h>
#include <asm/mach-imx/mx5_video.h>
#include <mmc.h>
#include <input.h>
#include <fsl_esdhc_imx.h>
#include <mc13892.h>
#include <malloc.h>
#include <netdev.h>
#include <phy.h>
#include "ts4800.h"
#ifdef CONFIG_FSL_ESDHC_IMX
#endif
#define UART_PAD_CTRL	(PAD_CTL_HYS | PAD_CTL_PUS_100K_DOWN | PAD_CTL_DSE_HIGH)
#ifdef CONFIG_FSL_ESDHC_IMX
#endif
#define TS4800_GPIO_FEC_PHY_RES         IMX_GPIO_NR(2, 14)
