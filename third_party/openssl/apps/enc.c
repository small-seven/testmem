#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "apps.h"
#include "progs.h"
#include <openssl/bio.h>
#include <openssl/err.h>
#include <openssl/evp.h>
#include <openssl/objects.h>
#include <openssl/x509.h>
#include <openssl/rand.h>
#include <openssl/pem.h>
#ifndef OPENSSL_NO_COMP
# include <openssl/comp.h>
#endif
#include <ctype.h>
#undef SIZE
#undef BSIZE
#define SIZE    (512)
#define BSIZE   (8*1024)
typedef enum OPTION_choice {
    OPT_ERR = -1, OPT_EOF = 0, OPT_HELP,
    OPT_LIST,
    OPT_E, OPT_IN, OPT_OUT, OPT_PASS, OPT_ENGINE, OPT_D, OPT_P, OPT_V,
    OPT_NOPAD, OPT_SALT, OPT_NOSALT, OPT_DEBUG, OPT_UPPER_P, OPT_UPPER_A,
    OPT_A, OPT_Z, OPT_BUFSIZE, OPT_K, OPT_KFILE, OPT_UPPER_K, OPT_NONE,
    OPT_UPPER_S, OPT_IV, OPT_MD, OPT_ITER, OPT_PBKDF2, OPT_CIPHER,
    OPT_R_ENUM
} OPTION_CHOICE;
#ifdef ZLIB
#endif
#ifndef OPENSSL_NO_ENGINE
#endif
#ifdef ZLIB
#endif
#ifdef ZLIB
#endif
#ifdef ZLIB
#endif
#ifdef ZLIB
#endif
#ifndef OPENSSL_NO_UI_CONSOLE
#endif
#ifdef ZLIB
#endif
#ifdef ZLIB
#endif
