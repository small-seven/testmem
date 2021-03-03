#include <common.h>
#include <asm/io.h>
#include <dm.h>
#include <clk.h>
#include <timer.h>
#define OSTM_CMP	0x00
#define OSTM_CNT	0x04
#define OSTM_TE		0x10
#define OSTM_TS		0x14
#define OSTM_TT		0x18
#define OSTM_CTL	0x20
#define OSTM_CTL_D	BIT(1)
#if CONFIG_IS_ENABLED(CLK)
#else
#endif
