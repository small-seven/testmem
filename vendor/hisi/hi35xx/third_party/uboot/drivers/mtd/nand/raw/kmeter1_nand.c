#include <common.h>
#include <nand.h>
#include <asm/io.h>
#define CONFIG_NAND_MODE_REG	(void *)(CONFIG_SYS_NAND_BASE + 0x20000)
#define CONFIG_NAND_DATA_REG	(void *)(CONFIG_SYS_NAND_BASE + 0x30000)
#define read_mode()	in_8(CONFIG_NAND_MODE_REG)
#define write_mode(val)	out_8(CONFIG_NAND_MODE_REG, val)
#define read_data()	in_8(CONFIG_NAND_DATA_REG)
#define write_data(val)	out_8(CONFIG_NAND_DATA_REG, val)
#define KPN_RDY2	(1 << 7)
#define KPN_RDY1	(1 << 6)
#define KPN_WPN		(1 << 4)
#define KPN_CE2N	(1 << 3)
#define KPN_CE1N	(1 << 2)
#define KPN_ALE		(1 << 1)
#define KPN_CLE		(1 << 0)
#define KPN_DEFAULT_CHIP_DELAY 50
#if defined(CONFIG_NAND_ECC_BCH)
#else
#endif
