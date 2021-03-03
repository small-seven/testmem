#include <clk.h>
#include <dm/device.h>
#include "clk-lib.h"
#define HZ_IN_MHZ	1000000
#define ceil(x, y)	({ ulong __x = (x), __y = (y); (__x + __y - 1) / __y; })
