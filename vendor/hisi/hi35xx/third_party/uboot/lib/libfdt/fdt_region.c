#include <linux/libfdt_env.h>
#ifndef USE_HOSTCC
#include <fdt.h>
#include <linux/libfdt.h>
#else
#include "fdt_host.h"
#endif
#define FDT_MAX_DEPTH	32
