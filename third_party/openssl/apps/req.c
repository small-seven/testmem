#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include "apps.h"
#include "progs.h"
#include <openssl/bio.h>
#include <openssl/evp.h>
#include <openssl/conf.h>
#include <openssl/err.h>
#include <openssl/asn1.h>
#include <openssl/x509.h>
#include <openssl/x509v3.h>
#include <openssl/objects.h>
#include <openssl/pem.h>
#include <openssl/bn.h>
#include <openssl/lhash.h>
#ifndef OPENSSL_NO_RSA
# include <openssl/rsa.h>
#endif
#ifndef OPENSSL_NO_DSA
# include <openssl/dsa.h>
#endif
#define SECTION         "req"
#define BITS            "default_bits"
#define KEYFILE         "default_keyfile"
#define PROMPT          "prompt"
#define DISTINGUISHED_NAME      "distinguished_name"
#define ATTRIBUTES      "attributes"
#define V3_EXTENSIONS   "x509_extensions"
#define REQ_EXTENSIONS  "req_extensions"
#define STRING_MASK     "string_mask"
#define UTF8_IN         "utf8"
#define DEFAULT_KEY_LENGTH      2048
#define MIN_KEY_LENGTH          512
typedef enum OPTION_choice {
    OPT_ERR = -1, OPT_EOF = 0, OPT_HELP,
    OPT_INFORM, OPT_OUTFORM, OPT_ENGINE, OPT_KEYGEN_ENGINE, OPT_KEY,
    OPT_PUBKEY, OPT_NEW, OPT_CONFIG, OPT_KEYFORM, OPT_IN, OPT_OUT,
    OPT_KEYOUT, OPT_PASSIN, OPT_PASSOUT, OPT_NEWKEY,
    OPT_PKEYOPT, OPT_SIGOPT, OPT_BATCH, OPT_NEWHDR, OPT_MODULUS,
    OPT_VERIFY, OPT_NODES, OPT_NOOUT, OPT_VERBOSE, OPT_UTF8,
    OPT_NAMEOPT, OPT_REQOPT, OPT_SUBJ, OPT_SUBJECT, OPT_TEXT, OPT_X509,
    OPT_MULTIVALUE_RDN, OPT_DAYS, OPT_SET_SERIAL, OPT_ADDEXT, OPT_EXTENSIONS,
    OPT_REQEXTS, OPT_PRECERT, OPT_MD,
    OPT_R_ENUM
} OPTION_CHOICE;
#ifndef OPENSSL_NO_ENGINE
#endif
#ifndef OPENSSL_NO_DES
#endif
#ifndef OPENSSL_NO_ENGINE
#endif
#ifndef OPENSSL_NO_DSA
#endif
#ifndef OPENSSL_NO_RSA
#endif
#ifndef OPENSSL_NO_ENGINE
#endif
#ifndef CHARSET_EBCDIC
#else
#endif
#ifndef CHARSET_EBCDIC
#else
#endif
#ifdef CHARSET_EBCDIC
#endif
#ifndef OPENSSL_NO_ENGINE
#endif
#ifndef OPENSSL_NO_ENGINE
#endif
#ifndef OPENSSL_NO_RSA
#endif
