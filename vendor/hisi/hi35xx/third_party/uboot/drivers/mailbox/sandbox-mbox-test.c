#include <common.h>
#include <dm.h>
#include <mailbox.h>
#include <asm/io.h>
int sandbox_mbox_test_free(struct udevice *dev)
{
	struct sandbox_mbox_test *sbmt = dev_get_priv(dev);

	return mbox_free(&sbmt->chan);
}
