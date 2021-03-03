#include "e_os.h"
#include "internal/cryptlib.h"
#include <stdio.h>
#include "crypto/ctype.h"
#include <openssl/conf.h>
#include <openssl/crypto.h>
#include <openssl/x509v3.h>
#include "crypto/x509.h"
#include <openssl/bn.h>
#include "ext_dat.h"
void X509V3_conf_free(CONF_VALUE *conf)
{
    if (!conf)
        return;
    OPENSSL_free(conf->name);
    OPENSSL_free(conf->value);
    OPENSSL_free(conf->section);
    OPENSSL_free(conf);
}
#define HDR_NAME        1
#define HDR_VALUE       2
static void str_free(OPENSSL_STRING str)
{
    OPENSSL_free(str);
}
void X509_email_free(STACK_OF(OPENSSL_STRING) *sk)
{
    sk_OPENSSL_STRING_pop_free(sk, str_free);
}
typedef int (*equal_fn) (const unsigned char *pattern, size_t pattern_len,
                         const unsigned char *subject, size_t subject_len,
                         unsigned int flags);

/* Skip pattern prefix to match "wildcard" subject */
static void skip_prefix(const unsigned char **p, size_t *plen,
                        size_t subject_len,
                        unsigned int flags)
{
    const unsigned char *pattern = *p;
    size_t pattern_len = *plen;

    /*
     * If subject starts with a leading '.' followed by more octets, and
     * pattern is longer, compare just an equal-length suffix with the
     * full subject (starting at the '.'), provided the prefix contains
     * no NULs.
     */
    if ((flags & _X509_CHECK_FLAG_DOT_SUBDOMAINS) == 0)
        return;

    while (pattern_len > subject_len && *pattern) {
        if ((flags & X509_CHECK_FLAG_SINGLE_LABEL_SUBDOMAINS) &&
            *pattern == '.')
            break;
        ++pattern;
        --pattern_len;
    }
#define LABEL_START     (1 << 0)
#define LABEL_END       (1 << 1)
#define LABEL_HYPHEN    (1 << 2)
#define LABEL_IDNA      (1 << 3)
typedef struct {
    /* Temporary store for IPV6 output */
    unsigned char tmp[16];
    /* Total number of bytes in tmp */
    int total;
    /* The position of a zero (corresponding to '::') */
    int zero_pos;
    /* Number of zeroes */
    int zero_cnt;
} IPV6_STAT;
#ifndef CHARSET_EBCDIC
#else
#endif
#ifndef CHARSET_EBCDIC
#else
#endif
