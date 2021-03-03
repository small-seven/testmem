#include "libavutil/avassert.h"
#include "libavutil/pixfmt.h"
#include "cbs.h"
#include "cbs_internal.h"
#include "cbs_av1.h"
#include "internal.h"
#define HEADER(name) do { \
#define CHECK(call) do { \
#define FUNC_NAME(rw, codec, name) cbs_ ## codec ## _ ## rw ## _ ## name
#define FUNC_AV1(rw, name) FUNC_NAME(rw, av1, name)
#define FUNC(name) FUNC_AV1(READWRITE, name)
#define SUBSCRIPTS(subs, ...) (subs > 0 ? ((int[subs + 1]){ subs, __VA_ARGS__ }) : NULL)
#define fb(width, name) \
#define fc(width, name, range_min, range_max) \
#define flag(name) fb(1, name)
#define su(width, name) \
#define fbs(width, name, subs, ...) \
#define fcs(width, name, range_min, range_max, subs, ...) \
#define flags(name, subs, ...) \
#define sus(width, name, subs, ...) \
#define fixed(width, name, value) do { \
#define READ
#define READWRITE read
#define RWContext GetBitContext
#define xf(width, name, var, range_min, range_max, subs, ...) do { \
#define xsu(width, name, var, subs, ...) do { \
#define uvlc(name, range_min, range_max) do { \
#define ns(max_value, name, subs, ...) do { \
#define increment(name, min, max) do { \
#define subexp(name, max, subs, ...) do { \
#define delta_q(name) do { \
#define leb128(name) do { \
#define infer(name, value) do { \
#define byte_alignment(rw) (get_bits_count(rw) % 8)
#include "cbs_av1_syntax_template.c"
#undef READ
#undef READWRITE
#undef RWContext
#undef xf
#undef xsu
#undef uvlc
#undef ns
#undef increment
#undef subexp
#undef delta_q
#undef leb128
#undef infer
#undef byte_alignment
#define WRITE
#define READWRITE write
#define RWContext PutBitContext
#define xf(width, name, var, range_min, range_max, subs, ...) do { \
#define xsu(width, name, var, subs, ...) do { \
#define uvlc(name, range_min, range_max) do { \
#define ns(max_value, name, subs, ...) do { \
#define increment(name, min, max) do { \
#define subexp(name, max, subs, ...) do { \
#define delta_q(name) do { \
#define leb128(name) do { \
#define infer(name, value) do { \
#define byte_alignment(rw) (put_bits_count(rw) % 8)
#include "cbs_av1_syntax_template.c"
#undef WRITE
#undef READWRITE
#undef RWContext
#undef xf
#undef xsu
#undef uvlc
#undef ns
#undef increment
#undef subexp
#undef delta_q
#undef leb128
#undef infer
#undef byte_alignment
