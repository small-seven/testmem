#include <common.h>
#include <dm.h>
#include <dm/lists.h>
#include <regmap.h>
#include <reset-uclass.h>
#include <syscon.h>
static int mediatek_reset_free(struct reset_ctl *reset_ctl)
{
	return 0;
}
