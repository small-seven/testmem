#include <inttypes.h>
#include "avformat.h"
#include "avio_internal.h"
#include "spdif.h"
#include "libavcodec/ac3.h"
#include "libavcodec/adts_parser.h"
#include "libavcodec/dca.h"
#include "libavcodec/dca_syncwords.h"
#include "libavutil/opt.h"
typedef struct IEC61937Context {
    const AVClass *av_class;
    enum IEC61937DataType data_type;///< burst info - reference to type of payload of the data-burst
    int length_code;                ///< length code in bits or bytes, depending on data type
    int pkt_offset;                 ///< data burst repetition period in bytes
    uint8_t *buffer;                ///< allocated buffer, used for swap bytes
    int buffer_size;                ///< size of allocated buffer

    uint8_t *out_buf;               ///< pointer to the outgoing data before byte-swapping
    int out_bytes;                  ///< amount of outgoing bytes

    int use_preamble;               ///< preamble enabled (disabled for exactly pre-padded DTS)
    int extra_bswap;                ///< extra bswap for payload (for LE DTS => standard BE DTS)

    uint8_t *hd_buf;                ///< allocated buffer to concatenate hd audio frames
    int hd_buf_size;                ///< size of the hd audio buffer
    int hd_buf_count;               ///< number of frames in the hd audio buffer
    int hd_buf_filled;              ///< amount of bytes in the hd audio buffer

    int dtshd_skip;                 ///< counter used for skipping DTS-HD frames

    /* AVOptions: */
    int dtshd_rate;
    int dtshd_fallback;
#define SPDIF_FLAG_BIGENDIAN    0x01
    int spdif_flags;

    /// function, which generates codec dependent header information.
    /// Sets data_type and pkt_offset, and length_code, out_bytes, out_buf if necessary
    int (*header_info) (AVFormatContext *s, AVPacket *pkt);
} IEC61937Context;
#define MAT_FRAME_SIZE          61424
#define TRUEHD_FRAME_OFFSET     2560
#define MAT_MIDDLE_CODE_OFFSET  -4
