#include <config.h>
#include <common.h>
#include <rtc.h>
#include <asm/io.h>
#define FTRTC010_CR_ENABLE		(1 << 0)
#define FTRTC010_CR_INTERRUPT_SEC	(1 << 1)	/* per second irq */
#define FTRTC010_CR_INTERRUPT_MIN	(1 << 2)	/* per minute irq */
#define FTRTC010_CR_INTERRUPT_HR	(1 << 3)	/* per hour   irq */
#define FTRTC010_CR_INTERRUPT_DAY	(1 << 4)	/* per day    irq */
#ifdef CONFIG_FTRTC010_PCLK
#else /* CONFIG_FTRTC010_EXTCLK */
#endif
