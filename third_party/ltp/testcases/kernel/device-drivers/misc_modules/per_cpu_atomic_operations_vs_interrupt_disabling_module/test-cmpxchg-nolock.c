#include <linux/jiffies.h>
#include <linux/compiler.h>
#include <linux/init.h>
#include <linux/module.h>
#include <linux/math64.h>
#include <asm/timex.h>
#include <asm/system.h>
#define NR_LOOPS 20000
#ifdef CONFIG_X86_32
#else
#endif
