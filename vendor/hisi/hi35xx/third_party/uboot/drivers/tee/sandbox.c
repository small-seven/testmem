#include <common.h>
#include <dm.h>
#include <sandboxtee.h>
#include <tee.h>
#include <tee/optee_ta_avb.h>
#ifdef CONFIG_OPTEE_TA_AVB
#endif /*OPTEE_TA_AVB*/
#ifdef CONFIG_OPTEE_TA_AVB
#endif
static int sandbox_tee_remove(struct udevice *dev)
{
	struct sandbox_tee_state *state = dev_get_priv(dev);

	hdestroy_r(&state->pstorage_htab);

	return 0;
}
