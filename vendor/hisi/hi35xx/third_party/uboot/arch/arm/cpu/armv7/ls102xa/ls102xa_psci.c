#include <config.h>
#include <cpu_func.h>
#include <asm/io.h>
#include <asm/psci.h>
#include <asm/arch/immap_ls102xa.h>
#include <fsl_immap.h>
#include "fsl_epu.h"
#define __secure __attribute__((section("._secure.text")))
#define CCSR_GICD_CTLR			0x1000
#define CCSR_GICC_CTLR			0x2000
#define DCSR_RCPM_CG1CR0		0x31c
#define DCSR_RCPM_CSTTACR0		0xb00
#define DCFG_CRSTSR_WDRFR		0x8
#define DDR_RESV_LEN			128
#ifdef CONFIG_LS1_DEEP_SLEEP
#ifdef QIXIS_BASE
#endif
#ifdef QIXIS_BASE
#endif
#else
#ifdef QIXIS_BASE
#endif
#endif
#ifdef CONFIG_LS1_DEEP_SLEEP
#else
#endif
