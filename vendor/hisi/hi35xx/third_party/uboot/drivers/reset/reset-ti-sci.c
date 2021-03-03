#include <common.h>
#include <dm.h>
#include <errno.h>
#include <reset-uclass.h>
#include <linux/soc/ti/ti_sci_protocol.h>
static int ti_sci_reset_free(struct reset_ctl *rst)
{
	debug("%s(rst=%p)\n", __func__, rst);
	return 0;
}
