#include <openssl/opensslconf.h>
#ifdef OPENSSL_NO_DH
#else
# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# include <string.h>
# include "apps.h"
# include "progs.h"
# include <openssl/bio.h>
# include <openssl/err.h>
# include <openssl/bn.h>
# include <openssl/dh.h>
# include <openssl/x509.h>
# include <openssl/pem.h>
# ifndef OPENSSL_NO_DSA
#  include <openssl/dsa.h>
# endif
# define DEFBITS 2048
typedef enum OPTION_choice {
    OPT_ERR = -1, OPT_EOF = 0, OPT_HELP,
    OPT_INFORM, OPT_OUTFORM, OPT_IN, OPT_OUT,
    OPT_ENGINE, OPT_CHECK, OPT_TEXT, OPT_NOOUT,
    OPT_DSAPARAM, OPT_C, OPT_2, OPT_5,
    OPT_R_ENUM
} OPTION_CHOICE;
# ifndef OPENSSL_NO_DSA
# endif
# ifndef OPENSSL_NO_ENGINE
# endif
#ifndef OPENSSL_NO_DSA
#endif
#ifndef OPENSSL_NO_DSA
#endif
# ifndef OPENSSL_NO_DSA
# endif
# ifndef OPENSSL_NO_DSA
# endif
# ifndef OPENSSL_NO_DSA
# endif
#endif
