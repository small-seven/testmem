#include <common.h>
#include <dm.h>
#include <video.h>
#include <video_console.h>
#define STBTT_ifloor		tt_floor
#define STBTT_iceil		tt_ceil
#define STBTT_fabs		tt_fabs
#define STBTT_sqrt		tt_sqrt
#define STBTT_malloc(size, u)	((void)(u), malloc(size))
#define STBTT_free(size, u)	((void)(u), free(size))
#define STBTT_assert(x)
#define STBTT_strlen(x)		strlen(x)
#define STBTT_memcpy		memcpy
#define STBTT_memset		memset
#define STB_TRUETYPE_IMPLEMENTATION
#include "stb_truetype.h"
#define POS_HISTORY_SIZE	(CONFIG_SYS_CBSIZE * 11 / 10)
#ifdef CONFIG_VIDEO_BPP8
#endif
#ifdef CONFIG_VIDEO_BPP16
#endif
#ifdef CONFIG_VIDEO_BPP32
#endif
#ifdef CONFIG_VIDEO_BPP16
#endif
#ifdef CONFIG_VIDEO_BPP8
#endif
#ifdef CONFIG_VIDEO_BPP16
#endif
#ifdef CONFIG_VIDEO_BPP32
#endif
#define FONT_DECL(_name) \
#define FONT_ENTRY(_name)		{ \
#ifdef CONFIG_CONSOLE_TRUETYPE_NIMBUS
#endif
#ifdef CONFIG_CONSOLE_TRUETYPE_ANKACODER
#endif
#ifdef CONFIG_CONSOLE_TRUETYPE_RUFSCRIPT
#endif
#ifdef CONFIG_CONSOLE_TRUETYPE_CANTORAONE
#endif
#define FONT_BEGIN(name)	__ttf_ ## name ## _begin
#define FONT_END(name)		__ttf_ ## name ## _end
#define FONT_IS_VALID(name)	(abs(FONT_END(name) - FONT_BEGIN) > 4)
