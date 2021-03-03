#include <common.h>
#include <time.h>
#include <asm/io.h>
#include <asm/arch/imx-regs.h>
#include <asm/arch/sys_proto.h>
#if defined(CONFIG_MX23)
#define TIMER_LOAD_VAL 0xffff
#elif defined(CONFIG_MX28)
#define TIMER_LOAD_VAL 0xffffffff
#endif
#define timestamp (gd->arch.tbl)
#define lastdec (gd->arch.lastinc)
#define	MXS_INCREMENTER_HZ		1000
#if defined(CONFIG_MX23)
#elif defined(CONFIG_MX28)
#endif
#if defined(CONFIG_MX23)
#elif defined(CONFIG_MX28)
#endif
#if defined(CONFIG_MX23)
#elif defined(CONFIG_MX28)
#else
#error "Don't know how to read timrot_regs"
#endif
#define	MXS_HW_DIGCTL_MICROSECONDS	0x8001c0c0
