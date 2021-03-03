#include <string.h>
#include <openssl/opensslconf.h>
#include <openssl/bio.h>
#include <openssl/crypto.h>
#include <openssl/evp.h>
#include <openssl/ssl.h>
#include <openssl/err.h>
#include <time.h>
#include "../ssl/packet_local.h"
#include "testutil.h"
#include "internal/nelem.h"
#include "ssltestlib.h"
#define CLIENT_VERSION_LEN      2
typedef int (*sni_test_fn)(void);

static sni_test_fn sni_test_fns[3] = {
    client_setup_sni_before_state,
    client_setup_sni_after_state,
    server_setup_sni
};
