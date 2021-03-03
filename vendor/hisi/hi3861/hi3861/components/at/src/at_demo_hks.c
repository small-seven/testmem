#ifdef CONFIG_TEE_HUKS_DEMO_SUPPORT
#include "stdio.h"
#include "stdlib.h"
#include <hi_at.h>
#include "hks_client.h"
#include "hks_types.h"
#include "hks_errno.h"
#include <hi_mem.h>
#include <hi_stdlib.h>
#include "hi_flash.h"
#include "hi3861_platform_base.h"
#include "hi_partition_table.h"
#include "hi_nv.h"
#include "hi_efuse.h"
#include "hi_time.h"
#include "hi_wifi_api.h"
#define FLASH_BASE_ADDR 0x400000
#define CERT_STORE_START_ADDR 0
#define CERT_TOTAL_LEN (1024*12)
#define MAX_CERT_KEY_CNT 100
#define CERT_KEY_START_FLAG 0xDEADBEEF
#define KEY_STORE_START_ADDR (1024 * 12)
#define KEY_LEN 512
#define MAX_KEY_CNT 8
#define KEY_DATA_MAX_LEN 380
#define KYY_PARAM_MAX_LEN 128
#define LEN_BYTE 4
#define CIPHER_PLAIN_LEN_MIN_DIFF 16
#define USR_DATA_START_ADDR (1024 * 16)
#define USR_DATA_LEN (1024 * 4)
#define ENC_PARAM_NONCE_LEN 16
#define ENC_PARAM_AAD_LEN 12
typedef struct encrypt_param_ {
    hi_u16 nonce_size;
    hi_u16 aad_size;
    hi_u8 nonce[ENC_PARAM_NONCE_LEN];
    hi_u8 aad[ENC_PARAM_AAD_LEN];
} encrypt_param;
#define CONN_DATA_KEY_LEN 64
#define CONN_DATA_CIPHER_DATA_MAX_LEN 220
#define CONN_DATA_ENC_PARAM_NONCE_SIZE 13
typedef struct encrypt_data_ {
    hi_u32 cipher_data_size;
    hi_u8 cipher_data[CONN_DATA_CIPHER_DATA_MAX_LEN];
} encrypt_cipher_data;
#define CERT_KEY_LEN 64
#define CERT_ENC_PARAM_NONCE_SIZE 13
#endif
