#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <openssl/crypto.h>
#include <openssl/lhash.h>
#include <openssl/err.h>
#include "crypto/ctype.h"
#include "crypto/lhash.h"
#include "lhash_local.h"
#undef MIN_NODES
#define MIN_NODES       16
#define UP_LOAD         (2*LH_LOAD_MULT) /* load times 256 (default 2) */
#define DOWN_LOAD       (LH_LOAD_MULT) /* load times 256 (default 1) */
void OPENSSL_LH_free(OPENSSL_LHASH *lh)
{
    unsigned int i;
    OPENSSL_LH_NODE *n, *nn;

    if (lh == NULL)
        return;

    for (i = 0; i < lh->num_nodes; i++) {
        n = lh->b[i];
        while (n != NULL) {
            nn = n->next;
            OPENSSL_free(n);
            n = nn;
        }
    }
    OPENSSL_free(lh->b);
    OPENSSL_free(lh);
}
