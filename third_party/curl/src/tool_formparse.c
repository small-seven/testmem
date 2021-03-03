#include "tool_setup.h"
#include "strcase.h"
#define ENABLE_CURLX_PRINTF
#include "curlx.h"
#include "tool_cfgable.h"
#include "tool_convert.h"
#include "tool_msgs.h"
#include "tool_binmode.h"
#include "tool_getparam.h"
#include "tool_paramhlp.h"
#include "tool_formparse.h"
#include "memdebug.h" /* keep this as LAST include */
#define CONST_FREE(x)           free((void *) (x))
#define CONST_SAFEFREE(x)       Curl_safefree(*((void **) &(x)))
#ifdef __VMS
#endif
void tool_mime_free(tool_mime *mime)
{
  if(mime) {
    if(mime->subparts)
      tool_mime_free(mime->subparts);
    if(mime->prev)
      tool_mime_free(mime->prev);
    CONST_SAFEFREE(mime->name);
    CONST_SAFEFREE(mime->filename);
    CONST_SAFEFREE(mime->type);
    CONST_SAFEFREE(mime->encoder);
    CONST_SAFEFREE(mime->data);
    curl_slist_free_all(mime->headers);
    free(mime);
  }
}
#ifdef CURL_DOES_CONVERSIONS
#else
#endif
#define NULL_CHECK(ptr, init, retcode) {                                \
#define SET_TOOL_MIME_PTR(m, field, retcode) {                          \
