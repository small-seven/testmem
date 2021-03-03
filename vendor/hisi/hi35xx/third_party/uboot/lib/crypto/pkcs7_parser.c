#define pr_fmt(fmt) "PKCS7: "fmt
#ifdef __UBOOT__
#include <linux/bitops.h>
#include <linux/compat.h>
#endif
#include <linux/kernel.h>
#ifndef __UBOOT__
#include <linux/module.h>
#include <linux/export.h>
#include <linux/slab.h>
#endif
#include <linux/err.h>
#include <linux/oid_registry.h>
#include <crypto/public_key.h>
#include "pkcs7_parser.h"
#include "pkcs7.asn1.h"
#ifdef __UBOOT__ /* OID_data is needed for authenticated UEFI variables */
#else
#endif
