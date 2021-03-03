#include <common.h>
#include <command.h>
#include <miiphy.h>
typedef struct _MII_field_desc_t {
	ushort hi;
	ushort lo;
	ushort mask;
	const char *name;
} MII_field_desc_t;
typedef struct _MII_reg_desc_t {
	ushort regno;
	const MII_field_desc_t *pdesc;
	ushort len;
	const char *name;
} MII_reg_desc_t;
#if defined(CONFIG_MII_INIT)
#endif
