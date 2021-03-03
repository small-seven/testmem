#include <asm/io.h>
#include <linux/errno.h>
#define HIBVT_I2C_GLB       0x0
#define HIBVT_I2C_SCL_H     0x4
#define HIBVT_I2C_SCL_L     0x8
#define HIBVT_I2C_DATA1     0x10
#define HIBVT_I2C_TXF       0x20
#define HIBVT_I2C_RXF       0x24
#define HIBVT_I2C_CMD_BASE  0x30
#define HIBVT_I2C_LOOP1     0xb0
#define HIBVT_I2C_DST1      0xb4
#define HIBVT_I2C_TX_WATER  0xc8
#define HIBVT_I2C_RX_WATER  0xcc
#define HIBVT_I2C_CTRL1     0xd0
#define HIBVT_I2C_CTRL2     0xd4
#define HIBVT_I2C_STAT      0xd8
#define HIBVT_I2C_INTR_RAW  0xe0
#define HIBVT_I2C_INTR_EN   0xe4
#define HIBVT_I2C_INTR_STAT 0xe8
#ifndef bit
#define bit(nr)         (1 << (nr))
#endif
#define GLB_EN_MASK     bit(0)
#define GLB_SDA_HOLD_MASK   0xffff00
#define GLB_SDA_HOLD_SHIFT  8
#define CMD_EXIT    0x0
#define CMD_TX_S    0x1
#define CMD_TX_D1_2 0x4
#define CMD_TX_D1_1 0x5
#define CMD_TX_FIFO 0x9
#define CMD_RX_FIFO 0x12
#define CMD_RX_ACK  0x13
#define CMD_IGN_ACK 0x15
#define CMD_TX_ACK  0x16
#define CMD_TX_NACK 0x17
#define CMD_JMP1    0x18
#define CMD_UP_TXF  0x1d
#define CMD_TX_RS   0x1e
#define CMD_TX_P    0x1f
#define CTRL1_CMD_START_MASK    bit(0)
#define STAT_RXF_NOE_MASK   bit(16) /* RX FIFO not empty flag */
#define STAT_TXF_NOF_MASK   bit(19) /* TX FIFO not full flag */
#define INTR_ABORT_MASK     (bit(0) | bit(11))
#define INTR_RX_MASK        bit(2)
#define INTR_TX_MASK        bit(4)
#define INTR_CMD_DONE_MASK  bit(12)
#define INTR_USE_MASK       (INTR_ABORT_MASK | \
#define INTR_ALL_MASK           0xffffffff
#define I2C_DEFAULT_FREQUENCY   100000
#define I2C_TXF_DEPTH       64
#define I2C_RXF_DEPTH       64
#define I2C_TXF_WATER       32
#define I2C_RXF_WATER       32
#define I2C_WAIT_TIMEOUT    0x400
#define I2C_IRQ_TIMEOUT     (msecs_to_jiffies(1000))
#define I2C_M_RD            0x0001  /* read data, from slave to master */
#define I2C_M_IGNORE_NAK    0x1000  /* if I2C_FUNC_PROTOCOL_MANGLING */
#define I2C_M_TEN           0x0010  /* this is a ten bit chip address */
#define I2C_M_STOP          0x8000  /* if I2C_FUNC_PROTOCOL_MANGLING */
#define CHECK_SDA_IN_SHIFT     16
#define GPIO_MODE_SHIFT        8
#define FORCE_SCL_OEN_SHIFT    4
#define FORCE_SDA_OEN_SHIFT    0
