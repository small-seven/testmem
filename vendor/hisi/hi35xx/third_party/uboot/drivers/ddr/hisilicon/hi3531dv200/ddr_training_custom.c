#include "ddr_interface.h"
#include "ddr_training_impl.h"
#define CRG_REG_BASE 0x11010000U
#define PERI_CRG_DDRT 0x22A0U
#define PERI_CRG_DDRCKSEL 0x2280U
#define DDRT_CTRL 0x4030 /* DDRT control register */
#define DDRTEST0_CKEN_BIT 4 /* DDRTEST0 clock gating configuration register */
#define DDRTEST0_SRST_REQ_BIT 0 /* soft reset request for DDRTEST0 */
#define DDRT0_MST_SEL_BIT 0 /* ddr p0 bus path selection control */
#define DDRT1_MST_SEL_BIT 1 /* ddr p1 bus path selection control */
#ifdef DDR_REG_BASE_PHY1
#endif
#ifdef DDR_REG_BASE_PHY1
#endif
#ifdef DDR_PCODE_TRAINING_CONFIG
#endif
