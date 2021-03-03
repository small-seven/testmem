#include <errno.h>
#include <common.h>
#include <asm/io.h>
#include <fdt_support.h>
#include <fsl_mdio.h>
#ifdef CONFIG_FSL_LAYERSCAPE
#include <asm/arch/fsl_serdes.h>
#else
#include <asm/fsl_serdes.h>
#endif
#include "fm.h"
#if (CONFIG_SYS_NUM_FM1_DTSEC >= 1)
#endif
#if (CONFIG_SYS_NUM_FM1_DTSEC >= 2)
#endif
#if (CONFIG_SYS_NUM_FM1_DTSEC >= 3)
#endif
#if (CONFIG_SYS_NUM_FM1_DTSEC >= 4)
#endif
#if (CONFIG_SYS_NUM_FM1_DTSEC >= 5)
#endif
#if (CONFIG_SYS_NUM_FM1_DTSEC >= 6)
#endif
#if (CONFIG_SYS_NUM_FM1_DTSEC >= 7)
#endif
#if (CONFIG_SYS_NUM_FM1_DTSEC >= 8)
#endif
#if (CONFIG_SYS_NUM_FM2_DTSEC >= 1)
#endif
#if (CONFIG_SYS_NUM_FM2_DTSEC >= 2)
#endif
#if (CONFIG_SYS_NUM_FM2_DTSEC >= 3)
#endif
#if (CONFIG_SYS_NUM_FM2_DTSEC >= 4)
#endif
#if (CONFIG_SYS_NUM_FM2_DTSEC >= 5)
#endif
#if (CONFIG_SYS_NUM_FM2_DTSEC >= 6)
#endif
#if (CONFIG_SYS_NUM_FM2_DTSEC >= 7)
#endif
#if (CONFIG_SYS_NUM_FM2_DTSEC >= 8)
#endif
#if (CONFIG_SYS_NUM_FM1_10GEC >= 1)
#endif
#if (CONFIG_SYS_NUM_FM1_10GEC >= 2)
#endif
#if (CONFIG_SYS_NUM_FM1_10GEC >= 3)
#endif
#if (CONFIG_SYS_NUM_FM1_10GEC >= 4)
#endif
#if (CONFIG_SYS_NUM_FM2_10GEC >= 1)
#endif
#if (CONFIG_SYS_NUM_FM2_10GEC >= 2)
#endif
#if (CONFIG_SYS_NUM_FMAN == 2)
#endif
#ifndef CONFIG_SYS_FMAN_V3
#endif
#ifndef CONFIG_SYS_FMAN_V3
#endif
#ifdef CONFIG_SYS_FMAN_V3
#ifndef CONFIG_FSL_FM_10GEC_REGULAR_NOTATION
#if (CONFIG_SYS_NUM_FMAN == 2)
#endif
#else
#endif
#endif
#ifndef CONFIG_SYS_FMAN_V3
#endif
#ifdef CONFIG_SYS_FMAN_V3
#else
#endif
