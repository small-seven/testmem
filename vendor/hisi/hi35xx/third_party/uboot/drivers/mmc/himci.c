#include <config.h>
#include <common.h>
#include <mmc.h>
#include <part.h>
#include <malloc.h>
#include <cpu_func.h>
#include <asm/io.h>
#include <himci_reg.h>
#include "mmc_private.h"
#include "himci.h"
#define MMC_CS_ERROR_MASK   0xFDFFA080
#ifdef CONFIG_TARGET_HI3516CV500
#endif
#if (defined CONFIG_TARGET_HI3516DV300) || (defined CONFIG_TARGET_HI3516AV300)
#endif
#ifdef CONFIG_TARGET_HI3556V200
#endif
#ifdef CONFIG_TARGET_HI3559V200
#endif
#ifdef CONFIG_TARGET_HI3562V100
#endif
#ifdef CONFIG_TARGET_HI3566V100
#endif
#if HI_MCI_DEBUG
#endif
#ifdef TUNING_PROC_DEBUG
#endif
#ifdef TUNING_PROC_DEBUG
#endif
#ifdef TUNING_PROC_DEBUG
#endif
#ifdef TUNING_PROC_DEBUG
#endif
#ifdef CONFIG_SUPPORT_EMMC_BOOT
#endif
