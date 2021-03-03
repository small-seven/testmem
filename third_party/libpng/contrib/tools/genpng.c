#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include "../../png.h"
#if defined(PNG_SIMPLIFIED_WRITE_SUPPORTED) && defined(PNG_STDIO_SUPPORTED)
#define color_count ((sizeof colors)/(sizeof colors[0]))
typedef int (*shape_fn_ptr)(const struct arg *arg, double x, double y);
   /* A function to determine if (x,y) is inside the shape.
    *
    * There are two implementations:
    *
    *    inside_fn: returns true if the point is inside
    *    check_fn:  returns;
    *       -1: the point is outside the shape by more than the filter width (2)
    *        0: the point may be inside the shape
    *       +1: the point is inside the shape by more than the filter width
    */
#define OUTSIDE (-1)
#define INSIDE  (1)

struct arg
{
   const struct color *color;
   shape_fn_ptr        inside_fn;
   shape_fn_ptr        check_fn;
   double              width; /* line width, 0 for 'filled' */
   double              x1, y1, x2, y2;
};
#if 0 /* bc code */
#endif
#define BICUBIC1(x) /*     |x| <= 1 */ ((1.5*(x)* - 2.5)*(x)*(x) + 1)
#define BICUBIC2(x) /* 1 < |x| <  2 */ (((2.5 - 0.5*(x))*(x) - 4)*(x) + 2)
#define FILTER_WEIGHT 9 /* Twice the first sum below */
#define FILTER_WIDTH  2 /* Actually half the width; -2..+2 */
#define FILTER_STEPS  8 /* steps per filter unit */
#        define FILTER_D (FILTER_WIDTH*FILTER_STEPS-1)
#  define         FN_INSIDE 0
#  define         FN_CHECK 1
#define shape_count ((sizeof shape_defs)/(sizeof shape_defs[0]))
#     define max_shapes 256
#if 1
#endif
#endif /* SIMPLIFIED_WRITE && STDIO */
