#include <common.h>
#include <charset.h>
#include <efi_loader.h>
#include <div64.h>
#include <hexdump.h>
#include <stdarg.h>
#include <vsprintf.h>
#include <linux/ctype.h>
#include <linux/err.h>
#include <linux/types.h>
#include <linux/string.h>
#define noinline __attribute__((noinline))
#define is_digit(c)	((c) >= '0' && (c) <= '9')
#define ZEROPAD	1		/* pad with zero */
#define SIGN	2		/* unsigned/signed long */
#define PLUS	4		/* show plus */
#define SPACE	8		/* space if plus */
#define LEFT	16		/* left justified */
#define SMALL	32		/* Must be 32 == 0x20 */
#define SPECIAL	64		/* 0x */
#define ADDCH(str, ch) do { \
#if CONFIG_IS_ENABLED(EFI_LOADER) && !defined(API_BUILD)
#if CONFIG_IS_ENABLED(EFI_DEVICE_PATH_TO_TEXT)
#endif
#endif
#ifdef CONFIG_LIB_UUID
#endif
#if 0
#endif
#if CONFIG_IS_ENABLED(EFI_DEVICE_PATH_TO_TEXT) && !defined(API_BUILD)
#endif
#ifdef CONFIG_LIB_UUID
#endif
#if CONFIG_IS_ENABLED(EFI_LOADER) && !defined(API_BUILD)
#endif
#if CONFIG_IS_ENABLED(PRINTF)
#endif
