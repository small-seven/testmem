#include <common.h>
#include "../common/common.h"
#include "kmp204x.h"
#define DIRECT_OFF		0x18
#define GPRT_OFF		0x1c
#define WDMASK_OFF	0x16
#define PRST_OFF	0x1a
#define PRSTCFG_OFF	0x1c
#define CTRLH_OFF		0x02
#define CTRLH_WRL_BOOT		0x01
#define CTRLH_WRL_UNITRUN	0x02
#define CTRLL_OFF		0x03
#define CTRLL_WRB_BUFENA	0x20
#define REASON1_OFF	0x12
#define REASON1_CPUWD	0x01
#define RSTCFG_OFF	0x11
