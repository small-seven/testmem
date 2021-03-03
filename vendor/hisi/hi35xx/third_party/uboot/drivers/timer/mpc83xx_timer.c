#include <common.h>
#include <board.h>
#include <clk.h>
#include <dm.h>
#include <irq_func.h>
#include <status_led.h>
#include <time.h>
#include <timer.h>
#include <watchdog.h>
#if defined(CONFIG_WATCHDOG) || defined(CONFIG_HW_WATCHDOG)
#endif    /* CONFIG_WATCHDOG || CONFIG_HW_WATCHDOG */
#ifdef CONFIG_LED_STATUS
#endif /* CONFIG_LED_STATUS */
