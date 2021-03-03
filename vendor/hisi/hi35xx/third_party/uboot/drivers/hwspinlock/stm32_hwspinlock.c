#include <common.h>
#include <clk.h>
#include <dm.h>
#include <hwspinlock.h>
#include <asm/io.h>
#define STM32_MUTEX_COREID	BIT(8)
#define STM32_MUTEX_LOCK_BIT	BIT(31)
#define STM32_MUTEX_NUM_LOCKS	32
