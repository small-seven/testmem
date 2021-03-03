#include <stdio.h>
#include <string.h>
#include <openssl/evp.h>
#include <openssl/bio.h>
#include <openssl/rand.h>
#include "testutil.h"
#define ENCRYPT  1
#define DECRYPT  0
#define DATA_SIZE    1024
#define MAX_IV       32
#define BUF_SIZE     (DATA_SIZE + MAX_IV)
# ifndef OPENSSL_NO_CHACHA
#  ifndef OPENSSL_NO_POLY1305
#  endif
# endif
# ifndef OPENSSL_NO_CHACHA
#  ifndef OPENSSL_NO_POLY1305
#  endif
# endif
