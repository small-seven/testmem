#include <config.h>
#include <phy.h>
#define ET1011C_CONFIG_REG		(0x16)
#define ET1011C_TX_FIFO_MASK		(0x3 << 12)
#define ET1011C_TX_FIFO_DEPTH_8		(0x0 << 12)
#define ET1011C_TX_FIFO_DEPTH_16	(0x1 << 12)
#define ET1011C_INTERFACE_MASK		(0x7 << 0)
#define ET1011C_GMII_INTERFACE		(0x2 << 0)
#define ET1011C_SYS_CLK_EN		(0x1 << 4)
#define ET1011C_TX_CLK_EN		(0x1 << 5)
#define ET1011C_STATUS_REG		(0x1A)
#define ET1011C_DUPLEX_STATUS		(0x1 << 7)
#define ET1011C_SPEED_MASK		(0x3 << 8)
#define ET1011C_SPEED_1000		(0x2 << 8)
#define ET1011C_SPEED_100		(0x1 << 8)
#define ET1011C_SPEED_10		(0x0 << 8)
#ifdef CONFIG_PHY_ET1011C_TX_CLK_FIX
#endif
