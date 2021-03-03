#include <stdio.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/signal.h>
#include <sys/sysinfo.h>
#include <stdint.h>
#include "test.h"
#define INVALID_ADDRESS ((uintptr_t)-1)
#if !defined(UCLINUX)
#else
#endif /* if !defined(UCLINUX) */
