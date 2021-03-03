#include <vorbis/vorbisenc.h>
#include "avcodec.h"
#include "bytestream.h"
#include "internal.h"
typedef struct OggVorbisDecContext {
    vorbis_info vi;                     /**< vorbis_info used during init   */
    vorbis_dsp_state vd;                /**< DSP state used for analysis    */
    vorbis_block vb;                    /**< vorbis_block used for analysis */
    vorbis_comment vc;                  /**< VorbisComment info             */
    ogg_packet op;                      /**< ogg packet                     */
} OggVorbisDecContext;
#if 0
#endif
