#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <openssl/x509.h>
#include <openssl/pem.h>
#include <openssl/conf.h>
#include <openssl/err.h>
#include "internal/nelem.h"
#include "testutil.h"
    typedef X509 *(*d2i_X509_t)(X509 **, const unsigned char **, long);
    typedef int (*i2d_X509_t)(X509 *, unsigned char **);
    int err = 0;
    BIO *fp = BIO_new_file(test_get_argument(num), "r");
    X509 *reuse = NULL;

    if (!TEST_ptr(fp))
        return 0;

    for (c = 0; !err && PEM_read_bio(fp, &name, &header, &data, &len); ++c) {
        const int trusted = (strcmp(name, PEM_STRING_X509_TRUSTED) == 0);

        d2i_X509_t d2i = trusted ? d2i_X509_AUX : d2i_X509;
        i2d_X509_t i2d = trusted ? i2d_X509_AUX : i2d_X509;
        X509 *cert = NULL;
        const unsigned char *p = data;
        unsigned char *buf = NULL;
        unsigned char *bufp;
        long enclen;

        if (!trusted
            && strcmp(name, PEM_STRING_X509) != 0
            && strcmp(name, PEM_STRING_X509_OLD) != 0) {
            TEST_error("unexpected PEM object: %s", name);
            err = 1;
            goto next;
        }
