#include <common.h>
#include <asm/io.h>
#include <asm/arch/imx-regs.h>
#include <asm/arch/sys_proto.h>
#include <asm/arch/crm_regs.h>
#include <asm/arch/clock.h>
#include <asm/arch/iomux-mx53.h>
#include <linux/errno.h>
#include <netdev.h>
#include <mmc.h>
#include <fsl_esdhc_imx.h>
#include <asm/gpio.h>
#define ETHERNET_INT		IMX_GPIO_NR(2, 31)
#ifdef CONFIG_NAND_MXC
#else
#endif
#define UART_PAD_CTRL	(PAD_CTL_HYS | PAD_CTL_DSE_HIGH | \
#ifdef CONFIG_FSL_ESDHC_IMX
#define SD_CMD_PAD_CTRL		(PAD_CTL_HYS | PAD_CTL_DSE_HIGH | \
#define SD_CLK_PAD_CTRL		(PAD_CTL_PUS_47K_UP | PAD_CTL_DSE_HIGH)
#define SD_PAD_CTRL		(PAD_CTL_HYS | PAD_CTL_PUS_47K_UP | \
#endif
#ifdef CONFIG_SMC911X
#endif
