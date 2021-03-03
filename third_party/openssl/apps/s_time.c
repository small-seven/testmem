#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/opensslconf.h>
#ifndef OPENSSL_NO_SOCK
#include "apps.h"
#include "progs.h"
#include <openssl/x509.h>
#include <openssl/ssl.h>
#include <openssl/pem.h>
#include "s_apps.h"
#include <openssl/err.h>
#include <internal/sockets.h>
#if !defined(OPENSSL_SYS_MSDOS)
# include OPENSSL_UNISTD
#endif
#define SSL_CONNECT_NAME        "localhost:4433"
#define SECONDS 30
#define SECONDSSTR "30"
typedef enum OPTION_choice {
    OPT_ERR = -1, OPT_EOF = 0, OPT_HELP,
    OPT_CONNECT, OPT_CIPHER, OPT_CIPHERSUITES, OPT_CERT, OPT_NAMEOPT, OPT_KEY,
    OPT_CAPATH, OPT_CAFILE, OPT_NOCAPATH, OPT_NOCAFILE, OPT_NEW, OPT_REUSE,
    OPT_BUGS, OPT_VERIFY, OPT_TIME, OPT_SSL3,
    OPT_WWW
} OPTION_CHOICE;
#ifndef OPENSSL_NO_SSL3
#endif
#define START   0
#define STOP    1
#if defined(SOL_SOCKET) && defined(SO_LINGER)
#endif
#endif /* OPENSSL_NO_SOCK */
