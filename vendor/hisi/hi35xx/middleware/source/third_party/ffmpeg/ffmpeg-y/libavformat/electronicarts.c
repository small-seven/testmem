#include <inttypes.h>
#include "libavutil/intreadwrite.h"
#include "avformat.h"
#include "internal.h"
#define SCHl_TAG MKTAG('S', 'C', 'H', 'l')
#define SEAD_TAG MKTAG('S', 'E', 'A', 'D')  /* Sxxx header */
#define SNDC_TAG MKTAG('S', 'N', 'D', 'C')  /* Sxxx data */
#define SEND_TAG MKTAG('S', 'E', 'N', 'D')  /* Sxxx end */
#define SHEN_TAG MKTAG('S', 'H', 'E', 'N')  /* SxEN header */
#define SDEN_TAG MKTAG('S', 'D', 'E', 'N')  /* SxEN data */
#define SEEN_TAG MKTAG('S', 'E', 'E', 'N')  /* SxEN end */
#define ISNh_TAG MKTAG('1', 'S', 'N', 'h')  /* 1SNx header */
#define EACS_TAG MKTAG('E', 'A', 'C', 'S')
#define ISNd_TAG MKTAG('1', 'S', 'N', 'd')  /* 1SNx data */
#define ISNe_TAG MKTAG('1', 'S', 'N', 'e')  /* 1SNx end */
#define PT00_TAG MKTAG('P', 'T', 0x0, 0x0)
#define GSTR_TAG MKTAG('G', 'S', 'T', 'R')
#define SCDl_TAG MKTAG('S', 'C', 'D', 'l')
#define SCEl_TAG MKTAG('S', 'C', 'E', 'l')
#define kVGT_TAG MKTAG('k', 'V', 'G', 'T')  /* TGV I-frame */
#define fVGT_TAG MKTAG('f', 'V', 'G', 'T')  /* TGV P-frame */
#define mTCD_TAG MKTAG('m', 'T', 'C', 'D')  /* MDEC */
#define MADk_TAG MKTAG('M', 'A', 'D', 'k')  /* MAD I-frame */
#define MADm_TAG MKTAG('M', 'A', 'D', 'm')  /* MAD P-frame */
#define MADe_TAG MKTAG('M', 'A', 'D', 'e')  /* MAD lqp-frame */
#define MPCh_TAG MKTAG('M', 'P', 'C', 'h')  /* MPEG-2 */
#define TGQs_TAG MKTAG('T', 'G', 'Q', 's')  /* TGQ I-frame (appears in .TGQ files) */
#define pQGT_TAG MKTAG('p', 'Q', 'G', 'T')  /* TGQ I-frame (appears in .UV files) */
#define pIQT_TAG MKTAG('p', 'I', 'Q', 'T')  /* TQI/UV2 I-frame (.UV2/.WVE) */
#define MVhd_TAG MKTAG('M', 'V', 'h', 'd')
#define MV0K_TAG MKTAG('M', 'V', '0', 'K')
#define MV0F_TAG MKTAG('M', 'V', '0', 'F')
#define AVhd_TAG MKTAG('A', 'V', 'h', 'd')
#define AV0K_TAG MKTAG('A', 'V', '0', 'K')
#define AV0F_TAG MKTAG('A', 'V', '0', 'F')
#define MVIh_TAG MKTAG('M', 'V', 'I', 'h')  /* CMV header */
#define MVIf_TAG MKTAG('M', 'V', 'I', 'f')  /* CMV I-frame */
#define AVP6_TAG MKTAG('A', 'V', 'P', '6')
typedef struct VideoProperties {
    enum AVCodecID codec;
    AVRational time_base;
    int width, height;
    int nb_frames;
    int stream_index;
} VideoProperties;
typedef struct EaDemuxContext {
    int big_endian;

    VideoProperties video, alpha;

    enum AVCodecID audio_codec;
    int audio_stream_index;

    int bytes;
    int sample_rate;
    int num_channels;
    int num_samples;

    int platform;
} EaDemuxContext;
