#include <common.h>
#include <dm.h>
#include <reset-uclass.h>
#include <regmap.h>
#define REG_COUNT	8
#define BITS_PER_REG	32
#define LEVEL_OFFSET	0x7c
static int meson_reset_free(struct reset_ctl *reset_ctl)
{
	return 0;
}
