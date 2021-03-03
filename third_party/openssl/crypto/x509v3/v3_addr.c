#include <stdio.h>
#include <stdlib.h>
#include "internal/cryptlib.h"
#include <openssl/conf.h>
#include <openssl/asn1.h>
#include <openssl/asn1t.h>
#include <openssl/buffer.h>
#include <openssl/x509v3.h>
#include "crypto/x509.h"
#include "ext_dat.h"
#ifndef OPENSSL_NO_RFC3779
#define ADDR_RAW_BUF_LEN        16
#define addr_prefixlen(bs) ((int) ((bs)->length * 8 - ((bs)->flags & 7)))
#define validation_err(_err_)           \
#undef validation_err
#endif                          /* OPENSSL_NO_RFC3779 */
