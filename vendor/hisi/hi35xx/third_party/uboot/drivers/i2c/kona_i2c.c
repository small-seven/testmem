#include <common.h>
#include <asm/io.h>
#include <linux/errno.h>
#include <asm/arch/sysmap.h>
#include <asm/kona-common/clk.h>
#include <i2c.h>
#define CS_OFFSET				0x00000020
#define CS_ACK_SHIFT				3
#define CS_ACK_MASK				0x00000008
#define CS_ACK_CMD_GEN_START			0x00000000
#define CS_ACK_CMD_GEN_RESTART			0x00000001
#define CS_CMD_SHIFT				1
#define CS_CMD_CMD_NO_ACTION			0x00000000
#define CS_CMD_CMD_START_RESTART		0x00000001
#define CS_CMD_CMD_STOP				0x00000002
#define CS_EN_SHIFT				0
#define CS_EN_CMD_ENABLE_BSC			0x00000001
#define TIM_OFFSET				0x00000024
#define TIM_PRESCALE_SHIFT			6
#define TIM_P_SHIFT				3
#define TIM_NO_DIV_SHIFT			2
#define TIM_DIV_SHIFT				0
#define DAT_OFFSET				0x00000028
#define TOUT_OFFSET				0x0000002c
#define TXFCR_OFFSET				0x0000003c
#define TXFCR_FIFO_FLUSH_MASK			0x00000080
#define TXFCR_FIFO_EN_MASK			0x00000040
#define IER_OFFSET				0x00000044
#define IER_READ_COMPLETE_INT_MASK		0x00000010
#define IER_I2C_INT_EN_MASK			0x00000008
#define IER_FIFO_INT_EN_MASK			0x00000002
#define IER_NOACK_EN_MASK			0x00000001
#define ISR_OFFSET				0x00000048
#define ISR_RESERVED_MASK			0xffffff60
#define ISR_CMDBUSY_MASK			0x00000080
#define ISR_READ_COMPLETE_MASK			0x00000010
#define ISR_SES_DONE_MASK			0x00000008
#define ISR_ERR_MASK				0x00000004
#define ISR_TXFIFOEMPTY_MASK			0x00000002
#define ISR_NOACK_MASK				0x00000001
#define CLKEN_OFFSET				0x0000004c
#define CLKEN_AUTOSENSE_OFF_MASK		0x00000080
#define CLKEN_M_SHIFT				4
#define CLKEN_N_SHIFT				1
#define CLKEN_CLKEN_MASK			0x00000001
#define FIFO_STATUS_OFFSET			0x00000054
#define FIFO_STATUS_RXFIFO_EMPTY_MASK		0x00000004
#define FIFO_STATUS_TXFIFO_EMPTY_MASK		0x00000010
#define HSTIM_OFFSET				0x00000058
#define HSTIM_HS_MODE_MASK			0x00008000
#define HSTIM_HS_HOLD_SHIFT			10
#define HSTIM_HS_HIGH_PHASE_SHIFT		5
#define HSTIM_HS_SETUP_SHIFT			0
#define PADCTL_OFFSET				0x0000005c
#define PADCTL_PAD_OUT_EN_MASK			0x00000004
#define RXFCR_OFFSET				0x00000068
#define RXFCR_NACK_EN_SHIFT			7
#define RXFCR_READ_COUNT_SHIFT			0
#define RXFIFORDOUT_OFFSET			0x0000006c
#define MAX_RX_FIFO_SIZE		64U	/* bytes */
#define MAX_TX_FIFO_SIZE		64U	/* bytes */
#define I2C_TIMEOUT			100000	/* usecs */
#define WAIT_INT_CHK			100	/* usecs */
#if I2C_TIMEOUT % WAIT_INT_CHK
#error I2C_TIMEOUT must be a multiple of WAIT_INT_CHK
#endif
#define DEF_SPD 100000
#define DEF_SPD_ENUM BCM_SPD_100K
#define DEF_DEVICE(num) \
#ifdef CONFIG_SYS_I2C_BASE0
#endif
#ifdef CONFIG_SYS_I2C_BASE1
#endif
#ifdef CONFIG_SYS_I2C_BASE2
#endif
#ifdef CONFIG_SYS_I2C_BASE3
#endif
#ifdef CONFIG_SYS_I2C_BASE4
#endif
#ifdef CONFIG_SYS_I2C_BASE5
#endif
#define I2C_M_TEN	0x0010	/* ten bit address */
#define I2C_M_RD	0x0001	/* read data */
#define I2C_M_NOSTART	0x4000	/* no restart between msgs */
#define DEF_ADAPTER(num) \
#ifdef CONFIG_SYS_I2C_BASE0
#endif
#ifdef CONFIG_SYS_I2C_BASE1
#endif
#ifdef CONFIG_SYS_I2C_BASE2
#endif
#ifdef CONFIG_SYS_I2C_BASE3
#endif
#ifdef CONFIG_SYS_I2C_BASE4
#endif
#ifdef CONFIG_SYS_I2C_BASE5
#endif
