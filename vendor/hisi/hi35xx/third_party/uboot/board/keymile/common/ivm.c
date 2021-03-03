#include <common.h>
#include <cli_hush.h>
#include <env.h>
#include <i2c.h>
#include "common.h"
#define MAC_STR_SZ	20
#define INV_BLOCKSIZE		0x100
#define INV_DATAADDRESS		0x21
#define INVENTORYDATASIZE	(INV_BLOCKSIZE - INV_DATAADDRESS - 3)
#define IVM_POS_SHORT_TEXT		0
#define IVM_POS_MANU_ID			1
#define IVM_POS_MANU_SERIAL		2
#define IVM_POS_PART_NUMBER		3
#define IVM_POS_BUILD_STATE		4
#define IVM_POS_SUPPLIER_PART_NUMBER	5
#define IVM_POS_DELIVERY_DATE		6
#define IVM_POS_SUPPLIER_BUILD_STATE	7
#define IVM_POS_CUSTOMER_ID		8
#define IVM_POS_CUSTOMER_PROD_ID	9
#define IVM_POS_HISTORY			10
#define IVM_POS_SYMBOL_ONLY		11
#define GET_STRING(name, which, len) \
#ifndef CONFIG_KMTEGR1
#else
#endif
