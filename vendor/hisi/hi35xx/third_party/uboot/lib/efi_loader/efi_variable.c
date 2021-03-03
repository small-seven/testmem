#include <common.h>
#include <efi_loader.h>
#include <env_internal.h>
#include <hexdump.h>
#include <malloc.h>
#include <search.h>
#include <u-boot/crc.h>
#define READ_ONLY BIT(31)
#define PREFIX_LEN (strlen("efi_xxxxxxxx-xxxx-xxxx-xxxx-xxxxxxxxxxxx_"))
