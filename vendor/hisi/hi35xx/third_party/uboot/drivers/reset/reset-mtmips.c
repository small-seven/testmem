#include <common.h>
#include <dm.h>
#include <errno.h>
#include <reset-uclass.h>
#include <linux/io.h>
static int mtmips_reset_free(struct reset_ctl *reset_ctl)
{
	return 0;
}
