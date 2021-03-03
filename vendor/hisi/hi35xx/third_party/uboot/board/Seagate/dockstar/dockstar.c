#include <common.h>
#include <miiphy.h>
#include <asm/arch/soc.h>
#include <asm/arch/mpp.h>
#include <asm/arch/cpu.h>
#include <asm/io.h>
#include <asm/mach-types.h>
#include "dockstar.h"
#ifdef CONFIG_RESET_PHY_R
#endif /* CONFIG_RESET_PHY_R */
#define GREEN_LED	(1 << 14)
#define ORANGE_LED	(1 << 15)
#define BOTH_LEDS	(GREEN_LED | ORANGE_LED)
#define NEITHER_LED	0
