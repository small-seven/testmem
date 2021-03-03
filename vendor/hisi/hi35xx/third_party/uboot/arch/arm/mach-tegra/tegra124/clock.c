#include <common.h>
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
#if CONFIG_IS_ENABLED(OF_CONTROL)
#endif /* CONFIG_IS_ENABLED(OF_CONTROL) */
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
#define  PLLE_BASE_ENABLE (1 << 30)
#define  PLLE_BASE_LOCK_OVERRIDE (1 << 29)
#define  PLLE_BASE_PLDIV_CML(x) (((x) & 0xf) << 24)
#define  PLLE_BASE_NDIV(x) (((x) & 0xff) << 8)
#define  PLLE_BASE_MDIV(x) (((x) & 0xff) << 0)
#define PLLE_MISC 0x0ec
#define  PLLE_MISC_IDDQ_SWCTL (1 << 14)
#define  PLLE_MISC_IDDQ_OVERRIDE (1 << 13)
#define  PLLE_MISC_LOCK_ENABLE (1 << 9)
#define  PLLE_MISC_PTS (1 << 8)
#define  PLLE_MISC_VREG_BG_CTRL(x) (((x) & 0x3) << 4)
#define  PLLE_MISC_VREG_CTRL(x) (((x) & 0x3) << 2)
#define PLLE_AUX 0x48c
#define  PLLE_AUX_SEQ_ENABLE (1 << 24)
#define  PLLE_AUX_ENABLE_SWCTL (1 << 4)
