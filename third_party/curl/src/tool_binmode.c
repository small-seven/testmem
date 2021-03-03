#include "tool_setup.h"
#ifdef HAVE_SETMODE
#ifdef HAVE_IO_H
#  include <io.h>
#endif
#ifdef HAVE_FCNTL_H
#  include <fcntl.h>
#endif
#include "tool_binmode.h"
#include "memdebug.h" /* keep this as LAST include */
#ifdef O_BINARY
#  ifdef __HIGHC__
#  else
#  endif
#else
#endif
#endif /* HAVE_SETMODE */
