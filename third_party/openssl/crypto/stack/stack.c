#include <stdio.h>
#include "internal/cryptlib.h"
#include "internal/numbers.h"
#include <openssl/stack.h>
#include <openssl/objects.h>
#include <errno.h>
#include <openssl/e_os2.h>      /* For ossl_inline */
void OPENSSL_sk_pop_free(OPENSSL_STACK *st, OPENSSL_sk_freefunc func)
{
    int i;

    if (st == NULL)
        return;
    for (i = 0; i < st->num; i++)
        if (st->data[i] != NULL)
            func((char *)st->data[i]);
    OPENSSL_sk_free(st);
}
void OPENSSL_sk_free(OPENSSL_STACK *st)
{
    if (st == NULL)
        return;
    OPENSSL_free(st->data);
    OPENSSL_free(st);
}
