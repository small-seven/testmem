#include "cbs.h"
#include "cbs_internal.h"
#include "cbs_jpeg.h"
#define HEADER(name) do { \
#define CHECK(call) do { \
#define SUBSCRIPTS(subs, ...) (subs > 0 ? ((int[subs + 1]){ subs, __VA_ARGS__ }) : NULL)
#define u(width, name, range_min, range_max) \
#define us(width, name, sub, range_min, range_max) \
#define READ
#define READWRITE read
#define RWContext GetBitContext
#define FUNC(name) cbs_jpeg_read_ ## name
#define xu(width, name, range_min, range_max, subs, ...) do { \
#include "cbs_jpeg_syntax_template.c"
#undef READ
#undef READWRITE
#undef RWContext
#undef FUNC
#undef xu
#define WRITE
#define READWRITE write
#define RWContext PutBitContext
#define FUNC(name) cbs_jpeg_write_ ## name
#define xu(width, name, range_min, range_max, subs, ...) do { \
#include "cbs_jpeg_syntax_template.c"
#undef WRITE
#undef READWRITE
#undef RWContext
#undef FUNC
#undef xu
#define SEGMENT(marker, type, func, free) \
#undef SEGMENT
#define SEGMENT(marker, func) \
