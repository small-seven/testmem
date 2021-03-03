#if 0 /* in case someone actually tries to compile this */
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <png.h>
#include <zlib.h>
#include <png.h>
#ifndef png_jmpbuf
#  define png_jmpbuf(png_ptr) ((png_ptr)->png_jmpbuf)
#endif
#define PNG_BYTES_TO_CHECK 4
#ifdef open_file /* prototype 1 */
#else no_open_file /* prototype 2 */
#endif no_open_file /* Only use one prototype! */
#ifdef streams /* PNG file I/O method 1 */
#else no_streams /* PNG file I/O method 2 */
#endif no_streams /* Use only one I/O method! */
#ifdef hilevel
#else
#ifdef PNG_READ_SCALE_16_TO_8_SUPPORTED
#else
#endif
#ifdef PNG_READ_QUANTIZE_SUPPORTED
#endif /* READ_QUANTIZE */
#ifdef PNG_READ_INTERLACING_SUPPORTED
#else /* !READ_INTERLACING */
#endif /* READ_INTERLACING */
#ifdef entire /* Read the entire image in one go */
#else no_entire /* Read the image one or more scanlines at a time */
#ifdef single /* Read the image a single row at a time */
#else no_single /* Read the image several rows at a time */
#ifdef sparkle /* Read the image using the "sparkle" effect. */
#else no_sparkle /* Read the image using the "rectangle" effect */
#endif no_sparkle /* Use only one of these two methods */
#endif no_single /* Use only one of these two methods */
#endif no_entire /* Use only one of these two methods */
#endif hilevel
#ifdef PNG_READ_INTERLACING_SUPPORTED
#endif /* READ_INTERLACING */
#ifdef streams /* I/O initialization method 1 */
#else no_streams /* I/O initialization method 2 */
#endif no_streams /* Only use one initialization method */
#ifdef hilevel
#else
#ifdef entire /* Write out the entire image data in one call */
#else no_entire /* Write out the image data by one or more scanlines */
#endif no_entire /* Use only one output method */
#endif hilevel
#endif /* if 0 */
