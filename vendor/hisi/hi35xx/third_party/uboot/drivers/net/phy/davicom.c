#include <common.h>
#include <phy.h>
#define MIIM_DM9161_SCR                0x10
#define MIIM_DM9161_SCR_INIT   0x0610
#define MIIM_DM9161_SCSR       0x11
#define MIIM_DM9161_SCSR_100F  0x8000
#define MIIM_DM9161_SCSR_100H  0x4000
#define MIIM_DM9161_SCSR_10F   0x2000
#define MIIM_DM9161_SCSR_10H   0x1000
#define MIIM_DM9161_10BTCSR    0x12
#define MIIM_DM9161_10BTCSR_INIT       0x7800
