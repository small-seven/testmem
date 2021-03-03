#include <config.h>
#include <common.h>
#include <dm.h>
#include <phy.h>
#include <u-boot/crc.h>
#include <malloc.h>
#include <asm/byteorder.h>
#include <fs.h>
#define AQUNTIA_10G_CTL		0x20
#define AQUNTIA_VENDOR_P1	0xc400
#define AQUNTIA_SPEED_LSB_MASK	0x2000
#define AQUNTIA_SPEED_MSB_MASK	0x40
#define AQUANTIA_SYSTEM_INTERFACE_SR     0xe812
#define  AQUANTIA_SYSTEM_INTERFACE_SR_READY	BIT(0)
#define AQUANTIA_VENDOR_PROVISIONING_REG 0xC441
#define AQUANTIA_FIRMWARE_ID		 0x20
#define AQUANTIA_RESERVED_STATUS	 0xc885
#define AQUANTIA_FIRMWARE_MAJOR_MASK	 0xff00
#define AQUANTIA_FIRMWARE_MINOR_MASK	 0xff
#define AQUANTIA_FIRMWARE_BUILD_MASK	 0xf0
#define AQUANTIA_USX_AUTONEG_CONTROL_ENA 0x0008
#define AQUANTIA_SI_IN_USE_MASK          0x0078
#define AQUANTIA_SI_USXGMII              0x0018
#define AQUANTIA_VND1_GLOBAL_SC			0x000
#define  AQUANTIA_VND1_GLOBAL_SC_LP		BIT(0xb)
#define GLOBAL_FIRMWARE_ID 0x20
#define GLOBAL_FAULT 0xc850
#define GLOBAL_RSTATUS_1 0xc885
#define GLOBAL_ALARM_1 0xcc00
#define SYSTEM_READY_BIT 0x40
#define GLOBAL_STANDARD_CONTROL 0x0
#define SOFT_RESET BIT(15)
#define LOW_POWER BIT(11)
#define MAILBOX_CONTROL 0x0200
#define MAILBOX_EXECUTE BIT(15)
#define MAILBOX_WRITE BIT(14)
#define MAILBOX_RESET_CRC BIT(12)
#define MAILBOX_BUSY BIT(8)
#define MAILBOX_CRC 0x0201
#define MAILBOX_ADDR_MSW 0x0202
#define MAILBOX_ADDR_LSW 0x0203
#define MAILBOX_DATA_MSW 0x0204
#define MAILBOX_DATA_LSW 0x0205
#define UP_CONTROL 0xc001
#define UP_RESET BIT(15)
#define UP_RUN_STALL_OVERRIDE BIT(6)
#define UP_RUN_STALL BIT(0)
#define AQUANTIA_PMA_RX_VENDOR_P1		0xe400
#define  AQUANTIA_PMA_RX_VENDOR_P1_MDI_MSK	GENMASK(1, 0)
#define  AQUANTIA_PMA_RX_VENDOR_P1_MDI_CFG	BIT(1)
#define  AQUANTIA_PMA_RX_VENDOR_P1_MDI_REV	BIT(0)
#define AQUANTIA_VND1_GSTART_RATE		0x31a
#define  AQUANTIA_VND1_GSTART_RATE_OFF		0
#define  AQUANTIA_VND1_GSTART_RATE_100M		1
#define  AQUANTIA_VND1_GSTART_RATE_1G		2
#define  AQUANTIA_VND1_GSTART_RATE_10G		3
#define  AQUANTIA_VND1_GSTART_RATE_2_5G		4
#define  AQUANTIA_VND1_GSTART_RATE_5G		5
#define AQUANTIA_VND1_GSYSCFG_BASE		0x31b
#define AQUANTIA_VND1_GSYSCFG_100M		0
#define AQUANTIA_VND1_GSYSCFG_1G		1
#define AQUANTIA_VND1_GSYSCFG_2_5G		2
#define AQUANTIA_VND1_GSYSCFG_5G		3
#define AQUANTIA_VND1_GSYSCFG_10G		4
#define AQUANTIA_VND1_SMBUS0			0xc485
#define AQUANTIA_VND1_SMBUS1			0xc495
#define DRAM_BASE_ADDR 0x3FFE0000
#define IRAM_BASE_ADDR 0x40000000
#define VERSION_STRING_SIZE 0x40
#define VERSION_STRING_OFFSET 0x0200
#define HEADER_OFFSET 0x300
#define AQUANTIA_NA		0
#define AQUANTIA_GEN1		1
#define AQUANTIA_GEN2		2
#define AQUANTIA_GEN3		3
#pragma pack(1)
#pragma pack()
#if defined(CONFIG_PHY_AQUANTIA_UPLOAD_FW)
#else
#endif
#ifdef CONFIG_DM_ETH
#endif