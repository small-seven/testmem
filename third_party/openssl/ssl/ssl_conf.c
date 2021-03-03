#include <stdio.h>
#include "ssl_local.h"
#include <openssl/conf.h>
#include <openssl/objects.h>
#include <openssl/dh.h>
#include "internal/nelem.h"
typedef struct {
    const char *name;
    int namelen;
    unsigned int name_flags;
    unsigned long option_value;
} ssl_flag_tbl;
typedef struct {
    unsigned long option_value;
    unsigned int name_flags;
} ssl_switch_tbl;
#define SSL_TFLAG_INV   0x1
#define SSL_TFLAG_TYPE_MASK 0xf00
#define SSL_TFLAG_OPTION    0x000
#define SSL_TFLAG_CERT      0x100
#define SSL_TFLAG_VFY       0x200
#define SSL_TFLAG_CLIENT SSL_CONF_FLAG_CLIENT
#define SSL_TFLAG_SERVER SSL_CONF_FLAG_SERVER
#define SSL_TFLAG_BOTH (SSL_TFLAG_CLIENT|SSL_TFLAG_SERVER)
#define SSL_FLAG_TBL(str, flag) \
#define SSL_FLAG_TBL_SRV(str, flag) \
#define SSL_FLAG_TBL_CLI(str, flag) \
#define SSL_FLAG_TBL_INV(str, flag) \
#define SSL_FLAG_TBL_SRV_INV(str, flag) \
#define SSL_FLAG_TBL_CERT(str, flag) \
#define SSL_FLAG_VFY_CLI(str, flag) \
#define SSL_FLAG_VFY_SRV(str, flag) \
#ifndef OPENSSL_NO_EC
#endif
#ifndef OPENSSL_NO_DH
#endif
typedef struct {
    int (*cmd) (SSL_CONF_CTX *cctx, const char *value);
    const char *str_file;
    const char *str_cmdline;
    unsigned short flags;
    unsigned short value_type;
} ssl_conf_cmd_tbl;
#define SSL_CONF_CMD(name, cmdopt, flags, type) \
#define SSL_CONF_CMD_STRING(name, cmdopt, flags) \
#define SSL_CONF_CMD_SWITCH(name, flags) \
#ifndef OPENSSL_NO_EC
#endif
#ifndef OPENSSL_NO_DH
#endif
void SSL_CONF_CTX_free(SSL_CONF_CTX *cctx)
{
    if (cctx) {
        size_t i;
        for (i = 0; i < SSL_PKEY_NUM; i++)
            OPENSSL_free(cctx->cert_filename[i]);
        OPENSSL_free(cctx->prefix);
        sk_X509_NAME_pop_free(cctx->canames, X509_NAME_free);
        OPENSSL_free(cctx);
    }
}
