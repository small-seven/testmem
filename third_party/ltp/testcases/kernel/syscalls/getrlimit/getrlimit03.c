#include <inttypes.h>
#include <stdint.h>
#include <sys/time.h>
#include <sys/resource.h>
#include "tst_test.h"
#include "lapi/syscalls.h"
#include "lapi/abisize.h"
#define SIGNED_GETRLIMIT (__NR_ugetrlimit != __LTP__NR_INVALID_SYSCALL)
#if SIGNED_GETRLIMIT
#define __NR_getrlimit_ulong		__NR_ugetrlimit
#define __NR_getrlimit_ulong_str	"__NR_ugetrlimit"
#else
#define __NR_getrlimit_ulong		__NR_getrlimit
#define __NR_getrlimit_ulong_str	"__NR_getrlimit"
#endif
#ifndef HAVE_STRUCT_RLIMIT64
#endif
#if defined(__mips__) && defined(TST_ABI32)
#else
#endif
#if SIGNED_GETRLIMIT
#endif
#if SIGNED_GETRLIMIT
#endif
#if SIGNED_GETRLIMIT
#endif
#if SIGNED_GETRLIMIT
#endif
