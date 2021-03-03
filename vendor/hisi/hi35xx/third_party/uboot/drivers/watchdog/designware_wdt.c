#include <common.h>
#include <watchdog.h>
#include <asm/io.h>
#include <asm/utils.h>
#define DW_WDT_CR	0x00
#define DW_WDT_TORR	0x04
#define DW_WDT_CRR	0x0C
#define DW_WDT_CR_EN_OFFSET	0x00
#define DW_WDT_CR_RMOD_OFFSET	0x01
#define DW_WDT_CR_RMOD_VAL	0x00
#define DW_WDT_CRR_RESTART_VAL	0x76
#if defined(CONFIG_HW_WATCHDOG)
#endif
