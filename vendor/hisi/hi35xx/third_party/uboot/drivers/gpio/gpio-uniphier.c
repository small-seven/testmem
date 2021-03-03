#include <common.h>
#include <dm.h>
#include <linux/bitops.h>
#include <linux/io.h>
#include <linux/sizes.h>
#include <linux/errno.h>
#include <asm/global_data.h>
#include <asm/gpio.h>
#include <dt-bindings/gpio/uniphier-gpio.h>
#define UNIPHIER_GPIO_PORT_DATA		0x0	/* data */
#define UNIPHIER_GPIO_PORT_DIR		0x4	/* direction (1:in, 0:out) */
#define UNIPHIER_GPIO_IRQ_EN		0x90	/* irq enable */
