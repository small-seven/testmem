#include <common.h>
#include <palmas.h>
#include <asm/armv7.h>
#include <asm/arch/cpu.h>
#include <asm/arch/sys_proto.h>
#include <asm/arch/clock.h>
#include <linux/sizes.h>
#include <asm/utils.h>
#include <asm/arch/gpio.h>
#include <asm/emif.h>
#include <asm/omap_common.h>
#ifndef CONFIG_DM_GPIO
#endif
#ifdef CONFIG_SPL_BUILD
#endif
#ifdef CONFIG_ARM_ERRATA_801819
#endif
#if defined(CONFIG_PALMAS_POWER)
#endif
