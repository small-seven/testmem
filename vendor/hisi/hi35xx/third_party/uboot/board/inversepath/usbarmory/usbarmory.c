#include <common.h>
#include <command.h>
#include <asm/io.h>
#include <asm/arch/imx-regs.h>
#include <asm/arch/sys_proto.h>
#include <asm/arch/crm_regs.h>
#include <asm/arch/clock.h>
#include <asm/arch/iomux-mx53.h>
#include <linux/errno.h>
#include <i2c.h>
#include <mmc.h>
#include <fsl_esdhc_imx.h>
#include <asm/gpio.h>
#define SD_CMD_PAD_CTRL	(PAD_CTL_HYS | PAD_CTL_DSE_HIGH | \
#define I2C_PAD_CTRL	(PAD_CTL_SRE_FAST | PAD_CTL_DSE_HIGH | \
#define PAD_CTRL_UP	PAD_CTL_PUS_100K_UP
#define PAD_CTRL_GND	PAD_CTL_PUS_100K_DOWN
#define CPU_CLOCK 800
#ifndef CONFIG_CMDLINE
#endif
