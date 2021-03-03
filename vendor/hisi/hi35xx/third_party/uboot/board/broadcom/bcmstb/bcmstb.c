#include <cpu_func.h>
#include <init.h>
#include <time.h>
#include <linux/types.h>
#include <common.h>
#include <env.h>
#include <asm/io.h>
#include <asm/bootm.h>
#include <mach/timer.h>
#include <mmc.h>
#include <fdtdec.h>
#define BCMSTB_DATA_SECTION __attribute__((section(".data")))
