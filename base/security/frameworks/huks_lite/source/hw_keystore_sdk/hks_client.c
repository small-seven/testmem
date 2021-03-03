#include "hks_client.h"
#include <mbedtls/config.h>
#include <mbedtls/platform.h>
#include "securec.h"
#include "common/hks_common.h"
#include "common/hks_log_utils.h"
#include "common/hks_mem.h"
#include "hks_errno.h"
#include "hks_file_api.h"
#include "hks_hardware_api.h"
#include "hks_types.h"
#include "soft_service/hks_service.h"
#include "hks_access.h"
#define HKS_AES_GCM_MIN_IV_LENGTH 12
#define hks_not_support_interface \
#if (defined(_CUT_STS_) || defined(_CUT_STS_SERVER_)) && \
#else
#ifdef _SUPPORT_HKS_TEE_
#else
#endif
#endif
#ifdef _SUPPORT_HKS_TEE_
#endif
#if defined(_CUT_STS_) || defined(_CUT_STS_SERVER_)
#else
#ifdef _SUPPORT_HKS_TEE_
#else
#endif
#endif
#if (defined(_CUT_STS_) || defined(_CUT_STS_SERVER_) ||  \
#else
#ifdef _SUPPORT_HKS_TEE_
#else
#endif
#endif
#if defined(_CUT_EXCHANGE_SERVER_) || defined(_CUT_PAKE_) || \
#else
#ifdef _SUPPORT_HKS_TEE_
#else
#endif
#endif
#if defined(_CUT_API_) && (defined(_CUT_STS_) || defined(_CUT_STS_SERVER_) || \
#else
#ifdef _SUPPORT_HKS_TEE_
#else
#endif
#endif
#if defined(_CUT_API_)
#else
#ifdef _SUPPORT_HKS_TEE_
#else
#endif
#endif
#if defined(_CUT_API_) && (defined(_CUT_STS_) || \
#else
#ifdef _SUPPORT_HKS_TEE_
#else
#endif
#endif
#if (defined(_CUT_STS_) || defined(_CUT_STS_SERVER_)) && \
#else
#ifdef _SUPPORT_HKS_TEE_
#else
#endif
#endif
#if (defined(_CUT_STS_) || defined(_CUT_STS_SERVER_)) && \
#else
#ifdef _SUPPORT_HKS_TEE_
#else
#endif
#endif
#ifdef _SUPPORT_HKS_TEE_
#else
#endif
#if defined(_CUT_PAKE_) || defined(_CUT_PAKE_SERVER_) || \
#else
#ifdef _SUPPORT_HKS_TEE_
#else
#endif
#endif
#ifdef _SUPPORT_HKS_TEE_
#else
#endif
#if defined(_CUT_PAKE_) || defined(_CUT_PAKE_SERVER_) || \
#else
#ifdef _SUPPORT_HKS_TEE_
#else
#endif
#endif
#if (defined(_CUT_STS_) || defined(_CUT_STS_SERVER_)) && \
#else
#ifdef _SUPPORT_HKS_TEE_
#else
#endif
#endif
#if defined(_CUT_STS_) || defined(_CUT_STS_SERVER_)
#else
#ifdef _SUPPORT_HKS_TEE_
#else
#endif
#endif
#if (defined(_CUT_STS_) || defined(_CUT_STS_SERVER_)) && \
#else
#ifdef _SUPPORT_HKS_TEE_
#else
#endif
#endif
#if defined(_CUT_PAKE_) || defined(_CUT_PAKE_SERVER_)
#else
#ifdef _SUPPORT_HKS_TEE_
#else
#endif
#endif
#if defined(_CUT_API_) &&  \
#else
#ifdef _SUPPORT_HKS_TEE_
#else
#endif
#endif
#if defined(_CUT_PAKE_) || defined(_CUT_PAKE_SERVER_)
#else
#ifdef _SUPPORT_HKS_TEE_
#else
#endif
#endif
#ifndef _SUPPORT_HKS_TEE_
#endif
#if defined(_CUT_API_)
#else
#ifdef _SUPPORT_HKS_TEE_
#else
#endif
#endif
#if (defined(_CUT_STS_) || defined(_CUT_STS_SERVER_)) &&  \
#else
#if defined(MBEDTLS_MEMORY_BUFFER_ALLOC_C) && defined(_STD_LIB_SOUTH_)
#endif
#ifdef _SUPPORT_HKS_TEE_
#else
#endif
#endif
#ifndef _SUPPORT_HKS_TEE_
HKS_DLL_API_PUBLIC void hks_destroy(void)
{
    hks_access_destroy();
}
#endif
#if defined(_SUPPORT_HKS_TEE_) || \
#else
#endif
#if defined (_SUPPORT_HKS_TEE_)
#endif
#ifdef _SECURE_ENVIREMENT_NMI_
#endif
