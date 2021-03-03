#include <common.h>
#include <asm/io.h>
#include <asm/arch/soc.h>
#include <asm/arch/mpp.h>
#include <nand.h>
#define NAND_ACTCEBOOT_BIT		0x02
#if defined(CONFIG_SYS_NAND_NO_SUBPAGE_WRITE)
#endif
#if defined(CONFIG_NAND_ECC_BCH)
#else
#endif
