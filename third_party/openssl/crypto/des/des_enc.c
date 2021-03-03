#include <openssl/crypto.h>
#include "des_local.h"
#include "spr.h"
#ifndef DES_DEFAULT_OPTIONS
# undef CBC_ENC_C__DONT_UPDATE_IV
# include "ncbc_enc.c"          /* DES_ncbc_encrypt */
#endif                          /* DES_DEFAULT_OPTIONS */
