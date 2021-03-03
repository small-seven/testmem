#include "hi_flashboot_io.h"
#include <hi_types.h>
#define GPIO_SWPORT_DR            0x00
#define GPIO_SWPORT_DDR           0x04
#define GPIO_EXT_PORT             0x50
#define IO_MUX_REG_BASE_ADDR      0x604  /* Base address for the I/O function multiplexing register */
#define IO_CTRL_REG_BASE_ADDR     0x904  /* Base address of the I/O control register, which is used to
#define IO_DRV_PULL_MASK          0x3
#define IO_DRV_STRENGTH_MASK      0x7
#define IO_DRV_PULL_START_BIT     8
#define IO_DRV_STRENGTH_START_BIT 4
#define OFFSET_10_B 10
#define OFFSET_2_B  2
#define IE_MSK      0x1
