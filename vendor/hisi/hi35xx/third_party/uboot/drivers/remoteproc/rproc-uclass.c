#define pr_fmt(fmt) "%s: " fmt, __func__
#include <common.h>
#include <errno.h>
#include <fdtdec.h>
#include <malloc.h>
#include <remoteproc.h>
#include <asm/io.h>
#include <dm/device-internal.h>
#include <dm.h>
#include <dm/uclass.h>
#include <dm/uclass-internal.h>
#if CONFIG_IS_ENABLED(OF_CONTROL)
#else
#endif
