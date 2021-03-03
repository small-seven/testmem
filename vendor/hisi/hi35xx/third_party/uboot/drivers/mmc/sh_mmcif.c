#include <config.h>
#include <common.h>
#include <watchdog.h>
#include <command.h>
#include <mmc.h>
#include <clk.h>
#include <dm.h>
#include <malloc.h>
#include <linux/errno.h>
#include <linux/compat.h>
#include <linux/io.h>
#include <linux/sizes.h>
#include "sh_mmcif.h"
#define DRIVER_NAME	"sh_mmcif"
#ifndef CONFIG_DM_MMC
#else
#endif
