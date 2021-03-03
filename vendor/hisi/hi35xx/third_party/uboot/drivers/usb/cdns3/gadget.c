#include <dm.h>
#include <linux/usb/gadget.h>
#include <linux/compat.h>
#include <linux/iopoll.h>
#include <asm/dma-mapping.h>
#include <linux/bitmap.h>
#include <linux/bug.h>
#include "core.h"
#include "gadget-export.h"
#include "gadget.h"
#include "trace.h"
#include "drd.h"
#define readl_poll_timeout_atomic readl_poll_timeout
#define usleep_range(a, b) udelay((b))
#define cdns3_wa2_enable_detection(priv_dev, ep_priv, reg) do { \
#ifndef __UBOOT__
#else
#endif
#ifndef __UBOOT__
#else
#endif
#ifndef __UBOOT__
#else
#endif
#ifndef __UBOOT__
#endif
