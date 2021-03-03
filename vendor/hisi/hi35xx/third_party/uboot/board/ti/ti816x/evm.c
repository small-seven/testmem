#include <common.h>
#include <env.h>
#include <spl.h>
#include <asm/cache.h>
#include <asm/io.h>
#include <asm/arch/clock.h>
#include <asm/arch/cpu.h>
#include <asm/arch/ddr_defs.h>
#include <asm/arch/hardware.h>
#include <asm/arch/sys_proto.h>
#include <asm/arch/mmc_host_def.h>
#include <asm/arch/mem.h>
#include <asm/arch/mux.h>
#if defined(CONFIG_MTD_RAW_NAND)
#endif
#ifdef CONFIG_SPL_BUILD
#define EMIF_TIM1   0x1779C9FE
#define EMIF_TIM2   0x50608074
#define EMIF_TIM3   0x009F857F
#define EMIF_SDREF  0x10001841
#define EMIF_SDCFG  0x62A73832
#define EMIF_PHYCFG 0x00000110
#define RD_DQS_GATE	(0x1B3)
#define RD_DQS		(0x35)
#define WR_DQS		(0x93)
#endif /* CONFIG_SPL_BUILD */
