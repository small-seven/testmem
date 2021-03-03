#include <common.h>
#include <config.h>
#include <command.h>
#include <env.h>
#include <image.h>
#include <linux/ctype.h>
#include <asm/byteorder.h>
#include <reiserfs.h>
#include <part.h>
#if !CONFIG_IS_ENABLED(DOS_PARTITION)
#error DOS partition support must be selected
#endif
#ifdef	REISER_DEBUG
#define	PRINTF(fmt,args...)	printf (fmt ,##args)
#else
#define PRINTF(fmt,args...)
#endif
