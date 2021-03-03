#include <common.h>
#include <asm/types.h>
#include <asm/io.h>
#include <fsl_dtsec.h>
#include <fsl_mdio.h>
#include <phy.h>
#include "fm.h"
#define RCTRL_INIT	(RCTRL_GRS | RCTRL_UPROM)
#define TCTRL_INIT	TCTRL_GTS
#define MACCFG1_INIT	MACCFG1_SOFT_RST
#define MACCFG2_INIT	(MACCFG2_PRE_LEN(0x7) | MACCFG2_LEN_CHECK | \
#define MAXFRM_MASK		0x00003fff
