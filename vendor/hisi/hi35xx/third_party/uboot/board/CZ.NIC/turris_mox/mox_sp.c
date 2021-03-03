#include <common.h>
#include <asm/io.h>
#define RWTM_CMD_PARAM(i)	(size_t)(0xd00b0000 + (i) * 4)
#define RWTM_CMD		0xd00b0040
#define RWTM_CMD_RETSTATUS	0xd00b0080
#define RWTM_CMD_STATUS(i)	(size_t)(0xd00b0084 + (i) * 4)
#define RWTM_HOST_INT_RESET	0xd00b00c8
#define RWTM_HOST_INT_MASK	0xd00b00cc
#define SP_CMD_COMPLETE		BIT(0)
#define MBOX_STS_SUCCESS		(0x0 << 30)
#define MBOX_STS_FAIL			(0x1 << 30)
#define MBOX_STS_BADCMD			(0x2 << 30)
#define MBOX_STS_LATER			(0x3 << 30)
#define MBOX_STS_ERROR(s)		((s) & (3 << 30))
#define MBOX_STS_VALUE(s)		(((s) >> 10) & 0xfffff)
#define MBOX_STS_CMD(s)			((s) & 0x3ff)
