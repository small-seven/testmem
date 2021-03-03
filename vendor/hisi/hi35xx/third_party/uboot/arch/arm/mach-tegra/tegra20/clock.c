#include <common.h>
#include <errno.h>
#include <asm/io.h>
#include <asm/arch/clock.h>
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
#define PMC_SATA_PWRGT 0x1ac
#define  PMC_SATA_PWRGT_PLLE_IDDQ_OVERRIDE (1 << 5)
#define  PMC_SATA_PWRGT_PLLE_IDDQ_SWCTL (1 << 4)
#define PLLE_SS_CNTL 0x68
#define  PLLE_SS_CNTL_SSCINCINTRV(x) (((x) & 0x3f) << 24)
#define  PLLE_SS_CNTL_SSCINC(x) (((x) & 0xff) << 16)
#define  PLLE_SS_CNTL_SSCBYP (1 << 12)
#define  PLLE_SS_CNTL_INTERP_RESET (1 << 11)
#define  PLLE_SS_CNTL_BYPASS_SS (1 << 10)
#define  PLLE_SS_CNTL_SSCMAX(x) (((x) & 0x1ff) << 0)
#define PLLE_BASE 0x0e8
#define  PLLE_BASE_ENABLE_CML (1 << 31)
#define  PLLE_BASE_ENABLE (1 << 30)
#define  PLLE_BASE_PLDIV_CML(x) (((x) & 0xf) << 24)
#define  PLLE_BASE_PLDIV(x) (((x) & 0x3f) << 16)
#define  PLLE_BASE_NDIV(x) (((x) & 0xff) << 8)
#define  PLLE_BASE_MDIV(x) (((x) & 0xff) << 0)
#define PLLE_MISC 0x0ec
#define  PLLE_MISC_SETUP_BASE(x) (((x) & 0xffff) << 16)
#define  PLLE_MISC_PLL_READY (1 << 15)
#define  PLLE_MISC_LOCK (1 << 11)
#define  PLLE_MISC_LOCK_ENABLE (1 << 9)
#define  PLLE_MISC_SETUP_EXT(x) (((x) & 0x3) << 2)
