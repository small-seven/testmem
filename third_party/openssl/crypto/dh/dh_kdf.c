#include "e_os.h"
#ifndef OPENSSL_NO_CMS
#include <string.h>
#include <openssl/dh.h>
#include <openssl/evp.h>
#include <openssl/asn1.h>
#include <openssl/cms.h>
#define DH_KDF_MAX      (1L << 30)
#endif
