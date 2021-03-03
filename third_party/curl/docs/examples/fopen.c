#include <stdio.h>
#include <string.h>
#ifndef WIN32
#  include <sys/time.h>
#endif
#include <stdlib.h>
#include <errno.h>
#include <curl/curl.h>
typedef struct fcurl_data URL_FILE;

/* exported functions */
URL_FILE *url_fopen(const char *url, const char *operation);
int url_fclose(URL_FILE *file);
int url_feof(URL_FILE *file);
size_t url_fread(void *ptr, size_t size, size_t nmemb, URL_FILE *file);
char *url_fgets(char *ptr, size_t size, URL_FILE *file);
void url_rewind(URL_FILE *file);

/* we use a global one for convenience */
static CURLM *multi_handle;

/* curl calls this routine to get more data */
static size_t write_callback(char *buffer,
                             size_t size,
                             size_t nitems,
                             void *userp)
{
  char *newbuff;
  size_t rembuff;

  URL_FILE *url = (URL_FILE *)userp;
  size *= nitems;

  rembuff = url->buffer_len - url->buffer_pos; /* remaining space in buffer */

  if(size > rembuff) {
    /* not enough space in buffer */
    newbuff = realloc(url->buffer, url->buffer_len + (size - rembuff));
    if(newbuff == NULL) {
      fprintf(stderr, "callback buffer grow failed\n");
      size = rembuff;
    }
#ifdef _WIN32
#else
#endif
#define FGETSFILE "fgets.test"
#define FREADFILE "fread.test"
#define REWINDFILE "rewind.test"
