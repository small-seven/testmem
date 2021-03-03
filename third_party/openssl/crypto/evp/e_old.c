#include <openssl/opensslconf.h>
#if OPENSSL_API_COMPAT >= 0x00908000L
#else
# include <openssl/evp.h>
# ifndef OPENSSL_NO_BF
#  undef EVP_bf_cfb
# endif
# ifndef OPENSSL_NO_DES
#  undef EVP_des_cfb
#  undef EVP_des_ede3_cfb
#  undef EVP_des_ede_cfb
# endif
# ifndef OPENSSL_NO_IDEA
#  undef EVP_idea_cfb
# endif
# ifndef OPENSSL_NO_RC2
#  undef EVP_rc2_cfb
# endif
# ifndef OPENSSL_NO_CAST
#  undef EVP_cast5_cfb
# endif
# ifndef OPENSSL_NO_RC5
#  undef EVP_rc5_32_12_16_cfb
# endif
# undef EVP_aes_128_cfb
# undef EVP_aes_192_cfb
# undef EVP_aes_256_cfb
#endif
