#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <openssl/opensslconf.h> /* To see if OPENSSL_NO_BF is defined */
#include "testutil.h"
#include "internal/nelem.h"
#ifndef OPENSSL_NO_BF
# include <openssl/blowfish.h>
# ifdef CHARSET_EBCDIC
#  include <openssl/ebcdic.h>
# endif
# define NUM_TESTS 34
# define KEY_TEST_NUM    25
#endif
#ifndef OPENSSL_NO_BF
# ifdef CHARSET_EBCDIC
# endif
#endif
