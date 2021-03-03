#include <common.h>
#include <asm/io.h>
#include <dm.h>
#include <dm/lists.h>
#include <dm/root.h>
#include <dm/device-internal.h>
#include <asm/arch/sci/sci.h>
#include <linux/iopoll.h>
#include <misc.h>
#define MU_CR_GIE_MASK		0xF0000000u
#define MU_CR_RIE_MASK		0xF000000u
#define MU_CR_GIR_MASK		0xF0000u
#define MU_CR_TIE_MASK		0xF00000u
#define MU_CR_F_MASK		0x7u
#define MU_SR_TE0_MASK		BIT(23)
#define MU_SR_RF0_MASK		BIT(27)
#define MU_TR_COUNT		4
#define MU_RR_COUNT		4
#ifdef CONFIG_SPL_BUILD
#else
#endif
static int imx8_scu_remove(struct udevice *dev)
{
	return 0;
}
