#include <common.h>
#include <command.h>
#include <rtc.h>
#include <i2c.h>
#if defined CONFIG_RTC_DS1337
#define RTC_SEC_REG_ADDR	0x0
#define RTC_MIN_REG_ADDR	0x1
#define RTC_HR_REG_ADDR		0x2
#define RTC_DAY_REG_ADDR	0x3
#define RTC_DATE_REG_ADDR	0x4
#define RTC_MON_REG_ADDR	0x5
#define RTC_YR_REG_ADDR		0x6
#define RTC_CTL_REG_ADDR	0x0e
#define RTC_STAT_REG_ADDR	0x0f
#define RTC_TC_REG_ADDR		0x10
#elif defined CONFIG_RTC_DS1388
#define RTC_SEC_REG_ADDR	0x1
#define RTC_MIN_REG_ADDR	0x2
#define RTC_HR_REG_ADDR		0x3
#define RTC_DAY_REG_ADDR	0x4
#define RTC_DATE_REG_ADDR	0x5
#define RTC_MON_REG_ADDR	0x6
#define RTC_YR_REG_ADDR		0x7
#define RTC_CTL_REG_ADDR	0x0c
#define RTC_STAT_REG_ADDR	0x0b
#define RTC_TC_REG_ADDR		0x0a
#endif
#define RTC_CTL_BIT_A1IE	0x1	/* Alarm 1 interrupt enable	*/
#define RTC_CTL_BIT_A2IE	0x2	/* Alarm 2 interrupt enable	*/
#define RTC_CTL_BIT_INTCN	0x4	/* Interrupt control		*/
#define RTC_CTL_BIT_RS1		0x8	/* Rate select 1		*/
#define RTC_CTL_BIT_RS2		0x10	/* Rate select 2		*/
#define RTC_CTL_BIT_DOSC	0x80	/* Disable Oscillator		*/
#define RTC_STAT_BIT_A1F	0x1	/* Alarm 1 flag			*/
#define RTC_STAT_BIT_A2F	0x2	/* Alarm 2 flag			*/
#define RTC_STAT_BIT_OSF	0x80	/* Oscillator stop flag		*/
#ifdef CONFIG_RTC_DS1388
#endif
#ifdef CONFIG_RTC_DS1337_NOOSC
#else
#endif
#ifdef CONFIG_RTC_DS1337
#elif defined CONFIG_RTC_DS1388
#endif
#ifdef CONFIG_RTC_DS1339_TCR_VAL
#endif
#ifdef CONFIG_RTC_DS1388_TCR_VAL
#endif
