#include "avcodec.h"
#include "davs2.h"
typedef struct DAVS2Context {
    void *decoder;

    AVFrame *frame;
    davs2_param_t    param;      // decoding parameters
    davs2_packet_t   packet;     // input bitstream

    davs2_picture_t  out_frame;  // output data, frame data
    davs2_seq_info_t headerset;  // output data, sequence header

}DAVS2Context;
