#include "hks_service.h"
#include <mbedtls/ctr_drbg.h>
#include <mbedtls/ecdh.h>
#include <mbedtls/entropy.h>
#include <mbedtls/platform.h>
#include <mbedtls/sha1.h>
#ifdef _SECURE_ENVIREMENT_NMI_
#include <openssl/curve25519.h>
#else
#include <ec_local.h>
#endif
#include "securec.h"
#include "common/hks_bn.h"
#include "common/hks_common.h"
#include "common/hks_hardware_random.h"
#include "common/hks_log_utils.h"
#include "common/hks_mem.h"
#include "hks_errno.h"
#include "hks_rkc.h"
#define HKS_BN_MOD_SHIFT_DEC 4 /* bn mod Dec bit shift */
#define HKS_BN_MOD_SHIFT_HEX 16 /* bn mod Hex bit shift */
#ifdef _SECURE_ENVIREMENT_NMI_
#endif
#ifndef _SUPPORT_HKS_TEE_
#ifdef _SECURE_ENVIREMENT_NMI_
#else
#endif
#endif
#if defined(_HILINK_PRODUCT_)  /* hilink replace generate random */
#else
#endif
#if defined(MBEDTLS_SHA256_C)
#endif
#if defined(MBEDTLS_SHA512_C)
#endif
#if defined(MBEDTLS_SHA256_C)
#endif
#if defined(MBEDTLS_SHA512_C)
#endif
#ifndef _SUPPORT_HKS_TEE_
#ifdef _SECURE_ENVIREMENT_NMI_
#else
#endif
#endif
#ifndef _SUPPORT_HKS_TEE_
#ifdef _SECURE_ENVIREMENT_NMI_
#endif
#else
#endif
#ifndef _SUPPORT_HKS_TEE_
#ifdef _SECURE_ENVIREMENT_NMI_
#endif
#ifdef _SECURE_ENVIREMENT_NMI_
#endif
#ifdef _SECURE_ENVIREMENT_NMI_
#else
#endif
#ifdef _SECURE_ENVIREMENT_NMI_
#endif
#ifndef _SECURE_ENVIREMENT_NMI_
#endif
void hks_service_destroy(void)
{
    hks_storage_destroy();
#ifndef _SECURE_ENVIREMENT_NMI_
    hks_rkc_destroy();
#endif
}
#ifndef _SECURE_ENVIREMENT_NMI_
#endif
#endif
