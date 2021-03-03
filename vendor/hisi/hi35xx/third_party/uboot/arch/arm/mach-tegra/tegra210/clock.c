#include <common.h>
#include <errno.h>
#include <asm/io.h>
#include <asm/arch/clock.h>
#include <asm/arch/sysctr.h>
#include <asm/arch/tegra.h>
#include <asm/arch-tegra/clk_rst.h>
#include <asm/arch-tegra/timer.h>
#include <div64.h>
#include <fdtdec.h>
#define CLK(x) CLOCK_ID_ ## x
#define TYPE(name, type) type
#define NONE(name) (-1)
#define OFFSET(name, value) PERIPHC_ ## name
#define INTERNAL_ID(id) (id & 0x000000ff)
#ifdef CONFIG_OF_CONTROL
#endif /* CONFIG_OF_CONTROL */
#define PLLREFE_MISC			0x4c8
#define  PLLREFE_MISC_LOCK		BIT(27)
#define  PLLREFE_MISC_IDDQ		BIT(24)
#define PLLREFE_BASE			0x4c4
#define  PLLREFE_BASE_BYPASS		BIT(31)
#define  PLLREFE_BASE_ENABLE		BIT(30)
#define  PLLREFE_BASE_REF_DIS		BIT(29)
#define  PLLREFE_BASE_KCP(kcp)		(((kcp) & 0x3) << 27)
#define  PLLREFE_BASE_KVCO		BIT(26)
#define  PLLREFE_BASE_DIVP(p)		(((p) & 0x1f) << 16)
#define  PLLREFE_BASE_DIVN(n)		(((n) & 0xff) << 8)
#define  PLLREFE_BASE_DIVM(m)		(((m) & 0xff) << 0)
#define PLLE_SS_CNTL 0x68
#define  PLLE_SS_CNTL_SSCINCINTR(x) (((x) & 0x3f) << 24)
#define  PLLE_SS_CNTL_SSCINC(x) (((x) & 0xff) << 16)
#define  PLLE_SS_CNTL_SSCINVERT (1 << 15)
#define  PLLE_SS_CNTL_SSCCENTER (1 << 14)
#define  PLLE_SS_CNTL_SSCBYP (1 << 12)
#define  PLLE_SS_CNTL_INTERP_RESET (1 << 11)
#define  PLLE_SS_CNTL_BYPASS_SS (1 << 10)
#define  PLLE_SS_CNTL_SSCMAX(x) (((x) & 0x1ff) << 0)
#define PLLE_BASE 0x0e8
#define  PLLE_BASE_ENABLE (1 << 31)
#define  PLLE_BASE_PLDIV_CML(x) (((x) & 0x1f) << 24)
#define  PLLE_BASE_NDIV(x) (((x) & 0xff) << 8)
#define  PLLE_BASE_MDIV(x) (((x) & 0xff) << 0)
#define PLLE_MISC 0x0ec
#define  PLLE_MISC_IDDQ_SWCTL (1 << 14)
#define  PLLE_MISC_IDDQ_OVERRIDE_VALUE (1 << 13)
#define  PLLE_MISC_LOCK (1 << 11)
#define  PLLE_PTS (1 << 8)
#define  PLLE_MISC_KCP(x) (((x) & 0x3) << 6)
#define  PLLE_MISC_VREG_CTRL(x) (((x) & 0x3) << 2)
#define  PLLE_MISC_KVCO (1 << 0)
#define PLLE_AUX 0x48c
#define  PLLE_AUX_SS_SEQ_INCLUDE (1 << 31)
#define  PLLE_AUX_REF_SEL_PLLREFE (1 << 28)
#define  PLLE_AUX_SEQ_ENABLE (1 << 24)
#define  PLLE_AUX_SS_SWCTL (1 << 6)
#define  PLLE_AUX_ENABLE_SWCTL (1 << 4)
#define  PLLE_AUX_USE_LOCKDET (1 << 3)
