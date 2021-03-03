#include <assert.h>
#include <stdio.h>
#include <string.h>
#include "internal/cryptlib.h"
#include <openssl/conf.h>
#include <openssl/asn1.h>
#include <openssl/asn1t.h>
#include <openssl/x509v3.h>
#include <openssl/x509.h>
#include "crypto/x509.h"
#include <openssl/bn.h>
#include "ext_dat.h"
#ifndef OPENSSL_NO_RFC3779
#define validation_err(_err_)           \
#undef validation_err
#endif                          /* OPENSSL_NO_RFC3779 */
