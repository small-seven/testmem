#include "libavutil/attributes.h"
#include "libavutil/avassert.h"
#include "bytestream.h"
#include "cbs.h"
#include "cbs_internal.h"
#include "cbs_h264.h"
#include "cbs_h265.h"
#include "h264.h"
#include "h264_sei.h"
#include "h2645_parse.h"
#include "hevc.h"
#include "hevc_sei.h"
#define HEADER(name) do { \
#define CHECK(call) do { \
#define FUNC_NAME(rw, codec, name) cbs_ ## codec ## _ ## rw ## _ ## name
#define FUNC_H264(rw, name) FUNC_NAME(rw, h264, name)
#define FUNC_H265(rw, name) FUNC_NAME(rw, h265, name)
#define SUBSCRIPTS(subs, ...) (subs > 0 ? ((int[subs + 1]){ subs, __VA_ARGS__ }) : NULL)
#define u(width, name, range_min, range_max) \
#define ub(width, name) \
#define flag(name) ub(1, name)
#define ue(name, range_min, range_max) \
#define i(width, name, range_min, range_max) \
#define ib(width, name) \
#define se(name, range_min, range_max) \
#define us(width, name, range_min, range_max, subs, ...) \
#define ubs(width, name, subs, ...) \
#define flags(name, subs, ...) \
#define ues(name, range_min, range_max, subs, ...) \
#define is(width, name, range_min, range_max, subs, ...) \
#define ibs(width, name, subs, ...) \
#define ses(name, range_min, range_max, subs, ...) \
#define fixed(width, name, value) do { \
#define READ
#define READWRITE read
#define RWContext GetBitContext
#define xu(width, name, var, range_min, range_max, subs, ...) do { \
#define xue(name, var, range_min, range_max, subs, ...) do { \
#define xi(width, name, var, range_min, range_max, subs, ...) do { \
#define xse(name, var, range_min, range_max, subs, ...) do { \
#define infer(name, value) do { \
#define more_rbsp_data(var) ((var) = cbs_h2645_read_more_rbsp_data(rw))
#define byte_alignment(rw) (get_bits_count(rw) % 8)
#define allocate(name, size) do { \
#define FUNC(name) FUNC_H264(READWRITE, name)
#include "cbs_h264_syntax_template.c"
#undef FUNC
#define FUNC(name) FUNC_H265(READWRITE, name)
#include "cbs_h265_syntax_template.c"
#undef FUNC
#undef READ
#undef READWRITE
#undef RWContext
#undef xu
#undef xi
#undef xue
#undef xse
#undef infer
#undef more_rbsp_data
#undef byte_alignment
#undef allocate
#define WRITE
#define READWRITE write
#define RWContext PutBitContext
#define xu(width, name, var, range_min, range_max, subs, ...) do { \
#define xue(name, var, range_min, range_max, subs, ...) do { \
#define xi(width, name, var, range_min, range_max, subs, ...) do { \
#define xse(name, var, range_min, range_max, subs, ...) do { \
#define infer(name, value) do { \
#define more_rbsp_data(var) (var)
#define byte_alignment(rw) (put_bits_count(rw) % 8)
#define allocate(name, size) do { \
#define FUNC(name) FUNC_H264(READWRITE, name)
#include "cbs_h264_syntax_template.c"
#undef FUNC
#define FUNC(name) FUNC_H265(READWRITE, name)
#include "cbs_h265_syntax_template.c"
#undef FUNC
#undef WRITE
#undef READWRITE
#undef RWContext
#undef xu
#undef xi
#undef xue
#undef xse
#undef u
#undef i
#undef flag
#undef ue
#undef se
#undef infer
#undef more_rbsp_data
#undef byte_alignment
#undef allocate
#define cbs_h2645_replace_ps(h26n, ps_name, ps_var, id_element) \
