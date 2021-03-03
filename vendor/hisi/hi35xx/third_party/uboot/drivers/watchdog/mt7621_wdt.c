#include <common.h>
#include <dm.h>
#include <wdt.h>
#include <linux/io.h>
#define TIMER_REG_TMRSTAT		0x00
#define TIMER_REG_TMR1CTL		0x20
#define TIMER_REG_TMR1LOAD		0x24
#define TMR1CTL_ENABLE			BIT(7)
#define TMR1CTL_RESTART			BIT(9)
#define TMR1CTL_PRESCALE_SHIFT		16
