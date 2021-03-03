#include "curl_setup.h"
#include <curl/curl.h>
#include "formdata.h"
#if !defined(CURL_DISABLE_HTTP) && !defined(CURL_DISABLE_MIME)
#if defined(HAVE_LIBGEN_H) && defined(HAVE_BASENAME)
#include <libgen.h>
#endif
#include "urldata.h" /* for struct Curl_easy */
#include "mime.h"
#include "non-ascii.h"
#include "vtls/vtls.h"
#include "strcase.h"
#include "sendf.h"
#include "strdup.h"
#include "rand.h"
#include "warnless.h"
#include "curl_printf.h"
#include "curl_memory.h"
#include "memdebug.h"
#define HTTPPOST_PTRNAME CURL_HTTPPOST_PTRNAME
#define HTTPPOST_FILENAME CURL_HTTPPOST_FILENAME
#define HTTPPOST_PTRCONTENTS CURL_HTTPPOST_PTRCONTENTS
#define HTTPPOST_READFILE CURL_HTTPPOST_READFILE
#define HTTPPOST_PTRBUFFER CURL_HTTPPOST_PTRBUFFER
#define HTTPPOST_CALLBACK CURL_HTTPPOST_CALLBACK
#define HTTPPOST_BUFFER CURL_HTTPPOST_BUFFER
#ifdef CURL_DOES_CONVERSIONS
#else
#endif
void curl_formfree(struct curl_httppost *form)
{
  struct curl_httppost *next;

  if(!form)
    /* no form to free, just get out of this */
    return;

  do {
    next = form->next;  /* the following form line */

    /* recurse to sub-contents */
    curl_formfree(form->more);

    if(!(form->flags & HTTPPOST_PTRNAME))
      free(form->name); /* free the name */
    if(!(form->flags &
         (HTTPPOST_PTRCONTENTS|HTTPPOST_BUFFER|HTTPPOST_CALLBACK))
      )
      free(form->contents); /* free the contents */
    free(form->contenttype); /* free the content type */
    free(form->showfilename); /* free the faked file name */
    free(form);       /* free the struct */
    form = next;
  } while(form); /* continue */
}
#ifdef CURL_DOES_CONVERSIONS
#endif
#else
void curl_formfree(struct curl_httppost *form)
{
  (void)form;
  /* does nothing HTTP is disabled */
}
#endif  /* if disabled */
