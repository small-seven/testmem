#include <config.h>
#include <asm/arch/platform.h>
#include <compiler.h>
#ifndef CONFIG_ASIC
#define DELAY_US        10
#else
#define DELAY_US        1000
#endif
#define MMC_BLK_SZ      512
#define MMC_CMD_GO_IDLE_STATE       0
#define MMC_CMD_SEND_OP_COND        1
#define MMC_CMD_ALL_SEND_CID        2
#define MMC_CMD_SET_RELATIVE_ADDR   3
#define MMC_CMD_SET_DSR         4
#define MMC_CMD_SWITCH          6
#define MMC_CMD_SELECT_CARD     7
#define MMC_CMD_SEND_EXT_CSD        8
#define MMC_CMD_SEND_CSD        9
#define MMC_CMD_SEND_CID        10
#define MMC_CMD_STOP_TRANSMISSION   12
#define MMC_CMD_SEND_STATUS     13
#define MMC_CMD_SET_BLOCKLEN        16
#define MMC_CMD_READ_SINGLE_BLOCK   17
#define MMC_CMD_READ_MULTIPLE_BLOCK 18
#define MMC_CMD_WRITE_SINGLE_BLOCK  24
#define MMC_CMD_WRITE_MULTIPLE_BLOCK    25
#define MMC_CMD_APP_CMD         55
#define SD_CMD_SEND_IF_COND     8
#define SD_CMD_APP_SEND_OP_COND     41
#define SD_CMD_APP_SET_BUS_WIDTH    6
#define OCR_BUSY        0x80000000
#define OCR_HCS         0x40000000
#define MMC_VDD_32_33       0x00100000  /* VDD voltage 3.2 ~ 3.3 */
#define MMC_VDD_33_34       0x00200000  /* VDD voltage 3.3 ~ 3.4 */
#define MMC_SWITCH_MODE_WRITE_BYTE  0x03 /* Set target byte to value */
#define EXT_CSD_BUS_WIDTH   183 /* R/W */
#define EXT_CSD_HS_TIMING   185 /* R/W */
#define EXT_CSD_BUS_WIDTH_1 0   /* Card is in 1 bit mode */
#define EXT_CSD_BUS_WIDTH_4 1   /* Card is in 4 bit mode */
#define EXT_CSD_BUS_WIDTH_8 2   /* Card is in 8 bit mode */
#ifdef CONFIG_SDHCI
#define SDHCI_BUFFER            0x20
#define SDHCI_INT_STATUS        0x30
#define SDHCI_INT_DATA_AVAIL    0x00000020
#define SDHCI_INT_ERROR_MASK    0xFFFF8000
#define debug_printf(fmt, args...) ;
#define CP_STEP1_SIZE 0x8000
#endif
