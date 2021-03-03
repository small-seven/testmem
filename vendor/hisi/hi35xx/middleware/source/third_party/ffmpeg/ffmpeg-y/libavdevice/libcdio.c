#include "config.h"
#if HAVE_CDIO_PARANOIA_H
#include <cdio/cdda.h>
#include <cdio/paranoia.h>
#elif HAVE_CDIO_PARANOIA_PARANOIA_H
#include <cdio/paranoia/cdda.h>
#include <cdio/paranoia/paranoia.h>
#endif
#include "libavutil/log.h"
#include "libavutil/mem.h"
#include "libavutil/opt.h"
#include "libavformat/avformat.h"
#include "libavformat/internal.h"
typedef struct CDIOContext {
    const AVClass       *class;
    cdrom_drive_t       *drive;
    cdrom_paranoia_t *paranoia;
    int32_t last_sector;

    /* private options */
    int speed;
    int paranoia_mode;
} CDIOContext;
#define OFFSET(x) offsetof(CDIOContext, x)
#define DEC AV_OPT_FLAG_DECODING_PARAM
