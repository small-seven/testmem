#ifdef CONFIG_FLASH_ENCRYPT_SUPPORT
#include <hi_stdlib.h>
#include <hi_mem.h>
#include <hi_cipher.h>
#include <hi_efuse.h>
#include <hi_flash.h>
#include <hi_nv.h>
#include <hi_upg_file.h>
#include <hi_partition_table.h>
#include "upg_common.h"
#include "kernel_crypto.h"
#define SFC_BUFFER_BASE_ADDRESS             0x400000
#endif
