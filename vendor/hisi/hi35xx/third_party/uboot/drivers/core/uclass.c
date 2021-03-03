#define LOG_CATEGORY LOGC_DM
#include <common.h>
#include <dm.h>
#include <errno.h>
#include <malloc.h>
#include <dm/device.h>
#include <dm/device-internal.h>
#include <dm/lists.h>
#include <dm/uclass.h>
#include <dm/uclass-internal.h>
#include <dm/util.h>
int uclass_destroy(struct uclass *uc)
{
	struct uclass_driver *uc_drv;
	struct udevice *dev;
	int ret;

	/*
	 * We cannot use list_for_each_entry_safe() here. If a device in this
	 * uclass has a child device also in this uclass, it will be also be
	 * unbound (by the recursion in the call to device_unbind() below).
	 * We can loop until the list is empty.
	 */
	while (!list_empty(&uc->dev_head)) {
		dev = list_first_entry(&uc->dev_head, struct udevice,
				       uclass_node);
		ret = device_remove(dev, DM_REMOVE_NORMAL);
		if (ret)
			return ret;
		ret = device_unbind(dev);
		if (ret)
			return ret;
	}

	uc_drv = uc->uc_drv;
	if (uc_drv->destroy)
		uc_drv->destroy(uc);
	list_del(&uc->sibling_node);
	if (uc_drv->priv_auto_alloc_size)
		free(uc->priv);
	free(uc);

	return 0;
}
#if !CONFIG_IS_ENABLED(OF_CONTROL) || \
#endif
#if CONFIG_IS_ENABLED(OF_CONTROL)
#endif
#if CONFIG_IS_ENABLED(OF_CONTROL)
#endif
#if CONFIG_IS_ENABLED(DM_DEVICE_REMOVE)
#endif
#if CONFIG_IS_ENABLED(DM_DEVICE_REMOVE)
#endif
