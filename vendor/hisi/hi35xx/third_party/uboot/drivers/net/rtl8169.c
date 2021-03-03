#include <common.h>
#include <cpu_func.h>
#include <dm.h>
#include <errno.h>
#include <malloc.h>
#include <memalign.h>
#include <net.h>
#ifndef CONFIG_DM_ETH
#include <netdev.h>
#endif
#include <asm/io.h>
#include <pci.h>
#undef DEBUG_RTL8169
#undef DEBUG_RTL8169_TX
#undef DEBUG_RTL8169_RX
#define drv_version "v1.5"
#define drv_date "01-17-2004"
#define currticks()	get_timer(0)
#define MAX_UNITS 8
#define MAC_ADDR_LEN	6
#define MAX_ETH_FRAME_SIZE	1536
#define TX_FIFO_THRESH 256	/* In bytes */
#define RX_FIFO_THRESH	7	/* 7 means NO threshold, Rx buffer level before first PCI xfer.	 */
#define RX_DMA_BURST	6	/* Maximum PCI burst, '6' is 1024 */
#define TX_DMA_BURST	6	/* Maximum PCI burst, '6' is 1024 */
#define EarlyTxThld	0x3F	/* 0x3F means NO early transmit */
#define RxPacketMaxSize 0x0800	/* Maximum size supported is 16K-1 */
#define InterFrameGap	0x03	/* 3 means InterFrameGap = the shortest one */
#define NUM_TX_DESC	1	/* Number of Tx descriptor registers */
#ifdef CONFIG_SYS_RX_ETH_BUFFER
#else
#endif
#define RX_BUF_SIZE	1536	/* Rx Buffer size */
#define RX_BUF_LEN	8192
#define RTL_MIN_IO_SIZE 0x80
#define TX_TIMEOUT  (6*HZ)
#define RTL_W8(reg, val8)	writeb((val8), ioaddr + (reg))
#define RTL_W16(reg, val16)	writew((val16), ioaddr + (reg))
#define RTL_W32(reg, val32)	writel((val32), ioaddr + (reg))
#define RTL_R8(reg)		readb(ioaddr + (reg))
#define RTL_R16(reg)		readw(ioaddr + (reg))
#define RTL_R32(reg)		readl(ioaddr + (reg))
#define bus_to_phys(a)	pci_mem_to_phys((pci_dev_t)(unsigned long)dev->priv, \
#define phys_to_bus(a)	pci_phys_to_mem((pci_dev_t)(unsigned long)dev->priv, \
#define RTL8169_DESC_SIZE 16
#if ARCH_DMA_MINALIGN > 256
#  define RTL8169_ALIGN ARCH_DMA_MINALIGN
#else
#  define RTL8169_ALIGN 256
#endif
#if RTL8169_DESC_SIZE < ARCH_DMA_MINALIGN
#if !defined(CONFIG_SYS_NONCACHED_MEMORY) && \
#warning cache-line size is larger than descriptor size
#endif
#endif
#ifdef DEBUG_RTL8169
#endif
#ifdef CONFIG_SYS_NONCACHED_MEMORY
#else
#endif
#ifndef CONFIG_SYS_NONCACHED_MEMORY
#endif
#ifndef CONFIG_SYS_NONCACHED_MEMORY
#endif
#ifndef CONFIG_SYS_NONCACHED_MEMORY
#endif
#ifndef CONFIG_SYS_NONCACHED_MEMORY
#endif
#ifdef CONFIG_DM_ETH
#else
#endif
#ifdef DEBUG_RTL8169_RX
#endif
#ifdef CONFIG_DM_ETH
#else
#endif
#ifdef CONFIG_DM_ETH
#else
#endif
#ifdef CONFIG_DM_ETH
#else
#endif /* nCONFIG_DM_ETH */
#define HZ 1000
#ifdef CONFIG_DM_ETH
#else
#endif
#ifdef DEBUG_RTL8169_TX
#endif
#ifdef CONFIG_DM_ETH
#else
#endif
#ifdef DEBUG_RTL8169_TX
#endif
#ifdef DEBUG_RTL8169_TX
#endif
#ifdef CONFIG_DM_ETH
#else
#endif
#ifdef DEBUG_RTL8169
#endif
#ifdef CONFIG_DM_ETH
#else
#endif
#ifdef DEBUG_RTL8169
#endif
#if 0
#endif
#ifdef CONFIG_DM_ETH
#else
#endif
#ifdef CONFIG_DM_ETH
#else
#endif
#ifdef DEBUG_RTL8169
#endif
#ifdef CONFIG_DM_ETH
#else
#endif
#ifdef DEBUG_RTL8169
#endif
#ifdef CONFIG_DM_ETH
#else
#endif
#ifdef DEBUG_RTL8169
#endif
#ifdef CONFIG_DM_ETH
#else
#endif
#ifdef DEBUG_RTL8169
#endif
#ifdef DEBUG_RTL8169
#endif
#ifdef CONFIG_DM_ETH
#else
#endif /* nCONFIG_DM_ETH */
#ifdef DEBUG_RTL8169
#endif
#ifdef CONFIG_DM_ETH
#else
#endif
#ifdef CONFIG_DM_ETH
#endif
#define board_found 1
#define valid_link 0
#ifdef DEBUG_RTL8169
#endif
#ifdef DEBUG_RTL8169
#endif
#ifdef DEBUG_RTL8169
#endif
#ifdef DEBUG_RTL8169
#endif
#ifdef DEBUG_RTL8169
#endif
#ifdef DEBUG_RTL8169
#endif
#ifdef DEBUG_RTL8169
#endif
#ifdef DEBUG_RTL8169
#endif
#ifndef CONFIG_DM_ETH
#endif
#ifdef CONFIG_DM_ETH
#endif
