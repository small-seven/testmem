#include <openssl/opensslconf.h>
#ifdef OPENSSL_NO_DSA
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
# include <openssl/dsa.h>
# include <openssl/x509.h>
# include <openssl/pem.h>
typedef enum OPTION_choice {
    OPT_ERR = -1, OPT_EOF = 0, OPT_HELP,
    OPT_OUT, OPT_PASSOUT, OPT_ENGINE, OPT_CIPHER,
    OPT_R_ENUM
} OPTION_CHOICE;
# ifndef OPENSSL_NO_ENGINE
# endif
#endif
