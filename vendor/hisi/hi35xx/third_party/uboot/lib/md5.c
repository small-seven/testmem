#include "compiler.h"
#ifndef USE_HOSTCC
#include <common.h>
#include <watchdog.h>
#endif /* USE_HOSTCC */
#include <u-boot/md5.h>
#define F1(x, y, z) (z ^ (x & (y ^ z)))
#define F2(x, y, z) F1(z, x, y)
#define F3(x, y, z) (x ^ y ^ z)
#define F4(x, y, z) (y ^ (x | ~z))
#define MD5STEP(f, w, x, y, z, data, s) \
#if defined(CONFIG_HW_WATCHDOG) || defined(CONFIG_WATCHDOG)
#endif
#if defined(CONFIG_HW_WATCHDOG) || defined(CONFIG_WATCHDOG)
#else
#endif
