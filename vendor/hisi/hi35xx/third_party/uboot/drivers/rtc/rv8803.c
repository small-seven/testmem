#include <common.h>
#include <command.h>
#include <dm.h>
#include <rtc.h>
#include <i2c.h>
#define RTC_SEC_REG_ADDR	0x00
#define RTC_MIN_REG_ADDR	0x01
#define RTC_HR_REG_ADDR		0x02
#define RTC_DAY_REG_ADDR	0x03
#define RTC_DATE_REG_ADDR	0x04
#define RTC_MON_REG_ADDR	0x05
#define RTC_YR_REG_ADDR		0x06
#define RTC_FLAG_REG_ADDR	0x0E
#define RTC_FLAG_BIT_V1F	BIT(0)
#define RTC_FLAG_BIT_V2F	BIT(1)
#define RTC_CTL_REG_ADDR	0x0F
#define RTC_CTL_BIT_RST		BIT(0)
