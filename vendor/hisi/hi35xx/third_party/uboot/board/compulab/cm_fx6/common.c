#include <common.h>
#include <asm/arch/sys_proto.h>
#include <asm/gpio.h>
#include <asm/mach-imx/spi.h>
#include <fsl_esdhc_imx.h>
#include "common.h"
#ifdef CONFIG_FSL_ESDHC_IMX
#define USDHC_PAD_CTRL (PAD_CTL_PUS_47K_UP |			\
#endif
#ifdef CONFIG_MXC_SPI
#define ECSPI_PAD_CTRL (PAD_CTL_SRE_FAST | PAD_CTL_SPEED_MED | \
#endif
