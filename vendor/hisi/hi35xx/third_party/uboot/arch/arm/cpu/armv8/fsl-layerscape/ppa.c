#include <common.h>
#include <malloc.h>
#include <config.h>
#include <errno.h>
#include <asm/system.h>
#include <asm/types.h>
#include <asm/arch/soc.h>
#ifdef CONFIG_FSL_LSCH3
#include <asm/arch/immap_lsch3.h>
#elif defined(CONFIG_FSL_LSCH2)
#include <asm/arch/immap_lsch2.h>
#endif
#ifdef CONFIG_ARMV8_SEC_FIRMWARE_SUPPORT
#include <asm/armv8/sec_firmware.h>
#endif
#ifdef CONFIG_CHAIN_OF_TRUST
#include <fsl_validate.h>
#endif
#ifdef CONFIG_SYS_LS_PPA_FW_IN_NAND
#include <nand.h>
#elif defined(CONFIG_SYS_LS_PPA_FW_IN_MMC)
#include <mmc.h>
#endif
#ifdef CONFIG_CHAIN_OF_TRUST
#if defined(CONFIG_SYS_LS_PPA_FW_IN_MMC) || \
#endif
#endif
#ifdef CONFIG_SYS_LS_PPA_FW_IN_XIP
#ifdef CONFIG_CHAIN_OF_TRUST
#endif
#else /* !CONFIG_SYS_LS_PPA_FW_IN_XIP */
#ifdef CONFIG_SYS_LS_PPA_FW_IN_MMC
#ifdef CONFIG_CHAIN_OF_TRUST
#endif
#elif defined(CONFIG_SYS_LS_PPA_FW_IN_NAND)
#ifdef CONFIG_CHAIN_OF_TRUST
#endif
#else
#error "No CONFIG_SYS_LS_PPA_FW_IN_xxx defined"
#endif
#endif
#ifdef CONFIG_CHAIN_OF_TRUST
#if defined(CONFIG_SYS_LS_PPA_FW_IN_MMC) || \
#endif
#endif
#ifdef CONFIG_FSL_LSCH3
#elif defined(CONFIG_FSL_LSCH2)
#endif
#if defined(CONFIG_SYS_LS_PPA_FW_IN_MMC) || \
#endif
