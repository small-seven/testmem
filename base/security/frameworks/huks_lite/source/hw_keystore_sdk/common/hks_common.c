#include "hks_common.h"
#include <mbedtls/ctr_drbg.h>
#include <mbedtls/entropy.h>
#include <mbedtls/hkdf.h>
#include <mbedtls/sha256.h>
#include <mbedtls/sha512.h>
#include "securec.h"
#ifdef _SECURE_ENVIREMENT_NMI_
#include <hi_types_base.h>
#include <hi_cipher.h>
#include <hi_efuse.h>
#include "hks_rkc.h"
#endif
#include "hks_errno.h"
#include "hks_hardware_random.h"
#include "hks_log_utils.h"
#include "hks_mem.h"
#define MAX_GCM_TAG_LENGTH 16
#define MBEDTLS_RET_CODE_BOUNDARY (-0x7f)
#define MBEDTLS_RET_CODE_HIGH_LEVEL_MASK 0x7F80
#if defined(_HILINK_PRODUCT_)
#elif defined(_SECURE_ENVIREMENT_NMI_)
#else
#endif
int32_t hks_malloc_init_ptr(uint32_t size, uint8_t **ptr)
{
    if (ptr == NULL)
        return HKS_ERROR_NULL_POINTER;
    if (size == 0)
        return HKS_ERROR_INVALID_ARGUMENT;
    *ptr = (uint8_t *)HKS_MALLOC(size);
    if (*ptr == NULL)
        return HKS_ERROR_INSUFFICIENT_MEMORY;

    if (memset_s(*ptr, size, 0, size) != EOK) {
        hks_free_ptr(*ptr);
        return HKS_ERROR_BAD_STATE;
    }
    return HKS_STATUS_OK;
}
void hks_blob_destroy(struct hks_blob *blob)
{
    if (blob == NULL)
        return;
    if (blob->size == 0)
        return;

    if (blob->data != NULL) {
        (void)memset_s(blob->data, blob->size, 0, blob->size);
        hks_free_ptr(blob->data);
    }

    blob->size = 0;
    blob->type = HKS_BLOB_TYPE_RAW;
}
#ifdef _SECURE_ENVIREMENT_NMI_
void hks_encrypt_material_destroy_free(struct hks_encrypt_material *encrypt_material)
{
    if (encrypt_material == NULL)
        return;

    hks_blob_destroy(encrypt_material->plain_text);
    hks_blob_destroy(encrypt_material->cipher_text);
    hks_blob_destroy(encrypt_material->nonce_blob);
    hks_blob_destroy(encrypt_material->aad_blob);

    hks_free_ptr(encrypt_material->plain_text);
    hks_free_ptr(encrypt_material->cipher_text);
    hks_free_ptr(encrypt_material->nonce_blob);
    hks_free_ptr(encrypt_material->aad_blob);
}
#endif
#ifndef _SUPPORT_HKS_TEE_
void hks_key_param_destroy(struct hks_key_param *pram)
{
    if (pram == NULL)
        return;

    if (pram->key_auth_id.data != NULL)
        hks_free_ptr(pram->key_auth_id.data);

    pram->key_auth_id.data = NULL;
}
#else
void hks_key_param_destroy(struct hks_key_param *pram)
{
    if (pram == NULL)
        return;

    if (pram->key_param_ext.key_auth_id.data != NULL)
        hks_free_ptr(pram->key_param_ext.key_auth_id.data);

    pram->key_param_ext.key_auth_id.data = NULL;
}
#endif
