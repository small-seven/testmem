#include <stdio.h>
#include <limits.h>
#include <errno.h>
#include "../ssl_local.h"
#include <openssl/evp.h>
#include <openssl/buffer.h>
#include <openssl/rand.h>
#include "record_local.h"
#include "../packet_local.h"
#if     defined(OPENSSL_SMALL_FOOTPRINT) || \
# undef EVP_CIPH_FLAG_TLS1_1_MULTIBLOCK
# define EVP_CIPH_FLAG_TLS1_1_MULTIBLOCK 0
#endif
#if defined(SSL3_ALIGN_PAYLOAD) && SSL3_ALIGN_PAYLOAD!=0
#endif
#if !defined(OPENSSL_NO_MULTIBLOCK) && EVP_CIPH_FLAG_TLS1_1_MULTIBLOCK
#endif
#if !defined(OPENSSL_NO_MULTIBLOCK) && EVP_CIPH_FLAG_TLS1_1_MULTIBLOCK
#endif  /* !defined(OPENSSL_NO_MULTIBLOCK) && EVP_CIPH_FLAG_TLS1_1_MULTIBLOCK */
#if defined(SSL3_ALIGN_PAYLOAD) && SSL3_ALIGN_PAYLOAD!=0
#endif
#if defined(SSL3_ALIGN_PAYLOAD) && SSL3_ALIGN_PAYLOAD != 0
#endif
