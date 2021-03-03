#include "cipher_osal.h"
#define rsa_var_null_goto_lab(var, ret, lab) \
#define rsa_ret_fail_goto_lab(ret, lab) \
#define rsa_func_fail_return(val, ret, func) \
#define rsa_not_equal_return(var, val, ret) \
typedef struct {
    hi_cipher_hash_type hash_type;
    hi_u32 hlen;
    hi_u32 klen;
    hi_u32 em_bit;
    hi_u8 key_bt;
    hi_u8 *in_data;
    hi_u32 in_len;
    hi_u8 *out_data;
    hi_u32 out_len;
} rsa_padding_s;
typedef struct {
    hi_u8 *masked_db;
    hi_u8 *masked_seed;
    hi_u8 salt[CIPHER_MAX_RSA_KEY_LEN];
    hi_u32 msb_bits;
    hi_u32 slen;
    hi_u32 key_len;
} rsa_pkcs1_pss_s;
typedef struct {
    hi_u8 arr_em[CIPHER_MAX_RSA_KEY_LEN];
    hi_u8 sign_hash[HASH_RESULT_MAX_LEN];
} rsa_sign_buf;
#define RSA_SIGN                1
#define ASN1_HASH_SHA1      "\x30\x21\x30\x09\x06\x05\x2b\x0e\x03\x02\x1a\x05\x00\x04\x14"
#define ASN1_HASH_SHA224    "\x30\x2D\x30\x0d\x06\x09\x60\x86\x48\x01\x65\x03\x04\x02\x04\x05\x00\x04\x1C"
#define ASN1_HASH_SHA256    "\x30\x31\x30\x0d\x06\x09\x60\x86\x48\x01\x65\x03\x04\x02\x01\x05\x00\x04\x20"
#define ASN1_HASH_SHA384    "\x30\x41\x30\x0d\x06\x09\x60\x86\x48\x01\x65\x03\x04\x02\x02\x05\x00\x04\x30"
#define ASN1_HASH_SHA512    "\x30\x51\x30\x0d\x06\x09\x60\x86\x48\x01\x65\x03\x04\x02\x03\x05\x00\x04\x40"
