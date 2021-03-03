#include <common.h>
#include <asm/system.h>
#include <asm/armv8/mmu.h>
#ifdef CONFIG_SOC_K3_AM6
#define NR_MMU_REGIONS	(CONFIG_NR_DRAM_BANKS + 5)
#endif /* CONFIG_SOC_K3_AM6 */
#ifdef CONFIG_SOC_K3_J721E
#define NR_MMU_REGIONS	(CONFIG_NR_DRAM_BANKS + 5)
#endif /* CONFIG_SOC_K3_J721E */
