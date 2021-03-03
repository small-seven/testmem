#include "tool_setup.h"
#ifdef HAVE_PWD_H
#  include <pwd.h>
#endif
#include <curl/mprintf.h>
#include "tool_homedir.h"
#include "memdebug.h" /* keep this as LAST include */
#if defined(HAVE_GETPWUID) && defined(HAVE_GETEUID)
#endif /* PWD-stuff */
#ifdef WIN32
#endif /* WIN32 */
