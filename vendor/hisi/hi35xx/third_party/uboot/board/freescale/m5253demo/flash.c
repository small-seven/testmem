#include <common.h>
#include <irq_func.h>
#include <asm/immap.h>
#ifndef CONFIG_SYS_FLASH_CFI
typedef unsigned short FLASH_PORT_WIDTH;
typedef volatile unsigned short FLASH_PORT_WIDTHV;

#define FPW             FLASH_PORT_WIDTH
#define FPWV            FLASH_PORT_WIDTHV

#define FLASH_CYCLE1    0x5555
#define FLASH_CYCLE2    0x2aaa

#define SYNC			__asm__("nop")

/*-----------------------------------------------------------------------
 * Functions
 */

ulong flash_get_size(FPWV * addr, flash_info_t * info);
int flash_get_offsets(ulong base, flash_info_t * info);
int write_word(flash_info_t * info, FPWV * dest, u16 data);
static inline void spin_wheel(void);

flash_info_t flash_info[CONFIG_SYS_MAX_FLASH_BANKS];

ulong flash_init(void)
{
	ulong size = 0;
	ulong fbase = 0;

	fbase = (ulong) CONFIG_SYS_FLASH_BASE;
	flash_get_size((FPWV *) fbase, &flash_info[0]);
	flash_get_offsets((ulong) fbase, &flash_info[0]);
	fbase += flash_info[0].size;
	size += flash_info[0].size;

	/* Protect monitor and environment sectors */
	flash_protect(FLAG_PROTECT_SET,
		      CONFIG_SYS_MONITOR_BASE,
		      CONFIG_SYS_MONITOR_BASE + monitor_flash_len - 1, &flash_info[0]);

	return size;
}
#endif
