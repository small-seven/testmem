#include <common.h>
#include <cpu_func.h>
#include <dm.h>
#include <env.h>
#include <netdev.h>
#include <asm/io.h>
#include <dm/platform_data/serial_pl01x.h>
#include "arm-ebi.h"
#include "integrator-sc.h"
#include <asm/mach-types.h>
#ifdef CONFIG_ARCH_CINTEGRATOR
#else
#endif
#if defined(CONFIG_SHOW_BOOT_PROGRESS)
#endif
#define COMP_MODE_ENABLE ((unsigned int)0x0000EAEF)
#ifdef CONFIG_ARCH_CINTEGRATOR
#else
#endif
#ifdef CONFIG_CM_REMAP
#endif
#ifdef CONFIG_ARCH_CINTEGRATOR
#else
#endif
#define REMAPPED_FLASH_SZ 0x40000
#ifdef CONFIG_CM_SPD_DETECT
#else
#endif /* CM_SPD_DETECT */
#ifdef CONFIG_CMD_NET
#ifdef CONFIG_SMC91111
#endif
#endif
