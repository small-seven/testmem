#include <common.h>
#ifdef CONFIG_PPC
#include <asm/fsl_law.h>
#endif
#include <div64.h>
#include <fsl_ddr.h>
#include <fsl_immap.h>
#include <asm/io.h>
#if defined(CONFIG_FSL_LSCH2) || defined(CONFIG_FSL_LSCH3) || \
#include <asm/arch/clock.h>
#endif
#define ULL_2E12 2000000000000ULL
#define UL_5POW12 244140625UL
#define UL_2POW13 (1UL << 13)
#define ULL_8FS 0xFFFFFFFFULL
#if defined(CONFIG_SYS_FSL_DDR2_ADDR) && (CONFIG_SYS_NUM_DDR_CTLRS > 1)
#endif
#if defined(CONFIG_SYS_FSL_DDR3_ADDR) && (CONFIG_SYS_NUM_DDR_CTLRS > 2)
#endif
#if defined(CONFIG_SYS_FSL_DDR4_ADDR) && (CONFIG_SYS_NUM_DDR_CTLRS > 3)
#endif
#ifdef CONFIG_PPC
#if !defined(CONFIG_PHYS_64BIT)
#endif
#endif
#ifdef CONFIG_E6500
#endif
#ifdef CONFIG_E6500
#endif
#if	defined(CONFIG_E6500) && (CONFIG_SYS_NUM_DDR_CTLRS == 3)
#endif
#if (CONFIG_SYS_NUM_DDR_CTLRS > 1)
#endif
#if CONFIG_SYS_NUM_DDR_CTLRS >= 2
#endif
#if CONFIG_SYS_NUM_DDR_CTLRS >= 3
#endif
#if (CONFIG_SYS_NUM_DDR_CTLRS == 3)
#ifdef CONFIG_E6500
#endif
#endif
#if (CONFIG_SYS_NUM_DDR_CTLRS >= 2)
#endif
#ifdef CONFIG_FSL_DDR_SYNC_REFRESH
#define DDRC_DEBUG20_INIT_DONE	0x80000000
#define DDRC_DEBUG2_RF		0x00000040
#if defined(CONFIG_SYS_FSL_DDR2_ADDR) && (CONFIG_SYS_NUM_DDR_CTLRS > 1)
#endif
#if defined(CONFIG_SYS_FSL_DDR3_ADDR) && (CONFIG_SYS_NUM_DDR_CTLRS > 2)
#endif
#if defined(CONFIG_SYS_FSL_DDR4_ADDR) && (CONFIG_SYS_NUM_DDR_CTLRS > 3)
#endif
#endif /* CONFIG_FSL_DDR_SYNC_REFRESH */
#ifdef CONFIG_SYS_FSL_HAS_CCN504
#endif
