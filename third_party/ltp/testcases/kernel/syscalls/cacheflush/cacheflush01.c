#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "test.h"
#include "lapi/syscalls.h"
#if __NR_cacheflush != __LTP__NR_INVALID_SYSCALL
#include <asm/cachectl.h>
#else
#ifndef   ICACHE
#define   ICACHE   (1<<0)	/* flush instruction cache        */
#endif
#ifndef   DCACHE
#define   DCACHE   (1<<1)	/* writeback and flush data cache */
#endif
#ifndef   BCACHE
#define   BCACHE   (ICACHE|DCACHE)	/* flush both caches              */
#endif
#endif
