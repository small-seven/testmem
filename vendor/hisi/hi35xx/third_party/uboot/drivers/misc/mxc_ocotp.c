#include <common.h>
#include <fuse.h>
#include <linux/errno.h>
#include <asm/io.h>
#include <asm/arch/clock.h>
#include <asm/arch/imx-regs.h>
#include <asm/mach-imx/sys_proto.h>
#define BO_CTRL_WR_UNLOCK		16
#define BM_CTRL_WR_UNLOCK		0xffff0000
#define BV_CTRL_WR_UNLOCK_KEY		0x3e77
#define BM_CTRL_ERROR			0x00000200
#define BM_CTRL_BUSY			0x00000100
#define BO_CTRL_ADDR			0
#ifdef CONFIG_MX7
#define BM_CTRL_ADDR                    0x0000000f
#define BM_CTRL_RELOAD                  0x00000400
#elif defined(CONFIG_MX7ULP)
#define BM_CTRL_ADDR                    0x000000FF
#define BM_CTRL_RELOAD                  0x00000400
#define BM_OUT_STATUS_DED				0x00000400
#define BM_OUT_STATUS_LOCKED			0x00000800
#define BM_OUT_STATUS_PROGFAIL			0x00001000
#elif defined(CONFIG_IMX8M)
#define BM_CTRL_ADDR			0x000000ff
#else
#define BM_CTRL_ADDR			0x0000007f
#endif
#ifdef CONFIG_MX7
#define BO_TIMING_FSOURCE               12
#define BM_TIMING_FSOURCE               0x0007f000
#define BV_TIMING_FSOURCE_NS            1001
#define BO_TIMING_PROG                  0
#define BM_TIMING_PROG                  0x00000fff
#define BV_TIMING_PROG_US               10
#else
#define BO_TIMING_STROBE_READ		16
#define BM_TIMING_STROBE_READ		0x003f0000
#define BV_TIMING_STROBE_READ_NS	37
#define BO_TIMING_RELAX			12
#define BM_TIMING_RELAX			0x0000f000
#define BV_TIMING_RELAX_NS		17
#define BO_TIMING_STROBE_PROG		0
#define BM_TIMING_STROBE_PROG		0x00000fff
#define BV_TIMING_STROBE_PROG_US	10
#endif
#define BM_READ_CTRL_READ_FUSE		0x00000001
#define BF(value, field)		(((value) << BO_##field) & BM_##field)
#define WRITE_POSTAMBLE_US		2
#if defined(CONFIG_MX6) || defined(CONFIG_VF610)
#define FUSE_BANK_SIZE	0x80
#ifdef CONFIG_MX6SL
#define FUSE_BANKS	8
#elif defined(CONFIG_MX6ULL) || defined(CONFIG_MX6SLL)
#define FUSE_BANKS	9
#else
#define FUSE_BANKS	16
#endif
#elif defined CONFIG_MX7
#define FUSE_BANK_SIZE	0x40
#define FUSE_BANKS	16
#elif defined(CONFIG_MX7ULP)
#define FUSE_BANK_SIZE	0x80
#define FUSE_BANKS	31
#elif defined(CONFIG_IMX8M)
#define FUSE_BANK_SIZE	0x40
#define FUSE_BANKS	64
#else
#error "Unsupported architecture\n"
#endif
#if defined(CONFIG_MX6)
#else
#endif
#ifdef CONFIG_MX7ULP
#endif
#ifdef CONFIG_MX7ULP
#endif
#ifdef CONFIG_MX7
#elif defined(CONFIG_MX7ULP)
#else
#endif
#ifdef CONFIG_MX7
#elif defined CONFIG_IMX8M
#else
#endif
#ifdef CONFIG_MX7
#else
#endif
#ifdef CONFIG_MX7ULP
#endif
#ifdef CONFIG_MX7ULP
#endif
#ifdef CONFIG_MX7
#else
#endif
#ifdef CONFIG_MX7ULP
#endif
#ifdef CONFIG_MX7ULP
#endif
