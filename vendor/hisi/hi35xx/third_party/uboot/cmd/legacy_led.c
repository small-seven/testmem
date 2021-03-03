#include <common.h>
#include <config.h>
#include <command.h>
#include <status_led.h>
typedef struct led_tbl_s led_tbl_t;

static const led_tbl_t led_commands[] = {
#ifdef CONFIG_LED_STATUS_BOARD_SPECIFIC
#ifdef CONFIG_LED_STATUS0
	{ "0", CONFIG_LED_STATUS_BIT, NULL, NULL, NULL },
#endif
#ifdef CONFIG_LED_STATUS1
#endif
#ifdef CONFIG_LED_STATUS2
#endif
#ifdef CONFIG_LED_STATUS3
#endif
#ifdef CONFIG_LED_STATUS4
#endif
#ifdef CONFIG_LED_STATUS5
#endif
#endif
#ifdef CONFIG_LED_STATUS_GREEN
#endif
#ifdef CONFIG_LED_STATUS_YELLOW
#endif
#ifdef CONFIG_LED_STATUS_RED
#endif
#ifdef CONFIG_LED_STATUS_BLUE
#endif
#ifdef CONFIG_LED_STATUS_BOARD_SPECIFIC
#ifdef CONFIG_LED_STATUS0
#endif
#ifdef CONFIG_LED_STATUS1
#endif
#ifdef CONFIG_LED_STATUS2
#endif
#ifdef CONFIG_LED_STATUS3
#endif
#ifdef CONFIG_LED_STATUS4
#endif
#ifdef CONFIG_LED_STATUS5
#endif
#endif
#ifdef CONFIG_LED_STATUS_GREEN
#endif
#ifdef CONFIG_LED_STATUS_YELLOW
#endif
#ifdef CONFIG_LED_STATUS_RED
#endif
#ifdef CONFIG_LED_STATUS_BLUE
#endif
