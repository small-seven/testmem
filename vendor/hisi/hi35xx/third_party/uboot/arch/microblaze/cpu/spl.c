#include <common.h>
#include <image.h>
#include <spl.h>
#include <asm/io.h>
#include <asm/u-boot.h>
#ifdef CONFIG_SPL_OS_BOOT
	typedef void (*image_entry_arg_t)(char *, ulong, ulong)
		__attribute__ ((noreturn));
	image_entry_arg_t image_entry =
		(image_entry_arg_t)spl_image->entry_point;

	image_entry(NULL, 0, (ulong)spl_image->arg);
}
#endif /* CONFIG_SPL_OS_BOOT */
#ifdef CONFIG_SPL_OS_BOOT
#endif
