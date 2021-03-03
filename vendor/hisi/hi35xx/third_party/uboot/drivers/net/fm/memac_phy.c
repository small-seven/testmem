#include <common.h>
#include <miiphy.h>
#include <phy.h>
#include <asm/io.h>
#include <fsl_memac.h>
#include <fm_eth.h>
#ifdef CONFIG_SYS_MEMAC_LITTLE_ENDIAN
#define memac_out_32(a, v)	out_le32(a, v)
#define memac_clrbits_32(a, v)	clrbits_le32(a, v)
#define memac_setbits_32(a, v)	setbits_le32(a, v)
#else
#define memac_out_32(a, v)	out_be32(a, v)
#define memac_clrbits_32(a, v)	clrbits_be32(a, v)
#define memac_setbits_32(a, v)	setbits_be32(a, v)
#endif
#ifdef CONFIG_SYS_MEMAC_LITTLE_ENDIAN
#else
#endif
