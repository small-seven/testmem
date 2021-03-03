#include "includes.h"
#include "common.h"
#include "crypto/sha1.h"
#include "crypto/tls.h"
#include "eap_defs.h"
#include "eap_tlv_common.h"
#include "eap_fast_common.h"
#define TLS_RANDOM_LEN 32
#define TLS_MASTER_SECRET_LEN 48
