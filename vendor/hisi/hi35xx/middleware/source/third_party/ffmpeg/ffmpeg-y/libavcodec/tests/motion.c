#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "config.h"
#include "libavcodec/me_cmp.h"
#include "libavutil/internal.h"
#include "libavutil/lfg.h"
#include "libavutil/mem.h"
#include "libavutil/time.h"
#undef printf
#define WIDTH 64
#define HEIGHT 64
#define NB_ITS 500
