#include <common.h>
#include <net.h>
#include <malloc.h>
#include <miiphy.h>
#include <asm/io.h>
#include <linux/errno.h>
#include <asm/types.h>
#include <asm/system.h>
#include <asm/byteorder.h>
#include <asm/arch/cpu.h>
#include <asm/arch/config.h>
#define LPC32XX_ETH_RX_DESC_SIZE (sizeof(struct lpc32xx_eth_rxdesc))
#define LPC32XX_ETH_RX_CTRL_SIZE_MASK 0x000007FF
#define LPC32XX_ETH_RX_CTRL_UNUSED    0x7FFFF800
#define LPC32XX_ETH_RX_CTRL_INTERRUPT 0x80000000
#define LPC32XX_ETH_RX_STAT_SIZE (sizeof(struct lpc32xx_eth_rxstat))
#define RX_STAT_RXSIZE 0x000007FF
#define RX_STAT_ERRORS 0x1B800000
#define LPC32XX_ETH_TX_DESC_SIZE (sizeof(struct lpc32xx_eth_txdesc))
#define TX_CTRL_TXSIZE    0x000007FF
#define TX_CTRL_LAST      0x40000000
#define LPC32XX_ETH_TX_STAT_SIZE (sizeof(struct lpc32xx_eth_txstat))
#define MAC1_RECV_ENABLE        0x00000001
#define MAC1_PASS_ALL_RX_FRAMES 0x00000002
#define MAC1_SOFT_RESET         0x00008000
#define MAC1_RESETS             0x0000CF00
#define MAC2_FULL_DUPLEX    0x00000001
#define MAC2_CRC_ENABLE     0x00000010
#define MAC2_PAD_CRC_ENABLE 0x00000020
#define SUPP_SPEED 0x00000100
#define MCFG_RESET_MII_MGMT     0x00008000
#define MCFG_CLOCK_SELECT_DIV28 0x0000001C
#define MADR_REG_MASK   0x0000001F
#define MADR_PHY_MASK   0x00001F00
#define MADR_REG_OFFSET 0
#define MADR_PHY_OFFSET 8
#define MIND_BUSY      0x00000001
#define COMMAND_RXENABLE      0x00000001
#define COMMAND_TXENABLE      0x00000002
#define COMMAND_PASSRUNTFRAME 0x00000040
#define COMMAND_RMII          0x00000200
#define COMMAND_FULL_DUPLEX   0x00000400
#define COMMAND_RESETS        0x00000038
#define STATUS_RXSTATUS 0x00000001
#define STATUS_TXSTATUS 0x00000002
#define RXFILTERCTRL_ACCEPTBROADCAST 0x00000002
#define RXFILTERCTRL_ACCEPTPERFECT   0x00000020
#define ATTRS(n) __aligned(n)
#define TX_BUF_COUNT 4
#define RX_BUF_COUNT 4
#define LPC32XX_ETH_DEVICE_SIZE (sizeof(struct lpc32xx_eth_device))
#define to_lpc32xx_eth(_d) container_of(_d, struct lpc32xx_eth_device, dev)
#define MII_TIMEOUT 10000000
#define MII_MAX_REG (MADR_REG_MASK >> MADR_REG_OFFSET)
#define MII_MAX_PHY (MADR_PHY_MASK >> MADR_PHY_OFFSET)
#if defined(CONFIG_PHYLIB) || defined(CONFIG_MII) || defined(CONFIG_CMD_MII)
#endif
#if !defined(CONFIG_LPC32XX_ETH_BUFS_BASE)
#define CONFIG_LPC32XX_ETH_BUFS_BASE 0x00001000
#endif
#if defined(CONFIG_RMII)
#endif
#define TX_TIMEOUT 10000
#define RX_TIMEOUT 1000000
#if defined(CONFIG_PHYLIB)
#endif
#if defined(CONFIG_PHYLIB)
#elif defined(CONFIG_MII) || defined(CONFIG_CMD_MII)
#endif
