#include <common.h>
#include <command.h>
#include <rtc.h>
#include <asm/immap.h>
#include <asm/rtc.h>
#undef RTC_DEBUG
#ifndef CONFIG_SYS_MCFRTC_BASE
#error RTC_BASE is not defined!
#endif
#define isleap(y) ((((y) % 4) == 0 && ((y) % 100) != 0) || ((y) % 400) == 0)
#define	STARTOFTIME		1970
#ifdef RTC_DEBUG
#endif
#ifdef RTC_DEBUG
#endif
