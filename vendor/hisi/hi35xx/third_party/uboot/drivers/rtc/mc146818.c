#include <common.h>
#include <command.h>
#include <dm.h>
#include <rtc.h>
#if defined(CONFIG_X86) || defined(CONFIG_MALTA)
#include <asm/io.h>
#define in8(p) inb(p)
#define out8(p, v) outb(v, p)
#endif
#define CLEAR_CMOS		0
#define RTC_PORT_MC146818	CONFIG_SYS_ISA_IO_BASE_ADDRESS + 0x70
#define RTC_SECONDS		0x00
#define RTC_SECONDS_ALARM	0x01
#define RTC_MINUTES		0x02
#define RTC_MINUTES_ALARM	0x03
#define RTC_HOURS		0x04
#define RTC_HOURS_ALARM		0x05
#define RTC_DAY_OF_WEEK		0x06
#define RTC_DATE_OF_MONTH	0x07
#define RTC_MONTH		0x08
#define RTC_YEAR		0x09
#define RTC_CONFIG_A		0x0a
#define RTC_CONFIG_B		0x0b
#define RTC_CONFIG_C		0x0c
#define RTC_CONFIG_D		0x0d
#define RTC_REG_SIZE		0x80
#define RTC_CONFIG_A_REF_CLCK_32KHZ	(1 << 5)
#define RTC_CONFIG_A_RATE_1024HZ	6
#define RTC_CONFIG_B_24H		(1 << 1)
#define RTC_CONFIG_D_VALID_RAM_AND_TIME	0x80
#ifdef CONFIG_SYS_RTC_REG_BASE_ADDR
#else
#endif
#ifdef CONFIG_SYS_RTC_REG_BASE_ADDR
#else
#endif
#ifdef RTC_DEBUG
#endif
#ifdef RTC_DEBUG
#endif
#ifdef RTC_DEBUG
#endif
#if CLEAR_CMOS
#endif
#ifdef CONFIG_DM_RTC
#else /* !CONFIG_DM_RTC */
#endif /* CONFIG_DM_RTC */
