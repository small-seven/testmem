#include <common.h>
#include <linux/compiler.h>
#include <asm/fsl_law.h>
#include <asm/io.h>
#include <linux/log2.h>
#define FSL_HW_NUM_LAWS CONFIG_SYS_FSL_NUM_LAWS
#ifdef CONFIG_FSL_CORENET
#define LAW_BASE (CONFIG_SYS_FSL_CORENET_CCM_ADDR)
#define LAWAR_ADDR(x) (&((ccsr_local_t *)LAW_BASE)->law[x].lawar)
#define LAWBARH_ADDR(x) (&((ccsr_local_t *)LAW_BASE)->law[x].lawbarh)
#define LAWBARL_ADDR(x) (&((ccsr_local_t *)LAW_BASE)->law[x].lawbarl)
#define LAWBAR_SHIFT 0
#else
#define LAW_BASE (CONFIG_SYS_IMMR + 0xc08)
#define LAWAR_ADDR(x) ((u32 *)LAW_BASE + 8 * x + 2)
#define LAWBAR_ADDR(x) ((u32 *)LAW_BASE + 8 * x)
#define LAWBAR_SHIFT 12
#endif
#ifdef CONFIG_FSL_CORENET
#else
#endif
#ifdef CONFIG_FSL_CORENET
#else
#endif
#if !defined(CONFIG_NAND_SPL) && \
#endif
#if !defined(CONFIG_NAND_SPL) && \
#ifdef CONFIG_FSL_CORENET
#else
#endif
#endif /* not SPL */
#if FSL_HW_NUM_LAWS < 32
#elif FSL_HW_NUM_LAWS == 32
#else
#error FSL_HW_NUM_LAWS can not be greater than 32 w/o code changes
#endif
#if defined(CONFIG_NXP_ESBC) && defined(CONFIG_E500) && \
#endif
#if !defined(CONFIG_NXP_ESBC)
#endif
#ifdef CONFIG_SRIO_PCIE_BOOT_SLAVE
#endif
