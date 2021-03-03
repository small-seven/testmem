#include <common.h>
#include <dm.h>
#include <zynqmp_firmware.h>
#if defined(CONFIG_ZYNQMP_IPI)
#include <mailbox.h>
#include <asm/arch/sys_proto.h>
#define PMUFW_PAYLOAD_ARG_CNT	8
#endif
