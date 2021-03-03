#include "e_os.h"
#include <stdio.h>
#include <string.h>
#include "internal/conf.h"
#include "crypto/ctype.h"
#include <openssl/crypto.h>
#include <openssl/err.h>
#include <openssl/conf.h>
#include <openssl/conf_api.h>
#include <openssl/lhash.h>
#ifdef OPENSSL_SYS_VMS
#else
#endif
#ifndef OPENSSL_NO_STDIO
#endif
void CONF_free(LHASH_OF(CONF_VALUE) *conf)
{
    CONF ctmp;
    CONF_set_nconf(&ctmp, conf);
    NCONF_free_data(&ctmp);
}
#ifndef OPENSSL_NO_STDIO
#endif
void NCONF_free(CONF *conf)
{
    if (conf == NULL)
        return;
    conf->meth->destroy(conf);
}
void NCONF_free_data(CONF *conf)
{
    if (conf == NULL)
        return;
    conf->meth->destroy_data(conf);
}
#ifndef OPENSSL_NO_STDIO
#endif
#ifndef OPENSSL_NO_STDIO
#endif
#ifndef OPENSSL_NO_STDIO
#endif
void OPENSSL_INIT_free(OPENSSL_INIT_SETTINGS *settings)
{
    free(settings->filename);
    free(settings->appname);
    free(settings);
}
