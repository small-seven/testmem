#include <common.h>
#include <asm/fsl_serdes.h>
#include <asm/immap_85xx.h>
#include <asm/io.h>
#include <asm/processor.h>
#include <asm/fsl_law.h>
#include <linux/errno.h>
#include <fsl_errata.h>
#include "fsl_corenet2_serdes.h"
#ifdef CONFIG_SYS_FSL_SRDS_1
#endif
#ifdef CONFIG_SYS_FSL_SRDS_2
#endif
#ifdef CONFIG_SYS_FSL_SRDS_3
#endif
#ifdef CONFIG_SYS_FSL_SRDS_4
#endif
#ifdef DEBUG
#endif
#ifdef CONFIG_SYS_FSL_SRDS_1
#endif
#ifdef CONFIG_SYS_FSL_SRDS_2
#endif
#ifdef CONFIG_SYS_FSL_SRDS_3
#endif
#ifdef CONFIG_SYS_FSL_SRDS_4
#endif
#ifdef CONFIG_SYS_FSL_SRDS_1
#endif
#ifdef CONFIG_SYS_FSL_SRDS_2
#endif
#ifdef CONFIG_SYS_FSL_SRDS_3
#endif
#ifdef CONFIG_SYS_FSL_SRDS_4
#endif
#define BC3_SHIFT	9
#define DC3_SHIFT	6
#define FC3_SHIFT	0
#define BC2_SHIFT	19
#define DC2_SHIFT	16
#define FC2_SHIFT	10
#define BC1_SHIFT	29
#define DC1_SHIFT	26
#define FC1_SHIFT	20
#define BC_MASK		0x1
#define DC_MASK		0x7
#define FC_MASK		0x3F
#define FUSE_VAL_MASK		0x00000003
#define FUSE_VAL_SHIFT		30
#define CR0_DCBIAS_SHIFT	5
#define CR1_FCAP_SHIFT		15
#define CR1_BCAP_SHIFT		29
#define FCAP_MASK		0x001F8000
#define BCAP_MASK		0x20000000
#define BCAP_OVD_MASK		0x10000000
#define BYP_CAL_MASK		0x02000000
#ifdef CONFIG_SYS_FSL_ERRATUM_A007186
#endif
#ifdef CONFIG_SYS_FSL_ERRATUM_A007186
#endif
#ifdef CONFIG_SYS_FSL_SRDS_1
#endif
#ifdef CONFIG_SYS_FSL_SRDS_2
#endif
#ifdef CONFIG_SYS_FSL_SRDS_3
#endif
#ifdef CONFIG_SYS_FSL_SRDS_4
#endif
#if defined(CONFIG_TARGET_T4240QDS) || defined(CONFIG_TARGET_T4160QDS)
#else
#endif
