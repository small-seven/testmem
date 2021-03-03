#include "tool_setup.h"
#define ENABLE_CURLX_PRINTF
#include "curlx.h"
#include "tool_cfgable.h"
#include "tool_doswin.h"
#include "tool_urlglob.h"
#include "tool_vms.h"
#include "memdebug.h" /* keep this as LAST include */
#define GLOBERROR(string, column, code) \
#if defined(MSDOS) || defined(WIN32)
#endif /* MSDOS || WIN32 */
