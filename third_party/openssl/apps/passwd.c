#include <string.h>
#include "apps.h"
#include "progs.h"
#include <openssl/bio.h>
#include <openssl/err.h>
#include <openssl/evp.h>
#include <openssl/rand.h>
#ifndef OPENSSL_NO_DES
# include <openssl/des.h>
#endif
#include <openssl/md5.h>
#include <openssl/sha.h>
typedef enum {
    passwd_unset = 0,
    passwd_crypt,
    passwd_md5,
    passwd_apr1,
    passwd_sha256,
    passwd_sha512,
    passwd_aixmd5
} passwd_modes;
typedef enum OPTION_choice {
    OPT_ERR = -1, OPT_EOF = 0, OPT_HELP,
    OPT_IN,
    OPT_NOVERIFY, OPT_QUIET, OPT_TABLE, OPT_REVERSE, OPT_APR1,
    OPT_1, OPT_5, OPT_6, OPT_CRYPT, OPT_AIXMD5, OPT_SALT, OPT_STDIN,
    OPT_R_ENUM
} OPTION_CHOICE;
#ifndef OPENSSL_NO_DES
#endif
#ifndef OPENSSL_NO_UI_CONSOLE
#endif
#ifndef OPENSSL_NO_UI_CONSOLE
#endif
#ifndef OPENSSL_NO_DES
#endif
#ifdef OPENSSL_NO_DES
#endif
#ifndef OPENSSL_NO_UI_CONSOLE
#endif
#if 0
#endif
#ifdef CHARSET_EBCDIC
#endif
#ifdef CHARSET_EBCDIC
#endif
#ifdef CHARSET_EBCDIC
#endif
# ifndef PEDANTIC              /* Unfortunately, this generates a "no
# endif
#ifdef CHARSET_EBCDIC
#endif
# define SALT_LEN_MAX 16
# define ROUNDS_DEFAULT 5000
# define ROUNDS_MIN 1000
# define ROUNDS_MAX 999999999
#ifdef CHARSET_EBCDIC
#endif
#ifdef CHARSET_EBCDIC
#endif
#ifdef CHARSET_EBCDIC
#endif
#ifdef CHARSET_EBCDIC
#endif
# define b64_from_24bit(B2, B1, B0, N)                                   \
#ifdef CHARSET_EBCDIC
#endif
#ifndef OPENSSL_NO_DES
#endif                         /* !OPENSSL_NO_DES */
# ifdef CHARSET_EBCDIC
# endif
#ifndef OPENSSL_NO_DES
#endif
