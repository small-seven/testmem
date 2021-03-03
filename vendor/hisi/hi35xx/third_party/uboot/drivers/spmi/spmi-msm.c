#include <common.h>
#include <dm.h>
#include <errno.h>
#include <fdtdec.h>
#include <asm/io.h>
#include <spmi/spmi.h>
#define PMIC_ARB_VERSION		0x0000
#define PMIC_ARB_VERSION_V2_MIN		0x20010000
#define ARB_CHANNEL_OFFSET(n)		(0x4 * (n))
#define SPMI_CH_OFFSET(chnl)		((chnl) * 0x8000)
#define SPMI_REG_CMD0			0x0
#define SPMI_REG_CONFIG			0x4
#define SPMI_REG_STATUS			0x8
#define SPMI_REG_WDATA			0x10
#define SPMI_REG_RDATA			0x18
#define SPMI_CMD_OPCODE_SHIFT		27
#define SPMI_CMD_SLAVE_ID_SHIFT		20
#define SPMI_CMD_ADDR_SHIFT		12
#define SPMI_CMD_ADDR_OFFSET_SHIFT	4
#define SPMI_CMD_BYTE_CNT_SHIFT		0
#define SPMI_CMD_EXT_REG_WRITE_LONG	0x00
#define SPMI_CMD_EXT_REG_READ_LONG	0x01
#define SPMI_STATUS_DONE		0x1
#define SPMI_MAX_CHANNELS	128
#define SPMI_MAX_SLAVES		16
#define SPMI_MAX_PERIPH		256
