#include <common.h>
#include <charset.h>
#include <time.h>
#include <dm/device.h>
#include <efi_loader.h>
#include <env.h>
#include <stdio_dev.h>
#include <video_console.h>
#define EFI_COUT_MODE_2 2
#define EFI_MAX_COUT_MODE 3
#define cESC '\x1b'
#define ESC "\x1b"
