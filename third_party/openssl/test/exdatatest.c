#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <openssl/crypto.h>
#include "testutil.h"
static void exfree(void *parent, void *ptr, CRYPTO_EX_DATA *ad,
            int idx, long argl, void *argp)
{
    if (!TEST_int_eq(idx, saved_idx)
        || !TEST_long_eq(argl, saved_argl)
        || !TEST_ptr_eq(argp, saved_argp))
        gbl_result = 0;
}
typedef struct myobj_ex_data_st {
    char *hello;
    int new;
    int dup;
} MYOBJ_EX_DATA;
typedef struct myobj_st {
    CRYPTO_EX_DATA ex_data;
    int id;
    int st;
} MYOBJ;
static void MYOBJ_free(MYOBJ *obj)
{
    CRYPTO_free_ex_data(CRYPTO_EX_INDEX_APP, obj, &obj->ex_data);
    OPENSSL_free(obj);
}
