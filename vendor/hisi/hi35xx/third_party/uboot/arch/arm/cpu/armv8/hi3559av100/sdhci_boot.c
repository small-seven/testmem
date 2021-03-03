#include <config.h>
#include <asm/arch/platform.h>
#include <compiler.h>
#define DELAY_US        1000
#define MMC_BLK_SZ      512
#define CP_STEP1_SIZE   0x8000
#define SDHCI_BUFFER            0x20
#define SDHCI_INT_STATUS        0x30
#define SDHCI_INT_DATA_AVAIL    0x00000020
#define SDHCI_INT_ERROR_MASK    0xFFFF8000
#define debug_printf(fmt, args...) ;
