#include "aactab.h"
#include "aacenc_pred.h"
#include "aacenc_utils.h"
#include "aacenc_is.h"            /* <- Needed for common window distortions */
#include "aacenc_quantization.h"
#define RESTORE_PRED(sce, sfb) \
