#include "gzguts.h"
#if defined(STDC) || defined(Z_HAVE_STDARG_H)
#include <stdarg.h>
#ifdef NO_vsnprintf
#  ifdef HAS_vsprintf_void
#  else
#  endif
#else
#  ifdef HAS_vsnprintf_void
#  else
#  endif
#endif
#else /* !STDC && !Z_HAVE_STDARG_H */
#ifdef NO_snprintf
#  ifdef HAS_sprintf_void
#  else
#  endif
#else
#  ifdef HAS_snprintf_void
#  else
#  endif
#endif
#endif
