#include "libavutil/common.h"
#include "golomb.h"
#include "hevc.h"
#include "hevc_parse.h"
#include "hevc_ps.h"
#include "hevc_sei.h"
#include "h2645_parse.h"
#include "internal.h"
#include "parser.h"
#define START_CODE 0x000001 ///< start_code_prefix_one_3bytes
#define IS_IRAP_NAL(nal) (nal->type >= 16 && nal->type <= 23)
#define IS_IDR_NAL(nal) (nal->type == HEVC_NAL_IDR_W_RADL || nal->type == HEVC_NAL_IDR_N_LP)
typedef struct HEVCParserContext {
    ParseContext pc;

    H2645Packet pkt;
    HEVCParamSets ps;
    HEVCSEI sei;
    SliceHeader sh;

    int is_avc;
    int nal_length_size;
    int parsed_extradata;

    int poc;
    int pocTid0;
} HEVCParserContext;
