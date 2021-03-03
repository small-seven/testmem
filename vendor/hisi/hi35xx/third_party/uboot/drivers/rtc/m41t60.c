#include <common.h>
#include <command.h>
#include <env.h>
#include <rtc.h>
#include <i2c.h>
#define RTC_SEC		0x0
#define RTC_MIN		0x1
#define RTC_HOUR	0x2
#define RTC_DAY		0x3
#define RTC_DATE	0x4
#define RTC_MONTH	0x5
#define RTC_YEAR	0x6
#define RTC_REG_CNT	7
#define RTC_CTRL	0x7
#if defined(DEBUG)
#else
#define rtc_dump(label)
#endif
