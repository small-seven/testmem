#include <common.h>
#include <command.h>
#include "ddr_interface.h"
#ifndef TEXT_BASE
#define TEXT_BASE (CONFIG_SYS_TEXT_BASE) /* for arm64 u-boot-2016.11 */
#endif
#define DDR_TRAINING_ENV            "ddrtr"
#define DDR_TRAINING_ENV_UN         "unddrtr"
#define DDR_TRAINING_DDRT_START_OFFSET  0x400000  /* 4M */
#define DDR_TRAINING_DDRT_LENGTH  0x400000  /* 4M  at lease 0x8000 */
#define DDR_CMD_SW_STR              "training"
#define DDR_CMD_TR_STR              "tr"
#define DDR_CMD_HW_STR              "hw"
#define DDR_CMD_MPR_STR             "mpr"
#define DDR_CMD_WL_STR              "wl"
#define DDR_CMD_GATE_STR            "gate"
#define DDR_CMD_DATAEYE_STR         "dataeye"
#define DDR_CMD_VREF_STR            "vref"
#define DDR_CMD_DCC_STR             "dcc"
#define DDR_CMD_PCODE_STR           "pcode"
#define DDR_CMD_AC_STR              "ac"
#define DDR_CMD_LPCA_STR            "lpca"
#define DDR_CMD_LOG_STR             "log"
#define DDR_CMD_BOOT_STR            "boot"
#define DDR_CMD_CONSOLE_STR         "console"
#ifndef CONFIG_MINI_BOOT
#endif
#ifdef CONFIG_DDR_TRAINING_BOOTENV
#endif
#ifdef DDR_TRAINING_EXEC_TIME
#endif
#ifndef CONFIG_MINI_BOOT
#ifdef DDR_TRAINING_EXEC_TIME
#endif
#ifdef DDR_TRAINING_EXEC_TIME
#endif
#endif
