#include <lilv/lilv.h>
#include <lv2/lv2plug.in/ns/ext/atom/atom.h>
#include <lv2/lv2plug.in/ns/ext/buf-size/buf-size.h>
#include "libavutil/avassert.h"
#include "libavutil/avstring.h"
#include "libavutil/channel_layout.h"
#include "libavutil/opt.h"
#include "audio.h"
#include "avfilter.h"
#include "internal.h"
typedef struct URITable {
    char    **uris;
    size_t    n_uris;
} URITable;
typedef struct LV2Context {
    const AVClass *class;
    char *plugin_uri;
    char *options;

    unsigned nb_inputs;
    unsigned nb_inputcontrols;
    unsigned nb_outputs;

    int sample_rate;
    int nb_samples;
    int64_t pts;
    int64_t duration;

    LilvWorld         *world;
    const LilvPlugin  *plugin;
    uint32_t           nb_ports;
    float             *values;
    URITable           uri_table;
    LV2_URID_Map       map;
    LV2_Feature        map_feature;
    LV2_URID_Unmap     unmap;
    LV2_Feature        unmap_feature;
    LV2_Atom_Sequence  seq_in[2];
    LV2_Atom_Sequence *seq_out;
    const LV2_Feature *features[5];

    float *mins;
    float *maxes;
    float *controls;

    LilvInstance *instance;

    LilvNode  *atom_AtomPort;
    LilvNode  *atom_Sequence;
    LilvNode  *lv2_AudioPort;
    LilvNode  *lv2_CVPort;
    LilvNode  *lv2_ControlPort;
    LilvNode  *lv2_Optional;
    LilvNode  *lv2_InputPort;
    LilvNode  *lv2_OutputPort;
    LilvNode  *urid_map;
    LilvNode  *powerOf2BlockLength;
    LilvNode  *fixedBlockLength;
    LilvNode  *boundedBlockLength;
} LV2Context;
#define OFFSET(x) offsetof(LV2Context, x)
#define FLAGS AV_OPT_FLAG_AUDIO_PARAM | AV_OPT_FLAG_FILTERING_PARAM
static void uri_table_destroy(URITable *table)
{
    int i;

    for (i = 0; i < table->n_uris; i++) {
        av_freep(&table->uris[i]);
    }

    av_freep(&table->uris);
}
