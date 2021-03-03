#include <common.h>
#include <dm.h>
#include <errno.h>
#include <timer.h>
#include <asm/io.h>
#define ALTERA_TIMER_CONT	BIT(1)	/* Continuous mode */
#define ALTERA_TIMER_START	BIT(2)	/* Start timer */
#define ALTERA_TIMER_STOP	BIT(3)	/* Stop timer */
