#include <linux/types.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <linux/ioctl.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/pci.h>
#include "tpci.h"
#define prk_err(fmt, ...) \
#define prk_info(fmt, ...) \
#define prk_debug(fmt, ...) \
#define TPASS	0
#define TFAIL	1
#define TSKIP	32
#ifdef CONFIG_HOTPLUG
#else
#endif
