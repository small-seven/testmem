#include <common.h>
#include <spl.h>
#include <dm.h>
#include <miiphy.h>
#include <asm/arch/crm_regs.h>
#include <asm/arch/sys_proto.h>
#include <asm/arch/iomux.h>
#include <asm/arch/mx6-pins.h>
#ifdef CONFIG_SPL_BUILD
# include <asm/arch/mx6-ddr.h>
#endif
#include <asm/arch/clock.h>
#include <asm/io.h>
#include <asm/gpio.h>
#define USBHUB_RSTN	IMX_GPIO_NR(1, 16)
#define BKLT_EN		IMX_GPIO_NR(1, 15)
#define CAPT_INT	IMX_GPIO_NR(4, 9)
#define CAPT_RESETN	IMX_GPIO_NR(4, 11)
#define SW_INTN		IMX_GPIO_NR(3, 26)
#define VCCDISP_EN	IMX_GPIO_NR(5, 18)
#define EMMC_RSTN	IMX_GPIO_NR(6, 8)
#define PMIC_IRQN	IMX_GPIO_NR(5, 22)
#define TASTER		IMX_GPIO_NR(5, 23)
#define ETH0_LINK	IMX_GPIO_NR(1, 27)
#define ETH1_LINK	IMX_GPIO_NR(1, 28)
#define UART_PAD_CTRL		(PAD_CTL_PUS_47K_UP |			\
#define I2C_PAD_CTRL		(PAD_CTL_PUS_47K_UP |			\
#define ECSPI_PAD_CTRL		(PAD_CTL_PUS_100K_DOWN |		\
#define USDHC_PAD_CTRL		(PAD_CTL_PUS_47K_UP |			\
#define ENET_PAD_CTRL		(PAD_CTL_PUS_100K_UP |			\
#define ENET_PAD_CTRL1		(PAD_CTL_PUS_100K_UP |			\
#define ENET_PAD_CTRL_PU	(PAD_CTL_PUS_100K_UP |		\
#define ENET_PAD_CTRL_CLK	((PAD_CTL_PUS_100K_UP & ~PAD_CTL_PKE) |	\
#define GPIO_PAD_CTRL_PU	(PAD_CTL_PUS_100K_UP |			\
#define GPIO_PAD_CTRL_PD	(PAD_CTL_PUS_100K_DOWN |		\
#define LCDCMOS_PAD_CTRL	(PAD_CTL_PUS_100K_DOWN |		\
#define MUXDESC(pad, ctrl)	IOMUX_PADS(pad | MUX_PAD_CTRL(ctrl))
#if !defined(CONFIG_SPL_BUILD)
#else
#endif /* CONFIG_SPL_BUILD */
