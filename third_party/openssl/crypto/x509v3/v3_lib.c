#include <stdio.h>
#include "internal/cryptlib.h"
#include <openssl/conf.h>
#include <openssl/x509v3.h>
#include "ext_dat.h"
#include "standard_exts.h"
static void ext_list_free(X509V3_EXT_METHOD *ext)
{
    if (ext->ext_flags & X509V3_EXT_DYNAMIC)
        OPENSSL_free(ext);
}
