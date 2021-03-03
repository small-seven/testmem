#include <common.h>
#include <eeprom.h>
#include <env.h>
#include <init.h>
#include <asm/arch/clock.h>
#include <asm/ti-common/keystone_net.h>
#include <asm/arch/psc_defs.h>
#include <asm/arch/mmc_host_def.h>
#include <fdtdec.h>
#include <i2c.h>
#include <remoteproc.h>
#include "mux-k2g.h"
#include "../common/board_detect.h"
#define K2G_GP_AUDIO_CODEC_ADDRESS	0x1B
#if defined(CONFIG_MMC)
#endif
#if defined(CONFIG_MULTI_DTB_FIT)
#endif
#if defined(CONFIG_DTB_RESELECT)
#ifndef CONFIG_DM_I2C
#else
#endif
#endif
#ifdef CONFIG_BOARD_LATE_INIT
#if !defined(CONFIG_SPL_BUILD) && defined(CONFIG_TI_I2C_BOARD_DETECT)
#endif
#ifdef CONFIG_ENV_VARS_UBOOT_RUNTIME_CONFIG
#endif
#endif
#ifdef CONFIG_BOARD_EARLY_INIT_F
#endif
#ifdef CONFIG_SPL_BUILD
#endif
#ifdef CONFIG_TI_SECURE_DEVICE
#endif
