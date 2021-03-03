#include <common.h>
#include <mpc83xx.h>
#include <spd_sdram.h>
#include <asm/bitops.h>
#include <asm/io.h>
#include <asm/processor.h>
	typedef void (*func_t)(void);
	func_t resume = *(func_t *)4;

	if (magic == 0xf5153ae5)
		resume();

	gd->flags &= ~GD_FLG_SILENT;
	puts("\nResume from sleep failed: bad magic word\n");
}
#ifndef CONFIG_SYS_RAMBOOT
#else
#endif /* CONFIG_SYS_RAMBOOT */
