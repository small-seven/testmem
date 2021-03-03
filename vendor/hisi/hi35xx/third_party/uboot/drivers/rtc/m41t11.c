#include <common.h>
#include <command.h>
#include <rtc.h>
#include <i2c.h>
#define CONFIG_RTC_M41T11 1
#define CONFIG_SYS_I2C_RTC_ADDR 0x68
#if 0
#define CONFIG_SYS_M41T11_EXT_CENTURY_DATA
#else
#define CONFIG_SYS_M41T11_BASE_YEAR 2000
#endif
#define RTC_SEC_ADDR       0x0
#define RTC_MIN_ADDR       0x1
#define RTC_HOUR_ADDR      0x2
#define RTC_DAY_ADDR       0x3
#define RTC_DATE_ADDR      0x4
#define RTC_MONTH_ADDR     0x5
#define RTC_YEARS_ADDR     0x6
#define RTC_REG_CNT        7
#define RTC_CONTROL_ADDR   0x7
#ifndef CONFIG_SYS_M41T11_EXT_CENTURY_DATA
#define REG_CNT            (RTC_REG_CNT+1)
#ifndef CONFIG_SYS_M41T11_BASE_YEAR
#define CONFIG_SYS_M41T11_BASE_YEAR 2000
#endif
#else
#define M41T11_YEAR_DATA   0x8
#define M41T11_YEAR_SIZE   1
#define REG_CNT            (RTC_REG_CNT+1+M41T11_YEAR_SIZE)
#endif
#define M41T11_STORAGE_SZ  (64-REG_CNT)
#ifndef CONFIG_SYS_M41T11_EXT_CENTURY_DATA
#else
#endif
#ifndef CONFIG_SYS_M41T11_EXT_CENTURY_DATA
#else
#endif
