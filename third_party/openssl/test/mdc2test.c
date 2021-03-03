#include <string.h>
#include "internal/nelem.h"
#include "testutil.h"
#if defined(OPENSSL_NO_DES) && !defined(OPENSSL_NO_MDC2)
# define OPENSSL_NO_MDC2
#endif
#ifndef OPENSSL_NO_MDC2
# include <openssl/evp.h>
# include <openssl/mdc2.h>
# ifdef CHARSET_EBCDIC
#  include <openssl/ebcdic.h>
# endif
# ifdef CHARSET_EBCDIC
# endif
#endif
#ifndef OPENSSL_NO_MDC2
#endif
