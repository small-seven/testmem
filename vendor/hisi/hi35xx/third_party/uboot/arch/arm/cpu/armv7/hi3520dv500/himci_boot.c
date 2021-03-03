#include <config.h>
#include <asm/arch/platform.h>
#include <compiler.h>
#ifndef CONFIG_ASIC
#define DELAY_US        10
#else
#define DELAY_US        1000
#endif
#define MMC_BLK_SZ	512
#define CP_STEP1_SIZE	0x7800
#define SDHCI_DMA_ADDRESS       0x00
#define SDHCI_BLOCK_SIZE        0x04
#define SDHCI_BLOCK_COUNT       0x06
#define SDHCI_ARGUMENT          0x08
#define SDHCI_TRANSFER_MODE     0x0C
#define  SDHCI_TRNS_DMA         0x0001
#define  SDHCI_TRNS_BLK_CNT_EN  0x0002
#define  SDHCI_TRNS_READ        0x0010
#define  SDHCI_TRNS_MULTI       0x0020
#define SDHCI_COMMAND           0x0E
#define  SDHCI_CMD_RESP_NONE    0x0000
#define  SDHCI_CMD_RESP_LONG    0x0001
#define  SDHCI_CMD_RESP_SHORT   0x0002
#define  SDHCI_CMD_CRC          0x0008
#define  SDHCI_CMD_DATA         0x0020
#define SDHCI_RESPONSE          0x10
#define SDHCI_BUFFER            0x20
#define SDHCI_PRESENT_STATE     0x24
#define  SDHCI_PSTATE_DAT_0     0x00100000
#define SDHCI_HOST_CONTROL      0x28
#define  SDHCI_CTRL_4BITBUS     0x02
#define  SDHCI_CTRL_8BITBUS     0x20
#define SDHCI_POWER_CONTROL     0x29
#define  SDHCI_POWER_ON         0x01
#define  SDHCI_POWER_180        0x0A
#define  SDHCI_POWER_300        0x0C
#define  SDHCI_POWER_330        0x0E
#define SDHCI_CLOCK_CONTROL     0x2C
#define  SDHCI_CLOCK_INT_EN     0x0001
#define  SDHCI_CLOCK_INT_STABLE 0x0002
#define  SDHCI_CLOCK_CARD_EN    0x0004
#define SDHCI_TIMEOUT_CONTROL   0x2E
#define SDHCI_SOFTWARE_RESET    0x2F
#define  SDHCI_RESET_ALL        0x01
#define  SDHCI_RESET_CMD        0x02
#define  SDHCI_RESET_DATA       0x04
#define SDHCI_INT_STATUS        0x30
#define  SDHCI_INT_RESPONSE     0x00000001
#define  SDHCI_INT_DATA_END     0x00000002
#define  SDHCI_INT_DMA          0x00000008
#define  SDHCI_INT_DATA_AVAIL   0x00000020
#define  SDHCI_INT_NORMAL_MASK  0x00007FFF
#define  SDHCI_INT_ERROR_MASK   0xFFFF8000
#define SDHCI_INT_ENABLE        0x34
#define SDHCI_EMMC_CTRL         0x52C
#define  SDHCI_CARD_IS_EMMC     0x0001
#define SDHCI_BOOT_CTRL         0x52E
#define  MAN_BOOT_EN            0x0001
#define  VALIDATE_BOOT          0x0080
#define SDHCI_EMMC_HW_RESET     0x534
#define sdhci_make_cmd(idx, param)   ((((idx) & 0xFF) << 8) | ((param) & 0xFF))
#define sdhci_make_blksz(dma, blksz) ((((dma) & 0x7) << 12) | ((blksz) & 0xFFF))
#define MMC_CMD_GO_IDLE_STATE       0
#define MMC_CMD_SEND_OP_COND        1
#define MMC_CMD_ALL_SEND_CID        2
#define MMC_CMD_SET_RELATIVE_ADDR   3
#define MMC_CMD_SWITCH              6
#define MMC_CMD_SELECT_CARD         7
#define MMC_CMD_SEND_CSD            9
#define MMC_CMD_STOP_TRANSMISSION   12
#define MMC_CMD_SET_BLOCKLEN        16
#define MMC_CMD_READ_SINGLE_BLOCK   17
#define MMC_CMD_READ_MULTIPLE_BLOCK 18
#define MMC_CMD_SET_BLOCK_COUNT     23
#define MMC_SWITCH_MODE_WRITE_BYTE  0x3
#define MMC_SWITCH_ACCESS_SHIFT     24
#define MMC_SWITCH_INDEX_SHIFT      16
#define MMC_SWITCH_VALUE_SHIFT      8
#define BOUNDARY_SIZE               (512 * 1024) /* 512K */
#define BOUNDARY_ARG                (0x7 << 12)  /* 512K */
#define MMC_SDMA_ENABLE	            1
#define OCR_BUSY                    0x80000000
#define OCR_HCS                     0x40000000
#define debug_printf(fmt, args...) ;
#define reg_get(addr) (*(volatile unsigned int *)((uintptr_t)(addr)))
