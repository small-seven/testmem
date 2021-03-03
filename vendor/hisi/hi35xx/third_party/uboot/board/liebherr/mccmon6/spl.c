#include <asm/arch/clock.h>
#include <asm/arch/imx-regs.h>
#include <asm/arch/iomux.h>
#include <asm/arch/mx6-pins.h>
#include <errno.h>
#include <asm/gpio.h>
#include <asm/mach-imx/iomux-v3.h>
#include <asm/mach-imx/video.h>
#include <mmc.h>
#include <fsl_esdhc_imx.h>
#include <asm/arch/crm_regs.h>
#include <asm/io.h>
#include <asm/arch/sys_proto.h>
#include <serial.h>
#include <spl.h>
#include <asm/arch/mx6-ddr.h>
#define IMX6DQ_DRIVE_STRENGTH		0x30
#define IMX6SDL_DRIVE_STRENGTH		0x28
#define UART_PAD_CTRL  (PAD_CTL_PUS_100K_UP |			\
#ifdef CONFIG_SPL_LOAD_FIT
#endif
#ifdef CONFIG_SPL_OS_BOOT
#endif /* CONFIG_SPL_OS_BOOT */
#define WEIM_NOR_PAD_CTRL (PAD_CTL_PKE | PAD_CTL_PUE |          \
#define NOR_WP			IMX_GPIO_NR(1, 1)
#define USDHC_PAD_CTRL (PAD_CTL_PUS_47K_UP |			\
#define USDHC2_CD_GPIO		IMX_GPIO_NR(1, 4)
#ifdef CONFIG_SPL_BOARD_INIT
#define DISPLAY_EN		IMX_GPIO_NR(1, 2)
#endif /* CONFIG_SPL_BOARD_INIT */
