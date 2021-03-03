#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/crypto.h>
#include <openssl/des.h>
#include <openssl/mdc2.h>
#undef c2l
#define c2l(c,l)        (l =((DES_LONG)(*((c)++)))    , \
#undef l2c
#define l2c(l,c)        (*((c)++)=(unsigned char)(((l)     )&0xff), \
