#include <common.h>
#include <dm.h>
#include <i2c.h>
#include <asm/arch/clk.h>
#include <asm/arch/cpu.h>
#include <asm/arch/pinmux.h>
#include "s3c24x0_i2c.h"
#define HSI2C_FUNC_MODE_I2C		(1u << 0)
#define HSI2C_MASTER			(1u << 3)
#define HSI2C_RXCHON			(1u << 6)	/* Write/Send */
#define HSI2C_TXCHON			(1u << 7)	/* Read/Receive */
#define HSI2C_SW_RST			(1u << 31)
#define HSI2C_RXFIFO_EN			(1u << 0)
#define HSI2C_TXFIFO_EN			(1u << 1)
#define HSI2C_TXFIFO_TRIGGER_LEVEL	(0x20 << 16)
#define HSI2C_RXFIFO_TRIGGER_LEVEL	(0x20 << 4)
#define HSI2C_TRAILING_COUNT		(0xff)
#define HSI2C_TX_UNDERRUN_EN		(1u << 2)
#define HSI2C_TX_OVERRUN_EN		(1u << 3)
#define HSI2C_RX_UNDERRUN_EN		(1u << 4)
#define HSI2C_RX_OVERRUN_EN		(1u << 5)
#define HSI2C_INT_TRAILING_EN		(1u << 6)
#define HSI2C_INT_I2C_EN		(1u << 9)
#define HSI2C_INT_ERROR_MASK	(HSI2C_TX_UNDERRUN_EN |\
#define HSI2C_AUTO_MODE			(1u << 31)
#define HSI2C_10BIT_ADDR_MODE		(1u << 30)
#define HSI2C_HS_MODE			(1u << 29)
#define HSI2C_READ_WRITE		(1u << 16)
#define HSI2C_STOP_AFTER_TRANS		(1u << 17)
#define HSI2C_MASTER_RUN		(1u << 31)
#define HSI2C_TIMEOUT_EN		(1u << 31)
#define HSI2C_MASTER_BUSY		(1u << 17)
#define HSI2C_SLAVE_BUSY		(1u << 16)
#define HSI2C_TIMEOUT_AUTO		(1u << 4)
#define HSI2C_NO_DEV			(1u << 3)
#define HSI2C_NO_DEV_ACK		(1u << 2)
#define HSI2C_TRANS_ABORT		(1u << 1)
#define HSI2C_TRANS_SUCCESS		(1u << 0)
#define HSI2C_TRANS_ERROR_MASK	(HSI2C_TIMEOUT_AUTO |\
#define HSI2C_TRANS_FINISHED_MASK (HSI2C_TRANS_ERROR_MASK | HSI2C_TRANS_SUCCESS)
#define HSI2C_RX_FIFO_EMPTY		(1u << 24)
#define HSI2C_RX_FIFO_FULL		(1u << 23)
#define HSI2C_TX_FIFO_EMPTY		(1u << 8)
#define HSI2C_TX_FIFO_FULL		(1u << 7)
#define HSI2C_RX_FIFO_LEVEL(x)		(((x) >> 16) & 0x7f)
#define HSI2C_TX_FIFO_LEVEL(x)		((x) & 0x7f)
#define HSI2C_SLV_ADDR_MAS(x)		((x & 0x3ff) << 10)
#define HSI2C_TIMEOUT_US 10000 /* 10 ms, finer granularity */
#if (defined CONFIG_EXYNOS4 || defined CONFIG_EXYNOS5)
#else
#endif
