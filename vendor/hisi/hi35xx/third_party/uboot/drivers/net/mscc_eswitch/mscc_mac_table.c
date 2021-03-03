#include <linux/io.h>
#include "mscc_mac_table.h"
#define ANA_TABLES_MACACCESS_VALID		BIT(11)
#define ANA_TABLES_MACACCESS_ENTRYTYPE(x)	((x) << 9)
#define ANA_TABLES_MACACCESS_DEST_IDX(x)	((x) << 3)
#define ANA_TABLES_MACACCESS_MAC_TABLE_CMD(x)	(x)
#define ANA_TABLES_MACACCESS_MAC_TABLE_CMD_M	GENMASK(2, 0)
#define MACACCESS_CMD_IDLE			0
#define MACACCESS_CMD_LEARN			1
