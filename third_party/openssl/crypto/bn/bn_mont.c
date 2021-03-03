#include "internal/cryptlib.h"
#include "bn_local.h"
#define MONT_WORD               /* use the faster word-based algorithm */
#ifdef MONT_WORD
#endif
#if defined(OPENSSL_BN_ASM_MONT) && defined(MONT_WORD)
#endif
#ifdef MONT_WORD
#else
#endif
#ifdef MONT_WORD
#endif                          /* MONT_WORD */
#ifdef MONT_WORD
#else                           /* !MONT_WORD */
#endif                          /* MONT_WORD */
void BN_MONT_CTX_free(BN_MONT_CTX *mont)
{
    if (mont == NULL)
        return;
    BN_clear_free(&mont->RR);
    BN_clear_free(&mont->N);
    BN_clear_free(&mont->Ni);
    if (mont->flags & BN_FLG_MALLOCED)
        OPENSSL_free(mont);
}
#ifdef MONT_WORD
# if defined(OPENSSL_BN_ASM_MONT) && (BN_BITS2<=32)
# else
# endif
#else                           /* !MONT_WORD */
#endif
