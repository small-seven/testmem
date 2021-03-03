#include "avcodec.h"
#include "get_bits.h"
#include "internal.h"
#include "libavutil/attributes.h"
#include "libavutil/colorspace.h"
#include "libavutil/opt.h"
#include "libavutil/imgutils.h"
#include "libavutil/avstring.h"
#include "libavutil/bswap.h"
typedef struct DVDSubContext
{
  AVClass *class;
  uint32_t palette[16];
  char    *palette_str;
  char    *ifo_str;
  int      has_palette;
  uint8_t  colormap[4];
  uint8_t  alpha[256];
  uint8_t  buf[0x10000];
  int      buf_size;
  int      forced_subs_only;
  uint8_t  used_color[256];
#ifdef DEBUG
  int sub_id;
#endif
} DVDSubContext;
#define READ_OFFSET(a) (big_offsets ? AV_RB32(a) : AV_RB16(a))
#if FF_API_AVPICTURE
#endif
#if FF_API_AVPICTURE
#endif
#ifdef DEBUG
#define ALPHA_MIX(A,BACK,FORE) (((255-(A)) * (BACK) + (A) * (FORE)) / 255)
#endif
#if defined(DEBUG)
#endif
#define OFFSET(field) offsetof(DVDSubContext, field)
#define SD AV_OPT_FLAG_SUBTITLE_PARAM | AV_OPT_FLAG_DECODING_PARAM
