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
#include "../../../drivers/video/da8xx-fb.h"
#include <asm/io.h>
#include <asm/emif.h>
#include <asm/gpio.h>
#include <i2c.h>
#include <miiphy.h>
#include <cpsw.h>
#include <watchdog.h>
#include "board.h"
#include "../common/factoryset.h"
#include "pmic.h"
#include <nand.h>
#include <bmp_layout.h>
#ifdef CONFIG_SPL_BUILD
#define MPU	0
#define CORE	1
#define OSC     (V_OSCK/1000000)
#endif /* if def CONFIG_SPL_BUILD */
#if (defined(CONFIG_DRIVER_TI_CPSW) && !defined(CONFIG_SPL_BUILD)) || \
#endif /* #if (defined(CONFIG_DRIVER_TI_CPSW) && !defined(CONFIG_SPL_BUILD)) */
#if defined(CONFIG_DRIVER_TI_CPSW) || \
#if (defined(CONFIG_DRIVER_TI_CPSW) && !defined(CONFIG_SPL_BUILD)) || \
#ifdef CONFIG_FACTORYSET
#endif /* #ifdef CONFIG_FACTORYSET */
#endif
#endif /* #if defined(CONFIG_DRIVER_TI_CPSW) */
#if defined(CONFIG_VIDEO) && !defined(CONFIG_SPL_BUILD)
#define PLL_GET_M(v) ((v >> 8) & 0x7ff)
#define PLL_GET_N(v) (v & 0x7f)
#endif
#ifdef CONFIG_BOARD_LATE_INIT
#ifdef CONFIG_FACTORYSET
#endif
#endif
#include "../common/board.c"
