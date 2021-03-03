#include <stdio.h>
#include <string.h>
#include <openssl/engine.h>
#include <openssl/sha.h>
#include <openssl/md5.h>
#include <openssl/rsa.h>
#include <openssl/evp.h>
#include <openssl/modes.h>
#include <openssl/aes.h>
#include <openssl/rand.h>
#include <openssl/crypto.h>
#include "e_ossltest_err.c"
#define AES_GCM_FLAGS   (EVP_CIPH_FLAG_DEFAULT_ASN1 \
#ifndef OPENSSL_NO_DYNAMIC_ENGINE
#endif
static int ossltest_destroy(ENGINE *e)
{
    destroy_digests();
    destroy_ciphers();
    ERR_unload_OSSLTEST_strings();
    return 1;
}
#undef data
#define data(ctx) ((MD5_CTX *)EVP_MD_CTX_md_data(ctx))
#undef data
#define data(ctx) ((SHA_CTX *)EVP_MD_CTX_md_data(ctx))
#undef data
#define data(ctx) ((SHA256_CTX *)EVP_MD_CTX_md_data(ctx))
#undef data
#define data(ctx) ((SHA512_CTX *)EVP_MD_CTX_md_data(ctx))
