#include "libavutil/avassert.h"
#include "cbs.h"
#include "cbs_internal.h"
#include "cbs_mpeg2.h"
#include "internal.h"
#define HEADER(name) do { \
#define CHECK(call) do { \
#define FUNC_NAME(rw, codec, name) cbs_ ## codec ## _ ## rw ## _ ## name
#define FUNC_MPEG2(rw, name) FUNC_NAME(rw, mpeg2, name)
#define FUNC(name) FUNC_MPEG2(READWRITE, name)
#define SUBSCRIPTS(subs, ...) (subs > 0 ? ((int[subs + 1]){ subs, __VA_ARGS__ }) : NULL)
#define ui(width, name) \
#define uir(width, name) \
#define uis(width, name, subs, ...) \
#define uirs(width, name, subs, ...) \
#define xui(width, name, var, range_min, range_max, subs, ...) \
#define sis(width, name, subs, ...) \
#define marker_bit() \
#define bit(string, value) do { \
#define READ
#define READWRITE read
#define RWContext GetBitContext
#define xuia(width, string, var, range_min, range_max, subs, ...) do { \
#define xsi(width, name, var, subs, ...) do { \
#define nextbits(width, compare, var) \
#define infer(name, value) do { \
#include "cbs_mpeg2_syntax_template.c"
#undef READ
#undef READWRITE
#undef RWContext
#undef xuia
#undef xsi
#undef nextbits
#undef infer
#define WRITE
#define READWRITE write
#define RWContext PutBitContext
#define xuia(width, string, var, range_min, range_max, subs, ...) do { \
#define xsi(width, name, var, subs, ...) do { \
#define nextbits(width, compare, var) (var)
#define infer(name, value) do { \
#include "cbs_mpeg2_syntax_template.c"
#undef WRITE
#undef READWRITE
#undef RWContext
#undef xuia
#undef xsi
#undef nextbits
#undef infer
#define START(start_code, type, read_func, free_func) \
#undef START
#define START(start_code, type, func) \
#undef START
