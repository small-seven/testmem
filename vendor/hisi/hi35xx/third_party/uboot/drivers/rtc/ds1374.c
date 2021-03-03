#include <common.h>
#include <command.h>
#include <rtc.h>
#include <i2c.h>
#undef DEBUG_RTC
#define DEBUG_RTC
#ifdef DEBUG_RTC
#define DEBUGR(fmt,args...) printf(fmt ,##args)
#else
#define DEBUGR(fmt,args...)
#endif
#ifndef CONFIG_SYS_I2C_RTC_ADDR
# define CONFIG_SYS_I2C_RTC_ADDR	0x68
#endif
#if defined(CONFIG_RTC_DS1374) && (CONFIG_SYS_I2C_SPEED > 400000)
# error The DS1374 is specified up to 400kHz in fast mode!
#endif
#define RTC_TOD_CNT_BYTE0_ADDR		0x00 /* TimeOfDay */
#define RTC_TOD_CNT_BYTE1_ADDR		0x01
#define RTC_TOD_CNT_BYTE2_ADDR		0x02
#define RTC_TOD_CNT_BYTE3_ADDR		0x03
#define RTC_WD_ALM_CNT_BYTE0_ADDR	0x04
#define RTC_WD_ALM_CNT_BYTE1_ADDR	0x05
#define RTC_WD_ALM_CNT_BYTE2_ADDR	0x06
#define RTC_CTL_ADDR			0x07 /* RTC-CoNTrol-register */
#define RTC_SR_ADDR			0x08 /* RTC-StatusRegister */
#define RTC_TCS_DS_ADDR			0x09 /* RTC-TrickleChargeSelect DiodeSelect-register */
#define RTC_CTL_BIT_AIE			(1<<0) /* Bit 0 - Alarm Interrupt enable */
#define RTC_CTL_BIT_RS1			(1<<1) /* Bit 1/2 - Rate Select square wave output */
#define RTC_CTL_BIT_RS2			(1<<2) /* Bit 2/2 - Rate Select square wave output */
#define RTC_CTL_BIT_WDSTR		(1<<3) /* Bit 3 - Watchdog Reset Steering */
#define RTC_CTL_BIT_BBSQW		(1<<4) /* Bit 4 - Battery-Backed Square-Wave */
#define RTC_CTL_BIT_WD_ALM		(1<<5) /* Bit 5 - Watchdoc/Alarm Counter Select */
#define RTC_CTL_BIT_WACE		(1<<6) /* Bit 6 - Watchdog/Alarm Counter Enable WACE*/
#define RTC_CTL_BIT_EN_OSC		(1<<7) /* Bit 7 - Enable Oscilator */
#define RTC_SR_BIT_AF			0x01 /* Bit 0 = Alarm Flag */
#define RTC_SR_BIT_OSF			0x80 /* Bit 7 - Osc Stop Flag */
