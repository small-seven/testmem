#include "signature.h"
#define HOUGH_MAX_OFFSET 90
#define MAX_FRAMERATE 60
#define DIR_PREV 0
#define DIR_NEXT 1
#define DIR_PREV_END 2
#define DIR_NEXT_END 3
#define STATUS_NULL 0
#define STATUS_END_REACHED 1
#define STATUS_BEGIN_REACHED 2
    typedef struct hspace_elem {
        int dist;
        size_t score;
        FineSignature *a;
        FineSignature *b;
    } hspace_elem;
static void sll_free(MatchingInfo *sll)
{
    void *tmp;
    while (sll) {
        tmp = sll;
        sll = sll->next;
        av_freep(&tmp);
    }
}
