#include <stdio.h>
#include <string.h>
#include <openssl/e_os2.h>
#include <openssl/evp.h>
#ifdef __VMS
# pragma names save
# pragma names as_is,shortened
#endif
#include "curve448_local.h"
#ifdef __VMS
# pragma names restore
#endif
#include "testutil.h"
