#include <cpu_func.h>
#include "cipher_adapt.h"
#include "spacc_body.h"
#include "spacc_union_define.h"
#include "drv_klad.h"
#define intf_func_fail_return(val, ret, func) \
#define intf_param_invalid_return(val) \
#define SPACC_MAX_CHN                   8
#define AES_BLOCK_SIZE                  16
#define SPACC_TIME_OUT                  100000
#define SPACC_PAD_BUF_SIZE              128
#define HASH_RESULT_MAX_LEN             64
#define CHN_0_CIPHER_IV                 (g_cipher_reg_base + 0x0000)
#define CHN_0_CIPHER_DOUT               (g_cipher_reg_base + 0x0080)
#define CHN_0_CIPHER_KEY                (g_cipher_reg_base + 0x0100)
#define CHN_0_SM1_SK                    (g_cipher_reg_base + 0x0200)
#define ODD_EVEN_KEY_SEL                (g_cipher_reg_base + 0x0290)
#define HDCP_MODE_CTRL                  (g_cipher_reg_base + 0x0300)
#define SEC_CHN_CFG                     (g_cipher_reg_base + 0x0304)
#define CALC_ST0                        (g_cipher_reg_base + 0x0318)
#define CALC_ERR                        (g_cipher_reg_base + 0x0320)
#define CHN_0_CCM_GCM_TAG               (g_cipher_reg_base + 0x0380)
#define CHN_0_CIPHER_CTRL               (g_cipher_reg_base + 0x0400)
#define CIPHER_INT_RAW                  (g_cipher_reg_base + 0x040c)
#define CHN_0_CIPHER_DIN                (g_cipher_reg_base + 0x0420)
#define SYMC_INT_LEVEL                  100 /* (SPACC_MAX_DEPTH / 2) */
typedef hi_void (*func_cipher_callback)(hi_u32);

typedef struct {
    cipher_mmz_buf_t mmz_buf;
} spacc_env_s;
typedef struct {
    hi_u8 *src_vir;
    hi_u8 *dest_vir;
    hi_u8 *aad_vir;

    cipher_mmz_buf_t src_mmz_buf;
    cipher_mmz_buf_t dest_mmz_buf;
    cipher_mmz_buf_t aad_mmz_buf;
} spacc_mmz_s;
typedef struct {
    hi_bool is_open;
    hi_u32 hard_num;
    hi_u32 block_size;

    hi_bool symc_done;
    CIPHER_QUEUE_HEAD queue;

    hi_cipher_data *node_list;
    hi_u32 node_num;
    hi_u32 node_cur;
    hi_u32 total_len;

    hi_u8 *pad_vir_addr;
    hi_size_t pad_phy_addr;

    hi_u32 data_size;
    hi_void* which_file;

    cipher_config_ctrl_ex_s ctrl_ex;

    func_cipher_callback callback;
} spacc_symc_chn_s;
typedef struct {
    hi_bool is_open;
    hi_u32 hard_num;
    hi_u32 node_num;
    hi_u32 node_cur;
    hi_u32 block_size;

    hi_bool digest_done;
    CIPHER_QUEUE_HEAD queue;

    func_cipher_callback callback;

    hi_u32 data_size;
    hi_void* which_file;
} spacc_digest_chn_s;
typedef struct {
    hi_u32 src_phys_addr;
    hi_u32 dst_phys_addr;
    hi_u32 byte_length;
    hi_bool is_use_odd_key;
} cipher_data_compat_s;
#ifdef INT_ENABLE
#endif
#ifdef INT_ENABLE
#endif
#ifdef INT_ENABLE
#endif
#ifdef CIPHER_KLAD_SUPPORT
#endif
#ifdef INT_ENABLE
#else
#endif
#ifdef INT_ENABLE
#else
#endif
#ifdef CIPHER_KLAD_SUPPORT
#endif
