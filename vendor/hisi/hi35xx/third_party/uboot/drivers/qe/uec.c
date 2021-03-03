#include <common.h>
#include <net.h>
#include <malloc.h>
#include <linux/errno.h>
#include <asm/io.h>
#include <linux/immap_qe.h>
#include "uccf.h"
#include "uec.h"
#include "uec_phy.h"
#include "miiphy.h"
#include <fsl_qe.h>
#include <phy.h>
#ifndef CONFIG_UTBIPAR_INIT_TBIPA
#define CONFIG_UTBIPAR_INIT_TBIPA 0x1F
#endif
#ifdef CONFIG_UEC_ETH1
#endif
#ifdef CONFIG_UEC_ETH2
#endif
#ifdef CONFIG_UEC_ETH3
#endif
#ifdef CONFIG_UEC_ETH4
#endif
#ifdef CONFIG_UEC_ETH5
#endif
#ifdef CONFIG_UEC_ETH6
#endif
#ifdef CONFIG_UEC_ETH7
#endif
#ifdef CONFIG_UEC_ETH8
#endif
#define MAXCONTROLLERS	(8)
#if defined(CONFIG_ARCH_P1021) || defined(CONFIG_ARCH_P1025)
#endif
#if defined(CONFIG_ARCH_P1021) || defined(CONFIG_ARCH_P1025)
#endif
#if defined(CONFIG_MII) || defined(CONFIG_CMD_MII)
#endif
#ifndef CONFIG_eTSEC_MDIO_BUS
#else
#endif
#if defined(CONFIG_ARCH_P1021) || defined(CONFIG_ARCH_P1025)
#endif
#if defined(CONFIG_ARCH_P1021) || defined(CONFIG_ARCH_P1025)
#endif
#if defined(CONFIG_ARCH_P1021) || defined(CONFIG_ARCH_P1025)
#endif
#if (MAX_QE_RISC == 4)
#endif
#if defined(CONFIG_MII) || defined(CONFIG_CMD_MII)
#endif
