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
#endif
#include "unzip.h"
#define CASESENSITIVITY (0)
#define WRITEBUFFERSIZE (8192)
#define MAXFILENAME (256)
#ifdef _WIN32
#define USEWIN32IOAPI
#include "iowin32.h"
#endif
#ifdef _WIN32
#else
#ifdef unix || __APPLE__
#endif
#endif
#ifdef _WIN32
#elif unix
#elif __APPLE__
#endif
#        ifdef USEWIN32IOAPI
#        endif
#        ifdef USEWIN32IOAPI
#        else
#        endif
#            ifdef USEWIN32IOAPI
#            else
#            endif
#ifdef _WIN32
#else
#endif
