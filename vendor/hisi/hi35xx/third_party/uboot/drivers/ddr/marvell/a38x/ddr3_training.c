#include "ddr3_init.h"
#include "mv_ddr_common.h"
#include "mv_ddr_training_db.h"
#include "mv_ddr_regs.h"
#define GET_CS_FROM_MASK(mask)	(cs_mask2_num[mask])
#define CS_CBE_VALUE(cs_num)	(cs_cbe_reg[cs_num])
#ifdef ODT_TEST_SUPPORT
#endif
#if defined(CONFIG_ARMADA_38X) || defined(CONFIG_ARMADA_39X)
#else /* !CONFIG_ARMADA_38X && !CONFIG_ARMADA_39X && !A70X0 && !A80X0 && !A3900 */
#pragma message "unknown platform to configure ddr clock swap"
#endif
#ifdef ODT_TEST_SUPPORT
#endif
#ifdef ODT_TEST_SUPPORT
#endif
#if defined(CONFIG_ARMADA_38X) || defined(CONFIG_ARMADA_39X)
#endif
#ifdef DDR_VIEWER_TOOL
#endif
#if defined(CONFIG_ARMADA_38X) || defined(CONFIG_ARMADA_39X)
#endif
#ifndef EXCLUDE_DEBUG_PRINTS
#endif /* EXCLUDE_DEBUG_PRINTS */
#ifdef DEVICE_MAX_DRAM_ADDRESS_SIZE
#endif
#ifdef DEVICE_MAX_DRAM_ADDRESS_SIZE
#endif
