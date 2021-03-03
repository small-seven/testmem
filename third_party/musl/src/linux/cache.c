#include <errno.h>
#include "syscall.h"
#include "atomic.h"
#ifdef SYS_cacheflush
#endif
#ifdef SYS_cachectl
#endif
#ifdef SYS_riscv_flush_icache
#define VDSO_FLUSH_ICACHE_SYM "__vdso_flush_icache"
#define VDSO_FLUSH_ICACHE_VER "LINUX_4.5"
#endif
