#include <common.h>
#include <command.h>
#include <rtc.h>
#include <i2c.h>
#define DEBUG 0
#if DEBUG
#else
#define rtc_debug 0	/* gcc will remove all the debug code for us */
#endif
#ifndef CONFIG_SYS_I2C_RTC_ADDR
#define CONFIG_SYS_I2C_RTC_ADDR 0x32
#endif
#define RS5C372_RAM_SIZE 0x10
#define RATE_32000HZ	0x80	/* Rate Select 32.000KHz */
#define RATE_32768HZ	0x00	/* Rate Select 32.768KHz */
#define STATUS_XPT  0x10    /* data invalid because voltage was 0 */
#define USE_24HOUR_MODE 0x20
#define TWELVE_HOUR_MODE(n) ((((n) >> 5) & 1) == 0)
#define HOURS_AP(n)	(((n) >> 5) & 1)
#define HOURS_12(n)	bcd2bin((n) & 0x1F)
#define HOURS_24(n)	bcd2bin((n) & 0x3F)
