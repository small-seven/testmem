#include <common.h>
#include <ioports.h>
#include <mpc83xx.h>
#include <asm/mpc8349_pci.h>
#include <i2c.h>
#include <miiphy.h>
#include <asm/mmu.h>
#include <pci.h>
#include <flash.h>
#include <mtd/cfi_flash.h>
#define IOSYNC			asm("eieio")
#define ISYNC			asm("isync")
#define SYNC			asm("sync")
#define FPW			FLASH_PORT_WIDTH
#define FPWV			FLASH_PORT_WIDTHV
#define DDR_MAX_SIZE_PER_CS	0x20000000
#if defined(DDR_CASLAT_20)
#define TIMING_CASLAT		TIMING_CFG1_CASLAT_20
#define MODE_CASLAT		DDR_MODE_CASLAT_20
#else
#define TIMING_CASLAT		TIMING_CFG1_CASLAT_25
#define MODE_CASLAT		DDR_MODE_CASLAT_25
#endif
#define INITIAL_CS_CONFIG	(CSCONFIG_EN | CSCONFIG_ROW_BIT_12 | \
#ifdef CONFIG_PCI
#else
#endif
	typedef unsigned long FLASH_PORT_WIDTH;
	typedef volatile unsigned long FLASH_PORT_WIDTHV;
	FPWV *bank1_base;
	FPWV *bank2_base;
	FPW bank1_read;
	FPW bank2_read;
	ulong bank1_size;
	ulong bank2_size;
	ulong total_size;

	cfi_flash_num_flash_banks = 2;	/* assume two banks */

	/* Get bank 1 and 2 information */
	bank1_size = flash_get_size(CONFIG_SYS_FLASH_BASE, 0);
	debug("Bank1 size: %lu\n", bank1_size);
	bank2_size = flash_get_size(CONFIG_SYS_FLASH_BASE + bank1_size, 1);
	debug("Bank2 size: %lu\n", bank2_size);
	total_size = bank1_size + bank2_size;

	if (bank2_size > 0) {
		/* Seems like we've got bank 2, but maybe it's mirrored 1 */

		/* Set the base addresses */
		bank1_base = (FPWV *) (CONFIG_SYS_FLASH_BASE);
		bank2_base = (FPWV *) (CONFIG_SYS_FLASH_BASE + bank1_size);

		/* Put bank 2 into CFI command mode and read */
		bank2_base[0x55] = 0x00980098;
		IOSYNC;
		ISYNC;
		bank2_read = bank2_base[0x10];

		/* Read from bank 1 (it's in read mode) */
		bank1_read = bank1_base[0x10];

		/* Reset Flash */
		bank1_base[0] = 0x00F000F0;
		bank2_base[0] = 0x00F000F0;

		if (bank2_read == bank1_read) {
			/*
			 * Looks like just one bank, but not sure yet. Let's
			 * read from bank 2 in autosoelect mode.
			 */
			bank2_base[0x0555] = 0x00AA00AA;
			bank2_base[0x02AA] = 0x00550055;
			bank2_base[0x0555] = 0x00900090;
			IOSYNC;
			ISYNC;
			bank2_read = bank2_base[0x10];

			/* Read from bank 1 (it's in read mode) */
			bank1_read = bank1_base[0x10];

			/* Reset Flash */
			bank1_base[0] = 0x00F000F0;
			bank2_base[0] = 0x00F000F0;

			if (bank2_read == bank1_read) {
				/*
				 * In both CFI command and autoselect modes,
				 * we got the some data reading from Flash.
				 * There is only one mirrored bank.
				 */
				cfi_flash_num_flash_banks = 1;
				total_size = bank1_size;
			}
#if defined(DDR_CASLAT_20)
#else
#endif
#ifdef CONFIG_OF_BOARD_SETUP
#ifdef CONFIG_PCI
#endif	/* CONFIG_PCI */
#endif	/* CONFIG_OF_BOARD_SETUP */
