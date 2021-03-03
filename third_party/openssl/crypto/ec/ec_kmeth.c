#include <string.h>
#include <openssl/ec.h>
#include <openssl/engine.h>
#include <openssl/err.h>
#include "ec_local.h"
#ifndef OPENSSL_NO_ENGINE
#endif
#ifndef OPENSSL_NO_ENGINE
#endif
void EC_KEY_METHOD_free(EC_KEY_METHOD *meth)
{
    if (meth->flags & EC_KEY_METHOD_DYNAMIC)
        OPENSSL_free(meth);
}
