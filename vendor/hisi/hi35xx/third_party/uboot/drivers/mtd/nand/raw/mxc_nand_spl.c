#include <common.h>
#include <nand.h>
#include <asm/arch/imx-regs.h>
#include <asm/io.h>
#include "mxc_nand.h"
#if defined(MXC_NFC_V1) || defined(MXC_NFC_V2_1)
#elif defined(MXC_NFC_V3_2)
#endif
#if defined(MXC_NFC_V1) || defined(MXC_NFC_V2_1)
#elif defined(MXC_NFC_V3_2)
#endif
#if defined(MXC_NFC_V3_2)
#ifndef CONFIG_SYS_NAND_BUSWIDTH_16
#endif
#elif defined(MXC_NFC_V2_1)
#elif defined(MXC_NFC_V1)
#endif
#ifdef NAND_MXC_2K_MULTI_CYCLE
#endif
#if defined(MXC_NFC_V1) || defined(MXC_NFC_V2_1)
#elif defined(MXC_NFC_V3_2)
#endif
#ifdef NAND_MXC_2K_MULTI_CYCLE
#endif
#if defined(MXC_NFC_V1)
#elif defined(MXC_NFC_V2_1) || defined(MXC_NFC_V3_2)
#endif
#if defined(MXC_NFC_V1) || defined(MXC_NFC_V2_1)
#elif defined(MXC_NFC_V3_2)
#endif
#ifndef CONFIG_SPL_FRAMEWORK
#endif
