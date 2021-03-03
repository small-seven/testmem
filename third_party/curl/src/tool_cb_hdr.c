#include "tool_setup.h"
#include "strcase.h"
#define ENABLE_CURLX_PRINTF
#include "curlx.h"
#include "tool_cfgable.h"
#include "tool_doswin.h"
#include "tool_msgs.h"
#include "tool_cb_hdr.h"
#include "tool_cb_wrt.h"
#include "tool_operate.h"
#include "memdebug.h" /* keep this as LAST include */
#ifdef WIN32
#define BOLD
#define BOLDOFF
#else
#define BOLD "\x1b[1m"
#define BOLDOFF "\x1b[0m"
#endif
#ifdef DEBUGBUILD
#endif
#if defined(MSDOS) || defined(WIN32)
#endif /* MSDOS || WIN32 */
#ifdef DEBUGBUILD
#endif
