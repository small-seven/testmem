#include <common.h>
#include <asm/mach-imx/iomux-v3.h>
#include <asm/arch-mx7/mx7-pins.h>
#define PADS_SET(pads_array)						       \
#ifdef CONFIG_FSL_ESDHC_IMX
#define USDHC_PAD_CTRL		(PAD_CTL_DSE_3P3V_32OHM | PAD_CTL_SRE_SLOW | \
#endif /* CONFIG_FSL_ESDHC_IMX */
#define UART_PAD_CTRL		(PAD_CTL_DSE_3P3V_49OHM | \
#ifdef CONFIG_SPI
#define SPI_PAD_CTRL	(PAD_CTL_HYS | PAD_CTL_SRE_SLOW | \
#define GPIO_PAD_CTRL	(PAD_CTL_PUS_PU5KOHM | PAD_CTL_PUE | \
#endif /* CONFIG_SPI */
#ifndef CONFIG_SPL_BUILD
#ifdef CONFIG_FSL_ESDHC_IMX
#endif /* CONFIG_FSL_ESDHC_IMX */
#ifdef CONFIG_FEC_MXC
#define ENET_PAD_CTRL		(PAD_CTL_PUS_PD100KOHM | PAD_CTL_DSE_3P3V_49OHM)
#define ENET_PAD_CTRL_MII	(PAD_CTL_PUS_PU5KOHM)
#endif /* CONFIG_FEC_MXC */
#endif /* !CONFIG_SPL_BUILD */
