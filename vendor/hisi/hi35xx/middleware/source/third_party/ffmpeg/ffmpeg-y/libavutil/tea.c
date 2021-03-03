#include "avutil.h"
#include "common.h"
#include "intreadwrite.h"
#include "tea.h"
typedef struct AVTEA {
    uint32_t key[16];
    int rounds;
} AVTEA;
