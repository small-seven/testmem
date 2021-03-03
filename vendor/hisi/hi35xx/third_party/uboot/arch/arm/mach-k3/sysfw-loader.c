#include <common.h>
#include <spl.h>
#include <malloc.h>
#include <remoteproc.h>
#include <linux/soc/ti/ti_sci_protocol.h>
#include <asm/arch/sys_proto.h>
#include "common.h"
#define SYSFW_FIRMWARE			"sysfw.bin"
#define SYSFW_CFG_BOARD			"board-cfg.bin"
#define SYSFW_CFG_PM			"pm-cfg.bin"
#define SYSFW_CFG_RM			"rm-cfg.bin"
#define SYSFW_CFG_SEC			"sec-cfg.bin"
#if CONFIG_IS_ENABLED(MMC_SUPPORT)
#ifdef CONFIG_K3_SYSFW_IMAGE_NAME
#else
#endif
#ifdef CONFIG_K3_SYSFW_IMAGE_MMCSD_RAW_MODE_PART
#else
#endif
#ifdef CONFIG_K3_SYSFW_IMAGE_MMCSD_RAW_MODE_SECT
#else
#endif
#endif
#if CONFIG_IS_ENABLED(YMODEM_SUPPORT)
#ifdef CONFIG_K3_EARLY_CONS
#endif
#endif
