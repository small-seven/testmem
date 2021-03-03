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
#define RTC_CTL_REG_ADDR	0x07
#define RTC_SEC_BIT_CH		0x80	/* Clock Halt (in Register 0)   */
#define RTC_CTL_BIT_RS0		0x01	/* Rate select 0                */
#define RTC_CTL_BIT_RS1		0x02	/* Rate select 1                */
#define RTC_CTL_BIT_SQWE	0x10	/* Square Wave Enable           */
#define RTC_CTL_BIT_OUT		0x80	/* Output Control               */
#define MCP7941X_BIT_ST		0x80
#define MCP7941X_BIT_VBATEN	0x08
#ifndef CONFIG_DM_RTC
#undef DEBUG_RTC
#ifdef DEBUG_RTC
#define DEBUGR(fmt, args...) printf(fmt, ##args)
#else
#define DEBUGR(fmt, args...)
#endif
#ifndef CONFIG_SYS_I2C_RTC_ADDR
# define CONFIG_SYS_I2C_RTC_ADDR	0x68
#endif
#if defined(CONFIG_RTC_DS1307) && (CONFIG_SYS_I2C_SPEED > 100000)
# error The DS1307 is specified only up to 100kHz!
#endif
#ifdef CONFIG_RTC_MCP79411
#endif
#ifdef CONFIG_RTC_DS1307
#endif
#ifdef CONFIG_RTC_MCP79411
#endif
#ifdef CONFIG_RTC_MCP79411
#else
#endif
#ifdef CONFIG_RTC_MCP79411
#else
#endif
#endif /* !CONFIG_DM_RTC */
#ifdef CONFIG_DM_RTC
#endif /* CONFIG_DM_RTC */
