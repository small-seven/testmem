#include "crypto/cryptlib.h"
#include "internal/thread_once.h"
 * The state for each class.  This could just be a typedef, but
 * a structure allows future changes.
 */
typedef struct ex_callbacks_st {
    STACK_OF(EX_CALLBACK) *meth;
} EX_CALLBACKS;
static void dummy_free(void *parent, void *ptr, CRYPTO_EX_DATA *ad, int idx,
                       long argl, void *argp)
{
}
