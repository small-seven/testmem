#include "tool_setup.h"
#if defined(__SYMBIAN32__) || defined(NETWARE)
#ifdef NETWARE
#  ifdef __NOVELL_LIBC__
#    include <screen.h>
#  else
#    include <nwconio.h>
#  endif
#endif
#include "tool_panykey.h"
#include "memdebug.h" /* keep this as LAST include */
#if defined(__SYMBIAN32__)
#elif defined(NETWARE)
#endif
#endif /* __SYMBIAN32__ || NETWARE */
