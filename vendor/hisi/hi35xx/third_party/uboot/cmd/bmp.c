#include <common.h>
#include <bmp_layout.h>
#include <command.h>
#include <dm.h>
#include <gzip.h>
#include <lcd.h>
#include <malloc.h>
#include <mapmem.h>
#include <splash.h>
#include <video.h>
#include <asm/byteorder.h>
#ifdef CONFIG_VIDEO_BMP_GZIP
#else
#endif
#ifdef CONFIG_NEEDS_MANUAL_RELOC
#endif
#ifdef CONFIG_DM_VIDEO
#endif
#ifdef CONFIG_DM_VIDEO
#elif defined(CONFIG_LCD)
#elif defined(CONFIG_VIDEO)
#else
# error bmp_display() requires CONFIG_LCD or CONFIG_VIDEO
#endif
