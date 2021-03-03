#include <common.h>
#include <wait_bit.h>
#include <asm/io.h>
#include <asm/arch/mailbox_s10.h>
#include <asm/arch/system_manager.h>
#include <asm/secure.h>
#define MBOX_READL(reg)			\
#define MBOX_WRITEL(data, reg)		\
#define MBOX_READ_RESP_BUF(rout)	\
#define MBOX_WRITE_CMD_BUF(data, cin)	\
#ifdef CONFIG_CADENCE_QSPI
#endif /* CONFIG_CADENCE_QSPI */
