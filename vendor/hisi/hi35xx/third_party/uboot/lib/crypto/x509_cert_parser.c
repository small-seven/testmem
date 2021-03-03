#define pr_fmt(fmt) "X.509: "fmt
#include <linux/kernel.h>
#ifndef __UBOOT__
#include <linux/export.h>
#include <linux/slab.h>
#endif
#include <linux/err.h>
#include <linux/oid_registry.h>
#ifdef __UBOOT__
#include <linux/string.h>
#endif
#include <crypto/public_key.h>
#include "x509_parser.h"
#include "x509.asn1.h"
#include "x509_akid.asn1.h"
#ifndef __UBOOT__
#endif
#define SEQ_TAG_KEYID (ASN1_CONT << 6)
#define dec2bin(X) ({ unsigned char x = (X) - '0'; if (x > 9) goto invalid_time; x; })
#define DD2bin(P) ({ unsigned x = dec2bin(P[0]) * 10 + dec2bin(P[1]); P += 2; x; })
