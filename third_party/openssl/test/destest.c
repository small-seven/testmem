#include <openssl/e_os2.h>
#include <string.h>
#include "testutil.h"
#ifndef OPENSSL_NO_DES
# include <openssl/des.h>
# define TEST_cs_eq  TEST_uint_eq
# define DATA_BUF_SIZE      20
# define NUM_TESTS 34
# ifdef SCREW_THE_PARITY
#  error "SCREW_THE_PARITY is not meant to be defined."
#  error "Original vectors are preserved for reference only."
# else
# endif
#endif
#ifndef OPENSSL_NO_DES
#endif
