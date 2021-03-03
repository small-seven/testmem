#include <common.h>
#include <asm/e820.h>
#include <asm/global_data.h>
#include <asm/sfi.h>
#define SFI_BASE_ADDR		0x000E0000
#define SFI_LENGTH		0x00020000
#define SFI_TABLE_LENGTH	16
#define sfi_for_each_mentry(i, sb, mentry)				\
