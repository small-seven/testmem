#include <config.h>
#include <common.h>
#include <asm/io.h>
#include <asm/immap_85xx.h>
#include <asm/fsl_serdes.h>
typedef struct serdes_85xx {
	u32	srdscr0;	/* 0x00 - SRDS Control Register 0 */
	u32	srdscr1;	/* 0x04 - SRDS Control Register 1 */
	u32	srdscr2;	/* 0x08 - SRDS Control Register 2 */
	u32	srdscr3;	/* 0x0C - SRDS Control Register 3 */
	u32	srdscr4;	/* 0x10 - SRDS Control Register 4 */
} serdes_85xx_t;
#define FSL_SRDSCR3_EIC0(x)	(((x) & 0x1f) << 8)
#define FSL_SRDSCR3_EIC0_MASK	FSL_SRDSCR3_EIC0(0x1f)
#define FSL_SRDSCR3_EIC1(x)	(((x) & 0x1f) << 0)
#define FSL_SRDSCR3_EIC1_MASK	FSL_SRDSCR3_EIC1(0x1f)
#define FSL_SRDSCR4_EIC2(x)	(((x) & 0x1f) << 8)
#define FSL_SRDSCR4_EIC2_MASK	FSL_SRDSCR4_EIC2(0x1f)
#define FSL_SRDSCR4_EIC3(x)	(((x) & 0x1f) << 0)
#define FSL_SRDSCR4_EIC3_MASK	FSL_SRDSCR4_EIC3(0x1f)
#define EIC_PCIE	0x13
#define EIC_SGMII	0x04
#define SRDS1_MAX_LANES		4
