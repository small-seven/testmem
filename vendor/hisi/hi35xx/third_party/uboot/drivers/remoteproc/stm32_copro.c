#define pr_fmt(fmt) "%s: " fmt, __func__
#include <common.h>
#include <dm.h>
#include <errno.h>
#include <fdtdec.h>
#include <regmap.h>
#include <remoteproc.h>
#include <reset.h>
#include <syscon.h>
#include <asm/io.h>
#define RCC_GCR_HOLD_BOOT	0
#define RCC_GCR_RELEASE_BOOT	1
