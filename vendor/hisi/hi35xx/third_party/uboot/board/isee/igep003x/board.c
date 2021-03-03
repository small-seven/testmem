#include <common.h>
#include <env.h>
#include <errno.h>
#include <init.h>
#include <serial.h>
#include <spl.h>
#include <asm/arch/cpu.h>
#include <asm/arch/hardware.h>
#include <asm/arch/omap.h>
#include <asm/arch/ddr_defs.h>
#include <asm/arch/clock.h>
#include <asm/arch/gpio.h>
#include <asm/arch/mmc_host_def.h>
#include <asm/arch/sys_proto.h>
#include <asm/io.h>
#include <asm/emif.h>
#include <asm/gpio.h>
#include <i2c.h>
#include <miiphy.h>
#include <cpsw.h>
#include <fdt_support.h>
#include <mtd_node.h>
#include <jffs2/load_kernel.h>
#include "board.h"
#define GPIO_GREEN_REVISION	27
#define GPIO_RED_REVISION	26
#ifdef CONFIG_SPL_BUILD
#define OSC    (V_OSCK/1000000)
#ifdef CONFIG_SPL_OS_BOOT
#endif
#endif
#ifdef CONFIG_BOARD_LATE_INIT
#ifdef CONFIG_ENV_VARS_UBOOT_RUNTIME_CONFIG
#endif
#endif
#ifdef CONFIG_OF_BOARD_SETUP
#ifdef CONFIG_FDT_FIXUP_PARTITIONS
#endif
#endif
#if defined(CONFIG_DRIVER_TI_CPSW)
#endif
