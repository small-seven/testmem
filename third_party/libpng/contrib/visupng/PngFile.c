#include <windows.h>
#include <commdlg.h>
#include <stdio.h>
#include <stdlib.h>
#include <zlib.h>
#include "png.h"
#include "pngfile.h"
#include "cexcept.h"
#ifdef PNG_CONSOLE_IO_SUPPORTED
#endif
#ifdef PNG_STDIO_SUPPORTED
#else
#endif
#ifdef PNG_READ_16_TO_8_SUPPORTED
#  ifdef PNG_READ_SCALE_16_TO_8_SUPPORTED
#  else
#  endif
#endif
#ifdef PNG_STDIO_SUPPORTED
#else
#endif
#ifndef PNG_STDIO_SUPPORTED
#endif
