#include <common.h>
#include <asm/io.h>
#include <asm/arch/imx-regs.h>
#include <asm/arch/iomux-vf610.h>
#include <asm/arch/ddrmc-vf610.h>
#include <asm/arch/crm_regs.h>
#include <asm/arch/clock.h>
#include <mmc.h>
#include <fsl_esdhc_imx.h>
#include <miiphy.h>
#include <netdev.h>
#include <i2c.h>
#define UART_PAD_CTRL	(PAD_CTL_PUS_100K_UP | PAD_CTL_SPEED_MED | \
#define ESDHC_PAD_CTRL	(PAD_CTL_PUS_100K_UP | PAD_CTL_SPEED_HIGH | \
#define ENET_PAD_CTRL	(PAD_CTL_PUS_47K_UP | PAD_CTL_SPEED_HIGH | \
#ifdef CONFIG_NAND_VF610_NFC
#endif
#ifdef CONFIG_FSL_ESDHC_IMX
#endif
#ifdef CONFIG_NAND_VF610_NFC
#endif
