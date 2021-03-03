#define pr_fmt(fmt) "%s: " fmt, __func__
#include <common.h>
#include <dm.h>
#include <errno.h>
#include <remoteproc.h>
#include <asm/io.h>
#define SANDBOX_RPROC_DEV_TO_PHY_OFFSET	0x1000
