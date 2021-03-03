#include <common.h>
#include <malloc.h>
#include <net.h>
#include <netdev.h>
#include <asm/io.h>
#include <pci.h>
#include <miiphy.h>
#undef DEBUG
#define SCBStatus		0	/* Rx/Command Unit Status *Word* */
#define SCBIntAckByte		1	/* Rx/Command Unit STAT/ACK byte */
#define SCBCmd			2	/* Rx/Command Unit Command *Word* */
#define SCBIntrCtlByte		3	/* Rx/Command Unit Intr.Control Byte */
#define SCBPointer		4	/* General purpose pointer. */
#define SCBPort			8	/* Misc. commands and operands. */
#define SCBflash		12	/* Flash memory control. */
#define SCBeeprom		14	/* EEPROM memory control. */
#define SCBCtrlMDI		16	/* MDI interface control. */
#define SCBEarlyRx		20	/* Early receive byte count. */
#define SCBGenControl		28	/* 82559 General Control Register */
#define SCBGenStatus		29	/* 82559 General Status register */
#define SCB_STATUS_CX		0x8000	/* CU finished command (transmit) */
#define SCB_STATUS_FR		0x4000	/* frame received */
#define SCB_STATUS_CNA		0x2000	/* CU left active state */
#define SCB_STATUS_RNR		0x1000	/* receiver left ready state */
#define SCB_STATUS_MDI		0x0800	/* MDI read/write cycle done */
#define SCB_STATUS_SWI		0x0400	/* software generated interrupt */
#define SCB_STATUS_FCP		0x0100	/* flow control pause interrupt */
#define SCB_INTACK_MASK		0xFD00	/* all the above */
#define SCB_INTACK_TX		(SCB_STATUS_CX | SCB_STATUS_CNA)
#define SCB_INTACK_RX		(SCB_STATUS_FR | SCB_STATUS_RNR)
#define CU_NOP			0x0000
#define CU_START		0x0010
#define CU_RESUME		0x0020
#define CU_STATSADDR		0x0040	/* Load Dump Statistics ctrs addr */
#define CU_SHOWSTATS		0x0050	/* Dump statistics counters. */
#define CU_ADDR_LOAD		0x0060	/* Base address to add to CU commands */
#define CU_DUMPSTATS		0x0070	/* Dump then reset stats counters. */
#define RUC_NOP			0x0000
#define RUC_START		0x0001
#define RUC_RESUME		0x0002
#define RUC_ABORT		0x0004
#define RUC_ADDR_LOAD		0x0006	/* (seems not to clear on acceptance) */
#define RUC_RESUMENR		0x0007
#define CU_CMD_MASK		0x00f0
#define RU_CMD_MASK		0x0007
#define SCB_M			0x0100	/* 0 = enable interrupt, 1 = disable */
#define SCB_SWI			0x0200	/* 1 - cause device to interrupt */
#define CU_STATUS_MASK		0x00C0
#define RU_STATUS_MASK		0x003C
#define RU_STATUS_IDLE		(0<<2)
#define RU_STATUS_SUS		(1<<2)
#define RU_STATUS_NORES		(2<<2)
#define RU_STATUS_READY		(4<<2)
#define RU_STATUS_NO_RBDS_SUS	((1<<2)|(8<<2))
#define RU_STATUS_NO_RBDS_NORES ((2<<2)|(8<<2))
#define RU_STATUS_NO_RBDS_READY ((4<<2)|(8<<2))
#define I82559_RESET		0x00000000	/* Software reset */
#define I82559_SELFTEST		0x00000001	/* 82559 Selftest command */
#define I82559_SELECTIVE_RESET	0x00000002
#define I82559_DUMP		0x00000003
#define I82559_DUMP_WAKEUP	0x00000007
#define EE_SHIFT_CLK		0x01	/* EEPROM shift clock. */
#define EE_CS			0x02	/* EEPROM chip select. */
#define EE_DATA_WRITE		0x04	/* EEPROM chip data in. */
#define EE_WRITE_0		0x01
#define EE_WRITE_1		0x05
#define EE_DATA_READ		0x08	/* EEPROM chip data out. */
#define EE_ENB			(0x4800 | EE_CS)
#define EE_CMD_BITS		3
#define EE_DATA_BITS		16
#define EE_EWENB_CMD		(4 << addr_len)
#define EE_WRITE_CMD		(5 << addr_len)
#define EE_READ_CMD		(6 << addr_len)
#define EE_ERASE_CMD		(7 << addr_len)
#define RFD_STATUS_C		0x8000	/* completion of received frame */
#define RFD_STATUS_OK		0x2000	/* frame received with no errors */
#define RFD_CONTROL_EL		0x8000	/* 1=last RFD in RFA */
#define RFD_CONTROL_S		0x4000	/* 1=suspend RU after receiving frame */
#define RFD_CONTROL_H		0x0010	/* 1=RFD is a header RFD */
#define RFD_CONTROL_SF		0x0008	/* 0=simplified, 1=flexible mode */
#define RFD_COUNT_MASK		0x3fff
#define RFD_COUNT_F		0x4000
#define RFD_COUNT_EOF		0x8000
#define RFD_RX_CRC		0x0800	/* crc error */
#define RFD_RX_ALIGNMENT	0x0400	/* alignment error */
#define RFD_RX_RESOURCE		0x0200	/* out of space, no resources */
#define RFD_RX_DMA_OVER		0x0100	/* DMA overrun */
#define RFD_RX_SHORT		0x0080	/* short frame error */
#define RFD_RX_LENGTH		0x0020
#define RFD_RX_ERROR		0x0010	/* receive error */
#define RFD_RX_NO_ADR_MATCH	0x0004	/* no address match */
#define RFD_RX_IA_MATCH		0x0002	/* individual address does not match */
#define RFD_RX_TCO		0x0001	/* TCO indication */
#define TxCB_CMD_TRANSMIT	0x0004	/* transmit command */
#define TxCB_CMD_SF		0x0008	/* 0=simplified, 1=flexible mode */
#define TxCB_CMD_NC		0x0010	/* 0=CRC insert by controller */
#define TxCB_CMD_I		0x2000	/* generate interrupt on completion */
#define TxCB_CMD_S		0x4000	/* suspend on completion */
#define TxCB_CMD_EL		0x8000	/* last command block in CBL */
#define TxCB_COUNT_MASK		0x3fff
#define TxCB_COUNT_EOF		0x8000
#define CONFIG_SYS_CMD_EL		0x8000
#define CONFIG_SYS_CMD_SUSPEND		0x4000
#define CONFIG_SYS_CMD_INT		0x2000
#define CONFIG_SYS_CMD_IAS		0x0001	/* individual address setup */
#define CONFIG_SYS_CMD_CONFIGURE	0x0002	/* configure */
#define CONFIG_SYS_STATUS_C		0x8000
#define CONFIG_SYS_STATUS_OK		0x2000
#define NUM_RX_DESC		PKTBUFSRX
#define NUM_TX_DESC		1	/* Number of TX descriptors   */
#define TOUT_LOOP		1000000
#if defined(CONFIG_E500)
#define bus_to_phys(a) (a)
#define phys_to_bus(a) (a)
#else
#define bus_to_phys(a)	pci_mem_to_phys((pci_dev_t)dev->priv, a)
#define phys_to_bus(a)	pci_phys_to_mem((pci_dev_t)dev->priv, a)
#endif
#if defined(CONFIG_MII) || defined(CONFIG_CMD_MII)
#endif
#ifdef DEBUG
#endif
#if defined (CONFIG_MII) || defined(CONFIG_CMD_MII)
#endif
#ifdef CONFIG_EEPRO100_SROM_WRITE
#endif
#ifdef DEBUG
#endif
