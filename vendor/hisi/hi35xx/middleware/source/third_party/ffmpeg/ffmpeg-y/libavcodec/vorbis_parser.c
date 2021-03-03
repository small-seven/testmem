#include "libavutil/log.h"
#include "get_bits.h"
#include "parser.h"
#include "xiph.h"
#include "vorbis_parser_internal.h"
void av_vorbis_parse_free(AVVorbisParseContext **s)
{
    av_freep(s);
}
#if CONFIG_VORBIS_PARSER
typedef struct VorbisParseContext {
    AVVorbisParseContext *vp;
} VorbisParseContext;
#endif /* CONFIG_VORBIS_PARSER */
