#include <common.h>
#include <dm.h>
#include <mailbox.h>
#include <mailbox-uclass.h>
#include <time.h>
int mbox_free(struct mbox_chan *chan)
{
	struct mbox_ops *ops = mbox_dev_ops(chan->dev);

	debug("%s(chan=%p)\n", __func__, chan);

	if (ops->free)
		return ops->free(chan);

	return 0;
}
