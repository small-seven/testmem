#include <common.h>
#include <command.h>
#include <dm.h>
#include <i2c.h>
#include <rtc.h>
#undef DEBUG_RTC
#ifdef DEBUG_RTC
#define DEBUGR(fmt,args...) printf(fmt ,##args)
#else
#define DEBUGR(fmt,args...)
#endif
#ifndef CONFIG_SYS_I2C_RTC_ADDR
# define CONFIG_SYS_I2C_RTC_ADDR	0x32
#endif
#ifdef CONFIG_DM_RTC
#define DEV_TYPE struct udevice
#else
#define DEV_TYPE struct ludevice
#endif
#define RTC_SEC_REG_ADDR	0x00
#define RTC_MIN_REG_ADDR	0x01
#define RTC_HR_REG_ADDR		0x02
#define RTC_DAY_REG_ADDR	0x03
#define RTC_DATE_REG_ADDR	0x04
#define RTC_MON_REG_ADDR	0x05
#define RTC_YR_REG_ADDR		0x06
#define RTC_CTL1_REG_ADDR	0x0e
#define RTC_CTL2_REG_ADDR	0x0f
#define RTC_CTL1_BIT_2412	0x20
#define RTC_CTL2_BIT_PON	0x10
#define RTC_CTL2_BIT_VDET	0x40
#define RTC_CTL2_BIT_XST	0x20
#define RTC_CTL2_BIT_VDSL	0x80
#ifdef CONFIG_DM_RTC
#define rtc_read(reg) buf[(reg) & 0xf]
#else
#define rtc_read(reg) buf[((reg) + 1) & 0xf]
#endif
#ifdef CONFIG_DM_RTC
#else
#endif
#ifdef CONFIG_DM_RTC
#else
#endif
#ifdef CONFIG_DM_RTC
#else
#endif
#ifdef CONFIG_DM_RTC
#else
#endif
