#include <common.h>
#include <dm.h>
#include <i2c.h>
#include <pci.h>
#include <asm/io.h>
#define SMB_BASE		0x20
#define HOSTC			0x40
#define  HST_EN			(1 << 0)
#define SMB_RCV_SLVA		0x09
#define SMBHSTSTAT		0x0
#define SMBHSTCTL		0x2
#define SMBHSTCMD		0x3
#define SMBXMITADD		0x4
#define SMBHSTDAT0		0x5
#define SMBHSTDAT1		0x6
#define SMBBLKDAT		0x7
#define SMBTRNSADD		0x9
#define SMBSLVDATA		0xa
#define SMBAUXCTL		0xd
#define SMLINK_PIN_CTL		0xe
#define SMBUS_PIN_CTL		0xf
#define SMBHSTSTS_BYTE_DONE	0x80
#define SMBHSTSTS_INUSE_STS	0x40
#define SMBHSTSTS_SMBALERT_STS	0x20
#define SMBHSTSTS_FAILED	0x10
#define SMBHSTSTS_BUS_ERR	0x08
#define SMBHSTSTS_DEV_ERR	0x04
#define SMBHSTSTS_INTR		0x02
#define SMBHSTSTS_HOST_BUSY	0x01
#define SMBHSTCNT_INTREN	0x01
#define SMBHSTCNT_KILL		0x02
#define SMBHSTCNT_LAST_BYTE	0x20
#define SMBHSTCNT_START		0x40
#define SMBHSTCNT_PEC_EN	0x80	/* ICH3 and later */
#define SMBAUXCTL_CRC		1
#define SMBAUXCTL_E32B		2
#define SMBUS_TIMEOUT	100	/* 100 ms */
