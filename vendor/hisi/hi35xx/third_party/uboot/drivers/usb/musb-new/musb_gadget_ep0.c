#ifndef __UBOOT__
#include <linux/kernel.h>
#include <linux/list.h>
#include <linux/timer.h>
#include <linux/spinlock.h>
#include <linux/device.h>
#include <linux/interrupt.h>
#else
#include <common.h>
#include "linux-compat.h"
#include <asm/processor.h>
#endif
#include "musb_core.h"
#define	next_ep0_request(musb)	next_in_request(&(musb)->endpoints[0])
