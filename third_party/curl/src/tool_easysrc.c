#include "tool_setup.h"
#include "slist_wc.h"
#ifndef CURL_DISABLE_LIBCURL_OPTION
#define ENABLE_CURLX_PRINTF
#include "curlx.h"
#include "tool_cfgable.h"
#include "tool_easysrc.h"
#include "tool_msgs.h"
#include "memdebug.h" /* keep this as LAST include */
static void easysrc_free(void)
{
  slist_wc_free_all(easysrc_decl);
  easysrc_decl = NULL;
  slist_wc_free_all(easysrc_data);
  easysrc_data = NULL;
  slist_wc_free_all(easysrc_code);
  easysrc_code = NULL;
  slist_wc_free_all(easysrc_toohard);
  easysrc_toohard = NULL;
  slist_wc_free_all(easysrc_clean);
  easysrc_clean = NULL;
}
#define CHKRET(v) do {CURLcode ret = (v); if(ret) return ret;} while(0)
#endif /* CURL_DISABLE_LIBCURL_OPTION */
