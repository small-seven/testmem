#include <cmd_loop.h>
#include <crc.h>
#include <transfer.h>
#define CMD_RX_DELAY_MS     100 /* 100ms */
#define US_PER_MS           1000
#define CMD_FRAME_TIMEOUT   20000 /* 20s */
#define CMD_ABNORMAL_MAX    100
#define CHECKSUM_SIZE       2
#define ACK_LEN             0x0C
#define VER_CFG_BIN_LEN 8
#define UPDATE_VER_STATUS_NONE        0
#define UPDATE_VER_STATUS_BOOT        1
#define UPDATE_VER_STATUS_KERNEL      2
#define UPDATE_VER_STATUS_BOOT_KERNEL 3
#define KERELN_VER_MAX          48
#define KERNEL_VER_LEN          6
#define BOOT_VER_MAX            16
#define BOOT_VER_LEN            2
#define BIT_U8   8
#define SEC_BOOT_FLAG 0x42
#define WAIT_VER_UPDATE_TRY_CNT 1000
#define WAIT_VER_UPDATE_TRY_INTER_US 10000
#define NMI_BASE_ADDRESS    0x40010000
#define NMI_CTRL            0x0258
#define NMI_INT_MOD_DONE_EN_POS 0
typedef enum {
    CMD_RX_STATUS_WAIT_START_0,
    CMD_RX_STATUS_WAIT_START_1,
    CMD_RX_STATUS_WAIT_START_2,
    CMD_RX_STATUS_WAIT_START_3,
    CMD_RX_STATUS_WAIT_SIZE_0,
    CMD_RX_STATUS_WAIT_SIZE_1,
    CMD_RX_STATUS_WAIT_TYPE,
    CMD_RX_STATUS_WAIT_PAD,
    CMD_RX_STATUS_WAIT_DATA,
    CMD_RX_STATUS_WAIT_CS_0,
    CMD_RX_STATUS_WAIT_CS_1,
} cmd_rx_status;
typedef hi_u32(*cmd_func) (const uart_ctx *cmd_ctx);

typedef struct {
    hi_u8 cmd_type;
    cmd_func cmdfunc;
} loader_cmd;
#ifdef CONFIG_FLASH_ENCRYPT_SUPPORT
#endif
