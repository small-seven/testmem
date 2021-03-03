#include "config.h"
#include "libavutil/channel_layout.h"
#include "parser.h"
#include "ac3_parser.h"
#include "ac3_parser_internal.h"
#include "aac_ac3_parser.h"
#include "get_bits.h"
#define AC3_HEADER_SIZE 7
#if CONFIG_AC3_PARSER
#else
#endif
