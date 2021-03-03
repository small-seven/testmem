#include "libavutil/avutil.h"
#include "libavutil/avstring.h"
#include "libavutil/opt.h"
#include "internal.h"
#include "avformat.h"
#include "avio_internal.h"
#include "tee_common.h"
typedef enum {
    ON_SLAVE_FAILURE_ABORT  = 1,
    ON_SLAVE_FAILURE_IGNORE = 2
} SlaveFailurePolicy;
#define DEFAULT_SLAVE_FAILURE_POLICY ON_SLAVE_FAILURE_ABORT
typedef struct {
    AVFormatContext *avf;
    AVBSFContext **bsfs; ///< bitstream filters per stream

    SlaveFailurePolicy on_fail;
    int use_fifo;
    AVDictionary *fifo_options;

    /** map from input to output streams indexes,
     * disabled output streams are set to -1 */
    int *stream_map;
    int header_written;
} TeeSlave;
typedef struct TeeContext {
    const AVClass *class;
    unsigned nb_slaves;
    unsigned nb_alive;
    TeeSlave *slaves;
    int use_fifo;
    AVDictionary *fifo_options;
    char *fifo_options_str;
} TeeContext;
#define OFFSET(x) offsetof(TeeContext, x)
#define STEAL_OPTION(option, field) do {                                \
