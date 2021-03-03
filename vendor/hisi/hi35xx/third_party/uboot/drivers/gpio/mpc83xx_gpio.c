#include <common.h>
#include <mpc83xx.h>
#include <asm/gpio.h>
#include <asm/io.h>
#ifndef CONFIG_MPC83XX_GPIO_0_INIT_DIRECTION
#define CONFIG_MPC83XX_GPIO_0_INIT_DIRECTION 0
#endif
#ifndef CONFIG_MPC83XX_GPIO_1_INIT_DIRECTION
#define CONFIG_MPC83XX_GPIO_1_INIT_DIRECTION 0
#endif
#ifndef CONFIG_MPC83XX_GPIO_0_INIT_OPEN_DRAIN
#define CONFIG_MPC83XX_GPIO_0_INIT_OPEN_DRAIN 0
#endif
#ifndef CONFIG_MPC83XX_GPIO_1_INIT_OPEN_DRAIN
#define CONFIG_MPC83XX_GPIO_1_INIT_OPEN_DRAIN 0
#endif
#ifndef CONFIG_MPC83XX_GPIO_0_INIT_VALUE
#define CONFIG_MPC83XX_GPIO_0_INIT_VALUE 0
#endif
#ifndef CONFIG_MPC83XX_GPIO_1_INIT_VALUE
#define CONFIG_MPC83XX_GPIO_1_INIT_VALUE 0
#endif
int gpio_free(unsigned gpio)
{
	/* Do not set to input */
	return 0;
}
#if MPC83XX_GPIO_CTRLRS >= 1
#endif
#if MPC83XX_GPIO_CTRLRS >= 2
#endif
#if MPC83XX_GPIO_CTRLRS >= 1
#endif
#if MPC83XX_GPIO_CTRLRS >= 2
#endif
