#include "tool_setup.h"
#define ENABLE_CURLX_PRINTF
#include "curlx.h"
#include "tool_cfgable.h"
#include "tool_getparam.h"
#include "tool_helpers.h"
#include "tool_homedir.h"
#include "tool_msgs.h"
#include "tool_parsecfg.h"
#include "memdebug.h" /* keep this as LAST include */
#define ISSEP(x,dash) (!dash && (((x) == '=') || ((x) == ':')))
#ifdef WIN32
#endif
#ifndef WIN32
#else /* Windows */
#endif
#ifdef DEBUG_CONFIG
#endif
#ifdef DEBUG_CONFIG
#endif
