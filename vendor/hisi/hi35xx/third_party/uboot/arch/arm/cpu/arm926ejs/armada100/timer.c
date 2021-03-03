#include <common.h>
#include <time.h>
#include <asm/arch/cpu.h>
#include <asm/arch/armada100.h>
#define TIMER			0	/* Use TIMER 0 */
#define MATCH_CMP(x)		((3 * TIMER) + x)
#define TIMER_LOAD_VAL 		0xffffffff
#define	COUNT_RD_REQ		0x1
#define MPMU_APRR_WDTR	(1<<4)
#define TMR_WFAR	0xbaba	/* WDT Register First key */
#define TMP_WSAR	0xeb10	/* WDT Register Second key */
