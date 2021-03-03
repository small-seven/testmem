#include <common.h>
#include <mvmfp.h>
#include <asm/arch/cpu.h>
#include <asm/arch/mfp.h>
#include <asm/arch/armada100.h>
#include <asm/gpio.h>
#include <miiphy.h>
#include <asm/mach-types.h>
#ifdef CONFIG_ARMADA100_FEC
#include <net.h>
#include <netdev.h>
#endif /* CONFIG_ARMADA100_FEC */
#ifdef CONFIG_ARMADA100_FEC
#ifdef CONFIG_RESET_PHY_R
#endif /* CONFIG_RESET_PHY_R */
#endif /* CONFIG_ARMADA100_FEC */
