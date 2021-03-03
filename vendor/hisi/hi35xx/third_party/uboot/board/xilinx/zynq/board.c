#include <common.h>
#include <init.h>
#include <dm/uclass.h>
#include <env.h>
#include <fdtdec.h>
#include <fpga.h>
#include <malloc.h>
#include <mmc.h>
#include <watchdog.h>
#include <wdt.h>
#include <zynqpl.h>
#include <asm/arch/hardware.h>
#include <asm/arch/sys_proto.h>
#if !defined(CONFIG_SYS_SDRAM_BASE) && !defined(CONFIG_SYS_SDRAM_SIZE)
#else
#endif
