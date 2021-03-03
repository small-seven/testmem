#include <hi_isr.h>
#include <hi_time.h>
#include <hi_clock.h>
#include "adc_drv.h"
#define CHECK_EMPTY_MAX_TIME_US  3000 /* 344ns * (0xfff + 18) * 2 = 2.8ms ，reserved 3ms */
