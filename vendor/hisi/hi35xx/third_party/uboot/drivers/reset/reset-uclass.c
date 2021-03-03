#include <common.h>
#include <dm.h>
#include <fdtdec.h>
#include <reset.h>
#include <reset-uclass.h>
int reset_free(struct reset_ctl *reset_ctl)
{
	struct reset_ops *ops = reset_dev_ops(reset_ctl->dev);

	debug("%s(reset_ctl=%p)\n", __func__, reset_ctl);

	return ops->free(reset_ctl);
}
