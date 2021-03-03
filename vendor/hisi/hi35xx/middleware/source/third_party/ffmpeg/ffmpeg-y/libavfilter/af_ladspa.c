#include <dlfcn.h>
#include <ladspa.h>
#include "libavutil/avassert.h"
#include "libavutil/avstring.h"
#include "libavutil/channel_layout.h"
#include "libavutil/opt.h"
#include "audio.h"
#include "avfilter.h"
#include "internal.h"
typedef struct LADSPAContext {
    const AVClass *class;
    char *dl_name;
    char *plugin;
    char *options;
    void *dl_handle;

    unsigned long nb_inputs;
    unsigned long *ipmap;      /* map input number to port number */

    unsigned long nb_inputcontrols;
    unsigned long *icmap;      /* map input control number to port number */
    LADSPA_Data *ictlv;        /* input controls values */

    unsigned long nb_outputs;
    unsigned long *opmap;      /* map output number to port number */

    unsigned long nb_outputcontrols;
    unsigned long *ocmap;      /* map output control number to port number */
    LADSPA_Data *octlv;        /* output controls values */

    const LADSPA_Descriptor *desc;
    int *ctl_needs_value;
    int nb_handles;
    LADSPA_Handle *handles;

    int sample_rate;
    int nb_samples;
    int64_t pts;
    int64_t duration;
} LADSPAContext;
#define OFFSET(x) offsetof(LADSPAContext, x)
#define FLAGS AV_OPT_FLAG_AUDIO_PARAM | AV_OPT_FLAG_FILTERING_PARAM
