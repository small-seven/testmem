#include <common.h>
#include <dm.h>
#include <env.h>
#include <fsl_validate.h>
#include <fsl_secboot_err.h>
#include <fsl_sfp.h>
#include <dm/root.h>
#if defined(CONFIG_SPL_BUILD) && defined(CONFIG_SPL_FRAMEWORK)
#include <spl.h>
#endif
#ifdef CONFIG_ADDR_MAP
#include <asm/mmu.h>
#endif
#ifdef CONFIG_FSL_CORENET
#include <asm/fsl_pamu.h>
#endif
#ifdef CONFIG_ARCH_LS1021A
#include <asm/arch/immap_ls102xa.h>
#endif
#if defined(CONFIG_MPC85xx)
#define CONFIG_DCFG_ADDR	CONFIG_SYS_MPC85xx_GUTS_ADDR
#else
#define CONFIG_DCFG_ADDR	CONFIG_SYS_FSL_GUTS_ADDR
#endif
#ifdef CONFIG_SYS_FSL_CCSR_GUR_LE
#define gur_in32(a)       in_le32(a)
#else
#define gur_in32(a)       in_be32(a)
#endif
#if defined(CONFIG_FSL_CORENET) || !defined(CONFIG_MPC85xx)
#endif
#if defined(CONFIG_MPC85xx) && !defined(CONFIG_FSL_CORENET)
#endif
#ifndef CONFIG_SPL_BUILD
#ifdef CONFIG_ARM
#else
#endif
#endif
#ifdef CONFIG_SPL_BUILD
#ifdef CONFIG_ADDR_MAP
#endif
#ifdef CONFIG_FSL_CORENET
#endif
#ifdef CONFIG_FSL_CAAM
#endif
#if defined(CONFIG_SPL_DM) && (!defined(CONFIG_SPL_FRAMEWORK))
#endif
#ifdef CONFIG_SPL_FRAMEWORK
	typedef void __noreturn (*image_entry_noargs_t)(void);
	uint32_t hdr_addr;

	image_entry_noargs_t image_entry =
		(image_entry_noargs_t)(unsigned long)spl_image->entry_point;

	hdr_addr = (spl_image->entry_point + spl_image->size -
			CONFIG_U_BOOT_HDR_SIZE);
	spl_validate_uboot(hdr_addr, (uintptr_t)spl_image->entry_point);
	/*
	 * In case of failure in validation, spl_validate_uboot would
	 * not return back in case of Production environment with ITS=1.
	 * Thus U-Boot will not start.
	 * In Development environment (ITS=0 and SB_EN=1), the function
	 * may return back in case of non-fatal failures.
	 */

	debug("image entry point: 0x%lX\n", spl_image->entry_point);
	image_entry();
}
#endif /* ifdef CONFIG_SPL_FRAMEWORK */
#endif /* ifdef CONFIG_SPL_BUILD */
