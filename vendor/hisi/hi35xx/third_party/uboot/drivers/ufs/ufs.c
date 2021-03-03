#include <charset.h>
#include <common.h>
#include <dm.h>
#include <dm/lists.h>
#include <dm/device-internal.h>
#include <malloc.h>
#include <hexdump.h>
#include <scsi.h>
#include <asm/dma-mapping.h>
#include "ufs.h"
#define UFSHCD_ENABLE_INTRS	(UTP_TRANSFER_REQ_COMPL |\
#define DME_LINKSTARTUP_RETRIES 3
#define UFS_UIC_COMMAND_RETRIES 3
#define QUERY_REQ_RETRIES 3
#define QUERY_REQ_TIMEOUT 1500 /* 1.5 seconds */
#define UFS_UIC_CMD_TIMEOUT	1000
#define NOP_OUT_RETRIES    10
#define NOP_OUT_TIMEOUT    30 /* msecs */
#define TASK_TAG	0
#define MASK_QUERY_UPIU_FLAG_LOC 0xFF
#define MAX_PRDT_ENTRY	262144
#define UFS_MAX_BYTES	(128 * 256 * 1024)
