#include <openssl/opensslconf.h>
#ifdef OPENSSL_NO_DSA
#else
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <time.h>
# include "apps.h"
# include "progs.h"
# include <openssl/bio.h>
# include <openssl/err.h>
# include <openssl/dsa.h>
# include <openssl/evp.h>
# include <openssl/x509.h>
# include <openssl/pem.h>
# include <openssl/bn.h>
typedef enum OPTION_choice {
    OPT_ERR = -1, OPT_EOF = 0, OPT_HELP,
    OPT_INFORM, OPT_OUTFORM, OPT_IN, OPT_OUT, OPT_ENGINE,
    /* Do not change the order here; see case statements below */
    OPT_PVK_NONE, OPT_PVK_WEAK, OPT_PVK_STRONG,
    OPT_NOOUT, OPT_TEXT, OPT_MODULUS, OPT_PUBIN,
    OPT_PUBOUT, OPT_CIPHER, OPT_PASSIN, OPT_PASSOUT
} OPTION_CHOICE;
# ifndef OPENSSL_NO_RC4
# endif
# ifndef OPENSSL_NO_ENGINE
# endif
# ifndef OPENSSL_NO_RC4
# endif
#ifndef OPENSSL_NO_RC4
#endif
# ifndef OPENSSL_NO_RSA
#  ifdef OPENSSL_NO_RC4
#  else
#  endif
# endif
#endif
