#include <asm/arch/clock.h>
#include <asm/arch/imx-regs.h>
#include <asm/arch/iomux.h>
#include <asm/arch/mx6-pins.h>
#include <linux/errno.h>
#include <asm/gpio.h>
#include <asm/mach-imx/iomux-v3.h>
#include <asm/mach-imx/video.h>
#include <mmc.h>
#include <fsl_esdhc_imx.h>
#include <asm/arch/crm_regs.h>
#include <asm/io.h>
#include <asm/arch/sys_proto.h>
#include <spl.h>
#include <netdev.h>
#include <miiphy.h>
#include <micrel.h>
#include <common.h>
#include <malloc.h>
#include <fuse.h>
#define UART_PAD_CTRL  (PAD_CTL_PUS_100K_UP |			\
#define USDHC_PAD_CTRL (PAD_CTL_PKE | PAD_CTL_PUE |             \
#define I2C_PAD_CTRL	(PAD_CTL_PUS_100K_UP |			\
#define ENET_PAD_CTRL		(PAD_CTL_PUS_100K_UP | PAD_CTL_SPEED_MED | \
#define ENET_NRST IMX_GPIO_NR(1, 25)
#define USDHC2_CD_GPIO	IMX_GPIO_NR(2, 0)
#if defined(CONFIG_SPL_BUILD)
#include <asm/arch/mx6-ddr.h>
#define IMX6SDL_DRIVE_STRENGTH	0x230
#ifdef CONFIG_MX6_DDRCAL
#endif
#endif
