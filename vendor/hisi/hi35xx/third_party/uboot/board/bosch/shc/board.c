#include <common.h>
#include <env.h>
#include <errno.h>
#include <init.h>
#include <irq_func.h>
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
#include <power/tps65217.h>
#include <env_internal.h>
#include <watchdog.h>
#include "mmc.h"
#include "board.h"
#if defined CONFIG_B_SAMPLE
#else
#endif
#if !defined(CONFIG_B_SAMPLE)
#endif
#if !defined(CONFIG_B_SAMPLE)
#endif
#if defined(CONFIG_B_SAMPLE)
#else /* All other SHCs starting with B2-Sample */
#endif
#if defined(CONFIG_B_SAMPLE)
#else /* All other SHCs starting with B2-Sample */
#endif
#if defined(CONFIG_B_SAMPLE)
#else /* All other SHCs starting with B2-Sample */
#endif
#if defined(CONFIG_SPL_BUILD)
#ifdef CONFIG_SPL_OS_BOOT
#endif
# ifdef CONFIG_SHC_ICT
# else
# endif
#define MPU_SPREADING_PERMILLE 18 /* Spread 1.8 percent */
#define OSC	(V_OSCK/1000000)
#define MPUPLL_N        (4-1)
#define MPUPLL_FREF (OSC / (MPUPLL_N + 1))
#endif
#if defined(CONFIG_HW_WATCHDOG)
#endif
#if defined(CONFIG_NOR) || defined(CONFIG_MTD_RAW_NAND)
#endif
#ifdef CONFIG_BOARD_LATE_INIT
#ifdef CONFIG_ENV_VARS_UBOOT_RUNTIME_CONFIG
#endif
#endif
#if defined(CONFIG_USB_ETHER) && \
#endif
#ifdef CONFIG_SHOW_BOOT_PROGRESS
#if defined(BLINK_CODE)
#endif
#endif
