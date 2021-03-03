#include <common.h>
#include <errno.h>
#include <asm/io.h>
#include <asm/arch/freeze_controller.h>
#include <asm/arch/scan_manager.h>
#include <asm/arch/system_manager.h>
#define SCANMGR_MAX_DELAY		100
#define TDI_TDO_MAX_PAYLOAD		127
#define SCANMGR_STAT_ACTIVE		(1 << 31)
#define SCANMGR_STAT_WFIFOCNT_MASK	0x70000000
#define JTAG_BP_INSN		(1 << 0)
#define JTAG_BP_TMS		(1 << 1)
#define JTAG_BP_PAYLOAD		(1 << 2)
#define JTAG_BP_2BYTE		(1 << 3)
#define JTAG_BP_4BYTE		(1 << 4)
