#include <common.h>
#include <bzlib.h>
#include <dm.h>
#include <mapmem.h>
#include <os.h>
#include <video.h>
#include <video_console.h>
#include <dm/test.h>
#include <dm/uclass-internal.h>
#include <test/ut.h>
#define WHITE		0xffff
#define SCROLL_LINES	100
#ifdef CONFIG_VIDEO_ANSI
#define ANSI_ESC "\x1b"
#endif
