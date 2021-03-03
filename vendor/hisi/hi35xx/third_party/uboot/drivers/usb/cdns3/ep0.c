#include <cpu_func.h>
#include <linux/usb/composite.h>
#include <linux/iopoll.h>
#include "gadget.h"
#include "trace.h"
#define readl_poll_timeout_atomic readl_poll_timeout
#define usleep_range(a, b) udelay((b))
#ifndef __UBOOT__
#else
#endif
#ifndef __UBOOT__
#endif
