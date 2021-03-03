#include <openssl/opensslconf.h>
#ifdef OPENSSL_NO_RSA
#else
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <time.h>
# include "apps.h"
# include "progs.h"
# include <openssl/bio.h>
# include <openssl/err.h>
# include <openssl/rsa.h>
# include <openssl/evp.h>
# include <openssl/x509.h>
# include <openssl/pem.h>
# include <openssl/bn.h>
typedef enum OPTION_choice {
    OPT_ERR = -1, OPT_EOF = 0, OPT_HELP,
    OPT_INFORM, OPT_OUTFORM, OPT_ENGINE, OPT_IN, OPT_OUT,
    OPT_PUBIN, OPT_PUBOUT, OPT_PASSOUT, OPT_PASSIN,
    OPT_RSAPUBKEY_IN, OPT_RSAPUBKEY_OUT,
    /* Do not change the order here; see case statements below */
    OPT_PVK_NONE, OPT_PVK_WEAK, OPT_PVK_STRONG,
    OPT_NOOUT, OPT_TEXT, OPT_MODULUS, OPT_CHECK, OPT_CIPHER
} OPTION_CHOICE;
# if !defined(OPENSSL_NO_DSA) && !defined(OPENSSL_NO_RC4)
# endif
# ifndef OPENSSL_NO_ENGINE
# endif
# if !defined(OPENSSL_NO_DSA) && !defined(OPENSSL_NO_RC4)
# endif
# if !defined(OPENSSL_NO_DSA) && !defined(OPENSSL_NO_RC4)
# endif
# ifndef OPENSSL_NO_DSA
#  ifdef OPENSSL_NO_RC4
#  else
#  endif
# endif
#endif
