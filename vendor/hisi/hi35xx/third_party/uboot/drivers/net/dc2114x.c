#include <common.h>
#include <env.h>
#include <malloc.h>
#include <net.h>
#include <netdev.h>
#include <pci.h>
#undef DEBUG_SROM
#undef DEBUG_SROM2
#undef UPDATE_SROM
#define PCI_CFDA_PSM		0x43
#define CFRV_RN		0x000000f0	/* Revision Number */
#define WAKEUP		0x00		/* Power Saving Wakeup */
#define SLEEP		0x80		/* Power Saving Sleep Mode */
#define DC2114x_BRK	0x0020		/* CFRV break between DC21142 & DC21143 */
#define DE4X5_BMR	0x000		/* Bus Mode Register */
#define DE4X5_TPD	0x008		/* Transmit Poll Demand Reg */
#define DE4X5_RRBA	0x018		/* RX Ring Base Address Reg */
#define DE4X5_TRBA	0x020		/* TX Ring Base Address Reg */
#define DE4X5_STS	0x028		/* Status Register */
#define DE4X5_OMR	0x030		/* Operation Mode Register */
#define DE4X5_SICR	0x068		/* SIA Connectivity Register */
#define DE4X5_APROM	0x048		/* Ethernet Address PROM */
#define BMR_SWR		0x00000001	/* Software Reset */
#define STS_TS		0x00700000	/* Transmit Process State */
#define STS_RS		0x000e0000	/* Receive Process State */
#define OMR_ST		0x00002000	/* Start/Stop Transmission Command */
#define OMR_SR		0x00000002	/* Start/Stop Receive */
#define OMR_PS		0x00040000	/* Port Select */
#define OMR_SDP		0x02000000	/* SD Polarity - MUST BE ASSERTED */
#define OMR_PM		0x00000080	/* Pass All Multicast */
#define R_OWN		0x80000000	/* Own Bit */
#define RD_RER		0x02000000	/* Receive End Of Ring */
#define RD_LS		0x00000100	/* Last Descriptor */
#define RD_ES		0x00008000	/* Error Summary */
#define TD_TER		0x02000000	/* Transmit End Of Ring */
#define T_OWN		0x80000000	/* Own Bit */
#define TD_LS		0x40000000	/* Last Segment */
#define TD_FS		0x20000000	/* First Segment */
#define TD_ES		0x00008000	/* Error Summary */
#define TD_SET		0x08000000	/* Setup Packet */
#define SROM_WRITE_CMD	5
#define SROM_READ_CMD	6
#define SROM_ERASE_CMD	7
#define SROM_HWADD	    0x0014	/* Hardware Address offset in SROM */
#define SROM_RD		0x00004000	/* Read from Boot ROM */
#define EE_DATA_WRITE	      0x04	/* EEPROM chip data in. */
#define EE_WRITE_0	    0x4801
#define EE_WRITE_1	    0x4805
#define EE_DATA_READ	      0x08	/* EEPROM chip data out. */
#define SROM_SR		0x00000800	/* Select Serial ROM when set */
#define DT_IN		0x00000004	/* Serial Data In */
#define DT_CLK		0x00000002	/* Serial ROM Clock */
#define DT_CS		0x00000001	/* Serial ROM Chip Select */
#define POLL_DEMAND	1
#ifdef CONFIG_TULIP_FIX_DAVICOM
#define RESET_DM9102(dev) {\
#else
#define RESET_DE4X5(dev) {\
#endif
#define START_DE4X5(dev) {\
#define STOP_DE4X5(dev) {\
#define NUM_RX_DESC PKTBUFSRX
#ifndef CONFIG_TULIP_FIX_DAVICOM
#else
#endif
#define RX_BUFF_SZ  PKTSIZE_ALIGN
#define TOUT_LOOP   1000000
#define SETUP_FRAME_LEN 192
#if defined(UPDATE_SROM) || !defined(CONFIG_TULIP_FIX_DAVICOM)
#endif	/* UPDATE_SROM || !CONFIG_TULIP_FIX_DAVICOM */
#ifdef UPDATE_SROM
#endif
#ifndef CONFIG_TULIP_FIX_DAVICOM
#endif	/* CONFIG_TULIP_FIX_DAVICOM */
#ifdef CONFIG_TULIP_SELECT_MEDIA
#endif
#if defined(CONFIG_E500)
#define phys_to_bus(a) (a)
#else
#define phys_to_bus(a)	pci_phys_to_mem((pci_dev_t)dev->priv, a)
#endif
#ifdef CONFIG_TULIP_FIX_DAVICOM
#endif
#ifndef CONFIG_TULIP_FIX_DAVICOM
#endif
#ifdef CONFIG_TULIP_USE_IO
#else
#endif
#ifdef CONFIG_TULIP_USE_IO
#else
#endif
#ifdef CONFIG_TULIP_USE_IO
#else
#endif
#ifdef CONFIG_TULIP_FIX_DAVICOM
#else
#endif
#ifdef CONFIG_TULIP_USE_IO
#else
#endif
#ifndef CONFIG_TULIP_FIX_DAVICOM
#endif
#ifdef CONFIG_TULIP_FIX_DAVICOM
#else
#endif
#ifdef CONFIG_TULIP_SELECT_MEDIA
#else
#endif
#ifdef CONFIG_TULIP_FIX_DAVICOM
#else
#endif
#ifdef CONFIG_TULIP_FIX_DAVICOM
#else
#endif
#if 0 /* test-only */
#endif
#if defined(UPDATE_SROM) || !defined(CONFIG_TULIP_FIX_DAVICOM)
#ifdef DEBUG_SROM
#endif
#ifdef DEBUG_SROM2
#endif
#ifdef DEBUG_SROM2
#endif
#ifdef DEBUG_SROM2
#endif
#ifdef DEBUG_SROM2
#endif
#endif	/* UPDATE_SROM || !CONFIG_TULIP_FIX_DAVICOM */
#if defined(UPDATE_SROM) || !defined(CONFIG_TULIP_FIX_DAVICOM)
#ifdef DEBUG_SROM
#endif
#ifdef DEBUG_SROM2
#endif
#ifdef DEBUG_SROM
#endif
#endif	/* UPDATE_SROM || !CONFIG_TULIP_FIX_DAVICOM */
#ifndef CONFIG_TULIP_FIX_DAVICOM
#endif	/* CONFIG_TULIP_FIX_DAVICOM */
#ifdef UPDATE_SROM
#ifdef DEBUG_SROM
#endif
#ifdef DEBUG_SROM
#endif
#ifdef DEBUG_SROM
#endif
#endif
#ifndef CONFIG_TULIP_FIX_DAVICOM
#ifdef UPDATE_SROM
#endif
#endif	/* CONFIG_TULIP_FIX_DAVICOM */
#ifdef UPDATE_SROM
#endif	/* UPDATE_SROM */
