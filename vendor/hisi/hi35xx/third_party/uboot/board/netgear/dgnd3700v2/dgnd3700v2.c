#include <common.h>
#include <asm/io.h>
#define GPIO_BASE_6362			0x10000080
#define GPIO_MODE_6362_REG		0x18
#define GPIO_MODE_6362_SERIAL_LED_DATA	BIT(2)
#define GPIO_MODE_6362_SERIAL_LED_CLK	BIT(3)
#ifdef CONFIG_BOARD_EARLY_INIT_F
#endif
