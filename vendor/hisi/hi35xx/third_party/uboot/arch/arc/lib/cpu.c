#include <common.h>
#include <malloc.h>
#include <vsprintf.h>
#include <asm/arcregs.h>
#include <asm/cache.h>
#ifdef CONFIG_DISPLAY_CPUINFO
#define MAX_CPU_NAME_LEN	64
#endif /* CONFIG_DISPLAY_CPUINFO */
