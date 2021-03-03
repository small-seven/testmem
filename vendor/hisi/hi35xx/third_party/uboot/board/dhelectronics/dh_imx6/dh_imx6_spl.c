#include <common.h>
#include <asm/arch/clock.h>
#include <asm/arch/crm_regs.h>
#include <asm/arch/imx-regs.h>
#include <asm/arch/iomux.h>
#include <asm/arch/mx6-ddr.h>
#include <asm/arch/mx6-pins.h>
#include <asm/arch/sys_proto.h>
#include <asm/gpio.h>
#include <asm/mach-imx/boot_mode.h>
#include <asm/mach-imx/iomux-v3.h>
#include <asm/mach-imx/mxc_i2c.h>
#include <asm/io.h>
#include <errno.h>
#include <fuse.h>
#include <fsl_esdhc_imx.h>
#include <i2c.h>
#include <mmc.h>
#include <spl.h>
#define ENET_PAD_CTRL							\
#define GPIO_PAD_CTRL							\
#define SPI_PAD_CTRL							\
#define UART_PAD_CTRL							\
#define USDHC_PAD_CTRL							\
#define DDR3_CODE_BIT_0   IMX_GPIO_NR(2, 22)
#define DDR3_CODE_BIT_1   IMX_GPIO_NR(2, 21)
#ifdef CONFIG_FSL_USDHC
#endif
#ifdef CONFIG_MX6_DDRCAL
#endif /* CONFIG_MX6_DDRCAL */
