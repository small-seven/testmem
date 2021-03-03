#include <common.h>
#include <env.h>
#include <time.h>
#ifdef CONFIG_SYS_P4080_ERRATUM_SERDES8
#include <hwconfig.h>
#endif
#include <asm/fsl_serdes.h>
#include <asm/immap_85xx.h>
#include <asm/io.h>
#include <asm/processor.h>
#include <asm/fsl_law.h>
#include <linux/errno.h>
#include "fsl_corenet_serdes.h"
#ifdef CONFIG_SYS_P4080_ERRATUM_SERDES_A001
#ifndef CONFIG_SYS_P4080_ERRATUM_SERDES8
#error "CONFIG_SYS_P4080_ERRATUM_SERDES_A001 requires CONFIG_SYS_P4080_ERRATUM_SERDES8"
#endif
#endif
#ifdef DEBUG
#endif
#ifdef CONFIG_ARCH_P4080
#else
#endif
#if SRDS_MAX_BANK > 3
#endif
#ifdef CONFIG_SYS_P4080_ERRATUM_SERDES8
#endif
#ifdef CONFIG_SYS_P4080_ERRATUM_SERDES9
#endif
#ifndef CONFIG_SYS_DCSRBAR_PHYS
#define CONFIG_SYS_DCSRBAR_PHYS	0x80000000 /* Must be 1GB-aligned for rev1.0 */
#define CONFIG_SYS_DCSRBAR	0x80000000
#define __DCSR_NOT_DEFINED_BY_CONFIG
#endif
#ifdef CONFIG_SYS_P4080_ERRATUM_SERDES8
#ifdef __DCSR_NOT_DEFINED_BY_CONFIG
#endif
#ifdef __DCSR_NOT_DEFINED_BY_CONFIG
#endif
#endif
#ifdef CONFIG_SYS_P4080_ERRATUM_SERDES_A005
#endif
#ifdef CONFIG_ARCH_P5040
#endif
#ifdef CONFIG_SYS_P4080_ERRATUM_SERDES8
#endif
#ifdef CONFIG_SYS_P4080_ERRATUM_SERDES_A001
#endif
#ifdef CONFIG_SYS_P4080_ERRATUM_SERDES8
#endif
#ifdef CONFIG_SYS_P4080_ERRATUM_SERDES8
#define B2_B3 (FSL_CORENET_RCWSRn_SRDS_LPD_B2 | FSL_CORENET_RCWSRn_SRDS_LPD_B3)
#endif
#ifdef CONFIG_ARCH_P5040
#endif
#ifdef CONFIG_SYS_P4080_ERRATUM_SERDES8
#endif
#ifdef CONFIG_SYS_P4080_ERRATUM_SERDES_A001
#endif
#ifdef CONFIG_SYS_P4080_ERRATUM_SERDES_A001
#else
#endif
#ifdef CONFIG_SYS_FSL_ERRATUM_A004699
#endif
#if defined(CONFIG_SYS_P4080_ERRATUM_SERDES8) || defined (CONFIG_SYS_P4080_ERRATUM_SERDES9)
#ifdef DEBUG
#endif
#ifdef CONFIG_SYS_P4080_ERRATUM_SERDES9
#endif
#ifdef CONFIG_SYS_P4080_ERRATUM_SERDES8
#endif
#endif
#ifdef DEBUG
#endif
#ifdef CONFIG_SYS_P4080_ERRATUM_SERDES_A005
#endif
#ifdef CONFIG_SYS_P4080_ERRATUM_SERDES8
#endif
#ifdef CONFIG_SYS_P4080_ERRATUM_SERDES8
#endif
#ifdef CONFIG_SYS_P4080_ERRATUM_SERDES_A001
#endif
