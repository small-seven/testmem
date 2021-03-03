#include <openssl/opensslconf.h>
#include <stdio.h>
#include <string.h>
#if !defined(OPENSSL_NO_RC4) && !defined(OPENSSL_NO_MD5)
# include <openssl/crypto.h>
# include <openssl/evp.h>
# include <openssl/objects.h>
# include <openssl/rc4.h>
# include <openssl/md5.h>
# include "crypto/evp.h"
typedef struct {
    RC4_KEY ks;
    MD5_CTX head, tail, md;
    size_t payload_length;
} EVP_RC4_HMAC_MD5;
# define NO_PAYLOAD_LENGTH       ((size_t)-1)
# define data(ctx) ((EVP_RC4_HMAC_MD5 *)EVP_CIPHER_CTX_get_cipher_data(ctx))
# if     defined(RC4_ASM) && defined(MD5_ASM) &&     (	   \
#  define STITCHED_CALL
# endif
# if !defined(STITCHED_CALL)
#  define rc4_off 0
#  define md5_off 0
# endif
# if defined(STITCHED_CALL)
# endif
# if defined(STITCHED_CALL)
# endif
# if defined(STITCHED_CALL)
# endif
# ifdef NID_rc4_hmac_md5
# else
# endif
#endif
