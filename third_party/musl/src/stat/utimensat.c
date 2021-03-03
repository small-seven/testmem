#include <sys/stat.h>
#include <sys/time.h>
#include <fcntl.h>
#include <errno.h>
#include <unsupported_api.h>
#include "syscall.h"
#define IS32BIT(x) !((x)+0x80000000ULL>>32)
#define NS_SPECIAL(ns) ((ns)==UTIME_NOW || (ns)==UTIME_OMIT)
#ifdef SYS_utimensat_time64
#else
#endif
#ifdef SYS_futimesat
#endif
