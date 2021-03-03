#include <common.h>
#include <linux/errno.h>
#include <asm/io.h>
#include <asm/arch/cpu.h>
#include <asm/arch/soc.h>
#include <linux/log2.h>
#include <linux/mbus.h>
#define TARGET_DDR		0
#define WIN_CTRL_OFF		0x0000
#define   WIN_CTRL_ENABLE       BIT(0)
#define   WIN_CTRL_TGT_MASK     0xf0
#define   WIN_CTRL_TGT_SHIFT    4
#define   WIN_CTRL_ATTR_MASK    0xff00
#define   WIN_CTRL_ATTR_SHIFT   8
#define   WIN_CTRL_SIZE_MASK    0xffff0000
#define   WIN_CTRL_SIZE_SHIFT   16
#define WIN_BASE_OFF		0x0004
#define   WIN_BASE_LOW          0xffff0000
#define   WIN_BASE_HIGH         0xf
#define WIN_REMAP_LO_OFF	0x0008
#define   WIN_REMAP_LOW         0xffff0000
#define WIN_REMAP_HI_OFF	0x000c
#define ATTR_HW_COHERENCY	(0x1 << 4)
#define DDR_BASE_CS_OFF(n)	(0x0000 + ((n) << 3))
#define  DDR_BASE_CS_HIGH_MASK  0xf
#define  DDR_BASE_CS_LOW_MASK   0xff000000
#define DDR_SIZE_CS_OFF(n)	(0x0004 + ((n) << 3))
#define  DDR_SIZE_ENABLED       BIT(0)
#define  DDR_SIZE_CS_MASK       0x1c
#define  DDR_SIZE_CS_SHIFT      2
#define  DDR_SIZE_MASK          0xff000000
#define DOVE_DDR_BASE_CS_OFF(n) ((n) << 4)
static int mvebu_mbus_window_is_free(struct mvebu_mbus_state *mbus,
				     const int win)
{
	void __iomem *addr = mbus->mbuswins_base +
		mbus->soc->win_cfg_offset(win);
	u32 ctrl = readl(addr + WIN_CTRL_OFF);
	return !(ctrl & WIN_CTRL_ENABLE);
}
#if defined(CONFIG_ARMADA_MSYS)
#endif
#ifndef CONFIG_KIRKWOOD
#endif
#ifndef CONFIG_KIRKWOOD
#endif
#if defined(CONFIG_KIRKWOOD)
#endif
#if defined(CONFIG_ARCH_MVEBU)
#endif
