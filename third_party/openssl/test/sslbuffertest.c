#include <string.h>
#include <openssl/ssl.h>
#include <openssl/bio.h>
#include <openssl/err.h>
#include "../ssl/packet_local.h"
#include "ssltestlib.h"
#include "testutil.h"
#define MAX_ATTEMPTS    100
