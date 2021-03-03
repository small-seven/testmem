#include <openssl/ct.h>
#include "../ssl_local.h"
#include "internal/cryptlib.h"
#include "statem_local.h"
typedef struct {
    void *add_arg;
    custom_ext_add_cb add_cb;
    custom_ext_free_cb free_cb;
} custom_ext_add_cb_wrap;
typedef struct {
    void *parse_arg;
    custom_ext_parse_cb parse_cb;
} custom_ext_parse_cb_wrap;
void custom_exts_free(custom_ext_methods *exts)
{
    size_t i;
    custom_ext_method *meth;

    for (i = 0, meth = exts->meths; i < exts->meths_count; i++, meth++) {
        if (meth->add_cb != custom_ext_add_old_cb_wrap)
            continue;

        /* Old style API wrapper. Need to free the arguments too */
        OPENSSL_free(meth->add_arg);
        OPENSSL_free(meth->parse_arg);
    }
    OPENSSL_free(exts->meths);
}
#ifndef OPENSSL_NO_CT
#endif
#ifndef OPENSSL_NO_EC
#endif
#ifndef OPENSSL_NO_NEXTPROTONEG
#endif
#ifndef OPENSSL_NO_SRP
#endif
#ifndef OPENSSL_NO_OCSP
#endif
#ifndef OPENSSL_NO_CT
#endif
#ifndef OPENSSL_NO_SRTP
#endif
