#include <common.h>
#include <malloc.h>
#include <clk-uclass.h>
#include <clk.h>
#include <dm.h>
#include <asm/io.h>
#include <asm/arch/cpu.h>
#define TBG_SEL		0x0
#define DIV_SEL0	0x4
#define DIV_SEL1	0x8
#define DIV_SEL2	0xC
#define CLK_SEL		0x10
#define CLK_DIS		0x14
#define CLK_FULL_DD(_n, _d, _mux, _r0, _r1, _s0, _s1)	\
#define CLK_FULL(_n, _d, _mux, _r, _s, _m, _t)	\
#define CLK_GATE_DIV(_n, _d, _r, _s, _m, _t, _p)	\
#define CLK_GATE(_n, _d, _p)		\
#define CLK_MUX_DIV(_n, _mux, _r, _s, _m, _t)	\
#define CLK_MUX_DD(_n, _mux, _r0, _r1, _s0, _s1)	\
#define diff(a, b) abs((long)(a) - (long)(b))
#if defined(CONFIG_CMD_CLK) && defined(CONFIG_CLK_ARMADA_3720)
#endif
