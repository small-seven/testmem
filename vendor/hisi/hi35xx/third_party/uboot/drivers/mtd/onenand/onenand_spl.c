#include <common.h>
#include <asm/io.h>
#include <linux/mtd/onenand_regs.h>
#include <onenand_uboot.h>
#define ONENAND_PAGES_PER_BLOCK			64
#define onenand_sector_address(page)		(page << 2)
#define onenand_buffer_address()		((1 << 3) << 8)
#ifdef CONFIG_SPL_UBI
#endif
