#include <common.h>
#include <i2c.h>
#include <asm/io.h>
#include <asm/arch/clock.h>
#include <asm/arch/fsl_serdes.h>
#ifdef CONFIG_FSL_LS_PPA
#include <asm/arch/ppa.h>
#endif
#include <asm/arch/mmu.h>
#include <asm/arch/soc.h>
#include <hwconfig.h>
#include <ahci.h>
#include <mmc.h>
#include <scsi.h>
#include <fsl_esdhc.h>
#include <env_internal.h>
#include <fsl_mmdc.h>
#include <netdev.h>
#include <fsl_sec.h>
#define BOOT_FROM_UPPER_BANK	0x2
#define BOOT_FROM_LOWER_BANK	0x1
#ifdef CONFIG_TARGET_LS1012ARDB
#else
#endif
#ifdef CONFIG_TFABOOT
#else
#ifndef CONFIG_TFABOOT
#endif
#if !defined(CONFIG_SPL) || defined(CONFIG_SPL_BUILD)
#endif
#endif
#ifdef CONFIG_SYS_FSL_ERRATUM_A010315
#endif
#ifdef CONFIG_ENV_IS_NOWHERE
#endif
#ifdef CONFIG_FSL_CAAM
#endif
#ifdef CONFIG_FSL_LS_PPA
#endif
#ifdef CONFIG_TARGET_LS1012ARDB
#ifdef CONFIG_HWCONFIG
#endif
#endif
