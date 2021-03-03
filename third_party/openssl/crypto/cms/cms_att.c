#include <openssl/asn1t.h>
#include <openssl/pem.h>
#include <openssl/x509v3.h>
#include <openssl/err.h>
#include <openssl/cms.h>
#include "cms_local.h"
#include "internal/nelem.h"
#define CMS_ATTR_F_SIGNED         0x01
#define CMS_ATTR_F_UNSIGNED       0x02
#define CMS_ATTR_F_REQUIRED_COND  0x10
#define CMS_ATTR_F_ONLY_ONE       0x20
#define CMS_ATTR_F_ONE_ATTR_VALUE 0x40
