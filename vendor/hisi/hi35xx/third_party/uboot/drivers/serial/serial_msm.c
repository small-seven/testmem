#include <common.h>
#include <clk.h>
#include <dm.h>
#include <errno.h>
#include <serial.h>
#include <watchdog.h>
#include <asm/io.h>
#include <linux/compiler.h>
#include <dm/pinctrl.h>
#define UARTDM_DMRX             0x34 /* Max RX transfer length */
#define UARTDM_NCF_TX           0x40 /* Number of chars to TX */
#define UARTDM_RXFS             0x50 /* RX channel status register */
#define UARTDM_RXFS_BUF_SHIFT   0x7  /* Number of bytes in the packing buffer */
#define UARTDM_RXFS_BUF_MASK    0x7
#define UARTDM_MR1				 0x00
#define UARTDM_MR2				 0x04
#define UARTDM_CSR				 0xA0
#define UARTDM_SR                0xA4 /* Status register */
#define UARTDM_SR_RX_READY       (1 << 0) /* Word is the receiver FIFO */
#define UARTDM_SR_TX_EMPTY       (1 << 3) /* Transmitter underrun */
#define UARTDM_SR_UART_OVERRUN   (1 << 4) /* Receive overrun */
#define UARTDM_CR                         0xA8 /* Command register */
#define UARTDM_CR_CMD_RESET_ERR           (3 << 4) /* Clear overrun error */
#define UARTDM_CR_CMD_RESET_STALE_INT     (8 << 4) /* Clears stale irq */
#define UARTDM_CR_CMD_RESET_TX_READY      (3 << 8) /* Clears TX Ready irq*/
#define UARTDM_CR_CMD_FORCE_STALE         (4 << 8) /* Causes stale event */
#define UARTDM_CR_CMD_STALE_EVENT_DISABLE (6 << 8) /* Disable stale event */
#define UARTDM_IMR                0xB0 /* Interrupt mask register */
#define UARTDM_ISR                0xB4 /* Interrupt status register */
#define UARTDM_ISR_TX_READY       0x80 /* TX FIFO empty */
#define UARTDM_TF               0x100 /* UART Transmit FIFO register */
#define UARTDM_RF               0x140 /* UART Receive FIFO register */
#define UART_DM_CLK_RX_TX_BIT_RATE 0xCC
#define MSM_BOOT_UART_DM_8_N_1_MODE 0x34
#define MSM_BOOT_UART_DM_CMD_RESET_RX 0x10
#define MSM_BOOT_UART_DM_CMD_RESET_TX 0x20
