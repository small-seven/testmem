#include <common.h>
#include <command.h>
#include <asm/io.h>
#include <linux/compiler.h>
#include <linux/time.h>
#include <i2c.h>
#include "qixis.h"
#ifndef QIXIS_LBMAP_BRDCFG_REG
#define QIXIS_LBMAP_BRDCFG_REG 0x00
#endif
#ifndef QIXIS_RCFG_CTL_RECONFIG_IDLE
#define QIXIS_RCFG_CTL_RECONFIG_IDLE 0x20
#endif
#ifndef QIXIS_RCFG_CTL_RECONFIG_START
#define QIXIS_RCFG_CTL_RECONFIG_START 0x21
#endif
#ifdef CONFIG_SYS_I2C_FPGA_ADDR
#ifndef CONFIG_DM_I2C
#else
#endif
#ifndef CONFIG_DM_I2C
#else
#endif
#endif
#ifdef QIXIS_BASE
#endif
#ifdef QIXIS_RST_FORCE_MEM
#endif
#ifndef CONFIG_SPL_BUILD
#ifdef QIXIS_LBMAP_ALTBANK
#endif
#ifdef CONFIG_NXP_LSCH3_2
#else
#endif
#ifdef QIXIS_LBMAP_ALTBANK
#else
#endif
#ifdef QIXIS_LBMAP_NAND
#else
#endif
#ifdef QIXIS_LBMAP_SD
#ifdef NON_EXTENDED_DUTCFG
#else
#endif
#else
#endif
#ifdef QIXIS_LBMAP_IFC
#else
#endif
#ifdef QIXIS_LBMAP_EMMC
#else
#endif
#ifdef QIXIS_LBMAP_SD_QSPI
#else
#endif
#ifdef QIXIS_LBMAP_QSPI
#else
#endif
#endif
