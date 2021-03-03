#include <stdint.h>
#include "libavutil/qsort.h"
#include "libavutil/common.h"
#include "avcodec.h"
#include "huffman.h"
#include "vlc.h"
#define HNODE -1
typedef struct HeapElem {
    uint64_t val;
    int name;
} HeapElem;
