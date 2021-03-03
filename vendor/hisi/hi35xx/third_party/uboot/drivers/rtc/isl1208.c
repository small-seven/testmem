#include <common.h>
#include <command.h>
#include <dm.h>
#include <rtc.h>
#include <i2c.h>
#ifdef DEBUG_RTC
#define DEBUGR(fmt,args...) printf(fmt ,##args)
#else
#define DEBUGR(fmt,args...)
#endif
#define RTC_SEC_REG_ADDR	0x0
#define RTC_MIN_REG_ADDR	0x1
#define RTC_HR_REG_ADDR		0x2
#define RTC_DATE_REG_ADDR	0x3
#define RTC_MON_REG_ADDR	0x4
#define RTC_YR_REG_ADDR		0x5
#define RTC_DAY_REG_ADDR	0x6
#define RTC_STAT_REG_ADDR	0x7
#define RTC_STAT_BIT_ARST	0x80	/* AUTO RESET ENABLE BIT */
#define RTC_STAT_BIT_XTOSCB	0x40	/* CRYSTAL OSCILLATOR ENABLE BIT */
#define RTC_STAT_BIT_WRTC	0x10	/* WRITE RTC ENABLE BIT */
#define RTC_STAT_BIT_ALM	0x04	/* ALARM BIT */
#define RTC_STAT_BIT_BAT	0x02	/* BATTERY BIT */
#define RTC_STAT_BIT_RTCF	0x01	/* REAL TIME CLOCK FAIL BIT */
