#include <common.h>
#include <asm/io.h>
#include <asm/arch/hardware.h>
#include <asm/arch/sys_proto.h>
#define HALT		0
#define RELEASE		1
#define VERSAL_RPU_CFG_CPU_HALT_MASK		0x01
#define VERSAL_RPU_GLBL_CTRL_SPLIT_LOCK_MASK	0x08
#define VERSAL_RPU_GLBL_CTRL_TCM_COMB_MASK	0x40
#define VERSAL_RPU_GLBL_CTRL_SLCLAMP_MASK	0x10
#define VERSAL_CRLAPB_RST_LPD_AMBA_RST_MASK	0x04
#define VERSAL_CRLAPB_RST_LPD_R50_RST_MASK	0x01
#define VERSAL_CRLAPB_RST_LPD_R51_RST_MASK	0x02
#define VERSAL_CRL_RST_CPU_R5_RESET_PGE_MASK	0x10
#define VERSAL_CRLAPB_CPU_R5_CTRL_CLKACT_MASK	0x1000000