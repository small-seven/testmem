#include <common.h>
#include <command.h>
#include <rtc.h>
#include <i2c.h>
#define RTC_SEC_REG_ADDR        0x0
#define RTC_MIN_REG_ADDR        0x1
#define RTC_HR_REG_ADDR         0x2
#define RTC_DAY_REG_ADDR        0x3
#define RTC_DATE_REG_ADDR       0x4
#define RTC_MON_REG_ADDR        0x5
#define RTC_YR_REG_ADDR         0x6
#define RTC_CTL_STAT_REG_ADDR   0x7
#define RTC_SEC_BIT_CH		0x80	/* Clock Halt (in Register 0) */
#define RTC_CTL_STAT_BIT_RS0    0x1	/* Rate select 0 */
#define RTC_CTL_STAT_BIT_RS1    0x2	/* Rate select 1 */
#define RTC_CTL_STAT_BIT_SQWE   0x10	/* Square Wave Enable */
#define RTC_CTL_STAT_BIT_OSF    0x20	/* Oscillator Stop Flag */
#define RTC_CTL_STAT_BIT_OUT    0x80	/* Output Level Control */
#define RTC_PT7C4338_RESET_VAL \
