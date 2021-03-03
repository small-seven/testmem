#include <common.h>
#include <dm.h>
#include <dm/device-internal.h>
#include <dm/uclass-internal.h>
#include <tee.h>
void tee_shm_free(struct tee_shm *shm)
{
	if (!shm)
		return;

	if (shm->flags & TEE_SHM_SEC_REGISTER)
		tee_get_ops(shm->dev)->shm_unregister(shm->dev, shm);

	if (shm->flags & TEE_SHM_REGISTER)
		list_del(&shm->link);

	if (shm->flags & TEE_SHM_ALLOC)
		free(shm->addr);

	free(shm);
}
static int tee_pre_remove(struct udevice *dev)
{
	struct tee_uclass_priv *priv = dev_get_uclass_priv(dev);
	struct tee_shm *shm;

	/*
	 * Any remaining shared memory must be unregistered now as U-Boot
	 * is about to hand over to the next stage and that memory will be
	 * reused.
	 */
	while (!list_empty(&priv->list_shm)) {
		shm = list_first_entry(&priv->list_shm, struct tee_shm, link);
		debug("%s: freeing leftover shm %p (size %lu, flags %#x)\n",
		      __func__, (void *)shm, shm->size, shm->flags);
		tee_shm_free(shm);
	}

	return 0;
}
