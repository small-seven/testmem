#include <common.h>
#include <asm/arch/sys_proto.h>
#include <asm/arch/cpu.h>
#include <asm/arch/emc.h>
#include <asm/gpio.h>
#include <env.h>
#include <spi.h>
#include <i2c.h>
#include <version.h>
#include <vsprintf.h>
#define GPO_15 111
#define MAX6957_CONF		0x04
#define MAX6957_CONF_08_11	0x0A
#define MAX6957_CONF_12_15	0x0B
#define MAX6957_CONF_16_19	0x0C
#define MAX6957AAX_HD44780_RS	0x29
#define MAX6957AAX_HD44780_R_W	0x2A
#define MAX6957AAX_HD44780_EN	0x2B
#define MAX6957AAX_HD44780_DATA	0x4C
#define HD44780_FUNCTION_SET		0x38
#define HD44780_DISPLAY_ON_OFF_CONTROL	0x0C
#define HD44780_ENTRY_MODE_SET		0x06
#define HD44780_CLEAR_DISPLAY		0x01
#define HD44780_SET_DDRAM_ADDR		0x80
#define HD44780_SET_CGRAM_ADDR		0x40
#define CONTRAST_DEFAULT  25
#ifdef CONFIG_CMD_MAX6957
#ifdef CONFIG_SYS_LONGHELP
#endif
#endif /* CONFIG_CMD_MAX6957 */
#ifdef CONFIG_CMD_HD44760
#if !defined(CONFIG_HUSH_PARSER)
#error CONFIG_CMD_HD44760 requires CONFIG_HUSH_PARSER
#endif
#ifdef CONFIG_SYS_LONGHELP
#endif
#endif /* CONFIG_CMD_HD44760 */
