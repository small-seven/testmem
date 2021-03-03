#include <common.h>
#include <dm.h>
#include <mailbox-uclass.h>
#include <asm/io.h>
#include <asm/mbox.h>
#define SANDBOX_MBOX_CHANNELS 2
static int sandbox_mbox_free(struct mbox_chan *chan)
{
	debug("%s(chan=%p)\n", __func__, chan);

	return 0;
}
