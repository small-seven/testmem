#define _GNU_SOURCE
#include "config.h"
#include "test.h"
#include <errno.h>
#include <signal.h>
#include <unistd.h>
#include <fcntl.h>
#include <inttypes.h>
#include "ltp_signal.h"
#ifndef HAVE_SIGNALFD
#define  USE_STUB
#endif
#if defined HAVE_SYS_SIGNALFD_H
#include <sys/signalfd.h>
#elif defined HAVE_LINUX_SIGNALFD_H
#include <linux/signalfd.h>
#define USE_OWNIMPL
#else
#define  USE_STUB
#endif
#ifndef HAVE_STRUCT_SIGNALFD_SIGINFO_SSI_SIGNO
#define USE_STUB
#endif
#ifdef USE_STUB
#else
#if defined USE_OWNIMPL
#include "lapi/syscalls.h"
#endif
#endif
