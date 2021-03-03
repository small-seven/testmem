#include <common.h>
#include <asm/io.h>
#include <asm/arch/sys_proto.h>
#include <asm/arch/hardware.h>
#ifndef CONFIG_ZYNQ_DDRC_INIT
#else
#define ZYNQ_DDRC_CTRLREG_BUSWIDTH_MASK		0xC
#define ZYNQ_DDRC_CTRLREG_BUSWIDTH_SHIFT	2
#define ZYNQ_DDRC_CTRLREG_BUSWIDTH_16BIT	1
#define ZYNQ_DDRC_ECC_SCRUBREG_ECC_MODE_MASK	0x7
#define ZYNQ_DDRC_ECC_SCRUBREG_ECCMODE_SECDED	0x4
#endif
