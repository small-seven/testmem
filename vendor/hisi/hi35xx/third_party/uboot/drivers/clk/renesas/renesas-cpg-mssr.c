#include <common.h>
#include <clk-uclass.h>
#include <dm.h>
#include <errno.h>
#include <wait_bit.h>
#include <asm/io.h>
#include <dt-bindings/clock/renesas-cpg-mssr.h>
#include "renesas-cpg-mssr.h"
#define	MSTPSR(i)	mstpsr[i]
#define	SMSTPCR(i)	smstpcr[i]
#define RMSTPCR(i)	(smstpcr[i] - 0x20)
#define MMSTPCR(i)	(smstpcr[i] + 0x20)
#define	SRSTCLR(i)	(0x940 + (i) * 4)
int renesas_clk_remove(void __iomem *base, struct cpg_mssr_info *info)
{
	unsigned int i;

	/* Stop TMU0 */
	clrbits_le32(TMU_BASE + TSTR0, TSTR0_STR0);

	/* Stop module clock */
	for (i = 0; i < info->mstp_table_size; i++) {
		clrsetbits_le32(base + SMSTPCR(i),
				info->mstp_table[i].sdis,
				info->mstp_table[i].sen);
		clrsetbits_le32(base + RMSTPCR(i),
				info->mstp_table[i].rdis,
				info->mstp_table[i].ren);
	}

	return 0;
}
