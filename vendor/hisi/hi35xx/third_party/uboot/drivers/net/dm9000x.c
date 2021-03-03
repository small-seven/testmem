#include <common.h>
#include <command.h>
#include <net.h>
#include <asm/io.h>
#include <dm9000.h>
#include "dm9000x.h"
#ifdef CONFIG_DM9000_DEBUG
#define DM9000_DBG(fmt,args...) printf(fmt, ##args)
#define DM9000_DMP_PACKET(func,packet,length)  \
#else
#define DM9000_DBG(fmt,args...)
#define DM9000_DMP_PACKET(func,packet,length)
#endif
typedef struct board_info {
	u32 runt_length_counter;	/* counter: RX length < 64byte */
	u32 long_length_counter;	/* counter: RX length > 1514byte */
	u32 reset_counter;	/* counter: RESET */
	u32 reset_tx_timeout;	/* RESET caused by TX Timeout */
	u32 reset_rx_status;	/* RESET caused by RX Statsus wrong */
	u16 tx_pkt_cnt;
	u16 queue_start_addr;
	u16 dbug_cnt;
	u8 phy_addr;
	u8 device_wait_reset;	/* device state */
	unsigned char srom[128];
	void (*outblk)(volatile void *data_ptr, int count);
	void (*inblk)(void *data_ptr, int count);
	void (*rx_status)(u16 *RxStatus, u16 *RxLen);
	struct eth_device netdev;
} board_info_t;
#ifndef CONFIG_DM9000_BYTE_SWAPPED
#define DM9000_outb(d,r) writeb(d, (volatile u8 *)(r))
#define DM9000_outw(d,r) writew(d, (volatile u16 *)(r))
#define DM9000_outl(d,r) writel(d, (volatile u32 *)(r))
#define DM9000_inb(r) readb((volatile u8 *)(r))
#define DM9000_inw(r) readw((volatile u16 *)(r))
#define DM9000_inl(r) readl((volatile u32 *)(r))
#else
#define DM9000_outb(d, r) __raw_writeb(d, r)
#define DM9000_outw(d, r) __raw_writew(d, r)
#define DM9000_outl(d, r) __raw_writel(d, r)
#define DM9000_inb(r) __raw_readb(r)
#define DM9000_inw(r) __raw_readw(r)
#define DM9000_inl(r) __raw_readl(r)
#endif
#ifdef CONFIG_DM9000_DEBUG
#endif
#if !defined(CONFIG_DM9000_NO_SROM)
#endif
#if !defined(CONFIG_DM9000_NO_SROM)
#endif
