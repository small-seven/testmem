#include "curl_setup.h"
#include <curl/curl.h>
#include "urldata.h"
#include "url.h"
#include "progress.h"
#include "multiif.h"
#include "sendf.h"
#include "conncache.h"
#include "share.h"
#include "sigpipe.h"
#include "connect.h"
#include "curl_printf.h"
#include "curl_memory.h"
#include "memdebug.h"
#define HASHKEY_SIZE 128
static void bundle_destroy(struct connectbundle *bundle)
{
  if(!bundle)
    return;

  Curl_llist_destroy(&bundle->conn_list, NULL);

  free(bundle);
}
void Curl_conncache_destroy(struct conncache *connc)
{
  if(connc)
    Curl_hash_destroy(&connc->hash);
}
#if 0
#endif
