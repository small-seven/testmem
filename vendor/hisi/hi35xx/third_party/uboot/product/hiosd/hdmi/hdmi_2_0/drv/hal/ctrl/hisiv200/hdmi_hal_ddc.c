#include "hdmi_hal_ddc.h"
#include "hdmi_osal.h"
#include "hdmi_reg_aon.h"
#include "hdmi_reg_ctrl.h"
#include "hdmi_hal_intf.h"
#include "hdmi_hal_ctrl.h"
#include "hdmi_product_define.h"
#define DDC_EDID_SALVE_ADDR  0xa0
#define DDC_HDCP_SALVE_ADDR  0x74
#define DDC_SCDC_SALVE_ADDR  0xa8
#define DDC_MAX_FIFO_SIZE    16
#define DDC_EXT_BLOCK_OFFSET 0x7e
#define DDC_MAX_EDID_EXT_NUM 3 /* 3: 4(max block num) - 1(base block) */
#define DDC_DATA_FIFO_DELAY  1
#define DDC_GPIO_DELAY       8 /* 8us */
typedef enum {
    DDC_CMD_READ_SINGLE_NO_ACK  = 0x00,
    DDC_CMD_READ_SINGLE_ACK     = 0x01,
    DDC_CMD_READ_MUTI_NO_ACK    = 0x02,
    DDC_CMD_READ_MUTI_ACK       = 0x03,
    DDC_CMD_READ_SEGMENT_NO_ACK = 0x04,
    DDC_CMD_READ_SEGMENT_ACK    = 0x05,
    DDC_CMD_WRITE_MUTI_NO_ACK   = 0x06,
    DDC_CMD_WRITE_MUTI_ACK      = 0x07,
    DDC_CMD_FIFO_CLR            = 0x09,
    DDC_CMD_SCL_DRV             = 0x0a,
    DDC_CMD_MASTER_ABORT        = 0x0f
} ddc_issue_cmd;
