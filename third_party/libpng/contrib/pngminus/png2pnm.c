#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#ifndef BOOL
#define BOOL unsigned char
#endif
#ifndef TRUE
#define TRUE (BOOL) 1
#endif
#ifndef FALSE
#define FALSE (BOOL) 0
#endif
#ifndef PNG_DEBUG
#define PNG_DEBUG 0
#endif
#include "png.h"
#if defined(O_BINARY) && (O_BINARY != 0)
#endif
#ifdef NJET
#endif
#if defined(O_BINARY) && (O_BINARY != 0)
#endif
