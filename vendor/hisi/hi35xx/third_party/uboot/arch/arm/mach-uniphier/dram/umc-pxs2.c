#include <linux/delay.h>
#include <linux/errno.h>
#include <linux/io.h>
#include <linux/printk.h>
#include <linux/sizes.h>
#include <asm/processor.h>
#include <time.h>
#include "../init.h"
#include "../soc-info.h"
#include "ddrmphy-regs.h"
#include "umc-regs.h"
#define DRAM_CH_NR	3
#ifdef DEBUG
#endif
