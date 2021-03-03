#include <common.h>
#include <config.h>
#include <debug_uart.h>
#include <asm/arch/cpu.h>
#include <asm/arch/dmc.h>
#include <asm/arch/power.h>
#include <asm/arch/tzpc.h>
#include <asm/arch/periph.h>
#include <asm/arch/pinmux.h>
#include <asm/arch/system.h>
#include <asm/armv7.h>
#include "common_setup.h"
#include "exynos5_setup.h"
#ifdef CONFIG_EXYNOS5420
#ifndef CONFIG_SYS_L2CACHE_OFF
#endif
#endif
#if !defined(CONFIG_SYS_L2CACHE_OFF) && defined(CONFIG_EXYNOS5420)
#endif
#ifdef CONFIG_DEBUG_UART
#if (defined(CONFIG_SPL_BUILD) && defined(CONFIG_SPL_SERIAL_SUPPORT)) || \
#endif
#endif
