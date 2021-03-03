#include <common.h>
#include <asm/io.h>
#include <dm.h>
#include <asm/arch/sci/sci.h>
#include <misc.h>
#define B2U8(X)     (((X) != SC_FALSE) ? (u8)(0x01U) : (u8)(0x00U))
int sc_rm_partition_free(sc_ipc_t ipc, sc_rm_pt_t pt)
{
	struct udevice *dev = gd->arch.scu_dev;
	struct sc_rpc_msg_s msg;
	int size = sizeof(struct sc_rpc_msg_s);
	int ret;

	RPC_VER(&msg) = SC_RPC_VERSION;
	RPC_SVC(&msg) = (u8)SC_RPC_SVC_RM;
	RPC_FUNC(&msg) = (u8)RM_FUNC_PARTITION_FREE;
	RPC_U8(&msg, 0U) = (u8)pt;
	RPC_SIZE(&msg) = 2U;

	ret = misc_call(dev, SC_FALSE, &msg, size, &msg, size);
	if (ret) {
		printf("%s: pt:%u res:%d\n",
		       __func__, pt, RPC_R8(&msg));
	}

	return ret;
}
