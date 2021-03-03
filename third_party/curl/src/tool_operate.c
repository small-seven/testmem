#include "tool_setup.h"
#ifdef HAVE_FCNTL_H
#  include <fcntl.h>
#endif
#ifdef HAVE_LOCALE_H
#  include <locale.h>
#endif
#ifdef HAVE_SYS_SELECT_H
#  include <sys/select.h>
#endif
#ifdef __VMS
#  include <fabdef.h>
#endif
#ifdef __AMIGA__
#  include <proto/dos.h>
#endif
#include "strcase.h"
#define ENABLE_CURLX_PRINTF
#include "curlx.h"
#include "tool_binmode.h"
#include "tool_cfgable.h"
#include "tool_cb_dbg.h"
#include "tool_cb_hdr.h"
#include "tool_cb_prg.h"
#include "tool_cb_rea.h"
#include "tool_cb_see.h"
#include "tool_cb_wrt.h"
#include "tool_dirhie.h"
#include "tool_doswin.h"
#include "tool_easysrc.h"
#include "tool_filetime.h"
#include "tool_getparam.h"
#include "tool_helpers.h"
#include "tool_homedir.h"
#include "tool_libinfo.h"
#include "tool_main.h"
#include "tool_metalink.h"
#include "tool_msgs.h"
#include "tool_operate.h"
#include "tool_operhlp.h"
#include "tool_paramhlp.h"
#include "tool_parsecfg.h"
#include "tool_setopt.h"
#include "tool_sleep.h"
#include "tool_urlglob.h"
#include "tool_util.h"
#include "tool_writeout.h"
#include "tool_xattr.h"
#include "tool_vms.h"
#include "tool_help.h"
#include "tool_hugehelp.h"
#include "tool_progress.h"
#include "memdebug.h" /* keep this as LAST include */
#ifdef CURLDEBUG
#endif
#define CURLseparator  "--_curl_--"
#ifndef O_BINARY
#  define O_BINARY 0
#endif
#define CURL_CA_CERT_ERRORMSG                                               \
#ifdef __VMS
#endif /* __VMS */
#define BUFFER_SIZE (100*1024)
#ifdef __VMS
#else
#endif
#ifdef __VMS
#endif
#ifdef USE_METALINK
#endif /* USE_METALINK */
#ifdef USE_METALINK
#endif /* USE_METALINK */
#ifdef HAVE_FTRUNCATE
#else
#endif
#ifdef __VMS
#else
#endif
#ifdef USE_METALINK
#endif /* USE_METALINK */
#ifdef USE_METALINK
#endif /* USE_METALINK */
#ifndef CURL_DISABLE_LIBCURL_OPTION
#endif
#ifdef CURLDEBUG
#endif
#ifdef WIN32
#endif
#ifdef HAVE_SETLOCALE
#endif
#ifndef CURL_DISABLE_LIBCURL_OPTION
#endif
#ifndef CURL_DISABLE_LIBCURL_OPTION
#endif
#ifndef CURL_DISABLE_LIBCURL_OPTION
#endif
