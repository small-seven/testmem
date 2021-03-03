#include <common.h>
#include <command.h>
#include <cpu_func.h>
#include <irq_func.h>
#include <asm/system.h>
#if !(CONFIG_IS_ENABLED(SYS_ICACHE_OFF) && CONFIG_IS_ENABLED(SYS_DCACHE_OFF))
#endif
