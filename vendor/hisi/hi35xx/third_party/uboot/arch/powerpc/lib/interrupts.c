#include <common.h>
#include <irq_func.h>
#include <asm/processor.h>
#include <watchdog.h>
#ifdef CONFIG_LED_STATUS
#include <status_led.h>
#endif
#ifndef CONFIG_MPC83XX_TIMER
#ifndef CONFIG_SYS_WATCHDOG_FREQ
#define CONFIG_SYS_WATCHDOG_FREQ (CONFIG_SYS_HZ / 2)
#endif
#endif /* !CONFIG_MPC83XX_TIMER */
#ifndef CONFIG_MPC83XX_TIMER
#if defined(CONFIG_WATCHDOG) || defined (CONFIG_HW_WATCHDOG)
#endif    /* CONFIG_WATCHDOG || CONFIG_HW_WATCHDOG */
#ifdef CONFIG_LED_STATUS
#endif /* CONFIG_LED_STATUS */
#endif /* !CONFIG_MPC83XX_TIMER */
