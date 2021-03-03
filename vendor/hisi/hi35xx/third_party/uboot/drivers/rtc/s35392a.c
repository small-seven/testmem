#include <command.h>
#include <common.h>
#include <dm.h>
#include <i2c.h>
#include <linux/bitrev.h>
#include <rtc.h>
#define S35390A_CMD_STATUS1		0x30
#define S35390A_CMD_STATUS2		0x31
#define S35390A_CMD_TIME1		0x32
#define S35390A_CMD_TIME2		0x33
#define S35390A_CMD_INT2_REG1	0x35
#define S35390A_BYTE_YEAR	0
#define S35390A_BYTE_MONTH	1
#define S35390A_BYTE_DAY	2
#define S35390A_BYTE_WDAY	3
#define S35390A_BYTE_HOURS	4
#define S35390A_BYTE_MINS	5
#define S35390A_BYTE_SECS	6
#define S35390A_FLAG_POC	0x01
#define S35390A_FLAG_BLD	0x02
#define S35390A_FLAG_INT2	0x04
#define S35390A_FLAG_24H	0x40
#define S35390A_FLAG_RESET	0x80
#define S35390A_LOW_VOLTAGE (S35390A_FLAG_POC | S35390A_FLAG_BLD)
#undef DEBUG_RTC
#ifdef DEBUG_RTC
#define DEBUGR(fmt, args...) printf(fmt, ##args)
#else
#define DEBUGR(fmt, args...)
#endif
#ifdef CONFIG_DM_RTC
#define DEV_TYPE struct udevice
#else
#define DEV_TYPE struct ludevice
#endif
#define msleep(a) udelay(a * 1000)
#ifdef CONFIG_DM_RTC
#else
#endif
#ifdef CONFIG_DM_RTC
#else
#endif
#ifndef CONFIG_DM_RTC
#else
#endif
