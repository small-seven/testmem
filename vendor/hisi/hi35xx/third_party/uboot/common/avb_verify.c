#include <avb_verify.h>
#include <blk.h>
#include <cpu_func.h>
#include <fastboot.h>
#include <image.h>
#include <malloc.h>
#include <part.h>
#include <tee.h>
#include <tee/optee_ta_avb.h>
#ifdef CONFIG_OPTEE_TA_AVB
#endif
#ifndef CONFIG_OPTEE_TA_AVB
#else
#endif
#ifndef CONFIG_OPTEE_TA_AVB
#else
#endif
#ifndef CONFIG_OPTEE_TA_AVB
#else
#endif
#ifdef CONFIG_OPTEE_TA_AVB
#endif
#ifdef CONFIG_OPTEE_TA_AVB
#endif
void avb_ops_free(AvbOps *ops)
{
	struct AvbOpsData *ops_data;

	if (!ops)
		return;

	ops_data = ops->user_data;

	if (ops_data) {
#ifdef CONFIG_OPTEE_TA_AVB
		if (ops_data->tee)
			tee_close_session(ops_data->tee, ops_data->session);
#endif
		avb_free(ops_data);
	}
}
