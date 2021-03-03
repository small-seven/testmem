#include "pngpriv.h"
#ifdef PNG_WRITE_SUPPORTED
#ifdef PNG_STDIO_SUPPORTED
#endif
#ifdef PNG_WRITE_FLUSH_SUPPORTED
#  ifdef PNG_STDIO_SUPPORTED
#  endif
#endif
#ifdef PNG_STDIO_SUPPORTED
#else
#endif
#ifdef PNG_WRITE_FLUSH_SUPPORTED
#  ifdef PNG_STDIO_SUPPORTED
#  else
#  endif
#else
#endif /* WRITE_FLUSH */
#ifdef PNG_READ_SUPPORTED
#endif
#endif /* WRITE */
