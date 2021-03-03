#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#include <errno.h>
#include <openssl/crypto.h>
#include <openssl/evp.h>
#include <openssl/x509.h>
#include <openssl/ssl.h>
#include <openssl/err.h>
#include <openssl/conf.h>
#ifndef OPENSSL_NO_ENGINE
#include <openssl/engine.h>
#endif
#include "testutil.h"
#include "internal/nelem.h"
#define _UC(c) ((unsigned char)(c))
    typedef X509 *(*d2i_X509_t)(X509 **, const unsigned char **, long);

    if (!TEST_ptr(chain = sk_X509_new_null()))
        goto err;

    for (count = 0;
         count < nelem && errtype == 0
         && PEM_read_bio(fp, &name, &header, &data, &len) == 1;
         ++count) {
        if (strcmp(name, PEM_STRING_X509) == 0
                    || strcmp(name, PEM_STRING_X509_TRUSTED) == 0
                    || strcmp(name, PEM_STRING_X509_OLD) == 0) {
            d2i_X509_t d = strcmp(name, PEM_STRING_X509_TRUSTED) != 0
                ? d2i_X509_AUX : d2i_X509;
            X509 *cert;
            const unsigned char *p = data;

            if (!TEST_ptr(cert = d(0, &p, len))
                    || !TEST_long_eq(p - data, len)) {
                TEST_info("Certificate parsing error");
                goto err;
            }
#include "internal/dane.h"
