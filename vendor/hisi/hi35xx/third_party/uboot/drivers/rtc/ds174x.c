#include <common.h>
#include <command.h>
#include <rtc.h>
#define RTC_BASE		( CONFIG_SYS_NVRAM_SIZE + CONFIG_SYS_NVRAM_BASE_ADDR )
#define RTC_YEAR		( RTC_BASE + 7 )
#define RTC_MONTH		( RTC_BASE + 6 )
#define RTC_DAY_OF_MONTH	( RTC_BASE + 5 )
#define RTC_DAY_OF_WEEK		( RTC_BASE + 4 )
#define RTC_HOURS		( RTC_BASE + 3 )
#define RTC_MINUTES		( RTC_BASE + 2 )
#define RTC_SECONDS		( RTC_BASE + 1 )
#define RTC_CENTURY		( RTC_BASE + 0 )
#define RTC_CONTROLA		RTC_CENTURY
#define RTC_CONTROLB		RTC_SECONDS
#define RTC_CONTROLC		RTC_DAY_OF_WEEK
#define RTC_CA_WRITE		0x80
#define RTC_CA_READ		0x40
#define RTC_CB_OSC_DISABLE	0x80
#define RTC_CC_BATTERY_FLAG	0x80
#define RTC_CC_FREQ_TEST	0x40
#ifdef RTC_DEBUG
#endif
#ifdef RTC_DEBUG
#endif
#ifdef RTC_DEBUG
#endif
#ifdef RTC_DEBUG
#endif
#ifdef RTC_DEBUG
#endif
