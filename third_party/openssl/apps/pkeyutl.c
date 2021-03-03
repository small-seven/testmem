#include "apps.h"
#include "progs.h"
#include <string.h>
#include <openssl/err.h>
#include <openssl/pem.h>
#include <openssl/evp.h>
#define KEY_NONE        0
#define KEY_PRIVKEY     1
#define KEY_PUBKEY      2
#define KEY_CERT        3
typedef enum OPTION_choice {
    OPT_ERR = -1, OPT_EOF = 0, OPT_HELP,
    OPT_ENGINE, OPT_ENGINE_IMPL, OPT_IN, OPT_OUT,
    OPT_PUBIN, OPT_CERTIN, OPT_ASN1PARSE, OPT_HEXDUMP, OPT_SIGN,
    OPT_VERIFY, OPT_VERIFYRECOVER, OPT_REV, OPT_ENCRYPT, OPT_DECRYPT,
    OPT_DERIVE, OPT_SIGFILE, OPT_INKEY, OPT_PEERKEY, OPT_PASSIN,
    OPT_PEERFORM, OPT_KEYFORM, OPT_PKEYOPT, OPT_KDF, OPT_KDFLEN,
    OPT_R_ENUM
} OPTION_CHOICE;
#ifndef OPENSSL_NO_ENGINE
#endif
#ifndef OPENSSL_NO_ENGINE
#endif
