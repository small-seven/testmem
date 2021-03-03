#include <common.h>
#include <dm.h>
#include <errno.h>
#include <mailbox.h>
#include <dm/device.h>
#include <linux/compat.h>
#include <linux/err.h>
#include <linux/soc/ti/k3-sec-proxy.h>
#include <linux/soc/ti/ti_sci_protocol.h>
#include "ti_sci.h"
#define handle_to_ti_sci_info(h) container_of(h, struct ti_sci_info, handle)
