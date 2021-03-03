#include "tool_setup.h"
#define ENABLE_CURLX_PRINTF
#include "curlx.h"
#include "tool_cfgable.h"
#include "tool_cb_see.h"
#include "memdebug.h" /* keep this as LAST include */
#define OUR_MAX_SEEK_L  2147483647L - 1L
#define OUR_MAX_SEEK_O  CURL_OFF_T_C(0x7FFFFFFF) - CURL_OFF_T_C(0x1)
#if(CURL_SIZEOF_CURL_OFF_T > SIZEOF_OFF_T) && !defined(USE_WIN32_LARGE_FILES)
#endif
#ifdef USE_TOOL_FTRUNCATE
#ifdef __BORLANDC__
#  define _lseeki64(hnd,ofs,whence) lseek(hnd,ofs,whence)
#endif
#ifdef __POCC__
#  if(__POCC__ < 450)
#    define _lseeki64(hnd,ofs,whence) _lseek(hnd,ofs,whence)
#  else
#    define _lseeki64(hnd,ofs,whence) _lseek64(hnd,ofs,whence)
#  endif
#endif
#ifdef _WIN32_WCE
#  undef _lseeki64
#  define _lseeki64(hnd,ofs,whence) lseek(hnd,ofs,whence)
#  undef _get_osfhandle
#  define _get_osfhandle(fd) (fd)
#endif
#endif /* USE_TOOL_FTRUNCATE */
