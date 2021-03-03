#include "tool_setup.h"
#if defined(HAVE_STRCASECMP) && defined(HAVE_STRINGS_H)
#include <strings.h>
#endif
#include "tool_panykey.h"
#include "tool_help.h"
#include "tool_libinfo.h"
#include "tool_version.h"
#include "memdebug.h" /* keep this as LAST include */
#ifdef MSDOS
#  define USE_WATT32
#endif
#ifdef NETWARE
#  define PRINT_LINES_PAUSE 23
#endif
#ifdef __SYMBIAN32__
#  define PRINT_LINES_PAUSE 16
#endif
#ifdef PRINT_LINES_PAUSE
#endif
#ifdef HAVE_STRCASECMP
#elif defined(HAVE_STRCMPI)
#else
#endif
#ifdef CURL_PATCHSTAMP
#else
#endif
#ifdef USE_METALINK
#endif
