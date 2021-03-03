#include <limits.h>
#include <string.h>
#include <stdio.h>
#include "../ssl_local.h"
#include "statem_local.h"
#include "internal/cryptlib.h"
#include <openssl/buffer.h>
#include <openssl/objects.h>
#include <openssl/evp.h>
#include <openssl/x509.h>
#define RSMBLY_BITMASK_SIZE(msg_len) (((msg_len) + 7) / 8)
#define RSMBLY_BITMASK_MARK(bitmask, start, end) { \
#define RSMBLY_BITMASK_IS_COMPLETE(bitmask, msg_len, is_complete) { \
void dtls1_hm_fragment_free(hm_fragment *frag)
{
    if (!frag)
        return;
    if (frag->msg_header.is_ccs) {
        EVP_CIPHER_CTX_free(frag->msg_header.
                            saved_retransmit_state.enc_write_ctx);
        EVP_MD_CTX_free(frag->msg_header.saved_retransmit_state.write_hash);
    }
    OPENSSL_free(frag->fragment);
    OPENSSL_free(frag->reassembly);
    OPENSSL_free(frag);
}
#ifndef OPENSSL_NO_SCTP
#endif
