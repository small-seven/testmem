#include <common.h>
#include <asm/io.h>
#include <asm/arch/imx-regs.h>
#ifndef CONFIG_WATCHDOG_TIMEOUT_MSECS
#define CONFIG_WATCHDOG_TIMEOUT_MSECS 0x1500
#endif
#define REFRESH_WORD0 0xA602 /* 1st refresh word */
#define REFRESH_WORD1 0xB480 /* 2nd refresh word */
#define UNLOCK_WORD0 0xC520 /* 1st unlock word */
#define UNLOCK_WORD1 0xD928 /* 2nd unlock word */
#define WDGCS1_WDGE                      (1<<7)
#define WDGCS1_WDGUPDATE                 (1<<5)
#define WDGCS2_FLG                       (1<<6)
#define WDG_BUS_CLK                      (0x0)
#define WDG_LPO_CLK                      (0x1)
#define WDG_32KHZ_CLK                    (0x2)
#define WDG_EXT_CLK                      (0x3)
