#include <stdio.h>
#include "crypto/ctype.h"
#include <limits.h>
#include "internal/cryptlib.h"
#include <openssl/lhash.h>
#include <openssl/asn1.h>
#include "crypto/objects.h"
#include <openssl/bn.h>
#include "crypto/asn1.h"
#include "obj_local.h"
#include "obj_dat.h"
#define ADDED_DATA      0
#define ADDED_SNAME     1
#define ADDED_LNAME     2
#define ADDED_NID       3
#ifdef CHARSET_EBCDIC
#endif
