#include <common.h>
#include <command.h>
#include <dm.h>
#include <rtc.h>
#include <i2c.h>
#define RTC_SEC_REG_ADDR	0x0
#define RTC_MIN_REG_ADDR	0x1
#define RTC_HR_REG_ADDR		0x2
#define RTC_DAY_REG_ADDR	0x3
#define RTC_DATE_REG_ADDR	0x4
#define RTC_MON_REG_ADDR	0x5
#define RTC_YR_REG_ADDR		0x6
#define RTC_CTL_REG_ADDR	0x0e
#define RTC_STAT_REG_ADDR	0x0f
#define RTC_CTL_BIT_A1IE	0x1	/* Alarm 1 interrupt enable     */
#define RTC_CTL_BIT_A2IE	0x2	/* Alarm 2 interrupt enable     */
#define RTC_CTL_BIT_INTCN	0x4	/* Interrupt control            */
#define RTC_CTL_BIT_RS1		0x8	/* Rate select 1                */
#define RTC_CTL_BIT_RS2		0x10	/* Rate select 2                */
#define RTC_CTL_BIT_DOSC	0x80	/* Disable Oscillator           */
#define RTC_STAT_BIT_A1F	0x1	/* Alarm 1 flag                 */
#define RTC_STAT_BIT_A2F	0x2	/* Alarm 2 flag                 */
#define RTC_STAT_BIT_OSF	0x80	/* Oscillator stop flag         */
#define RTC_STAT_BIT_BB32KHZ	0x40	/* Battery backed 32KHz Output  */
#define RTC_STAT_BIT_EN32KHZ	0x8	/* Enable 32KHz Output  */
#if !CONFIG_IS_ENABLED(DM_RTC)
#ifdef CONFIG_RTC_ENABLE_32KHZ_OUTPUT
#endif
#else
#ifdef CONFIG_RTC_ENABLE_32KHZ_OUTPUT
#endif
#endif
