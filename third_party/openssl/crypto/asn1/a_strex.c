#include <stdio.h>
#include <string.h>
#include "internal/cryptlib.h"
#include "crypto/asn1.h"
#include <openssl/crypto.h>
#include <openssl/x509.h>
#include <openssl/asn1.h>
#include "charmap.h"
#define CHARTYPE_BS_ESC         (ASN1_STRFLGS_ESC_2253 | CHARTYPE_FIRST_ESC_2253 | CHARTYPE_LAST_ESC_2253)
#define ESC_FLAGS (ASN1_STRFLGS_ESC_2253 | \
#ifndef OPENSSL_NO_STDIO
#endif
typedef int char_io (void *arg, const void *buf, int len);

/*
 * This function handles display of strings, one character at a time. It is
 * passed an unsigned long for each character because it could come from 2 or
 * even 4 byte forms.
 */

static int do_esc_char(unsigned long c, unsigned short flags, char *do_quotes,
                       char_io *io_ch, void *arg)
{
    unsigned short chflgs;
    unsigned char chtmp;
    char tmphex[HEX_SIZE(long) + 3];

    if (c > 0xffffffffL)
        return -1;
    if (c > 0xffff) {
        BIO_snprintf(tmphex, sizeof(tmphex), "\\W%08lX", c);
        if (!io_ch(arg, tmphex, 10))
            return -1;
        return 10;
    }
#define BUF_TYPE_WIDTH_MASK     0x7
#define BUF_TYPE_CONVUTF8       0x8
#define FN_WIDTH_LN     25
#define FN_WIDTH_SN     10
#ifndef OPENSSL_NO_STDIO
#endif
#ifndef OPENSSL_NO_STDIO
#endif
