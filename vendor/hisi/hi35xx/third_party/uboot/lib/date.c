#include <common.h>
#include <command.h>
#include <errno.h>
#include <rtc.h>
#include <linux/time.h>
#if defined(CONFIG_LIB_DATE) || defined(CONFIG_TIMESTAMP)
#define FEBRUARY		2
#define	STARTOFTIME		1970
#define SECDAY			86400L
#define SECYR			(SECDAY * 365)
#define	leapyear(year)		((year) % 4 == 0)
#define	days_in_year(a)		(leapyear(a) ? 366 : 365)
#define	days_in_month(a)	(month_days[(a) - 1])
#endif /* CONFIG_LIB_DATE || CONFIG_TIMESTAMP */
#ifdef CONFIG_LIB_DATE
#endif
