#include <charset.h>
#include <common.h>
#include <command.h>
#include <efi_loader.h>
#include <exports.h>
#include <hexdump.h>
#include <malloc.h>
#include <search.h>
#include <linux/ctype.h>
#define BS systab.boottime
#define RT systab.runtime
#define EFI_HANDLE_WIDTH ((int)sizeof(efi_handle_t) * 2)
#define EFI_PHYS_ADDR_WIDTH (int)(sizeof(efi_physical_addr_t) * 2)
#ifdef CONFIG_SYS_LONGHELP
#endif
