#include <common.h>
#include <asm/io.h>
#ifndef CONFIG_ARMV7_NONSEC
#error " Deep sleep needs non-secure mode support. "
#else
#include <asm/secure.h>
#endif
#include <asm/armv7.h>
#if defined(CONFIG_ARCH_LS1021A)
#include <asm/arch/immap_ls102xa.h>
#endif
#include "sleep.h"
#ifdef CONFIG_U_QE
#include <fsl_qe.h>
#endif
#if defined(CONFIG_ARMV7_PSCI) && defined(CONFIG_ARCH_LS1021A)
#ifdef QIXIS_BASE
#endif
#endif
#ifdef CONFIG_U_QE
#endif
#if defined(CONFIG_ARMV7_PSCI) && defined(CONFIG_ARCH_LS1021A)
#endif
