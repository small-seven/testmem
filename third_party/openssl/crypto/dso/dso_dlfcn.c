#ifndef _GNU_SOURCE
# define _GNU_SOURCE            /* make sure dladdr is declared */
#endif
#include "dso_local.h"
#include "e_os.h"
#ifdef DSO_DLFCN
# ifdef HAVE_DLFCN_H
#  ifdef __osf__
#   define __EXTENSIONS__
#  endif
#  include <dlfcn.h>
#  define HAVE_DLINFO 1
#  if defined(__SCO_VERSION__) || defined(_SCO_ELF) || \
#   undef HAVE_DLINFO
#  endif
# endif
# define DSO_MAX_TRANSLATED_SIZE 256
# if defined(__OpenBSD__) || defined(__NetBSD__)
#  ifdef DL_LAZY
#   define DLOPEN_FLAG DL_LAZY
#  else
#   ifdef RTLD_NOW
#    define DLOPEN_FLAG RTLD_NOW
#   else
#    define DLOPEN_FLAG 0
#   endif
#  endif
# else
#  define DLOPEN_FLAG RTLD_NOW  /* Hope this works everywhere else */
# endif
# ifdef RTLD_GLOBAL
# endif
# ifdef _AIX
# endif
# ifdef __sgi
#  include <rld_interface.h>
#  ifndef _RLD_INTERFACE_DLFCN_H_DLADDR
#   define _RLD_INTERFACE_DLFCN_H_DLADDR
typedef struct Dl_info {
    const char *dli_fname;
    void *dli_fbase;
    const char *dli_sname;
    void *dli_saddr;
    int dli_version;
    int dli_reserved1;
    long dli_reserved[4];
} Dl_info;
#  else
typedef struct Dl_info Dl_info;
#  endif
#  define _RLD_DLADDR             14

static int dladdr(void *address, Dl_info *dl)
{
    void *v;
    v = _rld_new_interface(_RLD_DLADDR, address, dl);
    return (int)v;
}
# endif                         /* __sgi */
# ifdef _AIX
#  include <sys/ldr.h>
#  include <errno.h>
#  define DLFCN_LDINFO_SIZE 86976
typedef struct Dl_info {
    const char *dli_fname;
} Dl_info;
# endif                         /* _AIX */
# ifdef HAVE_DLINFO
#  ifdef _AIX
#  endif
#  ifdef _AIX
#  endif
# endif
#endif                          /* DSO_DLFCN */
