#include <iconv.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <stdarg.h>
#pragma enum(int)
#include "curl.h"
#include "mprintf.h"
#include "slist.h"
#include "urldata.h"
#include "url.h"
#include "setopt.h"
#include "getinfo.h"
#include "ccsidcurl.h"
#include "os400sys.h"
#ifndef SIZE_MAX
#define SIZE_MAX        ((size_t) ~0)   /* Is unsigned on OS/400. */
#endif
#define ASCII_CCSID     819     /* Use ISO-8859-1 as ASCII. */
#define NOCONV_CCSID    65535   /* No conversion. */
#define ICONV_ID_SIZE   32      /* Size of iconv_open() code identifier. */
#define ICONV_OPEN_ERROR(t)     ((t).return_value == -1)
#define ALLOC_GRANULE   8       /* Alloc. granule for curl_formadd_ccsid(). */
#if CURLVERSION_NOW != CURLVERSION_FOURTH
#error curl_version_info_data structure has changed: upgrade this procedure.
#endif
typedef struct {
  curl_formget_callback append;
  void *                arg;
  unsigned int          ccsid;
}   cfcdata;
