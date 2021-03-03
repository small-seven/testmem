#include <common.h>
#include <command.h>
#include <rtc.h>
#if defined(CONFIG_CMD_DATE)
#define RTC_BASE		( CONFIG_SYS_NVRAM_SIZE + CONFIG_SYS_NVRAM_BASE_ADDR )
#define RTC_YEAR		( RTC_BASE + 0xf )
#define RTC_MONTH		( RTC_BASE + 0xe )
#define RTC_DAY_OF_MONTH	( RTC_BASE + 0xd )
#define RTC_DAY_OF_WEEK		( RTC_BASE + 0xc )
#define RTC_HOURS		( RTC_BASE + 0xb )
#define RTC_MINUTES		( RTC_BASE + 0xa )
#define RTC_SECONDS		( RTC_BASE + 0x9 )
#define RTC_CENTURY		( RTC_BASE + 0x8 )
#define RTC_CONTROLA		RTC_CENTURY
#define RTC_CONTROLB		RTC_SECONDS
#define RTC_CONTROLC		RTC_BASE
#define RTC_CA_WRITE		0x80
#define RTC_CA_READ		0x40
#define RTC_CB_OSC_DISABLE	0x80
#define RTC_CC_BATTERY_FLAG	0x10
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
#endif
