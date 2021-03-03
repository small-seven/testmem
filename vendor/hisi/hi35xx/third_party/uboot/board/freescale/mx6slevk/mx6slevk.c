#include <asm/arch/clock.h>
#include <asm/arch/iomux.h>
#include <asm/arch/crm_regs.h>
#include <asm/arch/imx-regs.h>
#include <asm/arch/mx6-ddr.h>
#include <asm/arch/mx6-pins.h>
#include <asm/arch/sys_proto.h>
#include <asm/gpio.h>
#include <asm/mach-imx/iomux-v3.h>
#include <asm/mach-imx/mxc_i2c.h>
#include <asm/io.h>
#include <linux/sizes.h>
#include <common.h>
#include <fsl_esdhc_imx.h>
#include <i2c.h>
#include <mmc.h>
#include <netdev.h>
#include <power/pmic.h>
#include <power/pfuze100_pmic.h>
#include "../common/pfuze.h"
#define UART_PAD_CTRL  (PAD_CTL_PUS_100K_UP |			\
#define USDHC_PAD_CTRL (PAD_CTL_PUS_22K_UP |			\
#define ENET_PAD_CTRL  (PAD_CTL_PKE | PAD_CTL_PUE |             \
#define OTGID_PAD_CTRL (PAD_CTL_PKE | PAD_CTL_PUE |		\
#define ETH_PHY_POWER	IMX_GPIO_NR(4, 21)
#ifdef CONFIG_SPL_BUILD
#endif
#ifdef CONFIG_DM_PMIC_PFUZE100
#endif
#ifdef CONFIG_FEC_MXC
#endif
#ifdef	CONFIG_FEC_MXC
#endif
#ifdef CONFIG_SPL_BUILD
#include <spl.h>
#include <linux/libfdt.h>
#define USDHC1_CD_GPIO	IMX_GPIO_NR(4, 7)
#define USDHC2_CD_GPIO	IMX_GPIO_NR(5, 0)
#define USDHC3_CD_GPIO	IMX_GPIO_NR(3, 22)
#endif
