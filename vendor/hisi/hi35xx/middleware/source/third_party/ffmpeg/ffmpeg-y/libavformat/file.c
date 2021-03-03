#include "libavutil/avstring.h"
#include "libavutil/internal.h"
#include "libavutil/opt.h"
#include "avformat.h"
#if HAVE_DIRENT_H
#include <dirent.h>
#endif
#include <fcntl.h>
#if HAVE_IO_H
#include <io.h>
#endif
#if HAVE_UNISTD_H
#include <unistd.h>
#endif
#include <sys/stat.h>
#include <stdlib.h>
#include "os_support.h"
#include "url.h"
#ifndef S_ISFIFO
#  ifdef S_IFIFO
#    define S_ISFIFO(m) (((m) & S_IFMT) == S_IFIFO)
#  else
#    define S_ISFIFO(m) 0
#  endif
#endif
#ifndef S_ISLNK
#  ifdef S_IFLNK
#    define S_ISLNK(m) (((m) & S_IFLNK) == S_IFLNK)
#  else
#    define S_ISLNK(m) 0
#  endif
#endif
#ifndef S_ISSOCK
#  ifdef S_IFSOCK
#    define S_ISSOCK(m) (((m) & S_IFMT) == S_IFSOCK)
#  else
#    define S_ISSOCK(m) 0
#  endif
#endif
typedef struct FileContext {
    const AVClass *class;
    int fd;
    int trunc;
    int blocksize;
    int follow;
    int seekable;
#if HAVE_DIRENT_H
    DIR *dir;
#endif
} FileContext;
#if HAVE_ACCESS && defined(R_OK)
#else
#   ifndef _WIN32
#   else
#   endif
#endif
#if HAVE_UNISTD_H
#   ifdef _WIN32
#   endif
#else
#endif /* HAVE_UNISTD_H */
#if CONFIG_FILE_PROTOCOL
#ifdef O_BINARY
#endif
#if HAVE_LSTAT
#else
#endif /* HAVE_LSTAT */
#if HAVE_LSTAT
#else
#endif /* HAVE_LSTAT */
#if HAVE_LSTAT
#else
#endif /* HAVE_LSTAT */
#endif /* CONFIG_FILE_PROTOCOL */
#if CONFIG_PIPE_PROTOCOL
#if HAVE_SETMODE
#endif
#endif /* CONFIG_PIPE_PROTOCOL */
