#include "config.h"
#include "file.h"
#include "internal.h"
#include "log.h"
#include "mem.h"
#include <fcntl.h>
#include <sys/stat.h>
#if HAVE_UNISTD_H
#include <unistd.h>
#endif
#if HAVE_IO_H
#include <io.h>
#endif
#if HAVE_MMAP
#include <sys/mman.h>
#elif HAVE_MAPVIEWOFFILE
#include <windows.h>
#endif
typedef struct FileLogContext {
    const AVClass *class;
    int   log_offset;
    void *log_ctx;
} FileLogContext;
#if HAVE_MMAP
#elif HAVE_MAPVIEWOFFILE
#else
#endif
#if HAVE_MMAP
#elif HAVE_MAPVIEWOFFILE
#else
#endif
