#include <clk.h>
#include <common.h>
#include <dm.h>
#include <timer.h>
#include <asm/io.h>
#define MTK_GPT4_CTRL	0x40
#define MTK_GPT4_CLK	0x44
#define MTK_GPT4_CNT	0x48
#define GPT4_ENABLE	BIT(0)
#define GPT4_CLEAR	BIT(1)
#define GPT4_FREERUN	GENMASK(5, 4)
#define GPT4_CLK_SYS	0x0
#define GPT4_CLK_DIV1	0x0
