#include <linux/io.h>
#include "mscc_xfer.h"
#define QS_XTR_FLUSH_FLUSH		GENMASK(1, 0)
#define QS_INJ_CTRL_GAP_SIZE(x)		((x) << 21)
#define QS_INJ_CTRL_EOF			BIT(19)
#define QS_INJ_CTRL_SOF			BIT(18)
#define QS_INJ_CTRL_VLD_BYTES(x)	((x) << 16)
#define XTR_EOF_0     ntohl(0x80000000u)
#define XTR_EOF_1     ntohl(0x80000001u)
#define XTR_EOF_2     ntohl(0x80000002u)
#define XTR_EOF_3     ntohl(0x80000003u)
#define XTR_PRUNED    ntohl(0x80000004u)
#define XTR_ABORT     ntohl(0x80000005u)
#define XTR_ESCAPE    ntohl(0x80000006u)
#define XTR_NOT_READY ntohl(0x80000007u)
#define BUF_CELL_SZ		60
#define XTR_VALID_BYTES(x)	(4 - ((x) & 3))
