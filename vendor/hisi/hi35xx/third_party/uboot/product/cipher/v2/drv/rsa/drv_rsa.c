#include "cipher_adapt.h"
#include "drv_rng.h"
#include "drv_klad.h"
#ifdef RSA_ENABLE
#define cipher_rsa_return_invalid_param(param) \
#define RSA_INTERRUPT_ENABLE
#define RSA_IRQ_NUMBER                          136
#define CIPHER_RSA_REG_BASE_RSA                   g_rsa_reg_base
#define SEC_RSA_BUSY_REG                          (CIPHER_RSA_REG_BASE_RSA + 0x50)
#define SEC_RSA_MOD_REG                           (CIPHER_RSA_REG_BASE_RSA + 0x54)
#define SEC_RSA_WSEC_REG                          (CIPHER_RSA_REG_BASE_RSA + 0x58)
#define SEC_RSA_WDAT_REG                          (CIPHER_RSA_REG_BASE_RSA + 0x5c)
#define SEC_RSA_RPKT_REG                          (CIPHER_RSA_REG_BASE_RSA + 0x60)
#define SEC_RSA_RRSLT_REG                         (CIPHER_RSA_REG_BASE_RSA + 0x64)
#define SEC_RSA_START_REG                         (CIPHER_RSA_REG_BASE_RSA + 0x68)
#define SEC_RSA_ADDR_REG                          (CIPHER_RSA_REG_BASE_RSA + 0x6C)
#define SEC_RSA_ERROR_REG                         (CIPHER_RSA_REG_BASE_RSA + 0x70)
#define SEC_RSA_CRC16_REG                         (CIPHER_RSA_REG_BASE_RSA + 0x74)
#define SEC_RSA_KEY_RANDOM_1                      (CIPHER_RSA_REG_BASE_RSA + 0x7c)
#define SEC_RSA_INT_EN                            (CIPHER_RSA_REG_BASE_RSA + 0x80)
#define SEC_RSA_INT_STATUS                        (CIPHER_RSA_REG_BASE_RSA + 0x84)
#define SEC_RSA_INT_RAW                           (CIPHER_RSA_REG_BASE_RSA + 0x88)
#define SEC_RSA_INT_ERR_CLR                       (CIPHER_RSA_REG_BASE_RSA + 0x8c)
#define SEC_RSA_KEY_RANDOM_2                      (CIPHER_RSA_REG_BASE_RSA + 0x94)
#define SEC_RSA_VERSION                           (CIPHER_RSA_REG_BASE_RSA + 0x90)
#define RSA_DATA_CLR               (7 << 4)
#define RSA_DATA_CLR_KEY           (1 << 4)
#define RSA_DATA_CLR_INPUT         (2 << 4)
#define RSA_DATA_CLR_OUTPUT        (4 << 4)
#define RSA_MOD_SEL                (3 << 0)
#define RSA_MOD_SEL_OPT            (0 << 0)
#define RSA_MOD_SEL_KEY_UPDATA     (1 << 0)
#define RSA_MOD_SEL_RAM_CLAER      (2 << 0)
#define RSA_MOD_SEL_CRC16          (3 << 0)
#define RSA_BUSY                   (1 << 0)
#define RSA_START                  (1 << 0)
#define RSA_RTY_CNT             50000
#define RSA_TIME_OUT            1000
#define RSA_RETRY_CNT           3
#define CRC16_POLYNOMIAL        0x1021
typedef enum {
    CIPHER_RSA_DATA_TYPE_CONTEXT,
    CIPHER_RSA_DATA_TYPE_MODULE,
    CIPHER_RSA_DATA_TYPE_KEY,
} cipher_rsa_data_type_e;
typedef enum {
    CIPHER_RSA_KEY_WIDTH_1K   = 0x00,
    CIPHER_RSA_KEY_WIDTH_2K   = 0x01,
    CIPHER_RSA_KEY_WIDTH_4K   = 0x02,
    CIPHER_RSA_KEY_WIDTH_3K   = 0x03,
    CIPHER_RSA_KEY_WIDTH_BUTT = 0xff,
} cipher_rsa_key_width_e;
static hi_s32 hal_rsa_wait_free(hi_void)
{
    hi_u32 value;
    hi_u32 try_count = 0;

    do {
        hal_cipher_read_reg(SEC_RSA_BUSY_REG, &value);
        if ((value & RSA_BUSY) == 0)
            return HI_SUCCESS;
        try_count++;
        cipher_msleep(1);
    } while (try_count < RSA_RTY_CNT);

    return HI_FAILURE;
}
#ifdef INT_ENABLE
#endif
#ifdef RSA_RAND_MASK
#endif
#ifdef INT_ENABLE
#endif
#ifdef INT_ENABLE
#endif
#ifdef INT_ENABLE
#endif
#ifdef RSA_RAND_MASK
#endif
#ifdef INT_ENABLE
#endif
#ifdef INT_ENABLE
#else
#endif
#ifdef RSA_RAND_MASK
#endif
#ifdef CIPHER_KLAD_SUPPORT
#else
#endif
#endif
