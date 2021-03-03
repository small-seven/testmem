#include <common.h>
#include <asm/io.h>
#include <spl.h>
#define RCAR_CNTC_BASE	0xE6080000
#define CNTCR_EN	BIT(0)
		typedef void (*image_entry_arg_t)(int, int, int, int)
			__attribute__ ((noreturn));
		image_entry_arg_t image_entry =
			(image_entry_arg_t)(uintptr_t) spl_image->entry_point;
		image_entry(IH_MAGIC, CONFIG_SPL_TEXT_BASE, 0, 0);
	} else {
		typedef void __noreturn (*image_entry_noargs_t)(void);
		image_entry_noargs_t image_entry =
			(image_entry_noargs_t)spl_image->entry_point;
		image_entry();
	}
