#include <asm/io.h>
#include <common.h>
#include <dm/device.h>
#include <dm/fdtaddr.h>
#include <dm/read.h>
#include <linux/bitops.h>
#include <watchdog.h>
#include <wdt.h>
#define WDTLOAD			0x000
#define WDTCONTROL		0x008
#define WDTINTCLR		0x00C
#define WDTLOCK			0xC00
#define TIME_OUT_MIN_MSECS	1
#define TIME_OUT_MAX_MSECS	120000
#define SYS_FSL_WDT_CLK_DIV	16
#define INT_ENABLE		BIT(0)
#define RESET_ENABLE		BIT(1)
#define DISABLE			0
#define UNLOCK			0x1ACCE551
#define LOCK			0x00000001
#define INT_MASK		BIT(0)
