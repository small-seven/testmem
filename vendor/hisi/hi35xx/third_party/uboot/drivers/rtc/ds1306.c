#include <common.h>
#include <command.h>
#include <rtc.h>
#include <spi.h>
#define	RTC_SECONDS		0x00
#define	RTC_MINUTES		0x01
#define	RTC_HOURS		0x02
#define	RTC_DAY_OF_WEEK		0x03
#define	RTC_DATE_OF_MONTH	0x04
#define	RTC_MONTH		0x05
#define	RTC_YEAR		0x06
#define	RTC_SECONDS_ALARM0	0x07
#define	RTC_MINUTES_ALARM0	0x08
#define	RTC_HOURS_ALARM0	0x09
#define	RTC_DAY_OF_WEEK_ALARM0	0x0a
#define	RTC_SECONDS_ALARM1	0x0b
#define	RTC_MINUTES_ALARM1	0x0c
#define	RTC_HOURS_ALARM1	0x0d
#define	RTC_DAY_OF_WEEK_ALARM1	0x0e
#define	RTC_CONTROL		0x0f
#define	RTC_STATUS		0x10
#define	RTC_TRICKLE_CHARGER	0x11
#define	RTC_USER_RAM_BASE	0x20
#ifdef CONFIG_SXNI855T		/* !!! SHOULD BE CHANGED TO NEW CODE !!! */
#define	PB_SPISCK	0x00000002	/* PB 30 */
#define PB_SPIMOSI	0x00000004	/* PB 29 */
#define PB_SPIMISO	0x00000008	/* PB 28 */
#define PB_SPI_CE	0x00010000	/* PB 15 */
#else  /* not CONFIG_SXNI855T */
#endif /* end of code exclusion (see #ifdef CONFIG_SXNI855T above) */
