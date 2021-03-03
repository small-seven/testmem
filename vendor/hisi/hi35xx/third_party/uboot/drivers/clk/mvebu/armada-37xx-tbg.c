#include <common.h>
#include <clk-uclass.h>
#include <clk.h>
#include <dm.h>
#include <asm/io.h>
#include <asm/arch/cpu.h>
#define NUM_TBG	    4
#define TBG_CTRL0		0x4
#define TBG_CTRL1		0x8
#define TBG_CTRL7		0x20
#define TBG_CTRL8		0x30
#define TBG_DIV_MASK		0x1FF
#define TBG_A_REFDIV		0
#define TBG_B_REFDIV		16
#define TBG_A_FBDIV		2
#define TBG_B_FBDIV		18
#define TBG_A_VCODIV_SE		0
#define TBG_B_VCODIV_SE		16
#define TBG_A_VCODIV_DIFF	1
#define TBG_B_VCODIV_DIFF	17
#if defined(CONFIG_CMD_CLK) && defined(CONFIG_CLK_ARMADA_3720)
#endif
