#include <stdint.h>
#include <string.h>
#include "config.h"
#include "libavutil/attributes.h"
#include "libavutil/error.h"
#include "libavutil/mem.h"
#include "libavutil/random_seed.h"
#include "rtmpdh.h"
#if CONFIG_MBEDTLS
#include <mbedtls/ctr_drbg.h>
#include <mbedtls/entropy.h>
#endif
#define P1024                                          \
#define Q1024                                          \
#if CONFIG_GMP
#define bn_new(bn)                      \
#define bn_free(bn)     \
#define bn_set_word(bn, w)          mpz_set_ui(bn, w)
#define bn_cmp(a, b)                mpz_cmp(a, b)
#define bn_copy(to, from)           mpz_set(to, from)
#define bn_sub_word(bn, w)          mpz_sub_ui(bn, bn, w)
#define bn_cmp_1(bn)                mpz_cmp_ui(bn, 1)
#define bn_num_bytes(bn)            (mpz_sizeinbase(bn, 2) + 7) / 8
#define bn_bn2bin(bn, buf, len)                     \
#define bn_bin2bn(bn, buf, len)                     \
#define bn_hex2bn(bn, buf, ret)                     \
#define bn_random(bn, num_bits)                       \
#elif CONFIG_GCRYPT
#define bn_new(bn)                                              \
#define bn_free(bn)                 gcry_mpi_release(bn)
#define bn_set_word(bn, w)          gcry_mpi_set_ui(bn, w)
#define bn_cmp(a, b)                gcry_mpi_cmp(a, b)
#define bn_copy(to, from)           gcry_mpi_set(to, from)
#define bn_sub_word(bn, w)          gcry_mpi_sub_ui(bn, bn, w)
#define bn_cmp_1(bn)                gcry_mpi_cmp_ui(bn, 1)
#define bn_num_bytes(bn)            (gcry_mpi_get_nbits(bn) + 7) / 8
#define bn_bn2bin(bn, buf, len)     gcry_mpi_print(GCRYMPI_FMT_USG, buf, len, NULL, bn)
#define bn_bin2bn(bn, buf, len)     gcry_mpi_scan(&bn, GCRYMPI_FMT_USG, buf, len, NULL)
#define bn_hex2bn(bn, buf, ret)     ret = (gcry_mpi_scan(&bn, GCRYMPI_FMT_HEX, buf, 0, 0) == 0)
#define bn_random(bn, num_bits)     gcry_mpi_randomize(bn, num_bits, GCRY_WEAK_RANDOM)
#elif CONFIG_OPENSSL
#define bn_new(bn)                  bn = BN_new()
#define bn_free(bn)                 BN_free(bn)
#define bn_set_word(bn, w)          BN_set_word(bn, w)
#define bn_cmp(a, b)                BN_cmp(a, b)
#define bn_copy(to, from)           BN_copy(to, from)
#define bn_sub_word(bn, w)          BN_sub_word(bn, w)
#define bn_cmp_1(bn)                BN_cmp(bn, BN_value_one())
#define bn_num_bytes(bn)            BN_num_bytes(bn)
#define bn_bn2bin(bn, buf, len)     BN_bn2bin(bn, buf)
#define bn_bin2bn(bn, buf, len)     bn = BN_bin2bn(buf, len, 0)
#define bn_hex2bn(bn, buf, ret)     ret = BN_hex2bn(&bn, buf)
#define bn_random(bn, num_bits)     BN_rand(bn, num_bits, 0, 0)
#elif CONFIG_MBEDTLS
#define bn_new(bn)                      \
#define bn_free(bn)                     \
#define bn_set_word(bn, w)          mbedtls_mpi_lset(bn, w)
#define bn_cmp(a, b)                mbedtls_mpi_cmp_mpi(a, b)
#define bn_copy(to, from)           mbedtls_mpi_copy(to, from)
#define bn_sub_word(bn, w)          mbedtls_mpi_sub_int(bn, bn, w)
#define bn_cmp_1(bn)                mbedtls_mpi_cmp_int(bn, 1)
#define bn_num_bytes(bn)            (mbedtls_mpi_bitlen(bn) + 7) / 8
#define bn_bn2bin(bn, buf, len)     mbedtls_mpi_write_binary(bn, buf, len)
#define bn_bin2bn(bn, buf, len)                     \
#define bn_hex2bn(bn, buf, ret)                     \
#define bn_random(bn, num_bits)                     \
#define bn_modexp(bn, y, q, p)      mbedtls_mpi_exp_mod(bn, y, q, p, 0)
#endif
#define MAX_BYTES 18000
#define dh_new()                    av_mallocz(sizeof(FF_DH))
void ff_dh_free(FF_DH *dh)
{
    if (!dh)
        return;
    bn_free(dh->p);
    bn_free(dh->g);
    bn_free(dh->pub_key);
    bn_free(dh->priv_key);
    av_free(dh);
}
