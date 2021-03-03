#define MAXFRM_MASK	0x0000ffff
#include <common.h>
#include <phy.h>
#include <asm/types.h>
#include <asm/io.h>
#include <fsl_tgec.h>
#include "fm.h"
#define TGEC_CMD_CFG_INIT	(TGEC_CMD_CFG_NO_LEN_CHK | \
#define TGEC_CMD_CFG_FINAL	(TGEC_CMD_CFG_NO_LEN_CHK | \
