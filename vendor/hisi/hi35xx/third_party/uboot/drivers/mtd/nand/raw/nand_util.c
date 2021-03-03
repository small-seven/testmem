#include <common.h>
#include <command.h>
#include <watchdog.h>
#include <malloc.h>
#include <memalign.h>
#include <div64.h>
#include <linux/errno.h>
#include <linux/mtd/mtd.h>
#include <nand.h>
#include <jffs2/jffs2.h>
typedef struct erase_info	erase_info_t;
typedef struct mtd_info		mtd_info_t;

/* for ecc0 read and write */
unsigned int ecc0_flag;
unsigned int oobsize_real;
/* support only for native endian JFFS2 */
#define cpu_to_je16(x) (x)
#define cpu_to_je32(x) (x)

/**
 * nand_erase_opts: - erase NAND flash with support for various options
 *		      (jffs2 formatting)
 *
 * @param mtd		nand mtd instance to erase
 * @param opts		options,  @see struct nand_erase_options
 * @return		0 in case of success
 *
 * This code is ported from flash_eraseall.c from Linux mtd utils by
 * Arcom Control System Ltd.
 */
int nand_erase_opts(struct mtd_info *mtd,
		    const nand_erase_options_t *opts)
{
	struct jffs2_unknown_node cleanmarker;
	erase_info_t erase;
	unsigned long erase_length, erased_length; /* in blocks */
	int result;
	int percent_complete = -1;
	const char *mtd_device = mtd->name;
	struct mtd_oob_ops oob_opts;
	struct nand_chip *chip = mtd_to_nand(mtd);

	if ((opts->offset & (mtd->erasesize - 1)) != 0) {
		printf("Attempt to erase non block-aligned data\n");
		return -1;
	}
#ifdef CONFIG_CMD_NAND_LOCK_UNLOCK
#define NAND_CMD_LOCK_TIGHT     0x2c
#define NAND_CMD_LOCK_STATUS    0x7a
#endif
#ifdef CONFIG_CMD_NAND_TRIMFFS
#endif
#ifdef CONFIG_CMD_NAND_TRIMFFS
#endif
#ifdef CONFIG_CMD_NAND_TORTURE
#endif
