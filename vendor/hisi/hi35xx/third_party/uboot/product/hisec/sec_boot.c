#include "sec_boot.h"
#include "common.h"
#include <malloc.h>
#include "v2/api/hi_types.h"
#include "v2/api/hi_mpi_cipher.h"
#define RSA_2048_N_LEN  256
#define RSA_4096_N_LEN  512
#define UBOOT_PUB_KEY_ADDR  16
#define UBOOT_PUB_KEY_LEN_ADDR  12
#define HEADER_LENGTH_COUNT 3
#ifdef CONFIG_HIFMC_SPI_NOR
#include "spi_flash.h"
#endif
#ifdef CONFIG_MMC
#include "mmc.h"
#endif
#ifdef CONFIG_HIFMC_SPI_NOR
#endif
#ifdef CONFIG_MMC
#endif
