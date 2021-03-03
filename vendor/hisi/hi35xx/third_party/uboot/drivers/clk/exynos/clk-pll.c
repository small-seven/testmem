#include <common.h>
#include <asm/io.h>
#include <div64.h>
#define PLL145X_MDIV_SHIFT	16
#define PLL145X_MDIV_MASK	0x3ff
#define PLL145X_PDIV_SHIFT	8
#define PLL145X_PDIV_MASK	0x3f
#define PLL145X_SDIV_SHIFT	0
#define PLL145X_SDIV_MASK	0x7
