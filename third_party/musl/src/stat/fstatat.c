#define _BSD_SOURCE
#include <sys/stat.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <stdint.h>
#include <sys/sysmacros.h>
#include "syscall.h"
#include "kstat.h"
#if _REDIR_TIME64
#endif
#ifdef SYS_stat
#else
#endif
#ifdef SYS_lstat
#endif
#ifdef SYS_stat
#endif
#if _REDIR_TIME64
#endif
#if !_REDIR_TIME64
#endif
