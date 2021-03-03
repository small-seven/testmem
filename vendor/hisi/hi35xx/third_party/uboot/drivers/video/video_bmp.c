#include <common.h>
#include <bmp_layout.h>
#include <dm.h>
#include <mapmem.h>
#include <splash.h>
#include <video.h>
#include <watchdog.h>
#include <asm/unaligned.h>
#ifdef CONFIG_VIDEO_BMP_RLE8
#define BMP_RLE8_ESCAPE		0
#define BMP_RLE8_EOL		0
#define BMP_RLE8_EOBMP		1
#define BMP_RLE8_DELTA		2
#endif
#if defined(CONFIG_BMP_16BPP)
#endif /* CONFIG_BMP_16BPP */
#ifdef CONFIG_VIDEO_BMP_RLE8
#endif
#if defined(CONFIG_BMP_16BPP)
#endif /* CONFIG_BMP_16BPP */
#if defined(CONFIG_BMP_24BPP)
#endif /* CONFIG_BMP_24BPP */
#if defined(CONFIG_BMP_32BPP)
#endif /* CONFIG_BMP_32BPP */
