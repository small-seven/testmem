#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "avassert.h"
#include "avstring.h"
#include "bprint.h"
#include "common.h"
#include "compat/va_copy.h"
#include "error.h"
#include "mem.h"
#define av_bprint_room(buf) ((buf)->size - FFMIN((buf)->len, (buf)->size))
#define av_bprint_is_allocated(buf) ((buf)->str != (buf)->reserved_internal_buffer)
#define WHITESPACES " \n\t\r"
