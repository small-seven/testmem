#include <string.h>
#include "avstring.h"
#include "dict.h"
#include "internal.h"
#include "mem.h"
#include "time_internal.h"
#include "bprint.h"
void av_dict_free(AVDictionary **pm)
{
    AVDictionary *m = *pm;

    if (m) {
        while (m->count--) {
            av_freep(&m->elems[m->count].key);
            av_freep(&m->elems[m->count].value);
        }
        av_freep(&m->elems);
    }
    av_freep(pm);
}
