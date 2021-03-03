#include "test.h"
#ifdef HAVE_LOCALE_H
#  include <locale.h> /* for setlocale() */
#endif
#ifdef HAVE_IO_H
#  include <io.h> /* for setmode() */
#endif
#ifdef HAVE_FCNTL_H
#  include <fcntl.h> /* for setmode() */
#endif
#ifdef USE_NSS
#include <nspr.h>
#endif
#ifdef CURLDEBUG
#  define MEMDEBUG_NODEFINES
#  include "memdebug.h"
#endif
#ifdef USE_WINSOCK
#endif
#ifdef UNITTESTS
#endif
#ifdef CURLDEBUG
#else
#  define memory_tracking_init() Curl_nop_stmt
#endif
#ifdef O_BINARY
#  ifdef __HIGHC__
#  else
#  endif
#endif
#ifdef HAVE_SETLOCALE
#endif
#ifdef USE_NSS
#endif
