#include <common.h>
#include <command.h>
#include <rtc.h>
#define RTC_EPOCH                 2000	/* century */
#define RTC_BASE		( CONFIG_SYS_NVRAM_BASE_ADDR + CONFIG_SYS_NVRAM_SIZE )
#define RTC_YEAR		( RTC_BASE + 0x07 )
#define RTC_MONTH		( RTC_BASE + 0x06 )
#define RTC_DAY_OF_MONTH	( RTC_BASE + 0x05 )
#define RTC_DAY_OF_WEEK		( RTC_BASE + 0x04 )
#define RTC_HOURS		( RTC_BASE + 0x03 )
#define RTC_MINUTES		( RTC_BASE + 0x02 )
#define RTC_SECONDS		( RTC_BASE + 0x01 )
#define RTC_CONTROL		( RTC_BASE + 0x00 )
#define RTC_CONTROLA		RTC_CONTROL	/* W=bit6, R=bit5 */
#define   RTC_CA_WRITE		  0x80
#define   RTC_CA_READ		  0x40
#define RTC_CONTROLB		RTC_SECONDS	/* OSC=bit7       */
#define   RTC_CB_OSC_DISABLE	  0x80
#define RTC_CONTROLC		RTC_DAY_OF_WEEK	/* FT=bit6        */
#define   RTC_CC_FREQ_TEST	  0x40
#ifdef RTC_DEBUG
#endif
#ifdef RTC_DEBUG
#endif
#ifdef RTC_DEBUG
#endif
#ifdef RTC_DEBUG
#endif
#ifdef RTC_DEBUG
#endif
