#include <common.h>
#include <linux/io.h>
#include "arm-mpcore.h"
#define PERIPHCLK (50 * 1000 * 1000) /* 50 MHz */
#define PRESCALER ((PERIPHCLK) / (CONFIG_SYS_TIMER_RATE) - 1)
