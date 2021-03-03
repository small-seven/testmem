#include <stdio.h>
#include "internal/cryptlib.h"
#include <openssl/buffer.h>
#define LIMIT_BEFORE_EXPANSION 0x5ffffffc
void BUF_MEM_free(BUF_MEM *a)
{
    if (a == NULL)
        return;
    if (a->data != NULL) {
        if (a->flags & BUF_MEM_FLAG_SECURE)
            OPENSSL_secure_clear_free(a->data, a->max);
        else
            OPENSSL_clear_free(a->data, a->max);
    }
    OPENSSL_free(a);
}
static char *sec_alloc_realloc(BUF_MEM *str, size_t len)
{
    char *ret;

    ret = OPENSSL_secure_malloc(len);
    if (str->data != NULL) {
        if (ret != NULL) {
            memcpy(ret, str->data, str->length);
            OPENSSL_secure_clear_free(str->data, str->length);
            str->data = NULL;
        }
    }
    return ret;
}
