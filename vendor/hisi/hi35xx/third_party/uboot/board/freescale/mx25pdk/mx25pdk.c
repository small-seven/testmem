#include <common.h>
#include <init.h>
#include <asm/io.h>
#include <asm/gpio.h>
#include <asm/arch/imx-regs.h>
#include <asm/arch/iomux-mx25.h>
#include <asm/arch/clock.h>
#include <mmc.h>
#include <fsl_esdhc_imx.h>
#include <i2c.h>
#include <power/pmic.h>
#include <fsl_pmic.h>
#include <mc34704.h>
#define FEC_RESET_B		IMX_GPIO_NR(4, 8)
#define FEC_ENABLE_B		IMX_GPIO_NR(2, 3)
#define CARD_DETECT		IMX_GPIO_NR(2, 1)
#ifdef CONFIG_FSL_ESDHC_IMX
#endif
#define FEC_OUT_PAD_CTRL	0
#define I2C_PAD_CTRL		(PAD_CTL_HYS | PAD_CTL_PUS_100K_UP | \
#define UART1_IN_PAD_CTRL	(PAD_CTL_HYS | PAD_CTL_PUS_100K_UP)
#define UART1_OUT_PAD_CTRL	0
#ifdef CONFIG_FSL_ESDHC_IMX
#endif
