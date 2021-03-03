#include <common.h>
#include <command.h>
#include <rtc.h>
#define DATA		0x200
#define SCLK		0x400
#define RST		0x800
#define RESET		rtc_go_low(RST), rtc_go_low(SCLK)
#define N_RESET		rtc_go_high(RST), rtc_go_low(SCLK)
#define CLOCK_HIGH	rtc_go_high(SCLK)
#define CLOCK_LOW	rtc_go_low(SCLK)
#define DATA_HIGH	rtc_go_high(DATA)
#define DATA_LOW	rtc_go_low(DATA)
#define DATA_READ	(GTREGREAD(GPP_VALUE) & DATA)
#undef RTC_DEBUG
#ifdef RTC_DEBUG
#  define DPRINTF(x,args...)	printf("ds1302: " x , ##args)
#else
#  define DPRINTF(x,args...)
#  define DUMP(ptr, num)
#endif
#ifdef RTC_DEBUG
#endif
