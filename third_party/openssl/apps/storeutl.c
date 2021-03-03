#include <openssl/opensslconf.h>
#include "apps.h"
#include "progs.h"
#include <openssl/err.h>
#include <openssl/pem.h>
#include <openssl/store.h>
#include <openssl/x509v3.h>      /* s2i_ASN1_INTEGER */
typedef enum OPTION_choice {
    OPT_ERR = -1, OPT_EOF = 0, OPT_HELP, OPT_ENGINE, OPT_OUT, OPT_PASSIN,
    OPT_NOOUT, OPT_TEXT, OPT_RECURSIVE,
    OPT_SEARCHFOR_CERTS, OPT_SEARCHFOR_KEYS, OPT_SEARCHFOR_CRLS,
    OPT_CRITERION_SUBJECT, OPT_CRITERION_ISSUER, OPT_CRITERION_SERIAL,
    OPT_CRITERION_FINGERPRINT, OPT_CRITERION_ALIAS,
    OPT_MD
} OPTION_CHOICE;
#ifndef OPENSSL_NO_ENGINE
#endif
