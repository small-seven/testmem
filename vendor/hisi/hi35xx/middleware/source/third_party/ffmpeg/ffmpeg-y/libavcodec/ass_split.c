#include "avcodec.h"
#include "ass_split.h"
typedef enum {
    ASS_STR,
    ASS_INT,
    ASS_FLT,
    ASS_COLOR,
    ASS_TIMESTAMP,
    ASS_ALGN,
} ASSFieldType;
typedef struct {
    const char *name;
    int type;
    int offset;
} ASSFields;
typedef struct {
    const char *section;
    const char *format_header;
    const char *fields_header;
    int         size;
    int         offset;
    int         offset_count;
    ASSFields   fields[24];
} ASSSection;
typedef int (*ASSConvertFunc)(void *dest, const char *buf, int len);

static int convert_str(void *dest, const char *buf, int len)
{
    char *str = av_malloc(len + 1);
    if (str) {
        memcpy(str, buf, len);
        str[len] = 0;
        if (*(void **)dest)
            av_free(*(void **)dest);
        *(char **)dest = str;
    }
void ff_ass_split_free(ASSSplitContext *ctx)
{
    if (ctx) {
        int i;
        for (i=0; i<FF_ARRAY_ELEMS(ass_sections); i++) {
            free_section(ctx, &ass_sections[i]);
            av_freep(&(ctx->field_order[i]));
        }
        av_free(ctx);
    }
}
