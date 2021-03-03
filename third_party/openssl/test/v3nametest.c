#include <string.h>
#include <openssl/e_os2.h>
#include <openssl/x509.h>
#include <openssl/x509v3.h>
#include "internal/nelem.h"
#include "testutil.h"
#ifdef OPENSSL_SYS_WINDOWS
# define strcasecmp _stricmp
#endif
