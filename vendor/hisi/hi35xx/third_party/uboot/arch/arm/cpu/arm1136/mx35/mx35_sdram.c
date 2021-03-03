#include <asm/io.h>
#include <linux/errno.h>
#include <asm/arch/imx-regs.h>
#include <linux/types.h>
#include <asm/arch/sys_proto.h>
#define ESDCTL_DDR2_EMR2	0x04000000
#define ESDCTL_DDR2_EMR3	0x06000000
#define ESDCTL_PRECHARGE	0x00000400
#define ESDCTL_DDR2_EN_DLL	0x02000400
#define ESDCTL_DDR2_RESET_DLL	0x00000333
#define ESDCTL_DDR2_MR		0x00000233
#define ESDCTL_DDR2_OCD_DEFAULT 0x02000780
#define set_mode(x, en, m)	(x | (en << 31) | (m << 28))
