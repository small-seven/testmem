#include "config.h"
#include "internal.h"
#include "mem.h"
#include <stdarg.h>
#include <fcntl.h>
#include <sys/stat.h>
#if HAVE_UNISTD_H
#include <unistd.h>
#endif
#if HAVE_IO_H
#include <io.h>
#endif
#ifdef _WIN32
#undef open
#undef lseek
#undef stat
#undef fstat
#include <windows.h>
#include <share.h>
#include <errno.h>
#include "wchar_filename.h"
#define open win32_open
#endif
#ifdef O_CLOEXEC
#endif
#ifdef O_NOINHERIT
#endif
#if HAVE_FCNTL
#endif
typedef struct FileLogContext {
    const AVClass *class;
    int   log_offset;
    void *log_ctx;
} FileLogContext;
#if !HAVE_MKSTEMP
#undef free
#else
#endif
#if !HAVE_MKSTEMP
#   ifndef O_BINARY
#       define O_BINARY 0
#   endif
#   ifndef O_EXCL
#       define O_EXCL 0
#   endif
#else
#if defined(_WIN32) || defined (__ANDROID__) || defined(__DJGPP__)
#endif
#endif
#ifdef O_BINARY
#endif
