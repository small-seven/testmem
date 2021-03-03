#include <common.h>
#include <asm/arch/mmc.h>
#include <asm/arch/rcar-mstp.h>
#include <asm/arch/rmobile.h>
#include <asm/arch/sh_sdhi.h>
#include <asm/arch/sys_proto.h>
#include <asm/gpio.h>
#include <asm/io.h>
#include <asm/mach-types.h>
#include <asm/processor.h>
#include <dm.h>
#include <dm/platform_data/serial_sh.h>
#include <env.h>
#include <i2c.h>
#include <linux/errno.h>
#include <malloc.h>
#include <miiphy.h>
#include <mmc.h>
#include <netdev.h>
#include "qos.h"
#define	CPG_PLL1CR	0xE6150028
#define	CPG_PLL3CR	0xE61500DC
#define TMU0_MSTP125	BIT(25)
#define QSPI_MSTP917	BIT(17)
#if defined(CONFIG_MTD_NOR_FLASH)
#endif
#if defined(CONFIG_MTD_NOR_FLASH)
#endif /* CONFIG_MTD_NOR_FLASH */
#ifdef CONFIG_SMC911X
#endif
