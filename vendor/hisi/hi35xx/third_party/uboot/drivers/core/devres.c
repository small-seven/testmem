#include <common.h>
#include <linux/compat.h>
#include <linux/kernel.h>
#include <linux/list.h>
#include <dm/device.h>
#include <dm/root.h>
#include <dm/util.h>
#ifdef CONFIG_DEBUG_DEVRES
#endif
#ifdef CONFIG_DEBUG_DEVRES
#else /* CONFIG_DEBUG_DEVRES */
#define set_node_dbginfo(dr, n, s)	do {} while (0)
#define devres_log(dev, dr, op)		do {} while (0)
#endif
#if CONFIG_DEBUG_DEVRES
#else
#endif
void devres_free(void *res)
{
	if (res) {
		struct devres *dr = container_of(res, struct devres, data);

		BUG_ON(!list_empty(&dr->entry));
		kfree(dr);
	}
}
void *devres_remove(struct udevice *dev, dr_release_t release,
		    dr_match_t match, void *match_data)
{
	void *res;

	res = devres_find(dev, release, match, match_data);
	if (res) {
		struct devres *dr = container_of(res, struct devres, data);

		list_del_init(&dr->entry);
		devres_log(dev, dr, "REM");
	}

	return res;
}
int devres_destroy(struct udevice *dev, dr_release_t release,
		   dr_match_t match, void *match_data)
{
	void *res;

	res = devres_remove(dev, release, match, match_data);
	if (unlikely(!res))
		return -ENOENT;

	devres_free(res);
	return 0;
}
#ifdef CONFIG_DEBUG_DEVRES
#endif
void *devm_kmalloc(struct udevice *dev, size_t size, gfp_t gfp)
{
	void *data;

	data = _devres_alloc(devm_kmalloc_release, size, gfp);
	if (unlikely(!data))
		return NULL;

	devres_add(dev, data);

	return data;
}
void devm_kfree(struct udevice *dev, void *p)
{
	int rc;

	rc = devres_destroy(dev, devm_kmalloc_release, devm_kmalloc_match, p);
	WARN_ON(rc);
}
