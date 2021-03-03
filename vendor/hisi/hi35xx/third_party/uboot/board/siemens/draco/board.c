#include <common.h>
#include <env.h>
#include <errno.h>
#include <init.h>
#include <spl.h>
#include <asm/arch/cpu.h>
#include <asm/arch/hardware.h>
#include <asm/arch/omap.h>
#include <asm/arch/ddr_defs.h>
#include <asm/arch/clock.h>
#include <asm/arch/gpio.h>
#include <asm/arch/mmc_host_def.h>
#include <asm/arch/sys_proto.h>
#include <asm/arch/mem.h>
#include <asm/io.h>
#include <asm/emif.h>
#include <asm/gpio.h>
#include <i2c.h>
#include <miiphy.h>
#include <cpsw.h>
#include <watchdog.h>
#include "board.h"
#include "../common/factoryset.h"
#include <nand.h>
#ifdef CONFIG_SPL_BUILD
#if DDR_PLL_FREQ == 303
#if !defined(CONFIG_TARGET_ETAMIN)
#else
#endif
#elif DDR_PLL_FREQ == 400
#endif
#endif /* CONFIG_SPL_BUILD */
#define AM335X_NAND_ECC_MASK 0x0f
#define AM335X_NAND_ECC_TYPE_16 0x02
#ifdef CONFIG_SPL_BUILD
#endif
#ifdef CONFIG_SPL_BUILD
#endif /* if def CONFIG_SPL_BUILD */
#ifdef CONFIG_BOARD_LATE_INIT
#ifdef CONFIG_TARGET_ETAMIN
#endif
#ifdef CONFIG_FACTORYSET
#else
#endif
#endif
#if (defined(CONFIG_DRIVER_TI_CPSW) && !defined(CONFIG_SPL_BUILD)) || \
#if defined(CONFIG_DRIVER_TI_CPSW) || \
#endif /* #if defined(CONFIG_DRIVER_TI_CPSW) */
#endif /* #if (defined(CONFIG_DRIVER_TI_CPSW) && !defined(CONFIG_SPL_BUILD)) */
#ifdef CONFIG_NAND_CS_INIT
#endif
#include "../common/board.c"
