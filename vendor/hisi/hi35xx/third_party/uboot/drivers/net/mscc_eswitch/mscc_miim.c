#include <miiphy.h>
#include <wait_bit.h>
#include "mscc_miim.h"
#define MIIM_STATUS			0x0
#define		MIIM_STAT_BUSY			BIT(3)
#define MIIM_CMD			0x8
#define		MIIM_CMD_SCAN		BIT(0)
#define		MIIM_CMD_OPR_WRITE	BIT(1)
#define		MIIM_CMD_OPR_READ	BIT(2)
#define		MIIM_CMD_SINGLE_SCAN	BIT(3)
#define		MIIM_CMD_WRDATA(x)	((x) << 4)
#define		MIIM_CMD_REGAD(x)	((x) << 20)
#define		MIIM_CMD_PHYAD(x)	((x) << 25)
#define		MIIM_CMD_VLD		BIT(31)
#define MIIM_DATA			0xC
#define		MIIM_DATA_ERROR		(0x2 << 16)
