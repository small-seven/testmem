#include "draw/draw_utils.h"
#include "color.h"
#include "draw/draw_triangle.h"
#include "font/ui_font.h"
#include "font/ui_font_header.h"
#include "graphic_log.h"
#include "securec.h"
#if ENABLE_WINDOW && ENABLE_HARDWARE_ACCELERATION
#include "gfx_engines.h"
#endif
#define DRAW_UTILS_PREPROCESS(opa)                                                   \
#if COLOR_DEPTH == 32 && ENABLE_BUFFER_RGBA == 0
#define WRITE_BUFFER(c, v)                                                           \
#define WRITE_BUFFER_WITH_ALPHA(hal, color, opa)                                     \
#else
#define WRITE_BUFFER(c, v) (c).full = (v).full;
#define WRITE_BUFFER_WITH_ALPHA(hal, color, opa) (hal) = Color::GetMixColor((color), (hal), (opa));
#endif
#if ENABLE_DMA2D
#endif
#ifdef VERSION_STANDARD
#endif
#if !ENABLE_WINDOW
#endif
#if ENABLE_DMA2D
#elif ENABLE_WINDOW && ENABLE_HARDWARE_ACCELERATION
#else
#endif
#if !ENABLE_WINDOW
#endif
#if ENABLE_WINDOW
#else
#endif
#if ENABLE_DMA2D & ENABLE_DMA2D_TEXT
#endif
#if ENABLE_WINDOW
#else
#endif
#if ENABLE_DMA2D
#endif
#if ENABLE_DMA2D
#endif
#if ENABLE_WINDOW && ENABLE_HARDWARE_ACCELERATION
#endif
#if COLOR_DEPTH == 32
#else
#endif
#if COLOR_DEPTH == 32 /* halbuffer is RGB888 */
#else /* halbuffer is RGB565 */
#endif
#if ENABLE_WINDOW
#else
#endif
#ifndef _LITEOS
#else
#endif
#if ENABLE_WINDOW
#else
#endif
#ifndef _LITEOS
#else
#endif
#if ENABLE_WINDOW
#else
#endif
#ifndef _LITEOS
#else
#endif
#ifndef _LITEOS
#else
#endif
#if ENABLE_WINDOW
#else
#endif
#ifndef _LITEOS
#else
#endif
#ifndef _LITEOS
#else
#endif
#if ENABLE_WINDOW
#else
#endif
#ifndef _LITEOS
#else
#endif
#ifndef _LITEOS
#else
#endif
#if ENABLE_WINDOW
#else
#endif
#ifndef _LITEOS
#else
#endif
#if ENABLE_SPEC_FONT
#else
#endif // ENABLE_SPEC_FONT
#if ENABLE_WINDOW != 1
#endif
