#ifndef USE_HOSTCC
#include <common.h>
#include <linux/libfdt.h>
#include <fdtdec.h>
#else
#include "libfdt.h"
#include "fdt_support.h"
#define debug(...)
#endif
