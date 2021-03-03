#include <common.h>
#include <command.h>
#include <dm.h>
#include <rtc.h>
#include <i2c.h>
#ifdef CONFIG_NEEDS_MANUAL_RELOC
#define RELOC(a)	((typeof(a))((unsigned long)(a) + gd->reloc_off))
#else
#define RELOC(a)	a
#endif
#ifdef CONFIG_DM_RTC
#elif defined(CONFIG_SYS_I2C)
#else
#endif
#ifdef CONFIG_DM_RTC
#else
#endif
#ifdef CONFIG_DM_RTC
#else
#endif
#ifdef CONFIG_DM_RTC
#else
#endif
#ifdef CONFIG_DM_RTC
#else
#endif
#ifdef CONFIG_SYS_I2C
#elif !defined(CONFIG_DM_RTC)
#endif
