#include <common.h>
#include <mpc83xx.h>
#include "lblaw/lblaw.h"
#include "elbc/elbc.h"
#ifndef CONFIG_ACR_PIPE_DEP_UNSET
#endif
#ifndef CONFIG_ACR_RPTCNT_UNSET
#endif
#ifdef CONFIG_SYS_SPCR_OPT
#endif
#ifdef CONFIG_SYS_DDRCDR
#endif
#ifdef CONFIG_SYS_OBIR
#endif
#if defined(CONFIG_SYS_NAND_BR_PRELIM)  \
#else
#error CONFIG_SYS_NAND_BR_PRELIM, CONFIG_SYS_NAND_OR_PRELIM, CONFIG_SYS_NAND_LBLAWBAR_PRELIM & CONFIG_SYS_NAND_LBLAWAR_PRELIM must be defined
#endif
