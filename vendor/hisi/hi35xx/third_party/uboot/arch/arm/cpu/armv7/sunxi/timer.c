#include <common.h>
#include <time.h>
#include <asm/io.h>
#include <asm/arch/timer.h>
#define TIMER_MODE   (0x0 << 7)	/* continuous mode */
#define TIMER_DIV    (0x0 << 4)	/* pre scale 1 */
#define TIMER_SRC    (0x1 << 2)	/* osc24m */
#define TIMER_RELOAD (0x1 << 1)	/* reload internal value */
#define TIMER_EN     (0x1 << 0)	/* enable timer */
#define TIMER_CLOCK		(24 * 1000 * 1000)
#define COUNT_TO_USEC(x)	((x) / 24)
#define USEC_TO_COUNT(x)	((x) * 24)
#define TICKS_PER_HZ		(TIMER_CLOCK / CONFIG_SYS_HZ)
#define TICKS_TO_HZ(x)		((x) / TICKS_PER_HZ)
#define TIMER_LOAD_VAL		0xffffffff
#define TIMER_NUM		0	/* we use timer 0 */
