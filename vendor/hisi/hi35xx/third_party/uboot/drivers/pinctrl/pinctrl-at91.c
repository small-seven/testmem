#include <common.h>
#include <dm.h>
#include <dm/pinctrl.h>
#include <asm/hardware.h>
#include <linux/io.h>
#include <linux/err.h>
#include <mach/at91_pio.h>
#define MAX_GPIO_BANKS		5
#define MAX_NB_GPIO_PER_BANK	32
#define MAX_PINMUX_ENTRIES	200
#define PULL_UP			BIT(0)
#define MULTI_DRIVE		BIT(1)
#define DEGLITCH		BIT(2)
#define PULL_DOWN		BIT(3)
#define DIS_SCHMIT		BIT(4)
#define DRIVE_STRENGTH_SHIFT	5
#define DRIVE_STRENGTH_MASK	0x3
#define DRIVE_STRENGTH		(DRIVE_STRENGTH_MASK << DRIVE_STRENGTH_SHIFT)
#define OUTPUT			BIT(7)
#define OUTPUT_VAL_SHIFT	8
#define OUTPUT_VAL		(0x1 << OUTPUT_VAL_SHIFT)
#define SLEWRATE_SHIFT	9
#define SLEWRATE_MASK	0x1
#define SLEWRATE	(SLEWRATE_MASK << SLEWRATE_SHIFT)
#define DEBOUNCE		BIT(16)
#define DEBOUNCE_VAL_SHIFT	17
#define DEBOUNCE_VAL		(0x3fff << DEBOUNCE_VAL_SHIFT)
#define DRIVE_STRENGTH_BIT_MSK(name)	(DRIVE_STRENGTH_BIT_##name << \
#define SLEWRATE_BIT_MSK(name)		(SLEWRATE_BIT_##name << SLEWRATE_SHIFT)
