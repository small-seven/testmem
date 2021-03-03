#include "avutil.h"
#include "audio_fifo.h"
#include "common.h"
#include "fifo.h"
#include "mem.h"
#include "samplefmt.h"
void av_audio_fifo_free(AVAudioFifo *af)
{
    if (af) {
        if (af->buf) {
            int i;
            for (i = 0; i < af->nb_buffers; i++) {
                av_fifo_freep(&af->buf[i]);
            }
            av_freep(&af->buf);
        }
        av_free(af);
    }
}
int av_audio_fifo_realloc(AVAudioFifo *af, int nb_samples)
{
    int i, ret, buf_size;

    if ((ret = av_samples_get_buffer_size(&buf_size, af->channels, nb_samples,
                                          af->sample_fmt, 1)) < 0)
        return ret;

    for (i = 0; i < af->nb_buffers; i++) {
        if ((ret = av_fifo_realloc2(af->buf[i], buf_size)) < 0)
            return ret;
    }
    af->allocated_samples = nb_samples;
    return 0;
}
