#include <common.h>
#include <asm/io.h>
#ifdef NAND_PLAT_GPIO_DEV_READY
# include <asm/gpio.h>
# define NAND_PLAT_DEV_READY(chip) gpio_get_value(NAND_PLAT_GPIO_DEV_READY)
#endif
#include <nand.h>
#ifdef NAND_PLAT_DEV_READY
#else
# define plat_dev_ready NULL
#endif
#ifdef NAND_PLAT_GPIO_DEV_READY
#endif
#ifdef NAND_PLAT_INIT
#endif
