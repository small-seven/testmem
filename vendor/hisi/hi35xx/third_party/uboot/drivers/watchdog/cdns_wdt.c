#include <common.h>
#include <dm.h>
#include <wdt.h>
#include <clk.h>
#include <div64.h>
#include <linux/io.h>
#define CDNS_WDT_DEFAULT_TIMEOUT	10
#define CDNS_WDT_MIN_TIMEOUT		1
#define CDNS_WDT_MAX_TIMEOUT		516
#define CDNS_WDT_RESTART_KEY		0x00001999
#define CDNS_WDT_REGISTER_ACCESS_KEY	0x00920000
#define CDNS_WDT_COUNTER_VALUE_DIVISOR	0x1000
#define CDNS_WDT_PRESCALE_64		64
#define CDNS_WDT_PRESCALE_512		512
#define CDNS_WDT_PRESCALE_4096		4096
#define CDNS_WDT_PRESCALE_SELECT_64	1
#define CDNS_WDT_PRESCALE_SELECT_512	2
#define CDNS_WDT_PRESCALE_SELECT_4096	3
#define CDNS_WDT_CLK_75MHZ	75000000
#define CDNS_WDT_COUNTER_MAX	0xFFF
#define CDNS_WDT_ZMR_WDEN_MASK	0x00000001 /* Enable the WDT */
#define CDNS_WDT_ZMR_RSTEN_MASK	0x00000002 /* Enable the reset output */
#define CDNS_WDT_ZMR_IRQEN_MASK	0x00000004 /* Enable IRQ output */
#define CDNS_WDT_ZMR_RSTLEN_16	0x00000030 /* Reset pulse of 16 pclk cycles */
#define CDNS_WDT_ZMR_ZKEY_VAL	0x00ABC000 /* Access key, 0xABC << 12 */
#define CDNS_WDT_CCR_CRV_MASK	0x00003FFC /* Counter reset value */
