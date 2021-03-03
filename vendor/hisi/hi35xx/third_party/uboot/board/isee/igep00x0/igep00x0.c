#include <common.h>
#include <env.h>
#include <status_led.h>
#include <dm.h>
#include <ns16550.h>
#include <twl4030.h>
#include <netdev.h>
#include <spl.h>
#include <asm/gpio.h>
#include <asm/io.h>
#include <asm/arch/mem.h>
#include <asm/arch/mmc_host_def.h>
#include <asm/arch/mux.h>
#include <asm/arch/sys_proto.h>
#include <linux/mtd/mtd.h>
#include <linux/mtd/rawnand.h>
#include <linux/mtd/onenand.h>
#include <jffs2/load_kernel.h>
#include <mtd_node.h>
#include <fdt_support.h>
#include "igep00x0.h"
#if defined(CONFIG_CMD_NET)
#ifdef CONFIG_SMC911X
#else
#endif
#else
#endif
#ifdef CONFIG_OF_BOARD_SETUP
#ifdef CONFIG_FDT_FIXUP_PARTITIONS
#endif
#endif
