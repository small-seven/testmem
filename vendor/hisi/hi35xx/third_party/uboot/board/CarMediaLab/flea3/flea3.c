#include <common.h>
#include <asm/io.h>
#include <env.h>
#include <linux/errno.h>
#include <asm/arch/imx-regs.h>
#include <asm/arch/crm_regs.h>
#include <asm/arch/iomux-mx35.h>
#include <i2c.h>
#include <linux/types.h>
#include <asm/gpio.h>
#include <asm/arch/sys_proto.h>
#include <netdev.h>
#include <fdt_support.h>
#include <mtd_node.h>
#include <jffs2/load_kernel.h>
#ifndef CONFIG_BOARD_EARLY_INIT_F
#error "CONFIG_BOARD_EARLY_INIT_F must be set for this board"
#endif
#define CCM_CCMR_CONFIG		0x003F4208
#define ESDCTL_DDR2_CONFIG	0x007FFC3F
#define I2C_PAD_CTRL	(PAD_CTL_HYS | PAD_CTL_PUS_100K_DOWN | PAD_CTL_ODE)
