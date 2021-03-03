#include <openssl/ocsp.h>
#include "../ssl_local.h"
#include "statem_local.h"
#include "internal/cryptlib.h"
#define COOKIE_STATE_FORMAT_VERSION     0
#define MAX_COOKIE_SIZE (2 + 2 + 2 + 2 + 2 + 1 + 4 + 2 + EVP_MAX_MD_SIZE + 1 \
#define MAX_HRR_SIZE    (SSL3_HM_HEADER_LENGTH + 2 + SSL3_RANDOM_SIZE + 1 \
#ifndef OPENSSL_NO_SRP
#endif
#ifndef OPENSSL_NO_EC
#endif                          /* OPENSSL_NO_EC */
#ifndef OPENSSL_NO_OCSP
#endif
#ifndef OPENSSL_NO_NEXTPROTONEG
#endif
#ifndef OPENSSL_NO_SRTP
#endif
#ifndef OPENSSL_NO_TLS1_3
#endif
#ifndef OPENSSL_NO_TLS1_3
#endif
#ifndef OPENSSL_NO_TLS1_3
#endif
#ifndef OPENSSL_NO_EC
#endif
#ifndef OPENSSL_NO_PSK
#endif /* OPENSSL_NO_PSK */
#ifndef OPENSSL_NO_EC
#endif
#ifndef OPENSSL_NO_EC
#endif
#ifndef OPENSSL_NO_OCSP
#endif
#ifndef OPENSSL_NO_NEXTPROTONEG
#endif
#ifndef OPENSSL_NO_SRTP
#endif
#ifndef OPENSSL_NO_TLS1_3
#else
#endif
#ifndef OPENSSL_NO_TLS1_3
#else
#endif
