#include <common.h>
#include <mpc83xx.h>
#include <spd_sdram.h>
#include <asm/bitops.h>
#include <asm/io.h>
#include <asm/processor.h>
#ifndef CONFIG_SYS_8313ERDB_BROKEN_PMC
	typedef void (*func_t)(void);
	func_t resume = *(func_t *)4;

	if (magic == 0xf5153ae5)
		resume();

	gd->flags &= ~GD_FLG_SILENT;
	puts("\nResume from sleep failed: bad magic word\n");
}
#endif
#ifndef CONFIG_SYS_RAMBOOT
#if ((CONFIG_SYS_SDRAM_BASE & 0x00FFFFFF) != 0)
#warning Chip select bounds is only configurable in 16MB increments
#endif
#ifndef CONFIG_SYS_8313ERDB_BROKEN_PMC
#endif
#endif
#ifndef CONFIG_SYS_8313ERDB_BROKEN_PMC
#endif
