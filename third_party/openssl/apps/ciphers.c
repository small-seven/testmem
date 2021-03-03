#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "apps.h"
#include "progs.h"
#include <openssl/err.h>
#include <openssl/ssl.h>
typedef enum OPTION_choice {
    OPT_ERR = -1, OPT_EOF = 0, OPT_HELP,
    OPT_STDNAME,
    OPT_CONVERT,
    OPT_SSL3,
    OPT_TLS1,
    OPT_TLS1_1,
    OPT_TLS1_2,
    OPT_TLS1_3,
    OPT_PSK,
    OPT_SRP,
    OPT_CIPHERSUITES,
    OPT_V, OPT_UPPER_V, OPT_S
} OPTION_CHOICE;
#ifndef OPENSSL_NO_SSL3
#endif
#ifndef OPENSSL_NO_TLS1
#endif
#ifndef OPENSSL_NO_TLS1_1
#endif
#ifndef OPENSSL_NO_TLS1_2
#endif
#ifndef OPENSSL_NO_TLS1_3
#endif
#ifndef OPENSSL_NO_PSK
#endif
#ifndef OPENSSL_NO_SRP
#endif
#ifndef OPENSSL_NO_PSK
#endif
#ifndef OPENSSL_NO_SRP
#endif
#ifndef OPENSSL_NO_PSK
#endif
#ifndef OPENSSL_NO_SRP
#endif
#ifndef OPENSSL_NO_PSK
#endif
#ifndef OPENSSL_NO_SRP
#endif
#ifndef OPENSSL_NO_PSK
#endif
#ifndef OPENSSL_NO_SRP
#endif
