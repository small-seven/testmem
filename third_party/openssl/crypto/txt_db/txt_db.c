#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "internal/cryptlib.h"
#include <openssl/buffer.h>
#include <openssl/txt_db.h>
#undef BUFSIZE
#define BUFSIZE 512
void TXT_DB_free(TXT_DB *db)
{
    int i, n;
    char **p, *max;

    if (db == NULL)
        return;
    if (db->index != NULL) {
        for (i = db->num_fields - 1; i >= 0; i--)
            lh_OPENSSL_STRING_free(db->index[i]);
        OPENSSL_free(db->index);
    }
    OPENSSL_free(db->qual);
    if (db->data != NULL) {
        for (i = sk_OPENSSL_PSTRING_num(db->data) - 1; i >= 0; i--) {
            /*
             * check if any 'fields' have been allocated from outside of the
             * initial block
             */
            p = sk_OPENSSL_PSTRING_value(db->data, i);
            max = p[db->num_fields]; /* last address */
            if (max == NULL) {  /* new row */
                for (n = 0; n < db->num_fields; n++)
                    OPENSSL_free(p[n]);
            } else {
                for (n = 0; n < db->num_fields; n++) {
                    if (((p[n] < (char *)p) || (p[n] > max)))
                        OPENSSL_free(p[n]);
                }
            }
            OPENSSL_free(sk_OPENSSL_PSTRING_value(db->data, i));
        }
        sk_OPENSSL_PSTRING_free(db->data);
    }
    OPENSSL_free(db);
}
