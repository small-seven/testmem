#include <common.h>
#include <linux/types.h>
#include <linux/errno.h>
#include <asm/io.h>
#include <asm/arch/imx-regs.h>
#include <asm/arch/sys_proto.h>
#include "ipu.h"
#include "ipu_regs.h"
#define SYNC_WAVE 0
#define DC_DISP_ID_SYNC(di)	(di)
#define DC_DISP_ID_SERIAL	2
#define DC_DISP_ID_ASYNC	3
#define mask_a(a) ((u32)(a) & 0x3FF)
#define mask_b(b) ((u32)(b) & 0x3FFF)
