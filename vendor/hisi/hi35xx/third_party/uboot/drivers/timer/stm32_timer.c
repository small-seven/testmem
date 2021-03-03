#include <common.h>
#include <clk.h>
#include <dm.h>
#include <fdtdec.h>
#include <timer.h>
#include <asm/io.h>
#define CR1_CEN			BIT(0)
#define CR1_ARPE		BIT(7)
#define EGR_UG			BIT(0)
#define GPT_FREE_RUNNING	0xFFFFFFFF
