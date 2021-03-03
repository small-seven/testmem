#include <dm.h>
#include <linux/delay.h>
#include <linux/iopoll.h>
#include <linux/kernel.h>
#include <linux/usb/otg.h>
#include "gadget.h"
#include "drd.h"
#include "core.h"
#define readl_poll_timeout_atomic readl_poll_timeout
#define usleep_range(a, b) udelay((b))
