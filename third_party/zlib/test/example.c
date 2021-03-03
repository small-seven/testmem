#include "zlib.h"
#include <stdio.h>
#ifdef STDC
#  include <string.h>
#  include <stdlib.h>
#endif
#if defined(VMS) || defined(RISCOS)
#  define TESTFILE "foo-gz"
#else
#  define TESTFILE "foo.gz"
#endif
#define CHECK_ERR(err, msg) { \
#ifdef Z_SOLO
void myfree(void *q, void *p)
{
    (void)q;
    free(p);
}
#else /* !Z_SOLO */
#ifdef NO_GZCOMPRESS
#else
#endif
#endif /* Z_SOLO */
#ifdef Z_SOLO
#else
#endif
