#include "test.h"
#include "memdebug.h"
#define F_RESUME        (1 << 0)        /* resume/range. */
#define F_HTTP416       (1 << 1)        /* Server returns http code 416. */
#define F_FAIL          (1 << 2)        /* Fail on error. */
#define F_CONTENTRANGE  (1 << 3)        /* Server sends content-range hdr. */
#define F_IGNOREBODY    (1 << 4)        /* Body should be ignored. */
typedef struct {
  unsigned int flags; /* ORed flags as above. */
  CURLcode result; /* Code that should be returned by curl_easy_perform(). */
}  testparams;
