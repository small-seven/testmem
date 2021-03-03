#include "opus_rc.h"
#define OPUS_RC_BITS 32
#define OPUS_RC_SYM  8
#define OPUS_RC_CEIL ((1 << OPUS_RC_SYM) - 1)
#define OPUS_RC_TOP (1u << 31)
#define OPUS_RC_BOT (OPUS_RC_TOP >> OPUS_RC_SYM)
#define OPUS_RC_SHIFT (OPUS_RC_BITS - OPUS_RC_SYM - 1)
