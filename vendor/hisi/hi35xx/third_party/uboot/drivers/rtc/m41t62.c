#include <common.h>
#include <command.h>
#include <dm.h>
#include <rtc.h>
#include <i2c.h>
#define M41T62_REG_SSEC	0
#define M41T62_REG_SEC	1
#define M41T62_REG_MIN	2
#define M41T62_REG_HOUR	3
#define M41T62_REG_WDAY	4
#define M41T62_REG_DAY	5
#define M41T62_REG_MON	6
#define M41T62_REG_YEAR	7
#define M41T62_REG_ALARM_MON	0xa
#define M41T62_REG_ALARM_DAY	0xb
#define M41T62_REG_ALARM_HOUR	0xc
#define M41T62_REG_ALARM_MIN	0xd
#define M41T62_REG_ALARM_SEC	0xe
#define M41T62_REG_FLAGS	0xf
#define M41T62_DATETIME_REG_SIZE	(M41T62_REG_YEAR + 1)
#define M41T62_ALARM_REG_SIZE	\
#define M41T62_SEC_ST		(1 << 7)	/* ST: Stop Bit */
#define M41T62_ALMON_AFE	(1 << 7)	/* AFE: AF Enable Bit */
#define M41T62_ALMON_SQWE	(1 << 6)	/* SQWE: SQW Enable Bit */
#define M41T62_ALHOUR_HT	(1 << 6)	/* HT: Halt Update Bit */
#define M41T62_FLAGS_AF		(1 << 6)	/* AF: Alarm Flag Bit */
#define M41T62_FLAGS_BATT_LOW	(1 << 4)	/* BL: Battery Low Bit */
#define M41T62_FEATURE_HT	(1 << 0)
#define M41T62_FEATURE_BL	(1 << 1)
#define M41T80_ALHOUR_HT	(1 << 6)	/* HT: Halt Update Bit */
#ifdef CONFIG_DM_RTC
#else /* NON DM RTC code - will be removed */
#endif /* CONFIG_DM_RTC */
