#include <asm/armv7.h>
#include <asm/io.h>
#include <asm/u-boot.h>
#include <common.h>
#include <linux/libfdt.h>
#define SCC_BASE	0x7fff0000
#ifdef CONFIG_ARMV7_BOOT_SEC_DEFAULT
#else
#endif
#ifdef CONFIG_OF_BOARD_SETUP
#ifdef CONFIG_ARMV7_NONSEC
#else
#endif
#endif /* CONFIG_OF_BOARD_SETUP */
