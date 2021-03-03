#include <config.h>
#include <common.h>
#include <cpu_func.h>
#include <init.h>
#include <asm/io.h>
#include <asm/sections.h>
#include <mach/jz4780.h>
#include <mach/jz4780_dram.h>
#include <mmc.h>
#include <spl.h>
#ifdef CONFIG_SPL_BUILD
	typedef void __noreturn (*image_entry_noargs_t)(void);
	struct mmc *mmc;
	unsigned long count;
	struct image_header *header;
	int ret;

	/* Set global data pointer */
	gd = &gdata;

	timer_init();
	pll_init();
	sdram_init();
	enable_caches();

	/* Clear the BSS */
	memset(__bss_start, 0, (char *)&__bss_end - __bss_start);

	gd->flags |= GD_FLG_SPL_INIT;

	ret = mmc_initialize(NULL);
	if (ret)
		hang();

	mmc = find_mmc_device(BOOT_DEVICE_MMC1);
	if (ret)
		hang();

	ret = mmc_init(mmc);
	if (ret)
		hang();

	header = (struct image_header *)(CONFIG_SYS_TEXT_BASE -
					 sizeof(struct image_header));

	count = blk_dread(mmc_get_blk_desc(mmc),
			  CONFIG_SYS_MMCSD_RAW_MODE_U_BOOT_SECTOR,
		0x800, header);
	if (count == 0)
		hang();

	image_entry_noargs_t image_entry =
		(image_entry_noargs_t)CONFIG_SYS_TEXT_BASE;

	image_entry();

	hang();
}
#endif /* CONFIG_SPL_BUILD */
