#include <common.h>
#include <env.h>
#include <hwconfig.h>
#include <fsl_ddr_sdram.h>
#include <fsl_ddr.h>
#if defined(CONFIG_FSL_LSCH2) || defined(CONFIG_FSL_LSCH3) || \
#include <asm/arch/clock.h>
#endif
#ifdef CONFIG_SYS_FSL_DDR4
#elif defined(CONFIG_SYS_FSL_DDR3)
#else	/* CONFIG_SYS_FSL_DDR3 */
#endif
#if (CONFIG_DIMM_SLOTS_PER_CTLR == 1)
#elif (CONFIG_DIMM_SLOTS_PER_CTLR == 2)
#ifdef CONFIG_FSL_DDR_FIRST_SLOT_QUAD_CAPABLE
#endif
#endif
#if defined(CONFIG_SYS_FSL_DDR3) || \
#endif
#if (CONFIG_FSL_SDRAM_TYPE != SDRAM_TYPE_DDR4)
#endif
#if defined(CONFIG_SYS_FSL_DDR3) || \
#if (CONFIG_DIMM_SLOTS_PER_CTLR == 1)
#elif (CONFIG_DIMM_SLOTS_PER_CTLR == 2)
#ifdef CONFIG_FSL_DDR_FIRST_SLOT_QUAD_CAPABLE
#endif
#endif	/* CONFIG_DIMM_SLOTS_PER_CTLR */
#endif	/* CONFIG_SYS_FSL_DDR2, 3, 4 */
#if defined(CONFIG_SYS_FSL_DDR3) || \
#else
#endif
#ifdef CONFIG_DDR_ECC
#endif
#if defined(CONFIG_SYS_FSL_DDR1)
#elif defined(CONFIG_SYS_FSL_DDR2) || defined(CONFIG_SYS_FSL_DDR3)
#endif
#if defined(CONFIG_SYS_FSL_DDR1) || defined(CONFIG_SYS_FSL_DDR2)
#else
#endif
#if defined(CONFIG_SYS_FSL_DDR3) || defined(CONFIG_SYS_FSL_DDR4)
#if defined(CONFIG_E500MC)
#else
#endif
#else
#endif
#if defined(CONFIG_SYS_FSL_DDR3) || defined(CONFIG_SYS_FSL_DDR4)
#endif
#if defined(CONFIG_SYS_FSL_DDR1)
#elif defined(CONFIG_SYS_FSL_DDR2)
#else
#endif
#if defined(CONFIG_SYS_FSL_DDR3) || defined(CONFIG_SYS_FSL_DDR4)
#endif
#if (CONFIG_SYS_NUM_DDR_CTLRS > 1)
#ifdef CONFIG_SYS_FSL_DDR_INTLV_256B
#else
#endif
#ifdef CONFIG_SYS_FSL_DDR_INTLV_256B
#else
#if (CONFIG_SYS_NUM_DDR_CTLRS == 3)
#elif (CONFIG_SYS_NUM_DDR_CTLRS == 4)
#endif
#endif	/* CONFIG_SYS_FSL_DDR_INTLV_256B */
#endif /* CONFIG_SYS_NUM_DDR_CTLRS > 1 */
#if (CONFIG_DIMM_SLOTS_PER_CTLR == 1)
#elif (CONFIG_DIMM_SLOTS_PER_CTLR == 2)
#ifdef CONFIG_FSL_DDR_FIRST_SLOT_QUAD_CAPABLE
#endif
#endif
#if (CONFIG_DIMM_SLOTS_PER_CTLR == 1)
#elif (CONFIG_DIMM_SLOTS_PER_CTLR == 2)
#endif
#if (CONFIG_DIMM_SLOTS_PER_CTLR == 1)
#elif (CONFIG_DIMM_SLOTS_PER_CTLR == 2)
#endif
#if (CONFIG_FSL_SDRAM_TYPE != SDRAM_TYPE_DDR4)
#endif
#if (3 == CONFIG_SYS_NUM_DDR_CTLRS)
#else
#endif
#ifdef CONFIG_DDR_SPD
#endif
