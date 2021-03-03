#include <common.h>
#include <miiphy.h>
#include <asm/mach-types.h>
#include <asm/arch/cpu.h>
#include <asm/arch/soc.h>
#include <asm/arch/mpp.h>
#include "openrd.h"
#if defined(CONFIG_BOARD_IS_OPENRD_BASE)
#elif defined(CONFIG_BOARD_IS_OPENRD_CLIENT)
#elif defined(CONFIG_BOARD_IS_OPENRD_ULTIMATE)
#endif
#ifdef CONFIG_RESET_PHY_R
#ifdef CONFIG_BOARD_IS_OPENRD_CLIENT
#endif
#if defined(CONFIG_BOARD_IS_OPENRD_CLIENT) || \
#endif
#endif /* CONFIG_RESET_PHY_R */
