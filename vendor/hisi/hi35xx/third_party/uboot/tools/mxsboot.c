#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include "compiler.h"
#define __round_mask(x, y) ((__typeof__(x))((y)-1))
#define round_down(x, y) ((x) & ~__round_mask(x, y))
#define	STRIDE_PAGES		64
#define	STRIDE_COUNT		4
#define	MAX_BOOTSTREAM_SIZE	(1 * 1024 * 1024)
#define	MXS_NAND_DMA_DESCRIPTOR_COUNT		4
#define	MXS_NAND_CHUNK_DATA_CHUNK_SIZE		512
#define	MXS_NAND_METADATA_SIZE			10
#define	MXS_NAND_BITS_PER_ECC_LEVEL		13
#define	MXS_NAND_COMMAND_BUFFER_SIZE		32
