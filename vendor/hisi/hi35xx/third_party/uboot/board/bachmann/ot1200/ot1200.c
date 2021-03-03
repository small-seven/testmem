#include <common.h>
#include <asm/io.h>
#include <asm/arch/clock.h>
#include <asm/arch/imx-regs.h>
#include <asm/arch/iomux.h>
#include <env.h>
#include <malloc.h>
#include <asm/arch/mx6-pins.h>
#include <asm/mach-imx/iomux-v3.h>
#include <asm/mach-imx/sata.h>
#include <asm/mach-imx/mxc_i2c.h>
#include <asm/mach-imx/boot_mode.h>
#include <asm/arch/crm_regs.h>
#include <asm/arch/sys_proto.h>
#include <mmc.h>
#include <fsl_esdhc_imx.h>
#include <netdev.h>
#include <i2c.h>
#include <pca953x.h>
#include <asm/gpio.h>
#include <phy.h>
#define OUTPUT_40OHM	(PAD_CTL_SPEED_MED|PAD_CTL_DSE_40ohm)
#define UART_PAD_CTRL	(PAD_CTL_PUS_100K_UP |			\
#define USDHC_PAD_CTRL	(PAD_CTL_PUS_47K_UP |			\
#define ENET_PAD_CTRL	(PAD_CTL_PUS_100K_UP | OUTPUT_40OHM |	\
#define SPI_PAD_CTRL	(PAD_CTL_HYS | OUTPUT_40OHM |		\
#define I2C_PAD_CTRL	(PAD_CTL_PUS_100K_UP | OUTPUT_40OHM |	\
#define PC MUX_PAD_CTRL(I2C_PAD_CTRL)
#ifdef CONFIG_SATA
#endif
#ifdef CONFIG_CMD_BMODE
#endif
#ifdef CONFIG_CMD_BMODE
#endif
