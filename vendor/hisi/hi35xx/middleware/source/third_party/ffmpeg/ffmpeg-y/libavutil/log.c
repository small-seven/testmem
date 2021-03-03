#include "config.h"
#if HAVE_UNISTD_H
#include <unistd.h>
#endif
#if HAVE_IO_H
#include <io.h>
#endif
#include <stdarg.h>
#include <stdlib.h>
#include "avutil.h"
#include "bprint.h"
#include "common.h"
#include "internal.h"
#include "log.h"
#include "thread.h"
#define LINE_SZ 1024
#if HAVE_VALGRIND_VALGRIND_H
#include <valgrind/valgrind.h>
#define BACKTRACE_LOGLEVEL AV_LOG_ERROR
#endif
#define NB_LEVELS 8
#if defined(_WIN32) && HAVE_SETCONSOLETEXTATTRIBUTE
#include <windows.h>
#else
#endif
#if defined(_WIN32) && HAVE_SETCONSOLETEXTATTRIBUTE
#elif HAVE_ISATTY
#else
#endif
#if defined(_WIN32) && HAVE_SETCONSOLETEXTATTRIBUTE
#else
#endif
#if HAVE_ISATTY
#endif
#if CONFIG_VALGRIND_BACKTRACE
#endif
