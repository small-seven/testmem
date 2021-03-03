#include "ass.h"
#include "libavutil/avstring.h"
#include "libavutil/bprint.h"
#include "htmlsubtitles.h"
typedef struct {
    AVBPrint source;
    AVBPrint content;
    AVBPrint encoded_source;
    AVBPrint encoded_content;
    AVBPrint full;
    int readorder;
} SAMIContext;
