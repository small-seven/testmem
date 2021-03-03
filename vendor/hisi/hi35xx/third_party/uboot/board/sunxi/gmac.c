#include <common.h>
#include <netdev.h>
#include <miiphy.h>
#include <asm/gpio.h>
#include <asm/io.h>
#include <asm/arch/clock.h>
#include <asm/arch/gpio.h>
#ifdef CONFIG_RGMII
#else
#endif
#ifndef CONFIG_MACH_SUN6I
#ifdef CONFIG_SUN7I_GMAC_FORCE_TXERR
#else
#endif
#ifdef CONFIG_RGMII
#endif
#elif defined CONFIG_RGMII
#elif defined CONFIG_GMII
#else
#endif
