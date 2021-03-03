#include <common.h>
#include <dm.h>
#include <env.h>
#include <ns16550.h>
#include <netdev.h>
#include <twl4030.h>
#include <linux/mtd/omap_gpmc.h>
#include <asm/io.h>
#include <asm/arch/mem.h>
#include <asm/arch/mmc_host_def.h>
#include <asm/arch/mux.h>
#include <asm/arch/sys_proto.h>
#include <asm/mach-types.h>
#include "zoom1.h"
#ifdef CONFIG_MMC
#endif
#ifdef CONFIG_CMD_NET
#ifdef CONFIG_SMC911X
#define STR_ENV_ETHADDR	"ethaddr"
#endif
#endif
