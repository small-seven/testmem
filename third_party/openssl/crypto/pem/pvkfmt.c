#include "internal/cryptlib.h"
#include <openssl/pem.h>
#include <openssl/rand.h>
#include <openssl/bn.h>
#if !defined(OPENSSL_NO_RSA) && !defined(OPENSSL_NO_DSA)
# include <openssl/dsa.h>
# include <openssl/rsa.h>
# define MS_PUBLICKEYBLOB        0x6
# define MS_PRIVATEKEYBLOB       0x7
# define MS_RSA1MAGIC            0x31415352L
# define MS_RSA2MAGIC            0x32415352L
# define MS_DSS1MAGIC            0x31535344L
# define MS_DSS2MAGIC            0x32535344L
# define MS_KEYALG_RSA_KEYX      0xa400
# define MS_KEYALG_DSS_SIGN      0x2200
# define MS_KEYTYPE_KEYX         0x1
# define MS_KEYTYPE_SIGN         0x2
# define BLOB_MAX_LENGTH          102400
# define MS_PVKMAGIC             0xb0b5f11eL
# define PVK_SALTLEN             0x10
# define PVK_MAX_KEYLEN          102400
# define PVK_MAX_SALTLEN         10240
# ifndef OPENSSL_NO_RC4
# endif
#endif
