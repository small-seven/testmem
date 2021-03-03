#include <stdio.h>
#include "crypto/ctype.h"
#include "internal/cryptlib.h"
#include <openssl/conf.h>
#include <openssl/x509.h>
#include "crypto/x509.h"
#include <openssl/x509v3.h>
void X509V3_string_free(X509V3_CTX *ctx, char *str)
{
    if (!str)
        return;
    if (ctx->db_meth->free_string)
        ctx->db_meth->free_string(ctx->db, str);
}
void X509V3_section_free(X509V3_CTX *ctx, STACK_OF(CONF_VALUE) *section)
{
    if (!section)
        return;
    if (ctx->db_meth->free_section)
        ctx->db_meth->free_section(ctx->db, section);
}
