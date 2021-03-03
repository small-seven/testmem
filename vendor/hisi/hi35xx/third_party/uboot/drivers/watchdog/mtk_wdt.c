#include <common.h>
#include <dm.h>
#include <wdt.h>
#include <asm/io.h>
#define MTK_WDT_MODE			0x00
#define MTK_WDT_LENGTH			0x04
#define MTK_WDT_RESTART			0x08
#define MTK_WDT_STATUS			0x0c
#define MTK_WDT_INTERVAL		0x10
#define MTK_WDT_SWRST			0x14
#define MTK_WDT_REQ_MODE		0x30
#define MTK_WDT_DEBUG_CTL		0x40
#define WDT_MODE_KEY			(0x22 << 24)
#define WDT_MODE_EN			BIT(0)
#define WDT_MODE_EXTPOL			BIT(1)
#define WDT_MODE_EXTEN			BIT(2)
#define WDT_MODE_IRQ_EN			BIT(3)
#define WDT_MODE_DUAL_EN		BIT(6)
#define WDT_LENGTH_KEY			0x8
#define WDT_LENGTH_TIMEOUT(n)		((n) << 5)
#define WDT_RESTART_KEY			0x1971
#define WDT_SWRST_KEY			0x1209
