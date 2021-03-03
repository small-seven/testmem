#include <common.h>
#include <log.h>
#include <tee.h>
#include <linux/types.h>
#include "optee_msg.h"
#include "optee_msg_supplicant.h"
#include "optee_private.h"
#include "optee_smc.h"
static void cmd_shm_free(struct optee_msg_arg *arg)
{
	arg->ret_origin = TEE_ORIGIN_COMMS;

	if (arg->num_params != 1 ||
	    arg->params[0].attr != OPTEE_MSG_ATTR_TYPE_VALUE_INPUT) {
		arg->ret = TEE_ERROR_BAD_PARAMETERS;
		return;
	}

	tee_shm_free((struct tee_shm *)(ulong)arg->params[0].u.value.b);
	arg->ret = TEE_SUCCESS;
}
