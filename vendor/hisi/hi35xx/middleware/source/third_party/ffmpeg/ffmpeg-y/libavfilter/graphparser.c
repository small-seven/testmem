#include <string.h>
#include <stdio.h>
#include "libavutil/avstring.h"
#include "libavutil/mem.h"
#include "avfilter.h"
#define WHITESPACES " \n\t\r"
void avfilter_inout_free(AVFilterInOut **inout)
{
    while (*inout) {
        AVFilterInOut *next = (*inout)->next;
        av_freep(&(*inout)->name);
        av_freep(inout);
        *inout = next;
    }
}
