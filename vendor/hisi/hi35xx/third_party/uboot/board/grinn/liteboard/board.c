#include <command.h>
#include <init.h>
#include <asm/arch/clock.h>
#include <asm/arch/iomux.h>
#include <asm/arch/imx-regs.h>
#include <asm/arch/crm_regs.h>
#include <asm/arch/litesom.h>
#include <asm/arch/mx6ul_pins.h>
#include <asm/arch/mx6-pins.h>
#include <asm/arch/sys_proto.h>
#include <asm/gpio.h>
#include <asm/mach-imx/iomux-v3.h>
#include <asm/mach-imx/boot_mode.h>
#include <asm/io.h>
#include <common.h>
#include <env.h>
#include <fsl_esdhc_imx.h>
#include <linux/sizes.h>
#include <linux/fb.h>
#include <miiphy.h>
#include <mmc.h>
#include <netdev.h>
#include <spl.h>
#define UART_PAD_CTRL  (PAD_CTL_PKE | PAD_CTL_PUE |		\
#define USDHC_PAD_CTRL (PAD_CTL_PKE | PAD_CTL_PUE |		\
#define ENET_PAD_CTRL  (PAD_CTL_PUS_100K_UP | PAD_CTL_PUE |     \
#define MDIO_PAD_CTRL  (PAD_CTL_PUS_100K_UP | PAD_CTL_PUE |     \
#define ENET_CLK_PAD_CTRL  (PAD_CTL_DSE_40ohm   | PAD_CTL_SRE_FAST)
#ifdef CONFIG_FSL_ESDHC_IMX
#define SD_CD_GPIO	IMX_GPIO_NR(1, 19)
#endif
#ifdef CONFIG_FEC_MXC
#endif
#ifdef	CONFIG_FEC_MXC
#endif
#ifdef CONFIG_CMD_BMODE
#endif
#ifdef CONFIG_CMD_BMODE
#endif
#ifdef CONFIG_ENV_IS_IN_MMC
#endif
#ifdef CONFIG_SPL_BUILD
#endif
