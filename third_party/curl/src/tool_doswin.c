#include "tool_setup.h"
#if defined(MSDOS) || defined(WIN32)
#if defined(HAVE_LIBGEN_H) && defined(HAVE_BASENAME)
#  include <libgen.h>
#endif
#ifdef WIN32
#  include <tlhelp32.h>
#  include "tool_cfgable.h"
#  include "tool_libinfo.h"
#endif
#include "tool_bname.h"
#include "tool_doswin.h"
#include "memdebug.h" /* keep this as LAST include */
#ifdef WIN32
#  undef  PATH_MAX
#  define PATH_MAX MAX_PATH
#endif
#ifndef S_ISCHR
#  ifdef S_IFCHR
#    define S_ISCHR(m) (((m) & S_IFMT) == S_IFCHR)
#  else
#    define S_ISCHR(m) (0) /* cannot tell if file is a device */
#  endif
#endif
#ifdef WIN32
#  define _use_lfn(f) (1)   /* long file names always available */
#elif !defined(__DJGPP__) || (__DJGPP__ < 2)  /* DJGPP 2.0 has _use_lfn() */
#  define _use_lfn(f) (0)  /* long file names never available */
#elif defined(__DJGPP__)
#  include <fcntl.h>                /* _use_lfn(f) prototype */
#endif
#ifndef UNITTESTS
#ifdef MSDOS
#endif
#endif /* !UNITTESTS (static declarations used if no unit tests) */
#ifndef MSDOS
#endif
#ifndef MSDOS
#endif
#ifdef MSDOS
#endif
#if defined(MSDOS) || defined(UNITTESTS)
#endif /* MSDOS || UNITTESTS */
#ifdef MSDOS
#endif
#ifndef MSDOS
#endif
#ifdef MSDOS
#endif
#if defined(MSDOS) && (defined(__DJGPP__) || defined(__GO32__))
#endif /* MSDOS && (__DJGPP__ || __GO32__) */
#ifdef WIN32
#ifdef UNICODE
#else
#endif
#endif /* WIN32 */
#endif /* MSDOS || WIN32 */
