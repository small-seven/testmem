#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/types.h>
#include <linux/fs.h>
#include <linux/blkdev.h>
#include <linux/ioctl.h>
#include <linux/pm.h>
#include <linux/acpi.h>
#include <linux/genhd.h>
#include <linux/dmi.h>
#include <linux/nls.h>
#include "ltp_acpi.h"
#define prk_err(fmt, ...) \
#define prk_alert(fmt, ...) \
#define prk_info(fmt, ...) \
#ifndef ACPI_EC_UDELAY_GLK
#define ACPI_EC_UDELAY_GLK	1000	/* Wait 1ms max. to get global lock */
#endif
#ifdef ACPI_FUTURE_USAGE
#endif
