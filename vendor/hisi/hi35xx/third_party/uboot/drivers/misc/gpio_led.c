#include <common.h>
#include <status_led.h>
#include <asm/gpio.h>
#ifndef CONFIG_GPIO_LED_INVERTED_TABLE
#define CONFIG_GPIO_LED_INVERTED_TABLE {}
#endif
#ifdef CONFIG_GPIO_LED_STUBS
#ifdef CONFIG_LED_STATUS_RED
#endif
#ifdef CONFIG_LED_STATUS_GREEN
#endif
#ifdef CONFIG_LED_STATUS_YELLOW
#endif
#ifdef CONFIG_LED_STATUS_BLUE
#endif
#endif /* CONFIG_GPIO_LED_STUBS */
