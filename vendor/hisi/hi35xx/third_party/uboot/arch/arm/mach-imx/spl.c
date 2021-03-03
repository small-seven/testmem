#include <common.h>
#include <asm/io.h>
#include <asm/arch/imx-regs.h>
#include <asm/arch/sys_proto.h>
#include <asm/spl.h>
#include <spl.h>
#include <asm/mach-imx/hab.h>
#include <asm/mach-imx/boot_mode.h>
#include <g_dnl.h>
#if defined(CONFIG_MX6)
#if !defined(CONFIG_MX6UL) && !defined(CONFIG_MX6ULL)
#endif
#if defined(CONFIG_MX6UL) || defined(CONFIG_MX6ULL)
#endif
#elif defined(CONFIG_MX7) || defined(CONFIG_IMX8M) || defined(CONFIG_IMX8)
#if defined(CONFIG_MX7)
#endif
#if defined(CONFIG_MX7)
#elif defined(CONFIG_IMX8)
#elif defined(CONFIG_IMX8M)
#endif
#endif /* CONFIG_MX7 || CONFIG_IMX8M || CONFIG_IMX8 */
#ifdef CONFIG_SPL_USB_GADGET
#endif
#if defined(CONFIG_SPL_MMC_SUPPORT)
#if defined(CONFIG_MX7) || defined(CONFIG_IMX8M) || defined(CONFIG_IMX8)
#if defined(CONFIG_SPL_FAT_SUPPORT)
#else
#endif
#if defined(CONFIG_SPL_FAT_SUPPORT)
#elif defined(CONFIG_SUPPORT_EMMC_BOOT)
#else
#endif
#else
#ifdef CONFIG_SPL_FORCE_MMC_BOOT
#else
#endif
#if defined(CONFIG_SPL_FS_FAT)
#elif defined(CONFIG_SUPPORT_EMMC_BOOT)
#else
#endif
#endif
#endif
#if defined(CONFIG_IMX_HAB)
	typedef void __noreturn (*image_entry_noargs_t)(void);
	uint32_t offset;

	image_entry_noargs_t image_entry =
		(image_entry_noargs_t)(unsigned long)spl_image->entry_point;

	debug("image entry point: 0x%lX\n", spl_image->entry_point);

	if (spl_image->flags & SPL_FIT_FOUND) {
		image_entry();
	} else {
#if !defined(CONFIG_SPL_FIT_SIGNATURE)
#endif
#endif
#if defined(CONFIG_MX6) && defined(CONFIG_SPL_OS_BOOT)
#endif
