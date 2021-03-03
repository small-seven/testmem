#include "common.h"
#include "samplefmt.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct SampleFmtInfo {
    char name[8];
    int bits;
    int planar;
    enum AVSampleFormat altform; ///< planar<->packed alternative form
} SampleFmtInfo;
