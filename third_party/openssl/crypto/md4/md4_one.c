#include <stdio.h>
#include <string.h>
#include <openssl/md4.h>
#include <openssl/crypto.h>
#ifdef CHARSET_EBCDIC
# include <openssl/ebcdic.h>
#endif
#ifndef CHARSET_EBCDIC
#else
#endif
