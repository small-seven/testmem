#include <common.h>
#include <fsl_esdhc_imx.h>
#include <asm-generic/gpio.h>
#include "common.h"
#ifdef CONFIG_SPI
#define CL_SOM_IMX7_GPIO_SPI_CS	IMX_GPIO_NR(4, 19)
#endif /* CONFIG_SPI */
#ifdef CONFIG_FSL_ESDHC_IMX
#endif /* CONFIG_FSL_ESDHC_IMX */
