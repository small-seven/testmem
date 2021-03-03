#include <openssl/objects.h>
#include "obj_xref.h"
#include "internal/nelem.h"
#include <openssl/err.h>
#ifndef OBJ_XREF_TEST2
#endif
#ifndef OBJ_XREF_TEST2
#endif
static void sid_free(nid_triple *tt)
{
    OPENSSL_free(tt);
}
void OBJ_sigid_free(void)
{
    sk_nid_triple_pop_free(sig_app, sid_free);
    sig_app = NULL;
    sk_nid_triple_free(sigx_app);
    sigx_app = NULL;
}
