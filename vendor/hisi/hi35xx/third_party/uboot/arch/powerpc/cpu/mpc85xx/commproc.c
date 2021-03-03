#include <common.h>
#include <asm/cpm_85xx.h>
#undef	CPM_DATAONLY_SIZE
#define CPM_DATAONLY_SIZE	((uint)(8 * 1024) - CPM_DATAONLY_BASE)
#define BRG_INT_CLK	gd->arch.brg_clk
#define BRG_UART_CLK	((BRG_INT_CLK + 15) / 16)
