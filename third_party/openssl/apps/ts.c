#include <openssl/opensslconf.h>
#ifdef OPENSSL_NO_TS
#else
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include "apps.h"
# include "progs.h"
# include <openssl/bio.h>
# include <openssl/err.h>
# include <openssl/pem.h>
# include <openssl/rand.h>
# include <openssl/ts.h>
# include <openssl/bn.h>
# define NONCE_LENGTH            64
# define ENV_OID_FILE            "oid_file"
# define EXACTLY_ONE(a, b, c) \
typedef enum OPTION_choice {
    OPT_ERR = -1, OPT_EOF = 0, OPT_HELP,
    OPT_ENGINE, OPT_CONFIG, OPT_SECTION, OPT_QUERY, OPT_DATA,
    OPT_DIGEST, OPT_TSPOLICY, OPT_NO_NONCE, OPT_CERT,
    OPT_IN, OPT_TOKEN_IN, OPT_OUT, OPT_TOKEN_OUT, OPT_TEXT,
    OPT_REPLY, OPT_QUERYFILE, OPT_PASSIN, OPT_INKEY, OPT_SIGNER,
    OPT_CHAIN, OPT_VERIFY, OPT_CAPATH, OPT_CAFILE, OPT_UNTRUSTED,
    OPT_MD, OPT_V_ENUM, OPT_R_ENUM
} OPTION_CHOICE;
# ifndef OPENSSL_NO_ENGINE
# endif
# ifndef OPENSSL_NO_ENGINE
# else
# endif
# ifndef OPENSSL_NO_ENGINE
# endif
#endif  /* ndef OPENSSL_NO_TS */
