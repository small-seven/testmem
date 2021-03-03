#include "jpegd_drv.h"
#include <common.h>
#define osal_readl(x) (*((volatile int *)(x)))
#define osal_writel(v, x) (*((volatile int *)(x)) = (v))
