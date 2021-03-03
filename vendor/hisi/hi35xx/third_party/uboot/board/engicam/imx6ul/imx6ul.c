#include <common.h>
#include <mmc.h>
#include <asm/io.h>
#include <asm/gpio.h>
#include <linux/sizes.h>
#include <asm/arch/clock.h>
#include <asm/arch/crm_regs.h>
#include <asm/arch/iomux.h>
#include <asm/arch/mx6-pins.h>
#include <asm/arch/sys_proto.h>
#include <asm/mach-imx/iomux-v3.h>
#include "../common/board.h"
#ifdef CONFIG_NAND_MXS
#define GPMI_PAD_CTRL0		(PAD_CTL_PKE | PAD_CTL_PUE | PAD_CTL_PUS_100K_UP)
#define GPMI_PAD_CTRL1		(PAD_CTL_DSE_40ohm | PAD_CTL_SPEED_MED | \
#define GPMI_PAD_CTRL2		(GPMI_PAD_CTRL0 | GPMI_PAD_CTRL1)
#endif /* CONFIG_NAND_MXS */
#ifdef CONFIG_ENV_IS_IN_MMC
#endif
