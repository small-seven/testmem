#include <common.h>
#include <i2c.h>
#include <spl.h>
#include <asm/io.h>
#include <asm/arch/cpu.h>
#include <asm/arch/soc.h>
#include "high_speed_env_spec.h"
#include "board_env_spec.h"
#define	SERDES_VERSION	"2.1.5"
#define ENDED_OK	"High speed PHY - Ended Successfully\n"
#define MV_BOARD_PEX_MODULE_ADDR		0x23
#define MV_BOARD_PEX_MODULE_ID			1
#define MV_BOARD_ETM_MODULE_ID			2
#define	PEX_MODULE_DETECT		1
#define	ETM_MODULE_DETECT               2
#define PEX_MODE_GET(satr)		((satr & 0x6) >> 1)
#define PEX_CAPABILITY_GET(satr, port)	((satr >> port) & 1)
#define MV_PEX_UNIT_TO_IF(pex_unit)	((pex_unit < 3) ? (pex_unit * 4) : 9)
#if defined(CONFIG_DB_88F78X60)
#elif defined(CONFIG_RD_88F78460_SERVER)
#elif defined(CONFIG_RD_78460_SERVER_REV2)
#elif defined(CONFIG_DB_78X60_PCAC)
#elif defined(CONFIG_DB_88F78X60_REV2)
#elif defined(CONFIG_RD_78460_NAS)
#elif defined(CONFIG_DB_78X60_AMC)
#elif defined(CONFIG_DB_78X60_PCAC_REV2)
#elif defined(CONFIG_DB_784MP_GP)
#elif defined(CONFIG_RD_78460_CUSTOMER)
#else
#endif
#if defined(CONFIG_MV78230)
#elif defined(CONFIG_MV78260)
#else
#endif
#ifdef ERRATA_GL_6572255
#endif
