#include <openssl/opensslconf.h>
#if defined(OPENSSL_NO_DES)
#else
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include "apps.h"
# include "progs.h"
# include <openssl/crypto.h>
# include <openssl/err.h>
# include <openssl/pem.h>
# include <openssl/pkcs12.h>
# define NOKEYS          0x1
# define NOCERTS         0x2
# define INFO            0x4
# define CLCERTS         0x8
# define CACERTS         0x10
#define PASSWD_BUF_SIZE 2048
typedef enum OPTION_choice {
    OPT_ERR = -1, OPT_EOF = 0, OPT_HELP,
    OPT_CIPHER, OPT_NOKEYS, OPT_KEYEX, OPT_KEYSIG, OPT_NOCERTS, OPT_CLCERTS,
    OPT_CACERTS, OPT_NOOUT, OPT_INFO, OPT_CHAIN, OPT_TWOPASS, OPT_NOMACVER,
    OPT_DESCERT, OPT_EXPORT, OPT_NOITER, OPT_MACITER, OPT_NOMACITER,
    OPT_NOMAC, OPT_LMK, OPT_NODES, OPT_MACALG, OPT_CERTPBE, OPT_KEYPBE,
    OPT_INKEY, OPT_CERTFILE, OPT_NAME, OPT_CSP, OPT_CANAME,
    OPT_IN, OPT_OUT, OPT_PASSIN, OPT_PASSOUT, OPT_PASSWORD, OPT_CAPATH,
    OPT_CAFILE, OPT_NOCAPATH, OPT_NOCAFILE, OPT_ENGINE,
    OPT_R_ENUM
} OPTION_CHOICE;
# ifndef OPENSSL_NO_RC2
# else
# endif
# ifndef OPENSSL_NO_ENGINE
# endif
# ifndef OPENSSL_NO_RC2
# else
# endif
#ifndef OPENSSL_NO_UI_CONSOLE
#endif
#ifndef OPENSSL_NO_UI_CONSOLE
#endif
#ifndef OPENSSL_NO_UI_CONSOLE
#endif
#ifndef OPENSSL_NO_SCRYPT
#endif
#endif
