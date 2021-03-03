#include "tool_setup.h"
#ifdef HAVE_SYS_IOCTL_H
#include <sys/ioctl.h>
#endif
#define ENABLE_CURLX_PRINTF
#include "curlx.h"
#include "tool_cfgable.h"
#include "tool_cb_prg.h"
#include "tool_util.h"
#include "tool_operate.h"
#include "memdebug.h" /* keep this as LAST include */
#ifdef HAVE_TERMIOS_H
#  include <termios.h>
#elif defined(HAVE_TERMIO_H)
#  include <termio.h>
#endif
#define MAX_BARLENGTH 256
#if (SIZEOF_CURL_OFF_T == 4)
#  define CURL_OFF_T_MAX CURL_OFF_T_C(0x7FFFFFFF)
#else
#  define CURL_OFF_T_MAX CURL_OFF_T_C(0x7FFFFFFFFFFFFFFF)
#endif
#ifdef TIOCGSIZE
#elif defined(TIOCGWINSZ)
#elif defined(WIN32)
#endif /* TIOCGSIZE */
