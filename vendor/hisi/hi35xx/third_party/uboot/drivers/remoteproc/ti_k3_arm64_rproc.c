#include <common.h>
#include <dm.h>
#include <remoteproc.h>
#include <errno.h>
#include <clk.h>
#include <reset.h>
#include <asm/io.h>
#include <power-domain.h>
#include <linux/soc/ti/ti_sci_protocol.h>
#include "ti_sci_proc.h"
#define INVALID_ID	0xffff
#define GTC_CNTCR_REG	0x0
#define GTC_CNTR_EN	0x3
