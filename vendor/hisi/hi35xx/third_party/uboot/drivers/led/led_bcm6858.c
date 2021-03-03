#include <common.h>
#include <dm.h>
#include <errno.h>
#include <led.h>
#include <asm/io.h>
#include <dm/lists.h>
#define LEDS_MAX		32
#define LEDS_WAIT		100
#define LED_MODE_REG		0x0
#define LED_MODE_OFF		0
#define LED_MODE_ON		1
#define LED_MODE_MASK		1
#define LED_CTRL_REG			0x00
#define LED_CTRL_MASK			0x1f
#define LED_CTRL_LED_TEST_MODE		BIT(0)
#define LED_CTRL_SERIAL_LED_DATA_PPOL	BIT(1)
#define LED_CTRL_SERIAL_LED_CLK_POL	BIT(2)
#define LED_CTRL_SERIAL_LED_EN_POL	BIT(3)
#define LED_CTRL_SERIAL_LED_MSB_FIRST	BIT(4)
#define LED_HW_LED_EN_REG		0x08
#define LED_FLASH_RATE_CONTROL_REG0	0x10
#define LED_SW_LED_IP_REG		0xb8
#define LED_SW_LED_IP_PPOL_REG		0xbc
#ifdef CONFIG_LED_BLINK
#endif
#ifdef CONFIG_LED_BLINK
#endif
#ifdef CONFIG_LED_BLINK
#endif
#ifdef CONFIG_LED_BLINK
#endif
#ifdef CONFIG_LED_BLINK
#endif
