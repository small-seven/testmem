#include <common.h>
#include <asm/io.h>
#include <linux/errno.h>
#include <bitfield.h>
#include <asm/arch/sysmap.h>
#include <asm/kona-common/clk.h>
#include "clk-core.h"
#define CLK_WR_ACCESS_PASSWORD	0x00a5a501
#define WR_ACCESS_OFFSET	0	/* common to all clock blocks */
#define POLICY_CTL_GO		1	/* Load and refresh policy masks */
#define POLICY_CTL_GO_ATL	4	/* Active Load */
#define CLK_GATE_DELAY_USEC 2000
