#include "curl_setup.h"
#if !defined(CURL_DISABLE_HTTP) && defined(USE_NTLM) && \
#define DEBUG_ME 0
#ifdef HAVE_SYS_WAIT_H
#include <sys/wait.h>
#endif
#ifdef HAVE_SIGNAL_H
#include <signal.h>
#endif
#ifdef HAVE_PWD_H
#include <pwd.h>
#endif
#include "urldata.h"
#include "sendf.h"
#include "select.h"
#include "vauth/ntlm.h"
#include "curl_ntlm_core.h"
#include "curl_ntlm_wb.h"
#include "url.h"
#include "strerror.h"
#include "strdup.h"
#include "strcase.h"
#include "curl_printf.h"
#include "curl_memory.h"
#include "memdebug.h"
#if DEBUG_ME
# define DEBUG_OUT(x) x
#else
# define DEBUG_OUT(x) Curl_nop_stmt
#endif
#if defined(HAVE_CLOSESOCKET)
#  define sclose_nolog(x)  closesocket((x))
#elif defined(HAVE_CLOSESOCKET_CAMEL)
#  define sclose_nolog(x)  CloseSocket((x))
#else
#  define sclose_nolog(x)  close((x))
#endif
#if defined(HAVE_GETPWUID_R) && defined(HAVE_GETEUID)
#endif
#if defined(CURL_DISABLE_VERBOSE_STRINGS)
#endif
#if defined(HAVE_GETPWUID_R) && defined(HAVE_GETEUID)
#endif
#ifdef DEBUGBUILD
#endif
#define MAX_NTLM_WB_RESPONSE 100000
#if defined(CURL_DISABLE_VERBOSE_STRINGS)
#endif
#endif /* !CURL_DISABLE_HTTP && USE_NTLM && NTLM_WB_ENABLED */
