#include <common.h>
#include <dm.h>
#include <reset-uclass.h>
#include <asm/io.h>
#include <asm/reset.h>
#define SANDBOX_RESET_SIGNALS 101
static int sandbox_reset_free(struct reset_ctl *reset_ctl)
{
	debug("%s(reset_ctl=%p)\n", __func__, reset_ctl);

	return 0;
}
