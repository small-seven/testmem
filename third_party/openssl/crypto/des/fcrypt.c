#include <stdio.h>
#ifdef _OSD_POSIX
# ifndef CHARSET_EBCDIC
#  define CHARSET_EBCDIC 1
# endif
#endif
#ifdef CHARSET_EBCDIC
# include <openssl/ebcdic.h>
#endif
#include <openssl/crypto.h>
#include "des_local.h"
#ifndef CHARSET_EBCDIC
#else
#endif
