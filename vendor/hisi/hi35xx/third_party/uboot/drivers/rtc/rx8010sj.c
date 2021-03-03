#include <command.h>
#include <common.h>
#include <dm.h>
#include <i2c.h>
#include <rtc.h>
#ifdef DEBUG_RTC
#define DEBUGR(fmt, args...) printf(fmt, ##args)
#else
#define DEBUGR(fmt, args...)
#endif
#ifndef CONFIG_SYS_I2C_RTC_ADDR
# define CONFIG_SYS_I2C_RTC_ADDR	0x32
#endif
#define RX8010_SEC     0x10
#define RX8010_MIN     0x11
#define RX8010_HOUR    0x12
#define RX8010_WDAY    0x13
#define RX8010_MDAY    0x14
#define RX8010_MONTH   0x15
#define RX8010_YEAR    0x16
#define RX8010_YEAR    0x16
#define RX8010_RESV17  0x17
#define RX8010_ALMIN   0x18
#define RX8010_ALHOUR  0x19
#define RX8010_ALWDAY  0x1A
#define RX8010_TCOUNT0 0x1B
#define RX8010_TCOUNT1 0x1C
#define RX8010_EXT     0x1D
#define RX8010_FLAG    0x1E
#define RX8010_CTRL    0x1F
#define RX8010_RESV30  0x30
#define RX8010_RESV31  0x32
#define RX8010_IRQ     0x32
#define RX8010_EXT_WADA  BIT(3)
#define RX8010_FLAG_VLF  BIT(1)
#define RX8010_FLAG_AF   BIT(3)
#define RX8010_FLAG_TF   BIT(4)
#define RX8010_FLAG_UF   BIT(5)
#define RX8010_CTRL_AIE  BIT(3)
#define RX8010_CTRL_UIE  BIT(5)
#define RX8010_CTRL_STOP BIT(6)
#define RX8010_CTRL_TEST BIT(7)
#define RX8010_ALARM_AE  BIT(7)
#ifdef CONFIG_DM_RTC
#define DEV_TYPE struct udevice
#else
#define DEV_TYPE struct ludevice
#endif
#ifdef CONFIG_DM_RTC
#else
#endif
#ifdef CONFIG_DM_RTC
#else
#endif
#ifndef CONFIG_DM_RTC
#else
#endif
