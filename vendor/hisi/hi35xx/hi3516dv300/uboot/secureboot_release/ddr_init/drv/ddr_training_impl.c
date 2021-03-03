#include "ddr_training_impl.h"
#include "ddr_interface.h"
#include <stdint.h>
#define __common__
void* ddrtr_memcpy(void *dst, const void *src, unsigned int len)
{
	const char *s = src;
	char *d = dst;

	while (len--)
			*d++ = *s++;
	return dst;
}
void* ddrtr_memset(void *b, int c, unsigned int len)
{
	char *bp = b;

	while (len--)
		*bp++ = (unsigned char)c;
	return b;
}
#ifdef DDR_TRAINING_CMD
#endif
#ifdef DDR_REG_BASE_PHY1
#endif
#ifdef DDR_REG_BASE_PHY1
#endif
#ifdef DDR_REG_BASE_PHY1
#endif
#ifdef DDR_TRAINING_STAT_CONFIG
#endif
#ifdef DDR_TRAINING_STAT_CONFIG
#endif
#if !defined(DDR_TRAINING_CUT_CODE_CONFIG) || defined(DDR_TRAINING_CMD)
#endif
#if defined(DDR_WL_TRAINING_CONFIG) || defined(DDR_MPR_TRAINING_CONFIG)
#endif
#if defined(DDR_HW_TRAINING_CONFIG) || defined(DDR_DCC_TRAINING_CONFIG)
#endif /* DDR_HW_TRAINING_CONFIG ||  DDR_DCC_TRAINING_CONFIG*/
#define __ddrt__
#ifdef DDR_DDRT_SPECIAL_CONFIG
#endif /* DDR_DDRT_SPECIAL_CONFIG */
#define __dataeye_adjust__
#ifdef DDR_TRAINING_ADJUST_CONFIG
#else
#define ddr_adjust_dataeye(cfg, training)
#endif /* DDR_TRAINING_ADJUST_CONFIG */
#define __dataeye_training__
#ifdef DDR_DATAEYE_TRAINING_CONFIG
#else
#endif  /* DDR_DATAEYE_TRAINING_CONFIG */
#define __hardware_training__
#ifdef DDR_HW_TRAINING_CONFIG
#ifdef DDR_HW_READ_ADJ_CONFIG
#else
#endif /* DDR_HW_READ_ADJ_CONFIG */
#ifdef DDR_WRITE_DM_DISABLE
#endif
#ifdef DDR_WRITE_DM_DISABLE
#endif
#endif /* DDR_HW_TRAINING_CONFIG */
#define __mpr_training__
#ifdef DDR_MPR_TRAINING_CONFIG
#endif /* DDR_MPR_TRAINING_CONFIG */
#define __vref_training__
#ifdef DDR_VREF_TRAINING_CONFIG
#ifdef DDR_VREF_WITHOUT_BDL_CONFIG
#else
#endif /* DDR_VREF_WITHOUT_BDL_CONFIG */
#if !defined(DDR_VREF_WITHOUT_BDL_CONFIG) || defined(DDR_TRAINING_CMD)
#endif
#else
#endif /* DDR_VREF_TRAINING_CONFIG */
#define __write_leveling__
#ifdef DDR_WL_TRAINING_CONFIG
#if defined (DDR_PHY_T28_CONFIG) || defined(DDR_PHY_T16_CONFIG) \
#else
#endif
#if defined (DDR_PHY_T28_CONFIG) || defined(DDR_PHY_T16_CONFIG) \
#else
#endif
#ifdef DDR_WL_DATAEYE_ADJUST_CONFIG
#endif /* DDR_WL_DATAEYE_ADJUST_CONFIG */
#ifdef DDR_WL_DATAEYE_ADJUST_CONFIG
#endif
#else
#define __gate_training__
#ifdef DDR_GATE_TRAINING_CONFIG
#else
#endif /* DDR_GATE_TRAINING_CONFIG */
#define __ac_training__
#ifdef DDR_AC_TRAINING_CONFIG
#else
#endif /* DDR_AC_TRAINING_CONFIG */
#define __lpca_training__
#ifdef DDR_LPCA_TRAINING_CONFIG
#if defined(DDR_TRAINING_CMD)
#endif
#if defined(DDR_TRAINING_CMD)
#endif
#else
#endif /* DDR_LPCA_TRAINING_CONFIG */
#define __dcc_training__
#ifdef DDR_DCC_TRAINING_CONFIG
#ifdef DDR_TRAINING_DEBUG
#define DDR_TRINING_BREAK_POINT(name) ddr_training_break_point(name)
#else
#define DDR_TRINING_BREAK_POINT(name)
#endif
#else
#endif /* DDR_DCC_TRAINING_CONFIG */
#define __pcode_training__
#ifdef DDR_PCODE_TRAINING_CONFIG
#else
#endif
