#include <string.h>
#include <openssl/opensslconf.h>
#include <openssl/bio.h>
#include <openssl/crypto.h>
#include <openssl/evp.h>
#include <openssl/ssl.h>
#include <openssl/err.h>
#include <openssl/rand.h>
#include <openssl/kdf.h>
#include "../ssl/packet_local.h"
#include "internal/nelem.h"
#include "testutil.h"
#define MAC_OFFSET (DTLS1_RT_HEADER_LENGTH + DTLS1_HM_HEADER_LENGTH)
#define mac_key (key_block + 20)
#define dec_key (key_block + 40)
#define enc_key (key_block + 56)
#define SS_SESSID_OFS 15 /* Session ID goes here */
#define SS_SECRET_OFS 49 /* Master secret goes here */
#define HV_COOKIE_OFS 28 /* Cookie goes here */
#define SH_RANDOM_OFS 27 /* Server random goes here */
#define SH_SESSID_OFS 60 /* Session ID goes here */
#define NODROP(x) { x##UL, 0 }
#define DROP(x)   { x##UL, 1 }
