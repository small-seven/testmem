#include <common.h>
#include <dm.h>
#include <errno.h>
#include <reset-uclass.h>
#include <asm/io.h>
#include <dm/lists.h>
#include <linux/log2.h>
#include <asm/arch/ccu.h>
static int sunxi_reset_free(struct reset_ctl *reset_ctl)
{
	debug("%s: (RST#%ld)\n", __func__, reset_ctl->id);

	return 0;
}
