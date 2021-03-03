#ifdef HAVE_TM_GMTOFF
#include <time.h>
#endif /* HAVE_TM_GMTOFF */
#ifdef _WINDOWS
#include <windows.h>
#include <winbase.h>
#include <winnt.h>
#include <time.h>
#endif /* _WINDOWS */
#ifdef __GNUC__
#include <sys/time.h>
#endif /* __GNUC__ */
#include "jerryscript-port.h"
#include "jerryscript-port-default.h"
#ifdef JERRY_FOR_IAR_CONFIG
#include "mc_type.h"
#include "mc_hal_rtc.h"
#define GET_SIGN_BIT(x) ((x) >> sizeof (x) * 8 - 1)
#define GET_TIMEZONE_HOUR(timeZone) (((timeZone) >> 8) & 0x7F)
#define GET_TIMEZONE_MIN(timeZone) ((timeZone) & 0xFF)
#define HOUR_TO_MIN 60
#define MIN_TO_SEC 60
#endif
#ifdef _WINDOWS
#endif /* _WINDOWS */
#ifdef HAVE_TM_GMTOFF
#else /* !HAVE_TM_GMTOFF */
#ifdef JERRY_FOR_IAR_CONFIG
#else
#ifdef _WINDOWS
#endif /* _WINDOWS */
#endif
#endif /* HAVE_TM_GMTOFF */
#ifdef __GNUC__
#endif /* __GNUC__ */
#ifdef JERRY_FOR_IAR_CONFIG
#endif
#ifdef _WINDOWS
#endif /* _WINDOWS */
