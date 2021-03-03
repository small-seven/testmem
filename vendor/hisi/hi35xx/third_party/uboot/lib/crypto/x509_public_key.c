#define pr_fmt(fmt) "X.509: "fmt
#ifdef __UBOOT__
#include <common.h>
#include <linux/compat.h>
#include <linux/errno.h>
#else
#include <linux/module.h>
#endif
#include <linux/kernel.h>
#ifndef __UBOOT__
#include <linux/slab.h>
#include <keys/asymmetric-subtype.h>
#include <keys/asymmetric-parser.h>
#include <keys/system_keyring.h>
#include <crypto/hash.h>
#include "asymmetric_keys.h"
#endif
#include "x509_parser.h"
#ifndef __UBOOT__
#endif
#ifdef __UBOOT__
#else
#endif /* __UBOOT__ */
#ifndef __UBOOT__
#endif /* !__UBOOT__ */
