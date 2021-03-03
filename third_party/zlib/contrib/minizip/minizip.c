#if (!defined(_WIN32)) && (!defined(WIN32)) && (!defined(__APPLE__))
#endif
#ifdef __APPLE__
#define FOPEN_FUNC(filename, mode) fopen(filename, mode)
#define FTELLO_FUNC(stream) ftello(stream)
#define FSEEKO_FUNC(stream, offset, origin) fseeko(stream, offset, origin)
#else
#define FOPEN_FUNC(filename, mode) fopen64(filename, mode)
#define FTELLO_FUNC(stream) ftello64(stream)
#define FSEEKO_FUNC(stream, offset, origin) fseeko64(stream, offset, origin)
#endif
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <errno.h>
#include <fcntl.h>
#ifdef _WIN32
# include <direct.h>
# include <io.h>
#else
# include <unistd.h>
# include <utime.h>
# include <sys/types.h>
# include <sys/stat.h>
#endif
#include "zip.h"
#ifdef _WIN32
#endif
#define WRITEBUFFERSIZE (16384)
#define MAXFILENAME (256)
#ifdef _WIN32
#else
#ifdef unix || __APPLE__
#else
#endif
#endif
#        ifdef USEWIN32IOAPI
#        else
#        endif
