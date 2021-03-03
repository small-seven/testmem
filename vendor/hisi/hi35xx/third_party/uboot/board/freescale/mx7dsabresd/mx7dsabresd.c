#include <init.h>
#include <asm/arch/clock.h>
#include <asm/arch/imx-regs.h>
#include <asm/arch/mx7-pins.h>
#include <asm/arch/sys_proto.h>
#include <asm/gpio.h>
#include <asm/mach-imx/iomux-v3.h>
#include <asm/io.h>
#include <linux/sizes.h>
#include <common.h>
#include <fsl_esdhc_imx.h>
#include <mmc.h>
#include <miiphy.h>
#include <netdev.h>
#include <power/pmic.h>
#include <power/pfuze3000_pmic.h>
#include "../common/pfuze.h"
#include <i2c.h>
#include <asm/mach-imx/mxc_i2c.h>
#include <asm/arch/crm_regs.h>
#define UART_PAD_CTRL  (PAD_CTL_DSE_3P3V_49OHM | \
#define ENET_PAD_CTRL  (PAD_CTL_PUS_PU100KOHM | PAD_CTL_DSE_3P3V_49OHM)
#define ENET_PAD_CTRL_MII  (PAD_CTL_DSE_3P3V_32OHM)
#define ENET_RX_PAD_CTRL  (PAD_CTL_PUS_PU100KOHM | PAD_CTL_DSE_3P3V_49OHM)
#define LCD_PAD_CTRL    (PAD_CTL_HYS | PAD_CTL_PUS_PU100KOHM | \
#define NAND_PAD_CTRL (PAD_CTL_DSE_3P3V_49OHM | PAD_CTL_SRE_SLOW | PAD_CTL_HYS)
#define SPI_PAD_CTRL \
#define NAND_PAD_READY0_CTRL (PAD_CTL_DSE_3P3V_49OHM | PAD_CTL_PUS_PU5KOHM)
#ifdef CONFIG_MXC_SPI
#endif
#ifdef CONFIG_NAND_MXS
#endif
#ifdef CONFIG_VIDEO_MXS
#endif
#ifdef CONFIG_FEC_MXC
#endif
#ifdef CONFIG_FEC_MXC
#endif
#ifdef CONFIG_FSL_QSPI
#endif
#ifdef CONFIG_FEC_MXC
#endif
#ifdef CONFIG_NAND_MXS
#endif
#ifdef CONFIG_VIDEO_MXS
#endif
#ifdef CONFIG_FSL_QSPI
#endif
#ifdef CONFIG_MXC_SPI
#endif
#ifdef CONFIG_DM_PMIC
#endif
