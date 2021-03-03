#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include "utils.c"
#define NOISE_X  10
#define NOISE_Y  30
#define NOISE_W  26
#define FRAC_BITS 8
#define FRAC_ONE (1 << FRAC_BITS)
#define NB_OBJS  10
typedef struct VObj {
    int x, y, w, h;
    int r, g, b;
} VObj;
