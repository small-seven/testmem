#include <common.h>
#include <time.h>
#include <asm/io.h>
#define SYSTICK_BASE		0xE000E010
#define TIMER_MAX_VAL		0x00FFFFFF
#define SYSTICK_CTRL_EN		BIT(0)
#define SYSTICK_CTRL_CPU_CLK	BIT(2)
#define SYSTICK_CAL_NOREF	BIT(31)
#define SYSTICK_CAL_SKEW	BIT(30)
#define SYSTICK_CAL_TENMS_MASK	0x00FFFFFF
#if defined(CONFIG_SYS_HZ_CLOCK)
#else
#endif
