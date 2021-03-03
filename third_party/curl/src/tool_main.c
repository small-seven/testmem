#include "tool_setup.h"
#include <sys/stat.h>
#ifdef HAVE_SIGNAL_H
#include <signal.h>
#endif
#ifdef USE_NSS
#include <nspr.h>
#include <plarenas.h>
#endif
#define ENABLE_CURLX_PRINTF
#include "curlx.h"
#include "tool_cfgable.h"
#include "tool_convert.h"
#include "tool_doswin.h"
#include "tool_msgs.h"
#include "tool_operate.h"
#include "tool_panykey.h"
#include "tool_vms.h"
#include "tool_main.h"
#include "tool_libinfo.h"
#include "memdebug.h" /* keep this as LAST include */
#ifdef __VMS
#endif
#ifdef __MINGW32__
#endif /* __MINGW32__ */
#ifndef UNITTESTS
#ifdef HAVE_PIPE
#endif
#ifdef CURLDEBUG
#else
#  define memory_tracking_init() Curl_nop_stmt
#endif
#if defined(__DJGPP__) || defined(__GO32__)
#endif
static void main_free(struct GlobalConfig *config)
{
  /* Cleanup the easy handle */
  /* Main cleanup */
  curl_global_cleanup();
  convert_cleanup();
  metalink_cleanup();
#ifdef USE_NSS
  if(PR_Initialized()) {
    /* prevent valgrind from reporting still reachable mem from NSRP arenas */
    PL_ArenaFinish();
    /* prevent valgrind from reporting possibly lost memory (fd cache, ...) */
    PR_Cleanup();
  }
#endif
  free_globalconfig(config);

  /* Free the config structures */
  config_free(config->last);
  config->first = NULL;
  config->last = NULL;
}
#ifdef WIN32
#ifndef ENABLE_VIRTUAL_TERMINAL_PROCESSING
#endif
#else
#define configure_terminal()
#endif
#ifdef WIN32
#endif
#ifdef WIN32
#endif
#if defined(HAVE_SIGNAL) && defined(SIGPIPE)
#endif
#ifdef __SYMBIAN32__
#endif
#ifdef __NOVELL_LIBC__
#endif
#ifdef __VMS
#else
#endif
#endif /* ndef UNITTESTS */
