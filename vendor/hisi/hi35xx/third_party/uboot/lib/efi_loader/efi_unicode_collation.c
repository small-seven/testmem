#include <common.h>
#include <charset.h>
#include <cp1250.h>
#include <cp437.h>
#include <efi_loader.h>
#if CONFIG_FAT_DEFAULT_CODEPAGE == 1250
#else
#endif
#if CONFIG_IS_ENABLED(EFI_UNICODE_COLLATION_PROTOCOL)
#endif
