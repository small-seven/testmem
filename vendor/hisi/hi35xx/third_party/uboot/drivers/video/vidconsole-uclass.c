#include <common.h>
#include <linux/ctype.h>
#include <dm.h>
#include <video.h>
#include <video_console.h>
#include <video_font.h>		/* Bitmap font for code page 437 */
#ifndef CONFIG_CONSOLE_SCROLL_LINES
#define CONFIG_CONSOLE_SCROLL_LINES 1
#endif
