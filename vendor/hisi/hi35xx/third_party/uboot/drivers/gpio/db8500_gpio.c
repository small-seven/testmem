#include <common.h>
#include <asm/io.h>
#include <asm/arch/db8500_gpio.h>
#include <asm/arch/db8500_pincfg.h>
#include <linux/compiler.h>
#define IO_ADDR(x) (void *) (x)
#define GPIO_TOTAL_PINS		268
#define GPIO_PINS_PER_BLOCK	32
#define GPIO_BLOCKS_COUNT	(GPIO_TOTAL_PINS/GPIO_PINS_PER_BLOCK + 1)
#define GPIO_BLOCK(pin)		(((pin + GPIO_PINS_PER_BLOCK) >> 5) - 1)
#define GPIO_PIN_WITHIN_BLOCK(pin)	((pin)%(GPIO_PINS_PER_BLOCK))
#define DB8500_GPIO_DAT		0x00
#define DB8500_GPIO_DATS	0x04
#define DB8500_GPIO_DATC	0x08
#define DB8500_GPIO_PDIS	0x0c
#define DB8500_GPIO_DIR		0x10
#define DB8500_GPIO_DIRS	0x14
#define DB8500_GPIO_DIRC	0x18
#define DB8500_GPIO_SLPC	0x1c
#define DB8500_GPIO_AFSLA	0x20
#define DB8500_GPIO_AFSLB	0x24
#define DB8500_GPIO_RIMSC	0x40
#define DB8500_GPIO_FIMSC	0x44
#define DB8500_GPIO_IS		0x48
#define DB8500_GPIO_IC		0x4c
#define DB8500_GPIO_RWIMSC	0x50
#define DB8500_GPIO_FWIMSC	0x54
#define DB8500_GPIO_WKS		0x58
