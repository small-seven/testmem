#include <common.h>
#include <cpu_func.h>
#include <malloc.h>
#include "fsl_sec.h"
#include "jr.h"
#include "jobdesc.h"
#include "desc_constr.h"
#include <time.h>
#ifdef CONFIG_FSL_CORENET
#include <asm/fsl_pamu.h>
#endif
#define CIRC_CNT(head, tail, size)	(((head) - (tail)) & (size - 1))
#define CIRC_SPACE(head, tail, size)	CIRC_CNT((tail), (head) + 1, (size))
#if defined(CONFIG_ARCH_C29X)
#endif
#define SEC_ADDR(idx)	\
#define SEC_JR0_ADDR(idx)	\
#ifdef CONFIG_PHYS_64BIT
#else
#endif
#ifdef CONFIG_PHYS_64BIT
#else
#endif
#ifdef CONFIG_FSL_CORENET
#endif
#ifdef CONFIG_PHYS_64BIT
#endif
#ifdef CONFIG_PHYS_64BIT
#ifdef CONFIG_SYS_FSL_SEC_LE
#elif defined(CONFIG_SYS_FSL_SEC_BE)
#endif /* ifdef CONFIG_SYS_FSL_SEC_LE */
#else
#endif /* ifdef CONFIG_PHYS_64BIT */
#ifdef CONFIG_PHYS_64BIT
#else
#endif
#ifndef CONFIG_SPL_BUILD
#endif
#ifndef CONFIG_SPL_BUILD
#endif
#ifdef CONFIG_FSL_CORENET
#endif
#ifdef CONFIG_ARCH_LS2080A
#else
#endif
#ifdef CONFIG_PHYS_64BIT
#endif
#ifdef CONFIG_FSL_CORENET
#ifdef CONFIG_SPL_BUILD
#else
#endif
#endif
#ifdef CONFIG_FSL_CORENET
#endif
#ifndef CONFIG_SPL_BUILD
#endif
