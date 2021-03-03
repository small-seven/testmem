#include <stdio.h>
#include <string.h>
#include <openssl/x509.h>
#include <openssl/x509v3.h>
#include "testutil.h"
#include "internal/nelem.h"
#ifdef __VMS
# pragma names save
# pragma names as_is,shortened
#endif
#include "../crypto/x509v3/ext_dat.h"
#include "../crypto/x509v3/standard_exts.h"
#ifdef __VMS
# pragma names restore
#endif
