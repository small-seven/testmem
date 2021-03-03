#include <common.h>
#include <dm.h>
#include <errno.h>
#include <time.h>
#include <timer.h>
#include <watchdog.h>
#include <div64.h>
#include <asm/io.h>
#ifndef CONFIG_WD_PERIOD
# define CONFIG_WD_PERIOD	(10 * 1000 * 1000)	/* 10 seconds default */
#endif
#ifdef CONFIG_SYS_TIMER_RATE
#endif
#ifdef CONFIG_SYS_TIMER_COUNTER
#ifdef CONFIG_SYS_TIMER_COUNTS_DOWN
#else
#endif
#if CONFIG_SYS_TIMER_RATE == 1000000
#elif CONFIG_SYS_TIMER_RATE > 1000000
#elif defined(CONFIG_SYS_TIMER_RATE)
#else
#endif
#else
#endif
#if CONFIG_IS_ENABLED(TIMER)
#ifdef CONFIG_TIMER_EARLY
#else
#endif
#ifdef CONFIG_TIMER_EARLY
#else
#endif
#else /* !CONFIG_TIMER */
#endif /* CONFIG_TIMER */
