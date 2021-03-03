#include "tool_setup.h"
#ifdef HAVE_SYS_SELECT_H
#  include <sys/select.h>
#endif
#ifdef HAVE_POLL_H
#  include <poll.h>
#elif defined(HAVE_SYS_POLL_H)
#  include <sys/poll.h>
#endif
#ifdef MSDOS
#  include <dos.h>
#endif
#include "tool_sleep.h"
#include "memdebug.h" /* keep this as LAST include */
#if defined(MSDOS)
#elif defined(WIN32)
#elif defined(HAVE_POLL_FINE)
#else
#endif
