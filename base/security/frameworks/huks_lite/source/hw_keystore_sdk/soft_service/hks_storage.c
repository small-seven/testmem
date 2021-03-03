#include "hks_storage.h"
#include <stdlib.h>
#include <string.h>
#include <mbedtls/ctr_drbg.h>
#include <mbedtls/ecdh.h>
#include <mbedtls/entropy.h>
#include <mbedtls/platform.h>
#include "securec.h"
#include "common/hks_common.h"
#include "common/hks_log_utils.h"
#include "common/hks_mem.h"
#include "hks_errno.h"
#include "hks_file.h"
#include "hks_rkc.h"
#define HKS_SEALING_NONCE_SIZE          16
#define HKS_SEALING_TAG_SIZE            16
#define HKS_SEALING_ALG_MASK            ((uint32_t)0xffff0000)
#define HKS_SEALING_AES_GCM_128         ((uint32_t)0x01010000)
#define HKS_SEALING_AES_GCM_256         ((uint32_t)0x01020000)
#define HKS_SEALING_HKDF_MASK           ((uint32_t)0x000000ff)
#define HKS_SEALING_HKDF_SHA_256        ((uint32_t)0x00000001)
#define HKS_SEALING_HKDF_SHA_512        ((uint32_t)0x00000002)
#define HKS_SEALING_AES_GCM_128_SHA_256 (HKS_SEALING_AES_GCM_128 | \
#define HKS_SEALING_AES_GCM_256_SHA_256 (HKS_SEALING_AES_GCM_256 | \
#define HKS_SEALING_AES_GCM_128_SHA_512 (HKS_SEALING_AES_GCM_128 | \
#define HKS_SEALING_AES_GCM_256_SHA_512 (HKS_SEALING_AES_GCM_256 | \
#define HKS_SEALING_DEFAULT             HKS_SEALING_AES_GCM_256_SHA_256
#ifndef hks_bits_to_bytes
#define hks_bits_to_bytes(x) (((x) + 7) / 8)
#endif
#define HKS_HEADER_RESERVE_SIZE  7
#define BUF_SIZE    65536
#define HKS_SLOT_PUBLIC_KEY_IDLE             ((uint8_t)0x00)
#define HKS_SLOT_PUBLIC_KEY_OCCUPY           ((uint8_t)0x01)
#define HKS_SLOT_KEYPAIR_IDLE                ((uint8_t)0x02)
#define HKS_SLOT_KEYPAIR_OCCUPY              ((uint8_t)0x03)
static void hks_free_buffer(void)
{
    hks_clean_buffer();
    hks_free_ptr(g_storage_image_buffer);
}
#ifdef _SECURE_ENVIREMENT_NMI_
#endif
int32_t hks_storage_remove_key_info(const struct hks_blob *key_alias)
{
    if (key_alias == NULL)
        return HKS_ERROR_NULL_POINTER;

    if ((key_alias->size > HKS_ALIAS_MAX_SIZE) || (key_alias->data == NULL))
        return HKS_ERROR_INVALID_ARGUMENT;

    uint8_t *key_pos = NULL;
    int32_t status = hks_get_key_pos(key_alias, &key_pos);

    if (status != HKS_STATUS_OK)
        return status;

    if (key_pos == NULL)
        return HKS_ERROR_KEY_NOT_EXIST;

    if (memset_s(key_pos, hks_get_key_slot_len(), 0,
        hks_get_key_slot_len()) != EOK)
        return HKS_ERROR_BAD_STATE;

    status = hks_reduce_key_count();
    if (status != HKS_STATUS_OK)
        return status;

    status = hks_refresh_header_hash();
    if (status != HKS_STATUS_OK)
        return status;

    status = hks_sync_buf_to_file();

    return status;
}
#if defined(_HILINK_PRODUCT_)
#else
#endif
void hks_storage_destroy(void)
{
    hks_clean_buffer();

    int32_t status = hks_sync_buf_to_file();

    log_info("clean key store, status=%d", status);
    (void)status; /* hilink compile will replace log with {} */
    hks_free_ptr(g_storage_image_buffer);
}
