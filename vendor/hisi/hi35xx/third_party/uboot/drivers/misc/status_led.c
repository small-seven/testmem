#include <common.h>
#include <status_led.h>
typedef struct {
	led_id_t mask;
	int state;
	int period;
	int cnt;
} led_dev_t;
#if defined(CONFIG_LED_STATUS1)
#endif
#if defined(CONFIG_LED_STATUS2)
#endif
#if defined(CONFIG_LED_STATUS3)
#endif
#if defined(CONFIG_LED_STATUS4)
#endif
#if defined(CONFIG_LED_STATUS5)
#endif
#define MAX_LED_DEV	(sizeof(led_dev)/sizeof(led_dev_t))
