#include "tool_setup.h"
#include <sys/stat.h>
#ifdef WIN32
#  include <direct.h>
#endif
#define ENABLE_CURLX_PRINTF
#include "curlx.h"
#include "tool_dirhie.h"
#include "memdebug.h" /* keep this as LAST include */
#ifdef NETWARE
#  ifndef __NOVELL_LIBC__
#    define mkdir mkdir_510
#  endif
#endif
#if defined(WIN32) || (defined(MSDOS) && !defined(__DJGPP__))
#  define mkdir(x,y) (mkdir)((x))
#  ifndef F_OK
#    define F_OK 0
#  endif
#endif
#ifdef EACCES
#endif
#ifdef ENAMETOOLONG
#endif
#ifdef EROFS
#endif
#ifdef ENOSPC
#endif
#ifdef EDQUOT
#endif
#if defined(WIN32) || defined(__DJGPP__)
#define PATH_DELIMITERS "\\/"
#else
#define PATH_DELIMITERS DIR_CHAR
#endif
#if defined(MSDOS) || defined(WIN32)
#endif
