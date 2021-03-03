#include <common.h>
#include <command.h>
#include <cache.h>
#include <dm.h>
#include <asm/io.h>
#include <dm/ofnode.h>
#define L2_ENABLE	0x1
#define IPREPETCH_OFF	3
#define DPREPETCH_OFF	5
#define IPREPETCH_MSK	(3 << IPREPETCH_OFF)
#define DPREPETCH_MSK	(3 << DPREPETCH_OFF)
#define TRAMOCTL_OFF	8
#define TRAMICTL_OFF	10
#define TRAMOCTL_MSK	(3 << TRAMOCTL_OFF)
#define TRAMICTL_MSK	BIT(TRAMICTL_OFF)
#define DRAMOCTL_OFF	11
#define DRAMICTL_OFF	13
#define DRAMOCTL_MSK	(3 << DRAMOCTL_OFF)
#define DRAMICTL_MSK	BIT(DRAMICTL_OFF)
#define CCTL_CMD_REG(base, hart)	((ulong)(base) + 0x40 + (hart) * 0x10)
#define L2_WBINVAL_ALL	0x12
#define CCTL_STATUS_MSK(hart)		(0xf << ((hart) * 4))
#define CCTL_STATUS_IDLE(hart)		(0 << ((hart) * 4))
#define CCTL_STATUS_PROCESS(hart)	(1 << ((hart) * 4))
#define CCTL_STATUS_ILLEGAL(hart)	(2 << ((hart) * 4))
