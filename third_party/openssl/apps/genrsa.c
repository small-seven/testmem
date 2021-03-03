#include <openssl/opensslconf.h>
#ifdef OPENSSL_NO_RSA
#else
# include <stdio.h>
# include <string.h>
# include <sys/types.h>
# include <sys/stat.h>
# include "apps.h"
# include "progs.h"
# include <openssl/bio.h>
# include <openssl/err.h>
# include <openssl/bn.h>
# include <openssl/rsa.h>
# include <openssl/evp.h>
# include <openssl/x509.h>
# include <openssl/pem.h>
# include <openssl/rand.h>
# define DEFBITS 2048
# define DEFPRIMES 2
typedef enum OPTION_choice {
    OPT_ERR = -1, OPT_EOF = 0, OPT_HELP,
    OPT_3, OPT_F4, OPT_ENGINE,
    OPT_OUT, OPT_PASSOUT, OPT_CIPHER, OPT_PRIMES,
    OPT_R_ENUM
} OPTION_CHOICE;
# ifndef OPENSSL_NO_ENGINE
# endif
#endif
