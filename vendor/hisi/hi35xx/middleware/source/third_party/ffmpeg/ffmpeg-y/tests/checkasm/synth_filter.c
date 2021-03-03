#include <math.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "libavutil/internal.h"
#include "libavutil/intfloat.h"
#include "libavcodec/dcadata.h"
#include "libavcodec/synth_filter.h"
#include "checkasm.h"
#define BUF_SIZE 32
#define randomize_input()                                       \
