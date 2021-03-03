#include <common.h>
#include <env.h>
#include <splash.h>
#include <lcd.h>
#if defined(CONFIG_DM_VIDEO) && defined(CONFIG_VIDEO_LOGO)
#include <bmp_logo_data.h>
#else
#endif
#ifdef CONFIG_SPLASH_SCREEN_ALIGN
#endif /* CONFIG_SPLASH_SCREEN_ALIGN */
#if defined(CONFIG_DM_VIDEO) && !defined(CONFIG_HIDE_LOGO_VERSION)
#ifdef CONFIG_VIDEO_LOGO
#include <bmp_logo.h>
#endif
#include <dm.h>
#include <video_console.h>
#include <video_font.h>
#ifdef CONFIG_VIDEO_LOGO
#else
#endif
#endif /* CONFIG_DM_VIDEO && !CONFIG_HIDE_LOGO_VERSION */
#if defined(CONFIG_SPLASH_SCREEN) && defined(CONFIG_CMD_BMP)
#if defined(CONFIG_DM_VIDEO) && !defined(CONFIG_HIDE_LOGO_VERSION)
#endif
#endif
