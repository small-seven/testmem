#include "curl_setup.h"
#include <curl/curl.h>
#include "mime.h"
#include "non-ascii.h"
#include "warnless.h"
#include "urldata.h"
#include "sendf.h"
#if (!defined(CURL_DISABLE_HTTP) && !defined(CURL_DISABLE_MIME)) || \
#if defined(HAVE_LIBGEN_H) && defined(HAVE_BASENAME)
#include <libgen.h>
#endif
#include "rand.h"
#include "slist.h"
#include "strcase.h"
#include "curl_printf.h"
#include "curl_memory.h"
#include "memdebug.h"
#ifdef WIN32
# ifndef R_OK
#  define R_OK 4
# endif
#endif
#define READ_ERROR                      ((size_t) -1)
#define STOP_FILLING                    ((size_t) -2)
#define QP_OK           1       /* Can be represented by itself. */
#define QP_SP           2       /* Space or tab. */
#define QP_CR           3       /* Carriage return. */
#define QP_LF           4       /* Line-feed. */
#ifndef __VMS
#define filesize(name, stat_data) (stat_data.st_size)
#define fopen_read fopen
#else
#include <fabdef.h>
#define filesize(name, stat_data) VmsSpecialSize(name, &stat_data)
#define fopen_read vmsfopenread
#endif
#ifndef HAVE_BASENAME
#define basename(x)  Curl_basename((x))
#endif
#ifdef CURL_DOES_CONVERSIONS
#endif
static size_t mime_mem_read(char *buffer, size_t size, size_t nitems,
                            void *instream)
{
  curl_mimepart *part = (curl_mimepart *) instream;
  size_t sz = curlx_sotouz(part->datasize - part->state.offset);
  (void) size;   /* Always 1.*/

  if(!nitems)
    return STOP_FILLING;

  if(sz > nitems)
    sz = nitems;

  if(sz)
    memcpy(buffer, part->data + curlx_sotouz(part->state.offset), sz);

  return sz;
}
static void mime_mem_free(void *ptr)
{
  Curl_safefree(((curl_mimepart *) ptr)->data);
}
static void mime_file_free(void *ptr)
{
  curl_mimepart *part = (curl_mimepart *) ptr;

  if(part->fp) {
    fclose(part->fp);
    part->fp = NULL;
  }
  Curl_safefree(part->data);
  part->data = NULL;
}
#ifdef CURL_DOES_CONVERSIONS
#endif
#ifdef CURL_DOES_CONVERSIONS
#endif
#ifdef CURL_DOES_CONVERSIONS
#endif
#ifdef CURL_DOES_CONVERSIONS
#endif
#ifdef CURL_DOES_CONVERSIONS
#endif
#ifdef CURL_DOES_CONVERSIONS
#endif
#ifdef CURL_DOES_CONVERSIONS
#endif
#ifdef CURL_DOES_CONVERSIONS
#endif
static void mime_subparts_free(void *ptr)
{
  curl_mime *mime = (curl_mime *) ptr;

  if(mime && mime->parent) {
    mime->parent->freefunc = NULL;  /* Be sure we won't be called again. */
    cleanup_part_content(mime->parent);  /* Avoid dangling pointer in part. */
  }
  curl_mime_free(mime);
}
void curl_mime_free(curl_mime *mime)
{
  curl_mimepart *part;

  if(mime) {
    mime_subparts_unbind(mime);  /* Be sure it's not referenced anymore. */
    while(mime->firstpart) {
      part = mime->firstpart;
      mime->firstpart = part->nextpart;
      Curl_mime_cleanpart(part);
      free(part);
    }
    free(mime);
  }
}
#else /* !CURL_DISABLE_HTTP || !CURL_DISABLE_SMTP || !CURL_DISABLE_IMAP */
void curl_mime_free(curl_mime *mime)
{
  (void) mime;
}
#endif /* if disabled */
