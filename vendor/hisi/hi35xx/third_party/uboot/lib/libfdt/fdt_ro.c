#include <linux/libfdt_env.h>
#ifndef USE_HOSTCC
#include <fdt.h>
#include <linux/libfdt.h>
#else
#include "fdt_host.h"
#endif
#include "libfdt_internal.h"
#if !defined(CHECK_LEVEL) || CHECK_LEVEL > 0
#endif
