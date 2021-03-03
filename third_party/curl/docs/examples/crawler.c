#include <libxml/HTMLparser.h>
#include <libxml/xpath.h>
#include <libxml/uri.h>
#include <curl/curl.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <signal.h>
typedef struct {
  char *buf;
  size_t size;
} memory;
#ifdef CURLPIPE_MULTIPLEX
#endif
