#include "curl_setup.h"
#include <curl/curl.h>
#include "hash.h"
#include "llist.h"
#include "curl_memory.h"
#include "memdebug.h"
#define FETCH_LIST(x,y,z) &x->table[x->hash_func(y, z, x->slots)]
#if defined(DEBUGBUILD) && defined(AGGRESIVE_TEST)
#endif
Curl_hash_destroy(struct curl_hash *h)
{
  int i;

  for(i = 0; i < h->slots; ++i) {
    Curl_llist_destroy(&h->table[i], (void *) h);
  }

  Curl_safefree(h->table);
  h->size = 0;
  h->slots = 0;
}
#if 0 /* useful function for debugging hashes and their contents */
#endif
