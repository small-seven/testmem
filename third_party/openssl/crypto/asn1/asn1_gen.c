#include "internal/cryptlib.h"
#include <openssl/asn1.h>
#include <openssl/x509v3.h>
#define ASN1_GEN_FLAG           0x10000
#define ASN1_GEN_FLAG_IMP       (ASN1_GEN_FLAG|1)
#define ASN1_GEN_FLAG_EXP       (ASN1_GEN_FLAG|2)
#define ASN1_GEN_FLAG_TAG       (ASN1_GEN_FLAG|3)
#define ASN1_GEN_FLAG_BITWRAP   (ASN1_GEN_FLAG|4)
#define ASN1_GEN_FLAG_OCTWRAP   (ASN1_GEN_FLAG|5)
#define ASN1_GEN_FLAG_SEQWRAP   (ASN1_GEN_FLAG|6)
#define ASN1_GEN_FLAG_SETWRAP   (ASN1_GEN_FLAG|7)
#define ASN1_GEN_FLAG_FORMAT    (ASN1_GEN_FLAG|8)
#define ASN1_GEN_STR(str,val)   {str, sizeof(str) - 1, val}
#define ASN1_FLAG_EXP_MAX       20
#define ASN1_GEN_SEQ_MAX_DEPTH  50
#define ASN1_GEN_FORMAT_ASCII   1
#define ASN1_GEN_FORMAT_UTF8    2
#define ASN1_GEN_FORMAT_HEX     3
#define ASN1_GEN_FORMAT_BITLIST 4
typedef struct {
    int exp_tag;
    int exp_class;
    int exp_constructed;
    int exp_pad;
    long exp_len;
} tag_exp_type;
typedef struct {
    int imp_tag;
    int imp_class;
    int utype;
    int format;
    const char *str;
    tag_exp_type exp_list[ASN1_FLAG_EXP_MAX];
    int exp_count;
} tag_exp_arg;
