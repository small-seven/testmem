#include <asm/arch/clock.h>
#include <asm/arch/iomux.h>
#include <asm/arch/imx-regs.h>
#include <asm/arch/crm_regs.h>
#include <asm/arch/mx6ul_pins.h>
#include <asm/arch/mx6-pins.h>
#include <asm/arch/sys_proto.h>
#include <asm/gpio.h>
#include <asm/mach-imx/iomux-v3.h>
#include <asm/mach-imx/boot_mode.h>
#include <asm/io.h>
#include <common.h>
#include <fsl_esdhc_imx.h>
#include <linux/sizes.h>
#include <mmc.h>
#define USDHC_PAD_CTRL (PAD_CTL_PKE | PAD_CTL_PUE |		\
#ifdef CONFIG_FSL_ESDHC_IMX
#define EMMC_PWR_GPIO	IMX_GPIO_NR(4, 10)
#endif
#ifdef CONFIG_SPL_BUILD
#include <linux/libfdt.h>
#include <spl.h>
#include <asm/arch/mx6-ddr.h>
#ifdef CONFIG_BOARD_EARLY_INIT_F
#endif
#endif
