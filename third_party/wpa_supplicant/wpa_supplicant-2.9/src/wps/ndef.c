#include "includes.h"
#include "common.h"
#include "wps/wps.h"
#define FLAG_MESSAGE_BEGIN (1 << 7)
#define FLAG_MESSAGE_END (1 << 6)
#define FLAG_CHUNK (1 << 5)
#define FLAG_SHORT_RECORD (1 << 4)
#define FLAG_ID_LENGTH_PRESENT (1 << 3)
#define FLAG_TNF_NFC_FORUM (0x01)
#define FLAG_TNF_RFC2046 (0x02)
