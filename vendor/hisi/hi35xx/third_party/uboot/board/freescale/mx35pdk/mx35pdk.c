#include <common.h>
#include <init.h>
#include <asm/io.h>
#include <linux/errno.h>
#include <asm/arch/imx-regs.h>
#include <asm/arch/crm_regs.h>
#include <asm/arch/clock.h>
#include <asm/arch/iomux-mx35.h>
#include <i2c.h>
#include <power/pmic.h>
#include <fsl_pmic.h>
#include <mmc.h>
#include <fsl_esdhc_imx.h>
#include <mc9sdz60.h>
#include <mc13892.h>
#include <linux/types.h>
#include <asm/gpio.h>
#include <asm/arch/sys_proto.h>
#include <netdev.h>
#include <asm/mach-types.h>
#ifndef CONFIG_BOARD_LATE_INIT
#error "CONFIG_BOARD_LATE_INIT must be set for this board"
#endif
#ifndef CONFIG_BOARD_EARLY_INIT_F
#error "CONFIG_BOARD_EARLY_INIT_F must be set for this board"
#endif
#define I2C_PAD_CTRL	(PAD_CTL_HYS | PAD_CTL_PUS_100K_DOWN | PAD_CTL_ODE)
#define USBOTG_IN_PAD_CTRL	(PAD_CTL_HYS | PAD_CTL_PUS_100K_DOWN | \
#define USBOTG_OUT_PAD_CTRL	(PAD_CTL_DSE_LOW | PAD_CTL_SRE_SLOW)
#define FEC_PAD_CTRL	(PAD_CTL_DSE_LOW | PAD_CTL_SRE_SLOW)
#if defined(CONFIG_SMC911X)
#endif
#if defined(CONFIG_FSL_ESDHC_IMX)
#endif
