#include <common.h>
#include <config.h>
#include <spl.h>
#include <image.h>
#include <linux/compiler.h>
#include <asm/mach-types.h>
#ifndef CONFIG_SPL_DM
#endif
#ifdef CONFIG_SPL_OS_BOOT
#ifdef CONFIG_ARM64
#else
#ifdef CONFIG_MACH_TYPE
#endif
	typedef void (*image_entry_arg_t)(int, int, void *)
		__attribute__ ((noreturn));
	image_entry_arg_t image_entry =
		(image_entry_arg_t)(uintptr_t) spl_image->entry_point;
	cleanup_before_linux();
	image_entry(0, machid, spl_image->arg);
}
#endif	/* CONFIG_ARM64 */
#endif
