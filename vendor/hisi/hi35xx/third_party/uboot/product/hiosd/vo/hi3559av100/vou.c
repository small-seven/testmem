#include "vou.h"
#include "vou_drv.h"
#include "vou_hal.h"
#include <cpu_func.h>
#define vo_align(val, align) (((val) + (align) - 1) & (~((align) - 1)))
