#include "includes.h"
#include "common.h"
#include "crypto/crypto.h"
#include "crypto/md5.h"
#include "crypto/sha1.h"
#include "crypto/random.h"
#include "ikev2_common.h"
#define NUM_INTEG_ALGS ARRAY_SIZE(ikev2_integ_algs)
#define NUM_PRF_ALGS ARRAY_SIZE(ikev2_prf_algs)
#define NUM_ENCR_ALGS ARRAY_SIZE(ikev2_encr_algs)
